#include<stdio.h>
#include<math.h>

int makebinary(int x)
{
    int res = 0, i;

    for(i = 7; i >= 0; i--)
    {
        res += ((x >> i) & 1);
        res*=10;
    }
    return res/10;
}

int main()
{
    int i, t, k;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        int a1, a2, a3, a4, b1, b2, b3, b4;
        int binary1, binary2, binary3, binary4;
        scanf("%d.%d.%d.%d", &a1, &a2, &a3, &a4);
        scanf("%d.%d.%d.%d", &b1, &b2, &b3, &b4);

        binary1 = makebinary(a1);
        binary2 = makebinary(a2);
        binary3 = makebinary(a3);
        binary4 = makebinary(a4);
        //printf("%d\n", binary1);
        //printf("%d\n", binary2);
        //printf("%d\n", binary3);
        //printf("%d\n", binary4);
        if(b1 == binary1 && b2 == binary2 && b3 == binary3 && b4 == binary4)
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);

    }


    return 0;
}
