#include <bits/stdc++.h>
using namespace std;

int mp[1286][128][60];
struct loca
{
    int x,y,z;
    loca(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
};

int m,n,l,t;
int dx[6]={1, -1, 0, 0, 0, 0}; 
int dy[6]={0, 0, 0, 0, 1, -1}; 
int dz[6]={0, 0, 1, -1, 0, 0}; 
int ans = 0;
int InRange(int x,int y,int z)
{
    return x<m&&x>=0&&y<n&&y>=0&&z<l&&z>=0;
}
void bfs(int x,int y,int z)
{
    int ret = 0;
	queue<loca> que;
	que.push(loca(x,y,z));
	mp[x][y][z] = 0;ret++;
	while (!que.empty())
	{
	    loca tp = que.front();que.pop();
	    x = tp.x;
 	    y = tp.y;
 	    z = tp.z;
	    for (int i=0;i<6;i++)
	    {
		    int nx = x + dx[i];
		    int ny = y + dy[i];
		    int nz = z + dz[i];
	        if (InRange(nx,ny,nz)&&mp[nx][ny][nz] == 1)
		        {
	        	mp[nx][ny][nz] = 0;ret++;
				que.push(loca(nx,ny,nz));
		        }
		}
	} 
	if (ret>=t)
	    ans += ret;
}
int main()
{
    scanf("%d%d%d%d",&m,&n,&l,&t);
    for (int k=0;k<l;k++)
	    for (int i=0;i<m;i++)
	        for (int j=0;j<n;j++)
	            scanf("%d",&mp[i][j][k]);
    for (int k=0;k<l;k++)
	    for (int i=0;i<m;i++)
	        for (int j=0;j<n;j++)
	            if (mp[i][j][k]==1)
	                bfs(i,j,k);
    printf("%d\n",ans);
    return 0;
}

