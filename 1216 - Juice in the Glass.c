#include<stdio.h>
#include<math.h>
#define PI acos(-1)

int main()
{
    int i, t;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        int r1, r2, h, p;
        scanf("%d %d %d %d", &r1, &r2, &h, &p);
        double r, vol, hh;

        r = (p*1.0/h*1.0)*((r1-r2)*1.0) + r2*1.0;
        hh = ((r*r) + (r2*r2*1.0) + (r*r2*1.0));
        vol =(PI*p*hh*1.0)/3.0;
        printf("Case %d: %lf\n", i, vol);
    }

    return 0;
}
