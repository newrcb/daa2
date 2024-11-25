#include <iostream>
using namespace std;

const int MAX = 100;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to find the root of a vertex (with path compression)
int find(int parent[], int v) {
    if (parent[v] != v)
        parent[v] = find(parent, parent[v]);
    return parent[v];
}

// Function to perform the union of two sets
void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);

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

// Function to sort edges by weight
void sortEdges(Edge edges[], int e) {
    for (int i = 0; i < e - 1; i++) {
        for (int j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int kruskal(Edge edges[], int n, int e) {
    int mstWeight = 0;
    int parent[MAX], rank[MAX];

    // Initialize parent and rank arrays
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    // Sort edges by weight
    sortEdges(edges, e);

    int edgeCount = 0;

    // Process edges in increasing weight order
    for (int i = 0; i < e; i++) {
        int rootSrc = find(parent, edges[i].src);
        int rootDest = find(parent, edges[i].dest);

        // If they belong to different sets, include the edge in MST
        if (rootSrc != rootDest) {
            unionSets(parent, rank, rootSrc, rootDest);
            mstWeight += edges[i].weight;
            edgeCount++;
            cout << "Edge included in MST: (" << edges[i].src + 1 << ", " << edges[i].dest + 1 << ") with weight " << edges[i].weight << endl;

            if (edgeCount == n - 1) break; // MST is complete
        }
    }

    if (edgeCount != n - 1) {
        cout << "Graph is disconnected; MST not possible." << endl;
        return -1;
    }

    return mstWeight;
}

int main() {
    int n, e;
    Edge edges[MAX];

    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (source, destination, weight):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        // Convert to 0-based indexing
        edges[i].src--;
        edges[i].dest--;
    }

    cout << "Finding Minimum Spanning Tree using Kruskal's Algorithm:" << endl;
    int mstWeight = kruskal(edges, n, e);

    if (mstWeight != -1) {
        cout << "Total weight of MST: " << mstWeight << endl;
    }

    return 0;
}
