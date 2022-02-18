#include <bits/stdc++.h>
#define maxn 550 
using namespace std;

vector<int> g[maxn], curpath, anspath;
int cost[maxn][maxn], vis[maxn];
int bike[maxn];
int cmax, n, sp, m;
int mincost= 1e9, minsend=1e9, minback=1e9;


void dfs(int cur, int cursend, int curback, int curcost){
    vis[cur]= 1;
    curpath.push_back(cur);
    //return 
    if(curcost> mincost) return;
    if(cur==sp){
        if(curcost<mincost){
            mincost= curcost;
            minsend= cursend;
            minback= curback;
            anspath= curpath;
            return;
        }
        if(curcost==mincost && cursend< minsend){
            mincost= curcost;
            minsend= cursend;
            minback= curback;
            anspath= curpath;
            return;
        }
         if(curcost==mincost && cursend==minsend&& curback<minback){
            mincost= curcost;
            minsend= cursend;
            minback= curback;
            anspath= curpath;
            return;
        }
    }

    //dfs
    for(int i=0; i<g[cur].size(); i++){
            int v= g[cur][i];
            if(!vis[v]){
	            if(bike[v]+ curback< cmax/2){
	                dfs(v, cursend+ cmax/2- bike[v]- curback, 0, curcost+ cost[cur][v]);
	            }else{
	                dfs(v, cursend, bike[v]+curback- cmax/2, curcost+ cost[cur][v]);
	            }
	            curpath.pop_back();
	            vis[v]=0;
			}
           
        }
     return;
    }


int main(){
    //input
    scanf("%d %d %d %d",&cmax, &n, &sp, &m);
    for(int i=0; i<n; i++){
        scanf("%d", &bike[i+1]);
    }
    for(int i=0, x, y,z; i<m; i++){
        scanf("%d %d %d", &x, &y, &z);
        g[x].push_back(y);
        g[y].push_back(x);
        cost[x][y]= z;
        cost[y][x]= z;
    }
    //dfs
    dfs(0,0,0,0);
    //result
    printf("%d ", minsend);
    for(int i=0; i<anspath.size(); i++){
        if(i!=anspath.size()-1){
            printf("%d->", anspath[i]);
        }else{
            printf("%d", anspath[i]);
        }
    }
    printf(" %d", minback);
    return 0;
}
