#include<stdio.h>

int main()
{
    int i, t, m, n, totalcase, x;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d %d", &m, &n);
        if(m == 1 || n == 1)
        {
            if(m>n)
                totalcase = m;
            else
                totalcase = n;
        }
        else if(m == 2)
        {
                totalcase = (n/4) * 4;
                if(n % 4 == 3)
                    totalcase += 4;
                else
                    totalcase += (n%4) * 2;
        }
        else if(n == 2)
        {
                totalcase = (m/4) * 4;
                if(m%4 == 3)
                    totalcase += 4;
                else
                    totalcase += (m%4) * 2;
        }
        else
        {
            x = m*n;
            if(m % 2 == 0 || n % 2 == 0)
                totalcase = x/2;
            else
                totalcase = (x/2) + 1;
        }
        printf("Case %d: %d\n", i, totalcase);
    }

    return 0;
}
