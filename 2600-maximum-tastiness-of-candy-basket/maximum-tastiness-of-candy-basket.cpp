class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        int l=0,r=1e9,ans=r;
        sort(price.begin(),price.end());
        while(l<=r){
            int mid=(l+r)/2;
            int cntofcandy=1,last=price[0];
            for(int i=1;i<n;i++){
                if(price[i]-last>=mid){
                    cntofcandy++;
                    last=price[i];
                }
            }
            if(cntofcandy>=k){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }

        }
        return ans;
    }
};