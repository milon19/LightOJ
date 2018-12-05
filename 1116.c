#include<stdio.h>

int main()
{
    long long int i, t, even = 0, odd, n, j, test = 0;
    scanf("%lld", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%lld", &n);
        if(n % 2 != 0)
            printf("Case %lld: Impossible\n", i);
        else
        {
            for(j = 2; j <= n/2; j*=2)
            {
                if(n % j == 0)
                   even = j;
            }
            odd = n/even;
            printf("Case %lld: %lld %lld\n", i, odd, even);
        }

    }
    return 0;
}
