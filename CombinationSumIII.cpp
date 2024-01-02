class Solution {
private:
    void solve(int start , int k , int sum , vector<vector<int>> &ans , vector<int> ds) {

        if(k == 0 && sum == 0){
            ans.push_back(ds);
        }
        if(k < 0)return;

        for(int i = start ; i <= 9 ; i++){
            if(sum >= i){
                ds.push_back(i);
                solve(i+1 , k-1 , sum-i , ans , ds);
                ds.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1 , k , n , ans , ds);
        return ans;
    }
};