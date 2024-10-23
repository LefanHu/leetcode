#include <vector>
using namespace std;

struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i){
            // initialize parents
            parent[i] = i;
        }
    }

    // Find the parent (root) of a set, with path compression
    int find(int u) {
        if (parent[u] != u){
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool join(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);

        if (root_u == root_v) return false;

        // Union by rank
        if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
        return true;
    }
};