#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) : u(u), v(v), weight(w) {}
};

vector<Edge> kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge& e1, Edge& e2) {
        return e1.weight < e2.weight;
    });

    DisjointSet ds(V);
    vector<Edge> mst;

    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;

        if (ds.find(u) != ds.find(v)) {
            ds.unionSets(u, v);
            mst.push_back(edge);
        }
    }

    return mst;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges;
    cout << "Enter edges (u, v, weight):\n";
    for (int i = 0; i < E; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edges.push_back(Edge(u, v, weight));
    }

    vector<Edge> mst = kruskal(V, edges);

    cout << "Minimum Spanning Tree (MST):\n";
    for (const Edge& edge : mst) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}
