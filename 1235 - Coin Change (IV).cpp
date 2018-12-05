#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long

using namespace std;
int a[30], n;
vector <ll> X, Y;

void calcSubSet1(int i, int val)
{
    X.push_back(val);
    if(i == n/2)
        return;
    calcSubSet1(i+1, val);
    calcSubSet1(i+1, val+a[i]);
    calcSubSet1(i+1, val+a[i]+a[i]);
}

void calcSubSet2(int i, int val)
{
    Y.push_back(val);
    if(i == n)
        return;
    calcSubSet2(i+1, val);
    calcSubSet2(i+1, val+a[i]);
    calcSubSet2(i+1, val+a[i]+a[i]);

}

int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);

    while(tc--)
    {
        ll k;
        scanf("%d %lld", &n, &k);
        for(int i = 0; i < n; i++)
        {
            int tm;
            scanf("%d", &tm);
            a[i] = tm;
        }
        calcSubSet1(0, 0);
        calcSubSet2(n/2, 0);

        sort(Y.begin(), Y.end());
        int fl = 0, sz_X = X.size();
        for(int i = 0; i < sz_X; i++)
        {
            if(binary_search(Y.begin(), Y.end(), k-X[i]))
            {
                fl = 1;
                break;
            }
        }

        if(fl == 1)
            printf("Case %d: Yes\n", cs++);
        else
            printf("Case %d: No\n", cs++);
        X.clear();
        Y.clear();
    }


    return 0;
}
