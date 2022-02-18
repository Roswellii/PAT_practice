// PAT Public Bike Management
#include <bits/stdc++.h>
using namespace std;

//? 
const int maxn= 500+5, INF= 1e9;
//?
int cap, n, sp, m, bike[maxn], cost[maxn][maxn];
//?
vector<int> G[maxn], anspath, curpath;
// center bike num & cost
int minsend= INF, minback= INF, mincost= INF;
//dij
int vis[maxn];

//current station + status
void dfs(int cur, int cursend, int curback, int curcost){
	//--- return condition
	vis[cur]= 1;
	curpath.push_back(cur);
	if(curcost>mincost) return;
	//visit problem station. yes, tehre exists only one problem station.
	if(cur==sp){
		//new path is better
		if(curcost< mincost){
			mincost= curcost;
			minsend= cursend;
			minback= curback;
			anspath= curpath;
			return;
		}
		//new path equals old one. compare bike num
		if(curcost== mincost && cursend< minsend){
			minsend= cursend;
			minback= curback;
			anspath= curpath;
			return;
		}
		//new path time and bike send number equal old one. compare bike back num
		if(curcost== mincost && cursend == minsend && curback <minback){
			minback= curback;
			anspath= curpath;
			return;
		}
		// new path is not better than old one
		return;
	}
	//-- dfs
	for(int i=0; i<G[cur].size(); ++i){
		int v= G[cur][i];
		if(!vis[v]){
			// curback all goes to v still not enough
			if(bike[v]+ curback< cap/2){
				dfs(v, cursend+ cap/2- bike[v]- curback, 0, curcost+cost[cur][v]);
			}
			//curback is enough for v
			else{
				dfs(v, cursend, curback+  bike[v]- cap/2, curcost+ cost[cur][v]);
			}
			// undo v for next cur station
			vis[v]=0;
			curpath.pop_back();
		}
	}
	
}



int main(){
	//input: station capacity, station number, problem station, road num
	scanf("%d %d %d %d", &cap, &n, &sp, &m);
	//input current bike number for each station
	for(int i=1; i<=n; ++i){
		scanf("%d", &bike[i]);
	}
	//input road
	for(int i=1, x, y, z; i<=m; ++i){
		scanf("%d %d %d", &x, &y, &z);
		G[x].push_back(y);
		G[y].push_back(x);
		cost[x][y]= z;
		cost[y][x]= z;
	}
	//?
	dfs(0,0,0,0);
	//output result
	printf("%d ", minsend);
	for(int i=0; i<anspath.size(); ++i){
		if(i==0){
			printf("%d", anspath[i]);
		}
		else{
			printf("->%d", anspath[i]);
		}
	}
	printf(" %d\n", minback);
	return 0;
}
