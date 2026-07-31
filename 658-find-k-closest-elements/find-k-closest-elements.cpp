class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>p;
        vector<int>ans;
        for(int i=0;i<arr.size();i++){
            int diff = abs(arr[i]-x);
            p.push({diff,arr[i]});

            if(p.size()>k){
                p.pop();
            }
        }
        while(!p.empty()){
            ans.push_back({p.top().second});
            p.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;

    }
};