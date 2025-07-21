class Solution {
public:
    int strStr(string haystack, string needle) {
        // int n=needle.size();
        // int m=haystack.size();
        // for(int i=0;i<m;i++){
        //     if(haystack.substr(i,n)==needle){
        //         return i;
        //     }
            
        // }
        // return -1;
        int a=needle.size();
        int b=haystack.size();
        for(int i=0;i<b;i++){
            if(haystack.substr(i,a) == needle){
                return i;
            }
        }
        return -1;
    }
};