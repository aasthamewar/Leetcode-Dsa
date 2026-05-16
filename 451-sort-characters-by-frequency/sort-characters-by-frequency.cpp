class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>s1;
        string ans="";
        for(int i=0;i<s.size();i++){
            s1[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;

        for(auto& it:s1){
            pq.push({it.second,it.first});
        }
        while(!pq.empty()){
            auto x= pq.top();
            pq.pop();
            ans+=string(x.first,x.second);
        }
        return ans;

        
    }
};