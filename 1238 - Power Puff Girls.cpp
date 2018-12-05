#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

char grid[21][21];
int visited[21][21], level[21][21];

int main()
{
    int tc, cs =1;
    cin >> tc;
    while(tc--)
    {
        vector< pair<int, int> > vt;
        int m, n, dx, dy;
        cin >> m >> n;


        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == 'a' || grid[i][j] == 'b' || grid[i][j] == 'c')
                    vt.push_back(make_pair(i, j));
                if(grid[i][j] == 'h')
                {
                    dx = i;
                    dy = j;
                }
                if(grid[i][j] == '#' || grid[i][j] == 'm')
                    visited[i][j] = 1;
                else
                    visited[i][j] = 0;
            }
        }
        queue < pair <int, int> > Q;
        int xx[] = {0, 1, -1, 0};
        int yy[] = {1, 0, 0, -1};
        int ln = vt.size(), ans = -1;

        for(int i = 0; i < ln; i++)
        {
            for(int k = 0; k < 21; k++)
                for(int j = 0; j < 21; j++)
                    level[k][j] = 0;
            for(int t = 0; t < m; t++)
            {
                for(int y = 0; y < n; y++)
                {


                    if(grid[t][y] == '.')
                        visited[t][y] = 0;
                    else
                        visited[t][y] = 1;
                    if(grid[t][y] == 'a' || grid[t][y] == 'b' || grid[t][y] == 'c' || grid[t][y] == 'h')
                        visited[t][y] = 0;

                }
            }
            Q.push(vt[i]);
            int x, y;
            x = vt[i].first;
            y = vt[i].second;
            level[x][y] = 0;

            while(!Q.empty())
            {
                int ux, uy, vx, vy;
                ux = Q.front().first;
                uy = Q.front().second;
                //cout << i << " " << ux << " " << uy << endl;
                Q.pop();

                for(int j = 0; j < 4; j++)
                {
                    int vx = ux + xx[j];
                    int vy = uy + yy[j];


                    if((vx >=0 && vx < m) && (vy >= 0 && vy < n))
                    {

                        if(visited[vx][vy] == 0)
                        {
                            Q.push(make_pair(vx, vy));
                            visited[vx][vy] = 1;
                            level[vx][vy] = level[ux][uy]+1;
                        }
                    }
                }

            }
            ans = max(ans, level[dx][dy]);

        }
        cout << "Case " << cs++ << ": " << ans << endl;

    }



    return 0;
}
