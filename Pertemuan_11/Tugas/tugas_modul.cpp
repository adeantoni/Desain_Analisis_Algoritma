#include <bits/stdc++.h>
#define MAX 100005
#define INF INT_MAX

using namespace std;

vector<pair<int, int>> adj[MAX];
bool vis[MAX];
int dist[MAX];
int route[MAX];

void djikstra(int start)
{
    memset(vis, false, sizeof vis);
    for (int i = 0; i < MAX; i++)
    {
        dist[i] = INF;
    }
    
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while(!pq.empty())
    {
        pair<int, int> p = pq.top();
        pq.pop();
        int x = p.second;
        if (vis[x])
        {
            continue;
        }
        vis[x] = true;

        for (int i = 0; i < adj[x].size(); i++)
        {
            int e = adj[x][i].first;
            int w = adj[x][i].second;
            if (dist[x] + w < dist[e])
            {
                dist[e] = dist[x] + w;
                route[e] = x;
                pq.push({dist[e], e});
            }
        }
    }
}

void addEdge(vector<pair<int, int>> *adj, int from, int to, int weight)
{
    // undirected graph

    adj[from].push_back({to, weight});
    adj[to].push_back({from, weight});
}

void printRoute(int start, int end) {
    if (dist[end] == INF) {
        cout << "Tidak ada rute dari node " << start << " ke node " << end << endl;
        return;
    }

    vector<int> path;
    int currentNode = end;

    while (currentNode != 0) {
        path.push_back(currentNode);
        currentNode = route[currentNode];
    }

    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << (i == path.size() - 1 ? "" : " -> "); // fungsi lambda
    }
}

int main()
{
    addEdge(adj, 1, 2, 7);
    addEdge(adj, 1, 3, 9);
    addEdge(adj, 1, 6, 14);
    addEdge(adj, 2, 3, 10);
    addEdge(adj, 2, 4, 15);
    addEdge(adj, 3, 4, 11);
    addEdge(adj, 3, 6, 2);
    addEdge(adj, 4, 5, 6);
    addEdge(adj, 5, 6, 9);

    int dari, ke;

    cout << "Masukkan node awal: ";
    cin >> dari;

    cout << "Masukkan node tujuan: ";
    cin >> ke;

    djikstra(dari);

    cout << "Jarak terpendek dari node " << dari << " ke node " << ke << " adalah: " << dist[ke] << endl;

    cout << "Rute: " << endl;
    printRoute(dari, ke);
    cout << endl;

    system("pause");

    return 0;
}