#include<iostream>
#include<cstdio>
#define N 1000001
#define M 1000003


using namespace std;
long long pre[N];

long long mood(long long b, long long p, long long m)
{
    if(p == 0)
        return 1;
    if(p%2 == 0)
    {
        long long tmp = mood(b, p/2, m);
        return (tmp*tmp)%m;
    }
    else
    {
        long long tmp = mood(b, p-1, m);
        return ((b%m)*tmp)%m;
    }
}
int main()
{
    pre[0] = 1;
    for(long long i = 1; i < N; i++)
        pre[i] = (pre[i-1]*i)%M;

    int tc, cs = 1;
    scanf("%d", &tc);

    while(tc--)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        if(k == 1)
        {
            printf("Case %d: %lld\n", cs++, n);
            continue;
        }
        long long a = pre[n];
        long long b = pre[k]*pre[n-k];
        long long x = mood(b, M-2, M);

        printf("Case %d: %lld\n", cs++, (a*x)%M);
    }

    return 0;
}
