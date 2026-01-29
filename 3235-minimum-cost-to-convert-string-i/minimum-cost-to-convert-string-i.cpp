#define NMAX 10001
#define lng long long int
#define ldbl long double
#define fori(N) for (int i = 0; i < N; i++)
#define forj(M) for (int j = 0; j < M; j++)
#define vpair pair<lng, char>


class Solution {
public:
    vector<pair<char, int>> adj_list[26]; // original[i]-'a' => changed[i]:cost[i]
    int n;
    int dist[126][126] = {{0}}; // distance from char original[i] to changed[i]

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        n = original.size();
        fori(n) {
            adj_list[original[i] - 'a'].push_back(make_pair(changed[i], cost[i]) );
        }
        lng out = 0;
        fori(source.length()) {
            if (source[i] != target[i]) {
                lng cost = getMinCost(source[i], target[i]);
                // cout << source[i] << "->" <<  target[i] << " : " << cost << endl;
                if (cost == -1) return -1;
                out += cost;
            }
        }
        return out;
    }

    lng getMinCost(char start, char end) {
        if (dist[start][end] != 0) return dist[start][end];
        priority_queue<vpair, vector<vpair>, greater<vpair>> pq;
        pq.push(make_pair(0, start));
        lng out = -1;
        while (!pq.empty()) {
            vpair node_pair = pq.top();
            pq.pop();
            int node_cost = node_pair.first;
            char node_char = node_pair.second;
            // cout << "at node " << node_cost << " " << node_char << endl;
            // if (node_char == end) out = node_cost;
            if (dist[start][node_char] != 0 && node_char != start && dist[start][node_char] < node_cost) continue;
            for (pair<char, int> adj_pair : adj_list[node_char - 'a']) {
                // cout << "checking " << adj_pair.first << " " << adj_pair.second << endl;
                lng new_cost = node_cost + adj_pair.second;
                if ((dist[start][adj_pair.first] == 0 && adj_pair.first != start) || new_cost < dist[start][adj_pair.first]) {
                    dist[start][adj_pair.first] = new_cost;
                    pq.push(make_pair(new_cost, adj_pair.first));
                }
                // if (dist[adj_pair.first][end] != 0) out = min(out, (lng)(dist[adj_pair.first][end] + dist[start][adj_pair.first]));
            }
        }
        if (dist[start][end] != 0) out = dist[start][end];
        return out;
    }

};