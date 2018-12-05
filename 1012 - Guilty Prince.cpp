#include<iostream>

using namespace std;

char grid[21][21];
int visited[21][21], ss = 1;

void dfs(int i, int j, int m, int n)
{

    if(i < 0 || j < 0 || i >= m || j >= n)
        return;
    if(visited[i][j] != 0)
        return;
    visited[i][j] = 2;
    dfs(i, j+1, m, n);
    dfs(i, j-1, m, n);
    dfs(i+1, j, m, n);
    dfs(i-1, j, m, n);

}
int main()
{
    int tc, cs = 1;

    cin >> tc;
    while(tc--)
    {
        int m, n, sx, sy;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
                if(grid[i][j] == '#')
                    visited[i][j] = 1;
                else
                    visited[i][j] = 0;
                if(grid[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
            }
        }

        dfs(sx, sy, m, n);

        int cnt = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(visited[i][j] == 2)
                    cnt++;
            }
        }

        cout << "Case " << cs++ << ": " << cnt << endl;
    }


    return 0;
}
