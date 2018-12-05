#include<stdio.h>
#include<math.h>
int main()
{
    int n, a, b, i;
    double num=0;
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d %d", &a, &b);
        num = ((((b-a)+1)/9.00)*6.00);
        printf("Case %d: %d\n", i, (int)num);
        num=0;
    }

    return 0;
}
