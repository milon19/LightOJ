#include<stdio.h>

int main()
{
    int i, t, j;
    long long a, b, n, count;

    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        count = 0;
        scanf("%lld %lld", &a, &b);
        long long dif = b - a;
        while(a%3 == 2 || a%3 == 0)
            a++;
        while(b%3 == 2 || b%3 == 0)
            b--;
        //printf("%lld %lld\n", a, b);
        long long p1 = a/3, p2 = b/3;
        //printf("%lld %lld\n", p1, p2);
        if(a == b)
            printf("Case %d: %lld\n", i, dif);
        else
        {
            long long p = (p2-p1);
            printf("Case %d: %lld\n", i, dif - p);

        }

    }

    return 0;
}
