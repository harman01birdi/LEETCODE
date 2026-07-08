class Solution {
public:
    void getperms(vector<int>&nums, int index, vector<vector<int>>&ans){
        if(index == nums.size()){
            ans.push_back({nums});
            return;
        }
        for(int i=index;i<nums.size();i++){
            swap(nums[index],nums[i]);
            getperms(nums,index+1,ans);

            //backtracking
            swap(nums[index],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        getperms(nums,0,ans);
        return ans;
    }
};