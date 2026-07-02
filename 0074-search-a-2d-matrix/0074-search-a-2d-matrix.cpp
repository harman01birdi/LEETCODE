class Solution {
public:
    bool searchinrow(vector<vector<int>>&mat,int target,int row){
        int m=mat[0].size();
        int start=0;
        int end=m-1;
        while(start<=end){
            int midrow=start+(end-start)/2;
            if(target==mat[row][midrow]){
                return true;
            }
            else if(target<mat[row][midrow]){
                end=midrow-1;
            }
            else{
                start=midrow+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();

        int startrow=0,endrow=n-1;
        while(startrow<=endrow){
            int midrow=startrow+(endrow-startrow)/2;
            if(target>=mat[midrow][0] && target<=mat[midrow][m-1]){
                return searchinrow(mat,target,midrow);
            }
            else if(target>=mat[midrow][m-1]){
                startrow=midrow+1;
            }
            else{
                endrow=midrow-1;
            }
        }
        return false;
    }
};