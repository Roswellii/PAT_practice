#include <iostream>
#include <vector>
using namespace std;
const int maxn=110;
int n,m,father,childnum,child;
int levelnum[maxn]={0},maxlevel=1,maxnum=0;   //设置一个某层结点个数数组，结点个数最多的层次及该层层号
vector<int> Node[maxn];                       //树，每个Node[]里面存储子结点编号
void DFS(int now,int level){                  //DFS遍历树（传入结点号与层号）
    levelnum[level]++;
    if(levelnum[level]>maxnum){               //更新结点最多的层号及结点个数
        maxnum=levelnum[level];
        maxlevel=level;
    }
    for(int i=0;i<Node[now].size();i++)       //遍历当前结点的子树
        DFS(Node[now][i],level+1);
}
int main(){  cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>father>>childnum;
        for(int j=0;j<childnum;j++){
            cin>>child;
            Node[father].push_back(child);
        }
    }
    DFS(1,1);
    cout<<maxnum<<" "<<maxlevel;
    return 0;
} 