#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define maxv 1010

struct Node{
    int id;
    int layer;
}; 

vector<Node> Adj[maxv];
bool inq[maxv]={false};

int BFS(int s, int L){
    int numForward= 0;
    queue<Node> q;
    Node st;
    st.id= s;
    st.layer= 0;
    q.push(st);
    inq[st.id]= 1;
    //
    while(!q.empty()){
        Node tp= q.front();
        q.pop();
        int u= tp.id;
        for(int i=0; i<Adj[u].size(); i++){
            Node next=Adj[u][i];
            next.layer= tp.layer+1;
            if(inq[next.id]==0 && next.layer<=L){
                q.push(next);
                inq[next.id]= 1;
                numForward++;
            }
        }

    }
    return numForward;
}

int main(){
    Node user;
    int n, l, numFollow, idFollow;
    scanf("%d%d",&n, &l);

    for(int i=1; i<=n; i++){
        user.id= i;
        scanf("%d", &numFollow);
        for(int j=0; j<numFollow; j++){
            scanf("%d", &idFollow);
            Adj[idFollow].push_back(user);
        }
    }

    int numQuery, s;
    scanf("%d",&numQuery);
    for(int i=0; i<numQuery; i++){
        memset(inq, false, sizeof(inq));
        scanf("%d", &s);
        int numForward= BFS(s, l);
        printf("%d\n", numForward);
    }

    return 0;
}
