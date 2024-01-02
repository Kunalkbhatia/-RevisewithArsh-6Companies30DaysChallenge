class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        // mapping 
        map<string , vector<string>> mp;
        for(int i = 0 ; i < access_times.size() ; i++){
            mp[access_times[i][0]].push_back(access_times[i][1]);
        }

        // solving
        vector<string> ans;
        string time = "";
        for(auto it : mp){
            if(it.second.size() == 1)continue;
            sort((it.second).begin() , (it.second).end());
            for(int i = 0; i < it.second.size()-2 ; i++){
                 time = it.second[i];
                 if(time[1] == '9'){
                     time[0]++;
                     time[1] = '0';
                 }
                 else{
                     time[1]++;
                 }
                 if(time > it.second[i+1] && time > it.second[i+2]){
                     ans.push_back(it.first);
                     break;
                 }
             }
        }
        return ans;
    }
};