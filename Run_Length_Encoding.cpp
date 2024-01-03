string encode(string src)
{     
  string ans = "";
  int cnt = 1;
  char ch = src[0];
  for(int i = 0 ; i < src.size() - 1; i++){
      if(ch == src[i+1]){
          cnt++;
      }
      else{
          ans.push_back(ch);
          ans.append(to_string(cnt));
          ch = src[i+1];
          cnt = 1;
      }
  }
  ans.push_back(ch);
  ans.append(to_string(cnt));
  return ans;

}   
