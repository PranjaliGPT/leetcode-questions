class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);

        int left = 0, right = nums.size() - 1;

        // Find first occurrence
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
        }

        if (left >= nums.size() || nums[left] != target)
            return ans;

        ans[0] = left;

        // Find last occurrence
        right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        ans[1] = right;

        return ans;
    }
};