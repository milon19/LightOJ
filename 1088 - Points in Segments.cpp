#include<iostream>
#include<cstdio>

using namespace std;

int lowerB(int arr[], int l, int r, int k)
{
    while(l <= r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == k)
            r = mid - 1;
        else if(arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l+1;

}

int upperB(int arr[], int l, int r, int k)
{
    int x;

    while(l <= r)
    {
        int mid = (l+r)/2;
        if(arr[mid] == k)
            l = mid + 1;
        else if(arr[mid] < k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r+1;

}

int main()
{
    //freopen("in.txt", "rt", stdin);
    //freopen("out.txt", "wt", stdout);
    int tc, cs = 1;
    scanf("%d", &tc);

    while(tc--)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        int arr[n];
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        printf("Case %d:\n", cs++);
        for(int i = 1; i <= q; i++)
        {
            int l, h;
            scanf("%d %d", &l, &h);
            int a = lowerB(arr, 0, n, l);
            int b = upperB(arr, 0, n, h);
            if(a < 0)
                a = 1;
            if(b > n)
                b = n;
            //printf("  %d %d\n", a, b);
            printf("%d\n", b-a+1);
        }
    }

    return 0;
}
