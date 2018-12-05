#include<stdio.h>

int main()
{
    int i, t, j;
    long long int arr[10000], n;
    scanf("%d", &t);
    for(i = 1; i <= t; i++)
    {
        for(j = 0; j < 6; j++)
        {
            scanf("%lld", &arr[j]);
        }
        scanf("%lld", &n);
        for(j = 6; j <= n; j++)
        {
            arr[j] = (arr[j-1] + arr[j-2] + arr[j-3] + arr[j-4] + arr[j-5] + arr[j-6]) % 10000007;
        }
        printf("Case %d: %lld\n", i, arr[n] % 10000007);
    }
    return 0;
}
