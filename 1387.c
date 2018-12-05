#include<stdio.h>

int main()
{
    int j, t, m;
    char ch[6];
    scanf("%d", &t);

    int sum = 0;
    for(j = 1; j <= t; j++)
    {
        scanf("%s", &ch);
        if(ch[0] == 'd')
        {
            scanf("%d", &m);
            sum += m;
        }
        else
            printf("%d\n", sum);
    }
    return 0;
}
