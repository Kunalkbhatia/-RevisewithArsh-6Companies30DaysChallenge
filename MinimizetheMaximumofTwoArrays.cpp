class Solution {
public :
    bool isValid(long long mid, long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2) {

        long long count_arr1 = mid - (mid / divisor1);
        long long count_arr2 = mid - (mid / divisor2);
        long long prod = ((long long)divisor1 * (long long)divisor2);
        long long lcm = prod / std::__gcd(divisor1, divisor2);
        long long count_both = mid - (mid / divisor1) - (mid / divisor2) + (mid / lcm);

        if ((count_arr1 >= uniqueCnt1) && (count_arr2 >= uniqueCnt2) && (count_arr1 + count_arr2 - count_both >= uniqueCnt1 + uniqueCnt2))
            return true;

        return false;
    }
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        
        long long low = 1;
        long long high = 10000000007;
        long long mid;
        long long ans = 0;
        while(low <= high){
            mid = low + (high - low)/2;
            if(isValid(mid, divisor1,  divisor2,  uniqueCnt1,  uniqueCnt2)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};