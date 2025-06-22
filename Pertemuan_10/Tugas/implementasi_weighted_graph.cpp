#include <iostream>
#include <vector>

using namespace std;

void addEdge(vector<vector<int>> &graph, int x, int y, int weight)
{
    graph[x][y] = weight;
}

void displayGraph(vector<vector<int>> graph)
{
    int n = graph.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Masukkan jumlah dimensi array ";
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));

    addEdge(graph, 0, 1, 3);
    addEdge(graph, 0, 2, 2);
    addEdge(graph, 1, 2, 4);
    addEdge(graph, 2, 3, 7);

    displayGraph(graph);

    return 0;
}