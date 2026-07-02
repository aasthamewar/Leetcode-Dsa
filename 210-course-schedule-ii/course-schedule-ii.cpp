class Solution {
public:

    bool isCycledfs(int src,
                    vector<bool>& vis,
                    vector<bool>& recpath,
                    vector<vector<int>>& adj)
    {
        vis[src] = true;
        recpath[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                if (isCycledfs(v, vis, recpath, adj))
                    return true;
            }
            else if (recpath[v]) {
                return true;
            }
        }

        recpath[src] = false;
        return false;
    }

    void topoOrder(int src,
                   vector<bool>& vis,
                   stack<int>& s,
                   vector<vector<int>>& adj)
    {
        vis[src] = true;

        for (int v : adj[src]) {
            if (!vis[v]) {
                topoOrder(v, vis, s, adj);
            }
        }

        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[1]].push_back(e[0]);
        }

        vector<bool> vis(n, false);
        vector<bool> recpath(n, false);

        // Check cycle
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (isCycledfs(i, vis, recpath, adj))
                    return {};
            }
        }

        // Topological Sort
        vis.assign(n, false);
        stack<int> s;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                topoOrder(i, vis, s, adj);
            }
        }

        vector<int> ans;

        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};