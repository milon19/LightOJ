#include<stdio.h>

int main()
{
    int i, t, j, k;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        char str[100000];
        long long int b, rem = 0, div = 0;
        scanf("%s %lld", &str, &b);
        j = 0;
        if(str[0] == '-') j = 1;

        for(k = j; str[k] != '\0'; k++)
        {
            div = rem*10 + str[k] - 48;
            rem = div%b;
            //printf("div = %lld rem = %lld\n", div, rem);

        }
        if(rem == 0)
            printf("Case %d: divisible\n", i);
        else
            printf("Case %d: not divisible\n", i);

    }

    return 0;
}
