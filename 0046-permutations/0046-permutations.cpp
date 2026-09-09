class Solution {
public:
void find(int ind, vector<int> & nums, vector<vector<int>> &ans){
    int n = nums.size();
    if(ind==n){
            ans.push_back(nums);
            return;
        }
    for(int i = ind; i<n;i++){        
        swap(nums[ind],nums[i]);
        find(ind+1,nums,ans);
        swap(nums[ind], nums[i]);

    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        find(0,nums,ans);
        return ans;
    }
};