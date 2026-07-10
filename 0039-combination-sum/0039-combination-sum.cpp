class Solution {
public:
    set<vector<int>>s;
    void getallcomb(vector<int>&arr, int idx, int tar, vector<vector<int>>&ans, vector<int>comb){
        if(tar == 0){
            if(s.find(comb) == s.end()){
                ans.push_back(comb);
                s.insert(comb);
                return;
            }
        }

        if(idx == arr.size() || tar<0){
            return;
        }

        //single include
        comb.push_back(arr[idx]);
        getallcomb(arr, idx+1, tar-arr[idx], ans, comb);

        //multiple include
        getallcomb(arr, idx, tar-arr[idx], ans, comb);
        comb.pop_back();

        //exclude
        getallcomb(arr, idx+1, tar, ans, comb);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>comb;

        getallcomb(candidates, 0, target,ans, comb);
        return ans;
    }
};