#include<stdio.h>

int main()
{
    int i, t;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        int n, a;
        char str[10];

        scanf("%d %s", &n, &str);

        if(strcmp(str, "Alice") == 0)
        {
            a = n % 3;
            if(a == 0 || a == 2)
                printf("Case %d: Alice\n", i);
            else
                printf("Case %d: Bob\n", i);
        }
        else if(strcmp(str, "Bob") == 0)
        {
            if(n % 3 == 0)
                printf("Case %d: Alice\n", i);
            else
                printf("Case %d: Bob\n", i);
        }
    }

    return 0;
}
