#include<stdio.h>
#include<math.h>

int main()
{
    long long int i, t, num, binary[32], res, a;
    scanf("%lld", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%lld", &num);
        int j = 0, k, temp, count = 0, m;
        while(num != 0)
        {
            binary[j] = num % 2;
            num/=2;
            j++;
        }
        if(binary[j-1] == 1)
            binary[j] = 0;
        for(k = 0; k <= j; k++)
        {

            if(binary[k] == 1 && binary[k+1] == 0)
            {
                temp = binary[k];
                binary[k] = binary[k+1];
                binary[k+1] = temp;
                count = k;
                break;
            }

        }
        for(k = 0; k < count; k++)
        {
            for(m = 0; m < count; m++)
            {
                if(binary[m] < binary[m+1])
                {
                    temp = binary[m];
                    binary[m] = binary[m+1];
                    binary[m+1] = temp;
                }
            }
        }
        res = 0;
        for(k = 0; k <= j; k++)
        {
            a = pow(2,k);
            res = res + (binary[k]*a);

        }
        printf("Case %lld: %lld\n", i, res);

    }

    return 0;
}
