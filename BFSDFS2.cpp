#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// BFS Function
void bfs(int start, int graph[26][26], int n) {
    bool visited[26] = {false}; // Track visited nodes
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << char(current + 'A') << " "; // Convert to character

        for (int i = 0; i < n; ++i) {
            if (graph[current][i] == 1 && !visited[i]) { // If connected and not visited
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// DFS Function
void dfs(int start, int graph[26][26], bool visited[26], int n) {
    visited[start] = true;
    cout << char(start + 'A') << " "; // Convert to character

    for (int i = 0; i < n; ++i) {
        if (graph[start][i] == 1 && !visited[i]) { // If connected and not visited
            dfs(i, graph, visited, n);
        }
    }
}

int main() {
    int graph[26][26] = {0}; // Adjacency matrix for the graph
    int edges;
    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter the edges (e.g., A B for an edge between A and B):" << endl;
    for (int i = 0; i < edges; ++i) {
        char u, v;
        cin >> u >> v;
        int uIndex = u - 'A'; // Convert to index
        int vIndex = v - 'A'; // Convert to index
        graph[uIndex][vIndex] = 1; // Mark edge
        graph[vIndex][uIndex] = 1; // Since the graph is undirected
    }

    char startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;
    int startIndex = startNode - 'A'; // Convert to index

    // Perform BFS
    cout << "BFS from node " << startNode << ": ";
    bfs(startIndex, graph, 26);

    // Perform DFS
    cout << "DFS from node " << startNode << ": ";
    bool visited[26] = {false};
    dfs(startIndex, graph, visited, 26);

    return 0;
}
