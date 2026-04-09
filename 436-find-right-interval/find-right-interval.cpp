class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans;
        int n=intervals.size();
        vector<pair<int,int>>s;
        for(int i=0;i<n;i++){
            s.push_back({intervals[i][0],i});
        }
        sort(s.begin(),s.end());
        
        
        for(int i=0;i<n;i++){
            int endval=intervals[i][1];
            int rightindex=-1;
            int low=0;
            int high=n-1;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(s[mid].first>=endval){
                    rightindex=s[mid].second;
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            ans.push_back(rightindex);
        }
        return ans;
    }
};