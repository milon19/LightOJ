#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>

using namespace std;

int main()
{
    //freopen("in.txt", "rt", stdin);
    //freopen("out.txt", "wt", stdout);
    int tc, cs = 1;
    scanf("%d", &tc);

    while(tc--)
    {
        map<int, int> mp;
        map<int, int> :: iterator it, it2;

        int n, num, lp = 0;
        scanf("%d", &n);

        for(int x = 2; x <= n; x++)
        {
            num = x;
            while(num%2==0)
            {
                num/=2;
                mp[2]++;
            }
            int sq = (int) sqrt((double) num);

            for(int i = 3; i <= sq; i+=2)
            {
                if(num%i == 0)
                {
                    while(num%i == 0)
                    {
                        num/=i;
                        mp[i]++;
                    }
                }

            }
            if(num > 1)
                mp[num]++;
        }
        it = mp.begin();
        printf("Case %d: %d = %d (%d)", cs++, n, (*it).first, (*it).second);

        for(it2 = ++it ; it2 != mp.end(); it2++)
            printf(" * %d (%d)", (*it2).first, (*it2).second);
        printf("\n");
    }

    return 0;
}

