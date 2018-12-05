#include<stdio.h>

int main()
{
    int i, test;
    long long int n, c, res;
    double t;
    scanf("%d", &test);

    for(i = 1; i <= test; i++)
    {
        scanf("%lld %lld", &n, &c);
        if(n == 0 || c == 0)
        {
            printf("Case %d: 0\n", i);
            continue;
        }

        t = c*1.0/(2*n*1.0);
        if(t <= 0) res = 0;
        else
        {   if((int)t + 0.5 >= t) res = (int)t;
            else res = (int)t+1;
        }
        printf("Case %d: %lld\n", i, res);
    }

    return 0;
}
