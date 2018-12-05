#include<stdio.h>
#include<math.h>

long long fact[21];

int main()
{
    int i, j, k;
    fact[0] = 1;
    for(i = 1; i <= 20; i++)
        fact[i] = i*fact[i-1];
    int t, num, ans[20], count, flag = 0, temp;
    double loop;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d", &num);
        loop = sqrt(num);

        while(1)
        {
            k = 0, j = 1, flag = 0;
            if(num == 0)
            {

                flag = 1;
                break;
            }
            else
            {
                for(k = 0; k <= ceil(loop); k++)
                {
                    if(num = fact[k])
                    {
                        ans[k++] = k;
                        num = 0;
                        break;
                    }
                    else
                    {
                        num = num - count;
                        ans[k++] = count;
                        count++;
                    }
                }
                flag = 0;
            }

        }

        if(flag == 1)
            printf("Impossible\n");
        //else
        //{
            for(i = 0; i < k; i++)
                printf("%d\n", ans[i]);
        //}

    }




    /*for(i = 1; i <= 20; i++)
        printf("%d %lld\n",i, fact[i]);*/

    return 0;
}
