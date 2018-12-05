#include<stdio.h>
#define pi 2*acos()
int main()
{
    int i, t;
    double r, a, b;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%lf", &r);
        b = 4*r*r;
        a = pi*r*r;
        printf("Case %d: %.2lf\n", i, b-a);
    }
    return 0;
}
