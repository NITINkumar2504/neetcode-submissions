class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;

        int freshCount = 0;
        int time = 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 2) q.push({i, j});
               else if(grid[i][j] == 1) freshCount++;
            }
        }

        if(freshCount == 0) return 0;

        vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

        while(!q.empty()){
            int n = q.size();
            while(n--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(auto &p: dir){
                    int newx = x + p.first;
                    int newy = y + p.second;

                    if(newx >= 0 && newx < row && newy >= 0 && newy < col && grid[newx][newy] == 1){
                        q.push({newx, newy});
                        grid[newx][newy] = 2;
                        freshCount--;
                    }
                }
            }
            time++;
        }

        return freshCount == 0 ? time - 1 : -1;
        // time - 1, bcoz last fruit in queue does not rot any adjacent fruit (no fresh/reachable fruits are left)        
    }
};
