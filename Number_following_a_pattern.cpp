class Solution{

public:
    string printMinNumberForPattern(string S){
        // code here 
        stack<int> s;
        int digit = 1;
        string ans = "";
        for(int i = 0 ; i < S.size() ; i++){
            if(S[i] == 'D'){
                s.push(digit);
                digit++;
            }
            else{
                s.push(digit);
                digit++;
                
                while(!s.empty()){
                    char ch = s.top() + '0';
                    ans.push_back(ch);
                    s.pop();
                }
            }
        }
        
        s.push(digit);
         while(!s.empty()){
                    char ch = s.top() + '0';
                    ans.push_back(ch);
                    s.pop();
                }
        return ans;
       
    }
};