#include<iostream>
#include<cstdio>
#include<cmath>
#define PI acos(-1)

using namespace std;

double a, b;
double perimeter(double x)
{

    double bc, r, th, ans, s, ss;
    bc = sqrt(a*a + b*b);
    r = bc/2.0;
    ss = (2.0*r*r-b*b)/(2.0*r*r);
    th = acos(ss);
    s = r*th;
    ans = (2*a + 2*s)*x;
    return ans;
}


double searchAns()
{
    double low = 0.0, high = 400.0, mid;
    while(high - low >= 1e-9)
    {
        mid = (high+low)/2.0;
        double tm = perimeter(mid);
        if(tm-400 > 0.0)
            high = mid;
        else
            low = mid;
    }
    return mid;
}
int main()
{
    int tc, cs = 1;
    scanf("%d", &tc);
    while(tc--)
    {
        char c;
        scanf("%lf %c %lf", &a, &c, &b);
        double ans = searchAns();
        printf("Case %d: %.7lf %.7lf\n", cs++, a*ans, b*ans);
    }

    return 0;
}
