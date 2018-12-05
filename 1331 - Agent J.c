#include<stdio.h>
#include<math.h>

int main()
{
    int i, t;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        double r1, r2, r3, a, b, c, s, AreaTri, A, B, C, AreaR1, AreaR2, AreaR3, AreaC;
        scanf("%lf %lf %lf", &r1, &r2, &r3);
        a = r2 + r3; b = r1 + r3; c = r1 + r2;
        s = (a+b+c)/2;
        AreaTri = sqrt(s*(s-a)*(s-b)*(s-c));

        A = acos((c*c+b*b-a*a)/(2*b*c));
        B = acos((c*c+a*a-b*b)/(2*a*c));
        C = acos((a*a+b*b-c*c)/(2*a*b));

        //printf("A = %lf, B = %lf, C = %lf\n", A, B, C);

        AreaR3 = A*r1*r1*.5;
        AreaR2 = B*r2*r2*.5;
        AreaR1 = C*r3*r3*.5;
        AreaC = AreaR1 + AreaR2 + AreaR3;
        printf("Case %d: %lf\n", i, AreaTri - AreaC);
    }

    return 0;
}

