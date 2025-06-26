class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
        string ans="";
        int n=arr.size();
        //traversing for all character in first string
        for(int i=0;i<arr[0].size();i++){
            char ch=arr[0][i];
            bool match=true;
            for(int j=1;j<n;j++){
                //not match
                if(i>= arr[j].size() || ch!=arr[j][i]){
                    match=false;
                    break;
                }
            }
            if(match==false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans;
    }
};