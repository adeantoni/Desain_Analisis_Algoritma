#include <bits/stdc++.h>
#define MAX 100005
#define INF INT_MAX

using namespace std;

int dist[MAX];
vector<pair<int, int>> adj[MAX];
bool vis[MAX];
int route[MAX];

void dijkstra(int start)
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

    cout << "Rute terpendek dari kota " << start << " ke kota " << end << " adalah:" << endl;
    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i] << (i == path.size() - 1 ? "" : " -> "); // fungsi ternary
    }
}

void printTable(int from, int to)
{
    for (int i = from; i <= to; i++)
    {
        for (int j = 0; j < to; j++)
        {
            cout << "\t" << adj[i][j].second;
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cout << "Masukkan Jumlah Kota : ";
    cin >> N;
    
    cout << "Nilai Cost Matrix" << endl;

    for (int i = 1; i <= N; i++)
    {

        cout << "Cost Element Baris ke-: " << i << endl;

        for (int j = 1; j <= N; j++)
        {
            int weight;
            cin >> weight;
            adj[i].push_back({j, weight});
        }

        cout << endl;
    }

    cout << "Cost List : " << endl;
    printTable(1, N);
    cout << endl;

    int asal, tujuan;

    cout << "Input Kota Asal : ";
    cin >> asal;
    cout << "Input Kota Tujuan : ";
    cin >> tujuan;

    dijkstra(asal);

    printRoute(asal, tujuan);

    cout << endl;

    cout << "Minimum Cost : " << dist[tujuan] << endl;

    system("pause");

    return 0;
}