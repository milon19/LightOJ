#include<stdio.h>
#include<math.h>

int main()
{
    int i, t, n;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d", &n);
        int arr[n], j, lies = 0;
        double f;

        for(j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
        }
        f = arr[0] - 2;
        lies = ceil(f/5);
        for(j = 1; j < n; j++)
        {
            f = arr[j] - arr[j-1];
            lies += ceil(f/5);
        }
        printf("Case %d: %d\n", i, lies);
    }
    return 0;
}
