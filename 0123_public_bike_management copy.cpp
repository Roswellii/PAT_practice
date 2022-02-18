#include <bits/stdc++.h>
using namespace std;
const int maxn= 500+ 5, INF= 1e9;
int cap, n, sp, m;
vector<int> G[maxn], anspath, curpath;
int minsend= INF, minback= INF, mincost= INF;
int vis[maxn];
int bike[maxn], cost[maxn][maxn];

void dfs(int cur, int cursend, int curback, int curcost){
	vis[cur]= 1;
	curpath.push_back(cur);
	//! return only happens when curcost > mincost or reach sp
	if(curcost> mincost) return;
	// if reached sp
	if(cur== sp){
		//update
		if(curcost< mincost){
			mincost= curcost;
			minsend= cursend;
			minback= curback;
			anspath= curpath;
			return;
		}
		if(curcost==mincost&& cursend< minsend){
			mincost= curcost;
			minsend= cursend;
			minback= curback;
			anspath= curpath;
			return;
		}
		if(curcost== mincost && cursend== minsend && curback< minback){
			mincost= curcost;
			minsend= cursend;
			minback= curback;
			anspath= curpath;
			return;
		}
		return;
	}
	
	// dfs
	//?
	for(int i=0; i<G[cur].size(); ++i){
		int v= G[cur][i];
		// have not visited yet
		if(!vis[v]){
			if(bike[v]+ curback< cap/2){
				//request more bike
				dfs(v, cursend+ cap/2- bike[v]- curback, 0, curcost+ cost[cur][v]);
			}else{
				dfs(v, cursend, curback+ bike[v]- cap/2, curcost+ cost[cur][v]);
			}
			//undo 
			vis[v]= 0;
			curpath.pop_back();
		}
	}


}



int main(){
	scanf("%d %d %d %d", &cap, &n, &sp, &m);
	// current bike num
	//! note: station's index start with 1
	for(int i=1; i<=n; ++i){
		scanf("%d", &bike[i]);
	}
	// cost
	for(int i=1, x, y, z; i<=m; ++i){
		scanf("%d %d %d", &x, &y, &z);
		G[x].push_back(y); 
		G[y].push_back(x);
		cost[x][y]= z;
		cost[y][x]= z;
	}
	//dfs
	dfs(0,0,0,0);

	//result
	printf("%d ", minsend);
	for(int i=0; i<anspath.size(); ++i){
		if(i==0){
			printf("%d", anspath[i]);
		}else{
			printf("->%d", anspath[i]);
		}
	}
	printf(" %d\n", minback);
	return 0;
}
