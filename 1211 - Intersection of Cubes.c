#include<stdio.h>

int main()
{
    int i, t, j;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        int n;
        scanf("%d", &n);
        int x1[n], y1[n], z1[n], x2[n], y2[n], z2[n], xi, yi, zi, xj, yj, zj, x, y, z;

        for(j = 0; j < n; j++)
            scanf("%d %d %d %d %d %d", &x1[j], &y1[j], &z1[j], &x2[j], &y2[j], &z2[j]);

        xi = x1[0];yi = y1[0]; zi = z1[0];xj = x2[0]; yj = y2[0];zj = z2[0];
        //printf("Out of loop: %d %d %d %d %d %d\n", xi, yi, zi, xj, yj, zj);

        for(j = 1; j < n ; j++)
        {
            if(xi < x1[j]) xi = x1[j];
            if(yi < y1[j]) yi = y1[j];
            if(zi < z1[j]) zi = z1[j];
            if(xj > x2[j]) xj = x2[j];
            if(yj > y2[j]) yj = y2[j];
            if(zj > z2[j]) zj = z2[j];
            //printf("In loop: %d %d %d %d %d %d\n", xi, yi, zi, xj, yj, zj);
        }
        //printf("Out of loop: %d %d %d %d %d %d\n", xi, yi, zi, xj, yj, zj);
        x = xj - xi; y = yj - yi; z = zj - zi;
        int vol = x*y*z;
        if(vol<0) vol = 0;
        printf("Case %d: %d\n", i, vol);
    }

    return 0;
}
