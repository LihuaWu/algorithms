#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

const double eps=1e-10;

double ch,cs,hs,t1,t2;

struct point
{
    double x,y;
    void init()
    {
        scanf("%lf%lf",&x,&y);
    }
}cinema,shop,house;

double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double getv(double v)
{
    point p;
    p.x=v*(shop.x-house.x)+house.x;
    p.y=v*(shop.y-house.y)+house.y;
    double d1=dist(p,cinema);
    double d2=dist(p,house);
    double d3=dist(p,shop);
    double dd1=d1;
    if (t2+eps>=d2+d1 && t1+eps>=d1+hs+d3) return min(t2-d2,t1-d3-hs);
    double l=0.0,r=1.0;
    for (int a=1;a<=300;a++)
    {
        double m=(l+r)/2.0;
        point q;
        q.x=(p.x-cinema.x)*m+cinema.x;
        q.y=(p.y-cinema.y)*m+cinema.y;
        d1=dist(cinema,q);
        d2=dist(house,q);
        d3=dist(shop,q);
        if (t2+eps>=d1+d2 && t1+eps>=d1+hs+d3) l=m;
        else r=m;
    }
    return r*dd1;
}

int main()
{
    scanf("%lf%lf",&t1,&t2);
    cinema.init();
    house.init();
    shop.init();
    ch=dist(cinema,house);
    cs=dist(cinema,shop);
    hs=dist(house,shop);
    t1+=cs+hs;
    t2+=ch;
    double ans;
    if (t2+eps>=cs+hs) ans=min(t1,t2);
    else
    {
        double l=0.0,r=1.0;
        for (int a=1;a<=300;a++)
        {
            double m1=(r-l)/3.0+l,m2=r+l-m1;
            if (getv(m1)<getv(m2)) l=m1;
            else r=m2;
        }
        ans=getv(r);
    }
    printf("%.8lf\n",ans);

    return 0;
}

