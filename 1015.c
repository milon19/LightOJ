#include<stdio.h>

int main()
{
    int i, t, j, n, a;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        int sum = 0;
        scanf("%d", &n);
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a);
            if(a>0)
                sum += a;
        }
        printf("Case %d: %d\n", i, sum);
    }
    return 0;
}
