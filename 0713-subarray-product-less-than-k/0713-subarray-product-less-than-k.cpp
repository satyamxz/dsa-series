class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int left = 0;
        long long product = 1;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Add current element
            product *= nums[right];

            // Shrink window if product is >= k
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            // Number of valid subarrays ending at right
            ans += right - left + 1;
        }

        return ans;
    }
};