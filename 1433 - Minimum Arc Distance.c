#include<stdio.h>
#include<math.h>

int main()
{
    int i, t, h, k, x1, y1, x2, y2;
    double r, d, angle, x, y;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d %d %d %d %d %d", &h, &k, &x1, &y1, &x2, &y2);
        d = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
        r = sqrt(pow(h-x1,2) + pow(k-y1,2));
        angle = acos(1 - 0.5*pow((d/r),2));
        printf("Case %d: %lf\n", i, angle*r);
    }
    return 0;
}
