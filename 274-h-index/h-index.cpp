class Solution {
public:
    int hIndex(vector<int>& citations) {
      sort(citations.begin(),citations.end(),greater<int>());
      int cnt=0;
      for(int i=0;i<citations.size();i++){
        if(i+1<=citations[i]){
            cnt++;
        }
        else{
            break;
        }
      } 
      return cnt;  
    }
};