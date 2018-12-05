#include<stdio.h>
#include<math.h>

int main()
{
    int i, t;
    long long int r1, c1, r2, c2, add1, add2, sub1, sub2, modr1, modc1, modr2, modc2;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%lld %lld %lld %lld", &r1, &c1, &r2, &c2);
        add1 = r1 + c1; add2 = r2 + c2; sub1 = r1-c1; sub2 = r2-c2;
        modr1 = r1 % 2;
        modc1 = c1 % 2;
        modr2 = r2 % 2;
        modc2 = c2 % 2;

        if((r1 == c1) && (r2 == c2))
            printf("Case %d: %d\n", i, 1);
         else if((add1 == add2) || (sub1 == sub2))
            printf("Case %d: %d\n", i, 1);
        else if((modr1 == 1 && modc1 == 1) || (modr1 == 0 && modc1 == 0))
        {
            if((modr2 == 1 && modc2 == 1) || (modr2 == 0 && modc2 == 0))
                printf("Case %d: %d\n", i, 2);
            else
                printf("Case %d: impossible\n", i);
        }
        else if((r1+c1+r2+c2) % 2 == 0)
            printf("Case %d: %d\n", i, 2);
        else
            printf("Case %d: impossible\n", i);
    }
    return 0;
}
