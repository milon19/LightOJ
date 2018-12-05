#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector <int> vt[30001];
vector <int> wt[30001];
int cost[30001], visited[30001];

int bfs(int src)
{

        for(int i = 0; i < 30001; i++)
            cost[i] = 0, visited[i] = 0;
        queue <int> Q;
        Q.push(src);
        visited[src] = 1;
        int mx = -1, rr;
        while(!Q.empty())
        {
            int uu = Q.front();
            //cout << " " << uu << endl;
            Q.pop();
            int sz = vt[uu].size();
            for(int i = 0; i < sz; i++)
            {
                int vv = vt[uu][i];
                int tm = wt[uu][i];

                if(visited[vv] == 0)
                {

                    cost[vv] = max(cost[uu]+tm, cost[uu]);
                    //cout << " " << cost[vv] << endl;
                    if(mx < cost[vv])
                    {
                        rr = vv;
                        mx = cost[vv];
                    }
                    visited[vv] = 1;
                    Q.push(vv);
                }
                //cout << vv << " " << cost[vv] << endl;
            }
        }
        return rr;
}

int main()
{
    int tc, cs = 1;
    cin >> tc;

    while(tc--)
    {
        for(int i = 0 ; i <= 30000; i++)
        {
            vt[i].clear();
            wt[i].clear();
        }

        int n;
        cin >> n;

        for(int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vt[u].push_back(v);
            vt[v].push_back(u);
            wt[u].push_back(w);
            wt[v].push_back(w);
        }
        int f1 = bfs(0);
        int f2 = bfs(f1);

        cout << "Case " << cs++ << ": " << cost[f2] << endl;
    }

    return 0;
}
