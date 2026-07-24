class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
         vector<int>f1(26,0); // f1->s1
         vector<int>f2(26,0); // f2->s2

         for(int i=0;i<s1.size();i++){
            f1[s1[i]-'a']++;
         }

         for(int i=0;i<s1.size();i++){
            f2[s2[i]-'a']++;
         }
         if(f1==f2){
            return true;
         }
        int k=s1.size();
         for(int i=k;i<s2.size();i++){
            f2[s2[i-k]-'a']--;
            f2[s2[i]-'a']++;

            if(f1==f2){
                return true;
            }
         }
         return false;

         

    }
};