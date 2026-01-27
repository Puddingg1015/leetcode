#define NMAX 50001
#define XMAX 100001
#define lng long long int
#define ldbl long double
#define fori(N) for (int i = 0; i < N; i++)
#define forj(M) for (int j = 0; j < M; j++)


class Solution {
public:

    lng dists[NMAX];
    int n;
    vector<pair<int, int>> adj_list[NMAX]; // end node, weight
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;

    int minCost(int _n, vector<vector<int>>& edges) {
        n = _n;
        fill_n(dists+1, n-1, INT_MAX);
        // dists[n-1] = -1;
        fori(edges.size()) {
            adj_list[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
            adj_list[edges[i][1]].push_back(make_pair(edges[i][0], 2*edges[i][2]));
        }

        queue.emplace(make_pair(0, 0)); // weight, end node

        while (!queue.empty()) {
            pair<int, int> next = queue.top();
            queue.pop();
            int n_dist = next.first;
            int n_node = next.second;
            // cout << n_node << " " << n_dist << endl;
            if (n_dist <= dists[n_node]) {
                for (pair<int, int> edge : adj_list[n_node]) {
                    // cout << n_node << " > " <<  edge.first << " : " << edge.second << endl;
                    if (dists[n_node] + edge.second < dists[edge.first]) {
                        dists[edge.first] = dists[n_node] + edge.second;
                        queue.emplace(make_pair(dists[edge.first], edge.first));
                    }
                }
            }
        }
        if (dists[n-1] == INT_MAX) return -1;
        return (int) dists[n-1];
    }
};