class DisjointSet {
public:
    /* To store the ranks, parents and 
    sizes of different set of vertices */
    vector<int> rank, parent, size;

    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    // Function to find ultimate parent
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    // Function to implement union by rank
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    // Function to implement union by size
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:

    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n &&
               col >= 0 && col < n;
    }

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        DisjointSet ds(n * n);

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        // Step 1: Connect all existing 1's
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {

                if(grid[row][col] == 0) continue;

                for(int k = 0; k < 4; k++) {

                    int newr = row + dr[k];
                    int newc = col + dc[k];

                    if(isValid(newr, newc, n) &&
                       grid[newr][newc] == 1) {

                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;

                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        int mx = 0;

        // Step 2: Try converting each 0 to 1
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {

                if(grid[row][col] == 1) continue;

                set<int> components;

                for(int k = 0; k < 4; k++) {

                    int newr = row + dr[k];
                    int newc = col + dc[k];

                    if(isValid(newr, newc, n) &&
                       grid[newr][newc] == 1) {

                        components.insert(
                            ds.findUPar(newr * n + newc)
                        );
                    }
                }

                int sizeTotal = 0;

                for(auto parent : components) {
                    sizeTotal += ds.size[parent];
                }

                mx = max(mx, sizeTotal + 1);
            }
        }

        // Step 3: Handle all-1s grid
        for(int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx,
                     ds.size[ds.findUPar(cellNo)]);
        }

        return mx;
    }
};