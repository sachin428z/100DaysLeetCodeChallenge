class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return;

        if(rank[px] < rank[py])
            parent[px] = py;

        else if(rank[px] > rank[py])
            parent[py] = px;

        else {
            parent[py] = px;
            rank[px]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size() < n - 1)
            return -1;

        DSU dsu(n);

        for(auto &edge : connections) {
            dsu.unite(edge[0], edge[1]);
        }

        unordered_set<int> components;

        for(int i = 0; i < n; i++) {
            components.insert(dsu.find(i));
        }

        return components.size() - 1;
    }
};