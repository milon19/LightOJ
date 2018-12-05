#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;
vector <int> vessel;

int searchNC(int NoV, int curSz)
{
    int NC = 1, x = curSz;
    for(int i = 0; i < NoV; i++)
    {
        if(x <= 0 || x < vessel[i])
        {
            NC++;
            x = curSz;
        }

        x -= vessel[i];

        //printf("\t x = %d NC = %d ves = %d\n", x, NC, vessel[i]);
    }

    return NC;
}

int getSizeC(int low, int high, int n, int m)
{
    int mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        int sz = searchNC(n, mid);
        //printf("l = %d h = %d mid = %d x = %d\n", low, high, mid, sz);
        if(sz == m)
            high = mid - 1;
        else if(sz > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}


int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
    while()
    {
        vessel.clear();
        int n, m, low = INT_MIN, high = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            int tm;
            scanf("%d", &tm);
            vessel.push_back(tm);
            low = max(low, tm);
            high += tm;
        }
        int ans = getSizeC(low, high, n, m);
        printf("Case %d: %d\n", cs++, ans);
    }

    return 0;
}
