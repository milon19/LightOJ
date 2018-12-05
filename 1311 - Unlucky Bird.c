#include<stdio.h>

int main()
{
    int i, t;
    double v1, v2, v3, a1, a2, s1, s2, s3, s, t1, t2, dbird, temp;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
        s1 = (v1*v1)/(2*a1);
        s2 = (v2*v2)/(2*a2);
        s = s1 + s2;
        t1 = v1/a1;
        t2 = v2/a2;
        if(t2 > t1)
        {
            temp = t2; t2 = t1; t1 = temp;
        }
        dbird = v3*t1;
        printf("Case %d: %lf %lf\n", i, s, dbird);
    }
    return 0;
}
