class Solution {
public:
    bool iscycle(int src, vector<bool>&vis, vector<bool>&recpath, vector<vector<int>>&prerequisites){
        vis[src]=true;
        recpath[src]=true;

        for(int i=0; i<prerequisites.size(); i++){
            int v= prerequisites[i][0];
            int u= prerequisites[i][1];

            if(u == src){
                if(!vis[v]){
                    if(iscycle(v, vis, recpath, prerequisites)){
                        return true;
                    }
                }else if(recpath[v]){
                    return true;
                }
            }
        }
        recpath[src]= false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool>vis(numCourses, false);
        vector<bool>recpath(numCourses, false);

        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(iscycle(i, vis, recpath, prerequisites)){
                    return false;
                }
            }
        }
        return true;
    }
};