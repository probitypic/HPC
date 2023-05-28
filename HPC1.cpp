#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 100

vector<int> graph[N];
bool vis[N] = {false};

void bfs(int s)
{
    queue<int> q;
    vis[s] = true;
    q.push(s);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

#pragma omp parallel for
        for (int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i];

            if (!vis[v])
            {
                vis[v] = true;
                q.push(v);
            }
        }
    }
}

void dfs(int s)
{
    vis[s] = true;

#pragma omp parallel for
    for (int i = 0; i < graph[s].size(); i++)
    {
        int v = graph[s][i];

        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{

    int n, m, s, choice;
    cin >> n >> m >> s >> choice;

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    if (choice == 1)
        bfs(s);
    else if (choice == 2)
        dfs(s);
    else
        cout << "Invalid choice\n";

    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            cout << i << " ";
    }
    cout << endl;
}
