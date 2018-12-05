#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

vector <int> vt[20001];
vector < pair <int, int> > vp;
map<int, int> mp;
map<int, int> :: iterator it;

int color[20005];

bool cmp(pair<int, int> f, pair <int, int> s)
{
    return f.first > s.first;
}

int bfs(int src)
{
    queue <int> Q;
    Q.push(src);
    int one = 0, zero = 0;
    color[src] = 1;
    one++;
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        int ln = vt[u].size();
        for(int i = 0; i < ln; i++)
        {
            int v = vt[u][i];

            if(color[v] == 0)
            {
                Q.push(v);
                if(color[u] == 1)
                {
                    color[v] = 2;
                    zero++;
                }
                else
                {
                    color[v] = 1;
                    one++;
                }
            }
        }

    }
    return max(one, zero);
}

int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);

    while(tc--)
    {

        int n;
        scanf("%d", &n);

        for(int i = 0; i < 20001; i++)
            vt[i].clear();

        for(int i = 1; i <= n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            vt[u].push_back(v);
            vt[v].push_back(u);
            mp[u]++;
            mp[v]++;
        }

        for(it = mp.begin(); it != mp.end(); it++)
        {
            int f = (*it).second;
            int num = (*it).first;
            vp.push_back(make_pair(f, num));
        }
        sort(vp.begin(), vp.end(), cmp);
        int sz = vp.size(), ans = 0;
        for(int i = 0; i < 20005; i++)
            color[i] = 0;

        for(int i = 0; i < sz; i++)
        {
            int val = vp[i].second;
            if(color[val] == 0 && !vt[val].empty())
            {
                int a = bfs(val);
                ans += a;
            }

        }
        printf("Case %d: %d\n", cs++, ans);

    }

    return 0;
}
