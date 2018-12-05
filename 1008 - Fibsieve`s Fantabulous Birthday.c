#include<stdio.h>
#include<math.h>

int main()
{
    int i, t;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        long long int n, m, high, low, mid, x, y;
        scanf("%lld", &n);
        //printf("n = %lld\n", n);
        m = ceil(sqrt(n));
       // printf("value of m: %lld\n", m);
        high = m*m;
       // printf("value of high: %lld\n", high);
        low = high - (2*m) + 2;
        //printf("value of low: %lld\n", low);
        mid = low + m - 1;
        //printf("value of mid: %lld\n", mid);
        if(n == mid)
        {
            x = m;
            y = m;
        }
        else if(m % 2 != 0)
        {
            if(n > mid)
            {
                y = m;
                x = high - n + 1;
            }
            else
            {
                x = m;
                y = n - low + 1;
            }
        }
        else
        {
            if(n < mid)
            {
                y = m;
                x = n - low + 1;
            }
            else
            {
                x = m;
                y = high - n + 1;
            }
        }
        printf("Case %d: %lld %lld\n", i, x, y);
    }

    return 0;
}
