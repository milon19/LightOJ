#include<iostream>
#include<cstdio>

using namespace std;

string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int n, k, num[27], used[27], cur = 0;

void permute(int start, int len)
{
    if(cur >= k)
        return;
    if(start == len)
    {
        for(int i = 0; i < len; i++)
            printf("%c", s[num[i]]);
        printf("\n");
        cur++;
        return;
    }
    for(int i = 0; i < len; i++)
    {
        if(used[i] == 0)
        {
            used[i] = 1;
            num[start] = i;
            permute(start+1, len);
            used[i] = 0;
        }
    }
}

int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d", &n, &k);
        printf("Case %d:\n", cs++);
        cur = 0;
        permute(0, n);
    }
    return 0;
}
