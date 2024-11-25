#include <iostream>
using namespace std;

const int MAX = 100;
void warshall(int graph[MAX][MAX], int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                graph[i][j] = graph[i][j] || (graph[i][k] && graph[k][j]);
            }
        }
    }
}
void printMatrix(int graph[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    int graph[MAX][MAX];
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }
    warshall(graph, n);
    cout << "Transitive Closure (Reachability Matrix):\n";
    printMatrix(graph, n);
    return 0;
}
