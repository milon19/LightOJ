#include<stdio.h>

struct cases
{
    char ch[200000];
    int h, w, s;
};

int main()
{
    int t, n, i, j;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d", &n);

        struct cases p[n];
        int v[n];

        for(j = 0; j < n; j++)
        {
            scanf("%s %d %d %d", &p[j].ch, &p[j].h, &p[j].w, &p[j].s);
            v[j] = p[j].h * p[j].w * p[j].s;
        }

        int maxx = v[0], minn = v[0], indexa = 0, indexb = 0;

        for(j = 1; j < n; j++)
        {
            if(maxx < v[j])
            {
                maxx = v[j];
                indexa = j;
            }
        }

        for(j = 1; j < n; j++)
        {
            if(minn > v[j])
            {
                minn = v[j];
                indexb = j;
            }
        }

        if(maxx == minn)
            printf("Case %d: no thief\n", i);
        else
            printf("Case %d: %s took chocolate from %s\n", i, p[indexa].ch, p[indexb].ch);

    }

    return 0;
}
