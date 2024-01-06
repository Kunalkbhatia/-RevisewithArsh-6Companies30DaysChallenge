class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        int ans = 0;
        queue<pair<int,int>> q;
        queue<pair<int,int>> q2;
        int dx[4] = {0 , -1 , 0 , 1};
        int dy[4] = {-1 , 0 , 1 , 0};
        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                if(isWater[i][j] == 1){
                    isWater[i][j] = -1;
                    q.push({i,j});
                    q2.push({i,j});
                }
            }
        }


        while(!q.empty()){
            auto cell = q.front();
            q.pop();
            int value = isWater[cell.first][cell.second];
            if(value == -1)value = 0;
            for(int i = 0 ; i < 4 ; i++){
                int x = cell.first + dx[i];
                int y = cell.second + dy[i];
                if(x >= 0 && x < row && y >= 0 && y < col && isWater[x][y] == 0){
                    isWater[x][y] = value + 1;
                    q.push({x,y});
                }
            }
        }

        while(!q2.empty()){
            auto cell = q2.front();
            isWater[cell.first][cell.second] = 0 ;
            q2.pop();
        }
        return isWater;
    }
};