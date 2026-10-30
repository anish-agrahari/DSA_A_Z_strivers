class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        struct Edge { 
            int v, w; bool same; 
        };

        vector<vector<Edge>> graph(n);

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w, labels[u] == labels[v]});
        }

        vector<int> done(n, k + 1);

        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> heap;
        heap.emplace(0, 0, 1);

        while (!heap.empty()) {
            auto [d, u, r] = heap.top();
            heap.pop();

            if (r >= done[u]) continue;
            done[u] = r;

            if (u == n - 1) return static_cast<int>(d);

            for (const auto& e : graph[u]) {
                int nr = e.same ? r + 1 : 1;

                if (nr < done[e.v]) {
                    heap.emplace(d + e.w, e.v, nr);
                }
            }
        }

        return -1;
    }
};