class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances from edges
        for(auto &it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        // Distance from a city to itself is 0
        for(int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Floyd-Warshall Algorithm
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {

                    if(dist[i][via] == INT_MAX ||
                       dist[via][j] == INT_MAX)
                        continue;

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][via] + dist[via][j]
                    );
                }
            }
        }

        int cntCity = INT_MAX;
        int cityNo = -1;

        for(int city = 0; city < n; city++) {

            int cnt = 0;

            for(int adjCity = 0; adjCity < n; adjCity++) {
                if(dist[city][adjCity] <= distanceThreshold) {
                    cnt++;
                }
            }

            // If same count, choose larger city number
            if(cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }
};