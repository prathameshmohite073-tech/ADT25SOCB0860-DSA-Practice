#include <iostream>
using namespace std;

int adj[100][100];
bool visited[100];
int n;

// DFS Function
void DFS(int vertex)
{
    visited[vertex] = true;
    cout << vertex << " ";

    for (int i = 0; i < n; i++)
    {
        if (adj[vertex][i] == 1 && visited[i] == false)
        {
            DFS(i);
        }
    }
}

int main()
{
    int e, u, v, start;

    // Input number of vertices
    cout << "Enter number of vertices: ";
    cin >> n;

    // Initialize adjacency matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }

    // Input number of edges
    cout << "Enter number of edges: ";
    cin >> e;

    // Add edges
    for (int k = 1; k <= e; k++)
    {
        cout << "Enter source vertex: ";
        cin >> u;

        cout << "Enter destination vertex: ";
        cin >> v;

        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // Display adjacency matrix
    cout << "\nAdjacency Matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    // Starting vertex
    cout << "\nEnter starting vertex for DFS: ";
    cin >> start;

    // Initialize visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    // Perform DFS
    cout << "DFS Traversal: ";
    DFS(start);

    return 0;
}
