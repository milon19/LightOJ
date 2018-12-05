#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

#define ll long long

using namespace std;

ll X[1<<16], Y[1<<16];

void calcSubset(ll a[], ll x[], int st, int sz)
{

    for(int i = 0; i < (1<<sz); i++)
    {

        ll sum = 0;
        for(int j = 0; j < sz; j++)
        {

            if(i & (1<<j))
            {
//                cout << a[j+st] << " ";
                sum+=a[j+st];
            }

        }
//        cout << "sum = " << sum;
//        cout << endl;
        x[i] = sum;
    }
}

ll vaildCombination(ll a[], int n, ll S)
{
    calcSubset(a, X, 0, n/2);
    calcSubset(a, Y, n/2, n-n/2);

    int X_sz = 1 << n/2;
    int Y_sz = 1 << (n-n/2);

    int cnt = 0;
    sort(Y, Y+Y_sz);
    for(int i = 0; i < X_sz; i++)
    {
        if(X[i] <= S)
        {
            cnt++;
            int p = upper_bound(Y, Y+Y_sz, S-X[i]) - Y;

            if(p == Y_sz || Y[p] != S-X[i])
                p--;
//            cout << X[i] << " " << S-X[i] << " " << p << endl;
            if(X[i] + Y[p] <= S)
                cnt+=p;
        }
    }

    return cnt;
}

int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        int n;
        ll k;
        scanf("%d %lld", &n, &k);
        ll arr[n];
        for(int i = 0; i < n; i++)
            scanf("%lld", &arr[i]);
        ll valid = vaildCombination(arr, n, k);
        printf("Case %d: %lld\n", cs++, valid);
    }

    return 0;
}
