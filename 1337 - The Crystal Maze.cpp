#include<iostream>
#include<cstdio>
#include<queue>
#define MX 500

using namespace std;

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};
char grid[MX+1][MX+1], visited[MX+1][MX+1];
int ans[MX+1][MX+1];

int bfs(int sx, int sy, int m, int n)
{
    queue< pair<int, int> > Q;
    int cnt = 0;
    Q.push(make_pair(sx, sy));
    visited[sx][sy] = 1;
    cnt = 0;
    if(grid[sx][sy] == 'C')
        cnt = 1;
    while(!Q.empty())
    {
        int ux = Q.front().first;
        int uy = Q.front().second;
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            int vx = ux+dx[i];
            int vy = uy+dy[i];
            if((vx >= 1 && vx <= m) && (vy >= 1 && vy <= n))
            {
                if(grid[vx][vy] != '#' && visited[vx][vy] == 0)
                {
                    visited[vx][vy] = 1;
                    if(grid[vx][vy] == 'C')
                        cnt++;
                    Q.push(make_pair(vx, vy));
                }
            }
        }
    }
    return cnt;
}

int main()
{

    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        for(int i = 1; i <= MX; i++)
            for(int j = 1; j <= MX; j++)
                ans[i][j] = -1;

        int m, n, q;
        scanf("%d %d %d", &m, &n, &q);
        getchar();
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
                scanf("%c", &grid[i][j]);
            getchar();
        }


        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                visited[i][j] = 0;
        int cnt = 0;
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(grid[i][j] == '#')
                    ans[i][j] = 0;
                else
                {
                    if(visited[i][j] == 0 )
                    {
                        cnt = bfs(i, j, m, n);
                        ans[i][j] = cnt;
                    }
                    else
                    {
                        for(int u = 0; u < 4; u++)
                        {
                            int vx = i+dx[u], vy = j+dy[u];
                            if((vx >= 1 && vx <= m) && (vy >= 1 && vy <= n) && grid[vx][vy] != '#')
                            {
                                cnt = max(cnt, ans[vx][vy]);
                            }
                        }
                        ans[i][j] = cnt;
                    }
                }
            }
        }
        printf("Case %d:\n", cs++);
        for(int i = 1; i <= q; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);

            printf("%d\n", ans[x][y]);
        }

    }

    return 0;
}
