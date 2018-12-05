#include<iostream>
#include<cstdio>


using namespace std;

int main()
{
    long long f[22];
    f[0] = 1;
    for(int i = 1; i <= 22; i++)
        f[i] = f[i-1]*i;
    int t, cs = 1, d[20];

    cin >> t;
    while(t--)
    {
        int st, x = 0, flag = 0;
        long long num;
        cin >> num;

        for(int i = 0; i < 20; i++)
            d[i] = 0;

        for(int i = 1; i <= 20; i++)
        {
            if(f[i] >= num)
            {
                st = i;
                break;
            }
        }

        for(int i = st; i >= 0; i--)
        {
            //cout << "num = " << num << endl;
            if(f[i] <= num)
            {
                num = num - f[i];
                d[x++] = i;
            }
            //cout << "num = " << num << endl;
            if(num == 0)
            {
                flag = 1;
                break;
            }
            if(num < 0)
            {
                flag = 0;
                break;
            }

        }
        cout << "Case " << cs++ << ": ";
        if(flag)
        {


            for(int i = x-1; i >= 0; i--)
            {

                cout << d[i] << "!";

                if(i > 0)
                    cout << "+";
            }
            cout << endl;
        }
        else
            cout << "impossible" << endl;



    }

    return 0;
}
