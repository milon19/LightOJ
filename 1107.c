#include<stdio.h>

int main()
{
    int i, t, x1, y1, x2, y2, x, y, cows, j;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        scanf("%d", &cows);
        for(j = 1; j <= cows; j++)
        {
            scanf("%d %d", &x, &y);
            if(j == 1)
                printf("Case %d:\n", i);
            if(( x > x1 && x < x2) && (y > y1 && y < y2))
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
