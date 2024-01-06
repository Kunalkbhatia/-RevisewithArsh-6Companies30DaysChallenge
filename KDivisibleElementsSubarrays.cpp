class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> s;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            int count = 0;
            ans.clear();
            for(int j = i ; j < nums.size() ; j++){
                if(nums[j] % p == 0)count++;
                if(count > k)break;
                ans.push_back(nums[j]);
                s.insert(ans);
            }
        }
        return s.size();
    }
};