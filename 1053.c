#include<stdio.h>

int main()
{
    int i, t, a, b, c, temp, x, y, z;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a<b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        if(a<c)
        {
            temp = a;
            a = c;
            c = temp;
        }
        if(b<c)
        {
            temp = b;
            b = c;
            c = temp;
        }
        x = a * a;
        y = b * b;
        z = c * c;
        if(x == y + z)
            printf("Case %d: yes\n", i);
        else
            printf("Case %d: no\n", i);
    }
    return 0;
}
