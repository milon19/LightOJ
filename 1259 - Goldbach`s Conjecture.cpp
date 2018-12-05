#include<iostream>
#include<cmath>
#include<vector>
#define N 10000000
using namespace std;

bool isprime[N+1];
vector<int>prime;

void sieve()
{
    for(int i = 2; i <= N; i+=2)
        isprime[i] = 1;
    isprime[2] = 0; isprime[1] = 1;
    int sq = (int) sqrt((double) N);
    for(int i = 3; i <= sq; i+=2)
    {
        if(isprime[i] == 0)
        {
            for(int j = i*i; j <= N; j += i+i)
                isprime[j] = 1;
        }
    }
    prime.push_back(2);
    for(int i = 3; i <= N; i+=2)
        if(isprime[i] == 0)
            prime.push_back(i);
}

int main()
{
    sieve();
    /*for(int i = 1; i <= 10; i++)
        if(isprime[i] == 0)
            cout << i << endl;*/
    int t, cs = 1;
    cin >> t;

    while(t--)
    {
        int n, cnt = 0;
        cin >> n;
        for(int i = 0; prime[i] <= n/2; i++)
        {
            if(isprime[n-prime[i]] == 0)
                cnt++;
        }

        cout << "Case " << cs++ << ": " << cnt << endl;
    }

    return 0;
}
