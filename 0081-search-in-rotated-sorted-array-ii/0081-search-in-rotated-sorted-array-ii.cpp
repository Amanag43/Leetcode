class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)  return true;
             if(nums[low]==nums[mid] && nums[high]==nums[mid]){
                    low++;
                    high--;
                    continue;
                }
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; 
                } else {
                    low = mid + 1;
                }
            } 
            else {
                // Check if target falls inside the right sorted range
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;  // Search right
                } else {
                    high = mid - 1; // Search left
                }
            }
        }

        return false;
    }
};