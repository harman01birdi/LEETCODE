class Solution {
public:
    void getsubsets(vector<int>&nums, vector<int>&ans, int i, vector<vector<int>>&allsubsets){
        if(i == nums.size()){
            allsubsets.push_back({ans});
            return ;
        }

        //include
        ans.push_back(nums[i]);
        getsubsets(nums,ans,i+1,allsubsets);

        ans.pop_back(); //backtraking
        //exclude
        getsubsets(nums,ans,i+1,allsubsets);
    }   



    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allsubsets;
        vector<int>ans;

        getsubsets(nums,ans,0,allsubsets);

        return allsubsets;
    }
};