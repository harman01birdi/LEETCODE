class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum=0;
        int totalsum=INT_MIN;
        for(int val:nums){
            currentsum+=val;
            totalsum=max(totalsum,currentsum);
            if(currentsum<0){
                currentsum=0;
            }
        }
    return totalsum;
    }


};