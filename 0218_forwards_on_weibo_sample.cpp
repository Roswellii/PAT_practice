#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAXV=1010;
struct Node
{
	int id;//结点编号
	int layer;//结点层号 
};
vector<Node> Adj[MAXV];//邻接表
bool inq[MAXV]={false};//顶点是否已被加入过队列
int BFS(int s,int L)
{
	//start为起始结点，L为层数上限
	int numForward=0;//转发数
	queue<Node> q;//BFS队列
	Node start;//定义起始结点；
	start.id=s;//起始结点编号
	start.layer=0;//起始结点层号为0
	q.push(start);//将起始结点压入队列
	inq[start.id]=true;//起始结点的编号设为已被加入过队列
	while(!q.empty())
	{
		Node topNode=q.front();//取出队首结点
		q.pop();//队首结点出队
		int u=topNode.id;//队首结点的编号
		for(int i=0;i<Adj[u].size();i++)
		{
			Node next=Adj[u][i];//从u出发能到达的结点next
			next.layer=topNode.layer+1;//next的层号等于当前结点层号加1
			//如果next的编号未被加入过队列，且next的层次不超过上限L
			if(inq[next.id]==false && next.layer<=L)
			{
				q.push(next);//入队
				inq[next.id]=true;//next的编号设为已被加入过队列
				numForward++;//转发数加1 
				 
			} 
		} 
	} 
	return numForward; 
} 
int main()
{
	Node user;
	int n,L,numFollow,idFollow;
	scanf("%d%d",&n,&L);//结点个数，层数上限
	for(int i=1;i<=n;i++)
	{
		user.id=i;//用户编号为i; 
		scanf("%d",&numFollow);//i号用户关注的人数
	    for(int j=0;j<numFollow;j++)
		{
			scanf("%d",&idFollow);//i号用户关注的用户编号
			Adj[idFollow].push_back(user);//边idFollow->i 
		} 
	} 
	int numQuery,s;
	scanf("%d",&numQuery);//查询个数
	for(int i=0;i<numQuery;i++)
	{
		memset(inq,false,sizeof(inq));//inq数组初始化
		scanf("%d",&s);//起始结点编号
		int numForward=BFS(s,L);//BFS返回转发数
		printf("%d\n",numForward); 
	} 
	return 0;
	
}
