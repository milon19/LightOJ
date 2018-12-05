#include<iostream>
#include<cstdio>

using namespace std;

int FindZeros(int n)
{
    int cnt = 0;
    for(int i = 5; n/i >= 1; i*=5)
        cnt += n/i;
    return cnt;
}

int searchN(int l, int h, int n)
{
    int mid;
    while(l <= h)
    {
        mid = (l+h)/2.0;
        int x = FindZeros(mid);
        //printf("l = %d h = %d mid = %d x = %d\n", l, h, mid, x);
        if(x == n)
            h = mid - 1;
        else if(x < n)
            l = mid+1;
        else
            h = mid-1;
    }
    return l;
}

int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        int q;
        scanf("%d", &q);
        int low = 5, high = 5*q;
        int N = searchN(low, high, q);
        if(FindZeros(N) == q)
            printf("Case %d: %d\n", cs++, N);
        else
            printf("Case %d: impossible\n", cs++);
    }


    return 0;
}
