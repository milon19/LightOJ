#include<stdio.h>

int main()
{
    int i, t, num, m;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d", &num);
        m = num; int rev = 0;
        while(num != 0)
        {
            rev = rev * 10;
            rev = rev + (num % 10);
            num /= 10;
        }
        if(m == rev)
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);
    }
    return 0;
}
