#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

int main()
{
    int t, cs = 1;
    cin >> t;

    while(t--)
    {
        int n, ad;
        cin >> n >> ad;
        int mod = ad%n, ans = 1;

        while(mod != 0)
        {
            mod = (mod*10 + ad)%n;
            ans++;
        }

        cout << "Case " << cs++ << ": " << ans << endl;
    }

    return 0;
}
