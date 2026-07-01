class Solution {
public:

    bool isCycledfs(int src,
             vector<vector<int>>& adj,
             vector<bool>& vis,
             vector<bool>& rec)
    {
        vis[src] = true;
        rec[src] = true;

        for(int v : adj[src])
        {
            if(!vis[v])
            {
                if(isCycledfs(v, adj, vis, rec))
                    return true;
            }
            else if(rec[v])
            {
                return true;
            }
        }

        rec[src] = false;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prerequisites) {

        vector<vector<int>> adj(n);

        for(auto &e : prerequisites)
            adj[e[1]].push_back(e[0]);

        vector<bool> vis(n,false);
        vector<bool> rec(n,false);

        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(isCycledfs(i, adj, vis, rec))
                    return false;
            }
        }

        return true;
    }
};