class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                // +1 if target, -1 otherwise
                sum += (nums[j] == target) ? 1 : -1;
                
                // sum > 0 means target appears more than half the time
                if (sum > 0) count++;
            }
        }
        
        return count;
    }
};