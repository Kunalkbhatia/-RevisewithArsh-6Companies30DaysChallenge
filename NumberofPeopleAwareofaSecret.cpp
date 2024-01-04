class Solution {
public:
    int mod = int(1e9+7);
private:
    int solve(int start , int delays , int forget, int n , vector<int> &dp){

        if(start == n)return 1;
        if(start > n)return 0 ;
        if(dp[start] != -1)return dp[start];
        int ans=1;
        if(start+forget <= n)ans = 0;
        for(int day = start+delays ; day < start+forget ; day++){
            ans = (ans  + solve(day , delays , forget, n, dp))%mod;
        }
        return dp[start] = ans ;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> dp(n+1 , -1);
        return solve(1 , delay , forget , n , dp);
    }
};