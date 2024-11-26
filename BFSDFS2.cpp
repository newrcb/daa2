#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void bfs(int start, int graph[26][26], int n) {
    bool visited[26] = {false};
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        for (int i = 0; i < n; ++i) {
            if (graph[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}
void dfs(int start, int graph[26][26], bool visited[26], int n) {
    visited[start] = true;
    cout << start << " ";
    for (int i = 0; i < n; ++i) {
        if (graph[start][i] == 1 && !visited[i]) {
            dfs(i, graph, visited, n);
        }
    }
}
int main() {
    int graph[26][26] = {0};
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;
    cout << "Enter the edges (e.g., 0 1 for an edge between node 0 and node 1):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    cout << "BFS from node " << startNode << ": ";
    bfs(startNode, graph, 26);
    cout << "DFS from node " << startNode << ": ";
    bool visited[26] = {false};
    dfs(startNode, graph, visited, 26);
    return 0;
}
