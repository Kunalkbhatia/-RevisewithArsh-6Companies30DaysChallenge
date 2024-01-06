class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int median;
        int n = nums.size();
        if(n % 2 == 0){
            median = ( nums[(n/2)-1] + nums[(n/2)])/2;
        }
        else{
            median = (nums[(n)/2]);
        }
        
        long long acc = 0;
        for(int j = 0 ; j < nums.size() ; j++){
            acc += (long long)(abs(median - nums[j]));
        }
        return acc;
    }
};