class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        vector<vector<pair<int,int>>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> costs;

        for (auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            indegree[v]++;
            costs.push_back(w);
        }

        // Topological order
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto &p : adj[u]) {
                if (--indegree[p.first] == 0)
                    q.push(p.first);
            }
        }

        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()), costs.end());

        auto check = [&](long long limit) {
            const long long INF = (1LL << 60);
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                // Offline nodes cannot be used as intermediate nodes.
                if (u != 0 && u != n - 1 && !online[u]) continue;

                for (auto &[v, w] : adj[u]) {
                    if (w < limit) continue;
                    if (v != 0 && v != n - 1 && !online[v]) continue;

                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            return dist[n - 1] <= k;
        };

        // No valid path at all
        if (!check(0)) return -1;

        int lo = 0, hi = (int)costs.size() - 1;
        int ans = 0;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            if (check(costs[mid])) {
                ans = costs[mid];
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};