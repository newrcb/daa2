#include <iostream>
using namespace std;

const int INF = 1000000000;
const int MAX = 100;
void floydWarshall(int graph[MAX][MAX], int n) {
    int dist[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    cout << "Shortest distances between every pair of vertices:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                cout << "INF ";
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
}
int main() {
    int n;
    int graph[MAX][MAX];
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the adjacency matrix (use " << INF << " for no direct edge):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    floydWarshall(graph, n);
    return 0;
}
