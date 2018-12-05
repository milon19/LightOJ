#include<stdio.h>

int main()
{
    int i, t, n;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        int mod = 0, ones = 0;
        scanf("%d", &n);
        while(n != 0)
        {
            mod = n % 2;
            n/=2;
            if(mod == 1)
                ones++;
        }
        if(ones % 2 == 0)
            printf("Case %d: even\n", i);
        else
            printf("Case %d: odd\n", i);
    }
    return 0;
}
