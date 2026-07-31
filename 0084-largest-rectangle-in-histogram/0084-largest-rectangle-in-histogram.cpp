class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>right(heights.size(),0);
        vector<int>left(heights.size(),0);
        stack<int>s;

        for(int i=heights.size()-1; i>=0; i--){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                right[i]=heights.size();
            }else{
                right[i]=s.top();
            }
            s.push(i);
        }


        while(!s.empty()){
            s.pop();
        }


        for(int i=0; i<heights.size(); i++){
            while(s.size() > 0 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                left[i]=-1;
            }else{
                left[i]=s.top();
            }
            s.push(i);
        }

        int ans=0;
        for(int i=0;i<heights.size();i++){
            int currarea=heights[i] * (right[i] - left[i] -1);
            ans=max(ans,currarea);
        }
        return ans;
    }
};