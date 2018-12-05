#include<stdio.h>
#include<math.h>

int main()
{
    int i, t, num, base, j;
    double save[1000001];
    for(j = 1; j < 1000001; j++)
    {
        save[j] = log10(j) + save[j-1];

    }
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d %d", &num, &base);
        double res;
        res = (save[num]/log10(base)) + 1;

        printf("Case %d: %d\n", i, (int)res);
    }

    return 0;
}
