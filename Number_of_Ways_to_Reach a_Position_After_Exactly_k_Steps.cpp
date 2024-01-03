class Solution {
public:
    int mod = int(1e9+7);
private:
    int ways(int start, int steps, int end, int add,  vector<vector<int>> &dp){

        if(steps == 0)return start == end;
        if(dp[start+add][steps] != -1)return dp[start+add][steps];

        int right = ways(start+1, steps-1, end, add, dp);
        int left  = ways(start-1, steps-1, end, add, dp);
        return dp[start+add][steps] =  (right + left)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int add = k-1;
        int n = startPos + k + add ;
        vector<vector<int>> dp(n, vector<int> (k+1 , -1));
        return ways(startPos, k, endPos, add,  dp);
    }
};