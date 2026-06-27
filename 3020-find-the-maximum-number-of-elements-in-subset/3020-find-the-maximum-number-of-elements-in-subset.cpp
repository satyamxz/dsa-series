class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> freq;
        for (int n : nums) freq[n]++;
        int ans = 1;
        if (freq.count(1)) {
            int ones = freq[1];
            ans = max(ans, ones % 2 == 1 ? ones : ones - 1);
        }
        
        for (auto& [x, cnt] : freq) {
            if (x == 1) continue;
            
            long long cur = x;
            int chainLen = 0;
            while (freq.count(cur) && freq[cur] >= 2) {
                chainLen++;
                if (cur > 1e9 / cur) { 
                    cur = (long long)2e18;
                    break;
                }
                cur *= cur;
            }
        
            int total;
            if (freq.count(cur) && freq[cur] >= 1) {
                total = 2 * chainLen + 1;
            } else {
                total = chainLen == 0 ? 1 : 2 * chainLen - 1 + 2;
                total = 2 * chainLen - 1;
                if (chainLen == 0) total = 1;
            }
            
            ans = max(ans, total);
        }
        
        return ans;
    }
};