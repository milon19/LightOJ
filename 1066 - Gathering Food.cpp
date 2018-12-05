#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int xx[] = {0, 1, -1, 0};
int yy[] = {1, 0, 0, -1};
char grid[12][12];
int visitd[12][12], color[12][12];

int bfs(pair < int, int> sc, pair < int, int> ds, int n, int d)
{
        int level[12][12];
        for(int i = 0; i < 12; i++)
            for(int j = 0; j < 12; j++)
                level[i][j] = 0;
        queue< pair<int, int> > Q;
        Q.push(sc);
        color[sc.first][sc.second] = 1;
        while(!Q.empty())
        {
            int ux = Q.front().first;
            int uy = Q.front().second;
//            cout << ux << "uu" << uy << endl;
            Q.pop();
            for(int i = 0; i < 4; i++)
            {
                int vx = ux+xx[i];
                int vy = uy+yy[i];
                if((vx >= 0 && vx < n) && (vy >= 0 && vy < n))
                {
                    if(visitd[vx][vy] != -1 && color[vx][vy] == 0 && visitd[vx][vy] <= d)
                    {
//                        cout << vx << "vv" << vy << endl;
                        color[vx][vy] = 1;
                        level[vx][vy] = level[ux][uy] + 1;
                        Q.push(make_pair(vx, vy));
                    }
                }
            }

        }
//        cout << level[ds.first][ds.second] << endl;
        return level[ds.first][ds.second];
}

int main()
{
    int tc, cs = 1;
    cin >> tc;
    while(tc--)
    {
        int n, sx, sy, maxx = -1, al = 0;
        cin.ignore();
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == '#')
                    visitd[i][j] = -1;
                else
                    visitd[i][j] = 0;
                if(grid[i][j] >= 'A' && grid[i][j] <= 'Z')
                {
                    al++;
                    visitd[i][j] = grid[i][j] - 'A' + 1;
                    maxx = max(visitd[i][j], maxx);
                }

            }
        }
        if(al == 1)
        {
            cout << "Case " << cs++ << ": 0" << endl;
            continue;
        }
        int s = 1, fl = 1;
        int cost = 0;
        while(1)
        {
//            cout << s << " " << s+1 << endl;
            for(int i = 0; i < 12; i++)
                for(int j = 0; j < 12; j++)
                    color[i][j] = 0;
            pair <int, int> sc, ds;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(visitd[i][j] == s)
                        sc = make_pair(i, j);
                    if(visitd[i][j] == s+1)
                        ds = make_pair(i, j);
                }
            }
            int a = bfs(sc, ds, n, s+1);
            if(a == 0)
            {
                fl = 0;
                break;
            }
            cost+=a;
            if(s+1 == maxx)
                break;
            s++;
        }
        if(fl == 0)
            cout << "Case " << cs++ << ": Impossible" << endl;
        else
            cout << "Case " << cs++ << ": " << cost << endl;

    }

    return 0;
}
