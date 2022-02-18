#include <iostream>
#include <queue>
using namespace std;
#define maxl 60

int m, n, s, t;
bool b[1286][128][maxl];
int ans= 0;

int dx[6]= {1, -1, 0, 0, 0, 0};
int dy[6]= {0, 0, 1, -1, 0, 0};
int dz[6]= {0, 0, 0, 0, 1, -1};


struct loca{
    int x, y, z;
    loca(int _x, int _y, int _z):x(_x), y(_y), z(_z){};
};

void bfs(loca l){
    int ct= 0;
    queue<loca> que;
    que.push(l);
    b[l.x][l.y][l.z]= 0;//@
    while(!que.empty()){
        loca temp= que.front();
        que.pop();
        int x= temp.x;
        int y= temp.y;
        int z= temp.z;
     
        //cout << "x: "<< x <<"y: "<< y <<"z: "<<  z << endl;
        ct+=1;

        for(int i=0; i<6; i++){
            int nx= x+ dx[i];
            int ny= y+ dy[i];
            int nz= z+ dz[i];

            if(nx>=0&&ny>=0&&nz>=0&&nx<m&&ny<n&&nz<s&& b[nx][ny][nz]==1){
                que.push(loca(nx, ny, nz));
                b[nx][ny][nz]= 0;//@ 
            }
        }
    }

    if(ct>=t){
        ans+= ct;
    }

}

int main(){
    cin >> m >> n >> s >> t;

    //
    for(int i=0; i<s; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                cin >> b[j][k][i];
            }
        }
    }

    //
    for(int i=0; i<s; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<n; k++){
                if(b[j][k][i]==1){
                    bfs(loca(j, k, i));
                }
            }
        }
    }
    cout << ans << endl;
 
    return 0;
}
