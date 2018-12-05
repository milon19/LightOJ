#include<stdio.h>
#include<math.h>
int main()
{
    int i, t, ax, ay, bx, by, cx, cy, dx, dy, area, x;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
        dx = (ax-bx) + cx;
        dy = (ay-by) + cy;
        x = ((ax*by) + (bx*cy) + (cx*dy) + (dx*ay)) - ((ay*bx) + (by*cx) + (cy*dx) + (dy*ax));
        area = .5*fabs(x);
        printf("Case %d: %d %d %d\n", i, dx, dy, area);
    }
    return 0;
}
