#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;


int divisor(int n)
{
    int num = 0, sq = (int)sqrt((double)n);
    for(int i = 1; i <= sq; i++)
    {
        if(n%i == 0)
        {
            num++;
            if(n/i > i)
                num++;
        }
    }
    return num;
}

bool cmp(pair<int, int>x, pair<int, int>y)
{
    if(x.first < y.first)
        return 1;
    if(x.first == y.first)
    {
        if(x.second > y.second)
            return 1;
        else
            return 0;
    }
    return 0;
}

int main()
{
    vector < pair <int, int> > aa(1001);

    for(int i = 1; i <= 1000; i++)
    {
        int cc = divisor(i);
        aa[i].first = cc;
        aa[i].second = i;

    }
    sort(aa.begin(), aa.end(), cmp);

    int N;
    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        cout << "Case " << i << ": " << aa[a].second << endl;
    }
    return 0;
}
