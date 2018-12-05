#include<stdio.h>

int main()
{
    int i, t, n, P, Q;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d %d %d", &n, &P, &Q);
        int arr[n], sum = 0, j, egg = 0;

        for(j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
            sum += arr[j];
            if(Q >= sum && P > egg)
                egg++;
        }
        printf("Case %d: %d\n", i, egg);
    }

    return 0;
}
