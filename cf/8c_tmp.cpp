#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

int n , N;
int dp[1<<24];
int first[1<<24];
int opt[1<<24];
int cost[24][24];
int way[24][24]; // 0 : fenkai 1 : yiqi
int X[24],Y[24] , X0 , Y0;
int par[24];

int dist(int x1 , int y1 , int x2 , int y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int dodp(int s)
{
    if(dp[s] >= 0)
             return dp[s];
    int ret = 100000000;
    int f = first[s];
    for(int j = f + 1 ; j < n ; j++)
            if((s & (1<<j)) > 0)
                  ret = min(ret , cost[f][j] + dodp(s - (1<<j) - (1<<f)));
    dp[s] = ret;
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    for(int i = 1 ; i < (1<<24) ; i++)
            for(int j = 0 ; ; j++)
                    if((i&(1<<j)) > 0)
                    {
                                  first[i] = j;
                                  break;
                    }
    while(cin>>X0>>Y0)
    {
                 cin>>n;
                 N = n;
                 for(int i = 0 ; i < n ; i++)
                         cin>>X[i]>>Y[i];
                 if(n % 2 == 1)
                 {
                      n++;
                      X[n-1] = X0;
                      Y[n-1] = Y0;
                 }
                 for(int i = 0 ; i < n ; i++)
                         for(int j = 0 ; j < n ; j++)
                                 if(i != j)
                                 {
                                      cost[i][j] = 2 * (dist(X0,Y0,X[i],Y[i]) + dist(X0,Y0,X[j],Y[j]));
                                      way[i][j] = 0;
                                      int nc = dist(X0,Y0,X[i],Y[i]) + dist(X0,Y0,X[j],Y[j]) + dist(X[i] , Y[i] , X[j] , Y[j]);
                                      if(nc < cost[i][j])
                                      {
                                            cost[i][j] = nc;
                                            way[i][j] = 1;
                                      }
                                 }
                 memset(dp , 0xff , sizeof(dp));
                 dp[0] = 0;
                 int ans = dodp((1<<n) - 1) , s = (1<<n) - 1;
                 cout<<ans<<endl;
                 memset(par , 0xff , sizeof(par));
                 while(s)
                 {
                         int f = first[s];
                         for(int j = f + 1 ; j < n ; j++)
                                 if((s & (1<<j)) > 0)
                                 {
                                       int val = cost[f][j] + dodp(s - (1<<j) - (1<<f));
                                       if(val == ans)
                                       {
                                              if(way[f][j] == 1)
                                              {
                                                           par[f] = j;
                                                           par[j] = f;
                                              }
                                              s = s - (1<<j) - (1<<f);
                                              ans = ans - cost[f][j];
                                              break;
                                       }
                                 }
                         
                 }
                 cout<<0;
                 for(int i = 0 ; i < N ; i++)
                         if(par[i] == -1)
                         {
                                   cout<<" "<<i+1<<" "<<0;
                         }
                         else
                         {
                             if(par[i] > i)
                                       cout<<" "<<i+1<<" "<<par[i]+1<<" "<<0;
                         }
                 cout<<endl;
    }
    return 0;
}
