class Solution {
public:
    int avg(vector<vector<int>>& img , int x , int y , int dx[] , int dy[]){
        int row = img.size();
        int col = img[0].size();
        int sum = img[x][y];
        int n = 1;
        for(int i = 0 ; i < 8 ; i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1 >= 0 && x1 < row && y1 >= 0 && y1 < col){
                n++;
                sum += img[x1][y1];
            }
        }
        int ans = sum/n;
        return ans;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int row = img.size();
        int col = img[0].size();

        vector<vector<int>> ans(row , vector<int> (col , 0));

        int dx[8] = {-1 , -1 , 0 , 1 , 1 , 1 , 0 , -1};
        int dy[8] = {0 , 1 , 1 , 1 , 0 , -1 , -1 , -1};

        for(int i = 0 ; i < row ; i++){
            for(int j = 0 ; j < col ; j++){
                ans[i][j] = avg(img , i , j , dx , dy);
            }
        }
        return ans;
    }
};