#include<iostream>
#include<cstdio>
#include<algorithm>
#define sz 2001

using namespace std;
int arr[sz];

int BS(int low, int high, int key)
{
    int mid;
    while(low <= high)
    {
        mid = (low+high)/2;
        if(arr[mid] == key)
            low = mid + 1;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);

    while(tc--)
    {
        int n, cnt = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        sort(arr, arr+n);
        for(int i = 0; i < n; i++)
        {
            int a = arr[i];
            for(int j = i+1; j < n; j++)
            {
                int b = arr[j];
                int key = a+b, index = j+1;
                int tm = BS(j+1, n-1, key-1);
                //cout << index << " " << tm << endl;
                cnt += (tm-j-1);
            }
        }
        printf("Case %d: %d\n", cs++, cnt);

    }

    return 0;
}
