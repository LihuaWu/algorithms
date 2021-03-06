#include <cstdio>
const int N=1000;

int x,y,i,j,k,n,m,p[N],a[N];

bool ok=true;

int get(int x) {
    if (p[x]!=x) p[x]=get(p[x]);
    return p[x];
}

int main() {
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) p[i]=i;
    for (i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        a[x]++;a[y]++;
        if ((a[x]>2)||(a[y]>2)) ok=false;
        x=get(x);y=get(y);
        if ((x==y)&&((i!=n)||(i!=m))){
            printf("i=%d n=%d m=%d\n", i, n, m);
            ok=false;
        } 
        else p[x]=y;
    }
    if (ok) {
        printf("YES\n%d\n",n-m);
        for (i=1;i<=n;i++)
            for (k=1;k<=2;k++)
                for (j=i+1;j<=n;j++) {
                    x=get(i);y=get(j);
                    if ((x!=y)&&(a[i]<2)&&(a[j]<2)) {
                        p[x]=y;
                        a[i]++;a[j]++;
                        printf("%d %d\n",i,j);
                    }
                }
        for (i=1;i<=n;i++)
            while (a[i]<2) {
                printf("%d ",i);
                a[i]++;
            }
    } else printf("NO\n");
    return 0;
}

