#include<stdio.h>
#include<math.h>
#define PI acos(-1)
int main()
{
    int i, t;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        double R, n, r, angle, x;
        scanf("%lf %lf", &R, &n);
        //printf("R : %lf, n : %lf\n", R, n);
        angle = 180/n;
        //printf("angle : %lf\n", angle);
        x = sin((angle*PI)/180);
        //printf("x : %lf\n", x);
        r = (R*x)/(1+x);
        printf("Case %d: %lf\n", i, r);
    }
    return 0;
}
