#include <stdio.h>

int main()
{
    long long int m, n, sum, t, i;
    scanf("%lld", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%lld %lld", &n, &m);
        sum = m * (n/2);
        printf("Case %lld: %lld\n", i, sum);
    }
    return 0;
}
