#include<stdio.h>
#include<math.h>
int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        double ab, ac, bc, ad, ratio;
        scanf("%lf %lf %lf %lf", &ab, &ac, &bc, &ratio);
        //printf("%  lf\n", ratio);
        ratio = ratio/(ratio+1);
        //printf("%  lf\n", ratio);
        ad = ab * sqrt(ratio);
        printf("Case %d: %lf\n", i, ad);
    }
    return 0;
}
