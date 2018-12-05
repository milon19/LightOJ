#include<iostream>
#include<vector>
#include<queue>

using namespace std;
 vector < vector <int> > vt;
int main()
{
    int tc, cs = 1;
    cin >> tc;

    while(tc--)
    {
        vt.clear();
        int k, n, m;
        cin >> k >> n >> m;
        int arr[k];
        vt.resize(n+1);

        for(int i = 0; i < k; i++)
            cin >> arr[i];

        for(int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            vt[u].push_back(v);
        }

        int color[n+1], visited[n+1];
        for(int i = 0; i <= n; i++)
            color[i] = 0;
        queue <int> Q;

        for(int i = 0; i < k; i++)
        {
            for(int i = 0; i <= n; i++)
                visited[i] = 0;
            Q.push(arr[i]);
            visited[arr[i]] = 1;
            color[arr[i]]++;
            while(!Q.empty())
            {
                int uu = Q.front();
                int ln = vt[uu].size();
                //cout << uu << endl;
                for(int i = 0; i < ln; i++)
                {
                    int vv = vt[uu][i];
                    if(visited[vv] == 0)
                    {
                        color[vv]++;
                        Q.push(vv);
                        visited[vv] = 1;
                    }
                }
                Q.pop();

            }

        }
        int cnt = 0;
        for(int i = 0; i <= n; i++)
        {
            //cout << color[i] << endl;
            if(color[i] == k)
                cnt++;
        }
        cout << "Case " << cs++ << ": " << cnt << endl;
    }

    return 0;
}
