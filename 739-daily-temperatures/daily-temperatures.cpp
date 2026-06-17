class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int>ans(n,0);
        
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(temperatures[i]<temperatures[j]){
        //             ans[i]=j-i;
        //             break;
        //         }
        //         // else{
        //         //     ans[i]=0;
        //         // }
        //     }
        // }
        // return ans;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && temperatures[i]>temperatures[st.top()]){
                int idx=st.top();
                st.pop();
                ans[idx]=i-idx;
            }
            st.push(i);
        }
        return ans;
        
    }
};