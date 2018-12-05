#include<stdio.h>
#include<math.h>

int main()
{
    int i, t;
    double w, l, x, v, b, c;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%lf %lf", &l, &w);
        b = 4 * (l + w);
        c = l * w;
        x = (b - sqrt((b*b)-4*12*c))/24;
        v = x * (l - (2*x)) * (w - (2*x));
        printf("Case %d: %lf\n", i, v);
    }

    return 0;
}
