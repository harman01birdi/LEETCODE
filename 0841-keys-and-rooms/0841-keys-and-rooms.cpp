class Solution {
public:

    void dfs(vector<vector<int>>& rooms, vector<bool>& visit, int room){
        visit[room]=true;

        for(int key : rooms[room]){
            if(!visit[key]){
                dfs(rooms, visit, key);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>visit(n, false);

        dfs(rooms, visit, 0);
        for(int i=0; i<n; i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;
    }
};