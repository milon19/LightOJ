/*
    LightOJ -> 1112 - Curious Robin Hood
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<climits>
#include<queue>
#include<stack>

#define pb push_back
#define m_p make_pair
#define sz 100005
//#define file_io

const int inf = 1e9+9;

using namespace std;

typedef pair<int, int> pii;
int arr[sz], st[4*sz];
int getMid(int b, int e){return b+(e-b)/2;}

void build_st(int node, int b, int e)
{
    if(b == e)
    {
        st[node] = arr[b];
        return;
    }
    int mid = getMid(b, e);
    int l = 2*node;
    int r = l+1;
    build_st(l, b, mid);
    build_st(r, mid+1, e);
    st[node] = st[l]+st[r];
}

int query(int node, int b, int e, int x, int y)
{
    if(y < b || e < x)
        return 0;
    if(x <= b && e <= y)
        return st[node];
    int mid = getMid(b, e);
    int l = node*2;
    int r = l+1;
    int lans = query(l, b, mid, x, y);
    int rans = query(r, mid+1, e, x, y);
    return lans+rans;
}
void update(int node, int b, int e, int pos, int v, int ck)
{
    if(pos < b || e < pos) return;
    if(b == e)
    {
        if(ck == 1)
            st[node] = 0;
        else
            st[node] += v;
        return;
    }
    int mid = getMid(b, e);
    int l = 2*node;
    int r = l+1;
    update(l, b, mid, pos, v, ck);
    update(r, mid+1, e, pos, v, ck);
    st[node] = st[l]+st[r];

}
int main()
{
    #ifdef file_io
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);
    #endif
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);

        build_st(1, 1, n);
        printf("Case %d:\n", cs++);
        for(int i = 1; i <= q; i++)
        {
            int type;
            scanf("%d", &type);
            if(type == 1){
                int x;
                scanf("%d", &x);
                int ans = query(1, 1, n, x+1, x+1);
                printf("%d\n", ans);
                update(1, 1, n, x+1, 0, 1);

            }
            else if(type == 2){
                int v, pos;
                scanf("%d %d", &pos, &v);
                update(1, 1, n, pos+1, v, 2);
            }
            else{
                int x, y;
                scanf("%d %d", &x, &y);
                int ans = query(1, 1, n, x+1, y+1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
