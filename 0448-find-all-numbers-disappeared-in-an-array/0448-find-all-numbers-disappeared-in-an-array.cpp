class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>m;
        int n=nums.size();
        int count=0;

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        for(int i=1; i<=n; i++){
            if(m.find(i) == m.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};