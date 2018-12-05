#include<stdio.h>
#include<math.h>

int main()
{
    int i, t;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        double a, b, c, d, h, ac, db, xx, area;
        scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
        ac = pow(a-c,2);
        db = pow(d,2) - pow(b,2);
        xx = (ac + db) / (2*(a-c));
        h = sqrt(pow(d,2) - pow(xx, 2));
        area = .5*(a+c)*h;
        printf("Case %d: %lf\n", i, area);
    }

    return 0;
}
