class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int> map(n+1 , 0);
        vector<int> ans(2);
        for(int i = 0 ; i < arr.size(); i++){
            int value = arr[i];
            map[value]++;
            
        }
        for(int i = 1 ; i < map.size() ; i++){
            if(map[i] == 0)ans[1] = i;
            else if(map[i] == 2)ans[0] = i;
        }
       
        return ans;
    }
};