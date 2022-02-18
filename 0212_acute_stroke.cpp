#include <bits/stdc++.h>
using namespace std;

int m,n,l,t;
int dx[6]={1, -1, 0, 0, 0, 0}; 
int dy[6]={0, 0, 0, 0, 1, -1}; 
int dz[6]={0, 0, 1, -1, 0, 0}; 
int ans;
int mp[1286][128][60];

struct loca{
	int x,y,z;
	loca(int _x, int _y, int _z):x(_x), y(_y), z(_z){}
};

//计算这一个连通区域的体积
void bfs(int x, int y, int z){
	int ret= 0;
	queue<loca> que;
	que.push(loca(x, y, z));
	mp[x][y][z]= 0;
	ret+=1;
	//在队列中保存邻接结点
	while(!que.empty()){
		loca tp= que.front();
		que.pop();
		x= tp.x;
		y= tp.y;
		z= tp.z;
		//访问当前结点的邻接结点
		for(int i=0; i<6; i++){
			int nx= x+ dx[i];
			int ny= y+ dy[i];
			int nz= z+ dz[i];
			if(nx>=0 && ny>=0 && nz>=0 && nx<m && ny <n&& nz<l && mp[nx][ny][nz]==1){
				ret+=1;
				mp[nx][ny][nz]= 0;
				que.push(loca(nx, ny, nz));
			}
		}
	}
	if(ret>= t){
		ans+= ret;
	}
}


int main(){
	scanf("%d%d%d%d",&m,&n,&l,&t);
    for (int k=0;k<l;k++)
	    for (int i=0;i<m;i++)
	        for (int j=0;j<n;j++)
	            scanf("%d",&mp[i][j][k]);
	
	for (int k=0;k<l;k++)
	    for (int i=0;i<m;i++)
	        for (int j=0;j<n;j++){
				if(mp[i][j][k]==1){
					bfs(i, j, k);
				}
			}
	cout << ans << endl;
	return 0;
}