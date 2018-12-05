#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;
vector<int> vt[101];
int level[101];
int bfs(int sc)
{
    int visited[101];
    for(int i = 0; i <= 100; i++)
        visited[i] = 0;
    queue <int> Q;
    Q.push(sc);
    visited[sc] = 1;
    int mx = -1;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int ln = vt[u].size();
        for(int i = 0; i < ln; i++)
        {
            int v = vt[u][i];
            if(visited[v] == 0)
            {
                visited[v] = 1;
                level[v] = level[u] + 1;
                mx = max(mx, level[v]);
                Q.push(v);
            }
        }
    }
    return mx;
}

int main()
{
    //freopen("out.txt", "wt", stdout);
    int tc, cs = 1;
    cin >> tc;

    while(tc--)
    {
        for(int i = 0; i <= 100; i++)
            vt[i].clear();
        int n, r;
        cin >> n >> r;

        for(int i = 1; i <= r; i++)
        {
            int u, v;
            cin >> u >> v;
            vt[u].push_back(v);
            vt[v].push_back(u);
        }
        int src, dst;
        for(int i = 0; i <= 100; i++)
            level[i] = 0;
        cin >> src >> dst;
        if(n==2)
        {
            printf("Case %d: 1\n", cs++);
            continue;
        }
        int a = bfs(src);
        int b = bfs(dst);
        printf("Case %d: %d\n", cs++, b);
    }

    return 0;
}
