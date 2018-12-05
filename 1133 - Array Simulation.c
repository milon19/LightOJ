#include<stdio.h>

int main()
{
    int i, t;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        int arr[n], j, k, d, kk, y, z, h, temp;

        for(j = 0; j < n; j++)
            scanf("%d", &arr[j]);
        /*
        printf("print array:\n");
        for(j = 0; j < n; j++)
        {
            printf("%d ", arr[j]);
        }
        printf("\n");
        */
        char ch[1];
        for(k = 1; k <= m; k++)
        {
            scanf(" %c", &ch[0]);

            if(ch[0] == 'S')
            {
                scanf("%d", &d);
                for(j = 0; j < n; j++)
                    arr[j]+=d;
                continue;

            }
            if(ch[0] == 'M')
            {
                scanf("%d", &d);
                for(j = 0; j < n; j++)
                    arr[j]*=d;
                continue;
            }
            if(ch[0] == 'D')
            {
                scanf("%d", &kk);
                for(j = 0; j < n; j++)
                    arr[j]/=kk;
                continue;
            }
            if(ch[0] == 'R')
            {
                for(j=0, h=n-1; h>=j; j++, h--)
                {
                    temp = arr[j];
                    arr[j] = arr[h];
                    arr[h]= temp;
                }
                /*
                printf("print array after reverse:\n");
                for(j = 0; j < n; j++)
                {
                    printf("%d ", arr[j]);
                }
                printf("\n");
                */
                continue;
            }
            if(ch[0] == 'P')
            {
                scanf("%d %d", &y, &z);
                int temp;
                temp = arr[y];
                arr[y] = arr[z];
                arr[z] = temp;

                continue;
            }
        }
        printf("Case %d:\n", i);
        for(j = 0; j < n; j++)
        {

            printf("%d", arr[j]);
            if(j < n-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
