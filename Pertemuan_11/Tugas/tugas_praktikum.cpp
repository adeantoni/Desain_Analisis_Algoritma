#include <bits/stdc++.h>
#define MAX 100005
#define INF INT_MAX

using namespace std;

vector<pair<int, int>> adj[MAX];
bool vis[MAX];
int dist[MAX];

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
                pq.push({dist[e], e});
            }
        }
    }
}

int main()
{
    const int total_node = 9;
    adj[0].push_back({0, 0});
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 12});
    adj[0].push_back({3, 19});
    adj[0].push_back({4, 21});
    adj[0].push_back({5, 11});  
    adj[0].push_back({6, 9});
    adj[0].push_back({7, 8});
    adj[0].push_back({8, 14});

    djikstra(0);

    cout << "Vertex\tDistance from Source" << endl;

    for (int i = 0; i < total_node - 1; i++)
    {
        cout << "  " << adj[0][i].first << "\t\t" << dist[i] << endl;
    }

	getchar();  
    return 0;
}