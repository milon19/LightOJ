#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

double l1, l2, h;

double searchH(double a)
{
    double h1 = sqrt(l1*l1 - a*a);
    double h2 = sqrt(l2*l2 - a*a);
    double ans = (h1*h2)/(h1+h2);
    return ans;
}

double searchBase()
{
    double low = 0.0, high = l1+l2, mid;
    while(high - low > 1e-9)
    {
        mid = (low+high)/2.0;
        double tm = searchH(mid);
        if(tm > h)
            low = mid;
        else
            high = mid;
    }
    return mid;
}

int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%lf %lf %lf", &l1, &l2, &h);
        double base = searchBase();
        printf("Case %d: %lf\n", cs++, base);
    }

    return 0;
}
