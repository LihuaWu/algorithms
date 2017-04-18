#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<algorithm>

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define For(i,x,y) for(int i=((int)x);i<=((int)y);i++)
#define Dep(i,y,x) for(int i=((int)y);i>=((int)x);i--)
#define Rep(i,x) for (int y,i=head[x];i;i=E[i].nxt)
using namespace std;

const int inf=1000000009;

typedef double db;
typedef long long ll;
typedef vector<int> VI;
typedef unsigned int uint;
typedef pair<int,int> pii;

int rd() {
    char c=getchar(); int t=0,f=1;
    while (!isdigit(c)) f=(c=='-')?-1:1,c=getchar();
    while (isdigit(c)) t=t*10+c-48,c=getchar(); return t*f;
}
void wt(int x) {
    if (x<0) putchar('-'),wt(-x);
    else { if (x>9) wt(x/10); putchar(x%10+48); }
}

const int N=5000015;
char s[N],A[N<<1]; int n,Len,p[N<<1],Res[N<<1]; ll Ans;

void Manachar() {
    int mx=1,id=1;
    For (i,1,n) {
        p[i]=max(1,min(p[2*id-i],mx-i));
//        p[i] = 1;
        printf("i=%d id=%d mx=%d p[2*%d-%d]=%d, mx-i=%d, p[%d]=%d Res[%d]=%d %d\n", i, id, mx, id, i, p[2*id-i],  mx-i, i, p[i], i, Res[i], Res[i+n]);
        while (i-p[i]>=1 && A[i-p[i]]==A[i+p[i]] && i+p[i]<=n) p[i]++;
        if (i+p[i]-1>=mx) mx=i+p[i]-1,id=i;
        if (i-p[i]+1==1) {
            if (i%2==0) Res[i+p[i]]=Res[i]+1;
            else Res[i+p[i]]=Res[i-1]+1;
            Ans+=Res[i+p[i]];
        }
    }
    return;
}

int main() {
    scanf("%s",s);
    Len=strlen(s);
    For (i,0,Len-1)
        A[++n]=s[i],A[++n]='#';
    n--;
    for (int i = 1; i <= n; i++) {
        //printf("%c", A[i]);
    }
    //printf("\n");
    Manachar();

    for (int i = 0; i < n+2; i++) {
        //printf("Res[%d]=%d, p[%d]=%d\n", i, Res[i], i, p[i]);
    }
    printf("%d\n",Ans);
    return 0;
}
