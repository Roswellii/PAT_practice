#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define Null -1
#define maxn 110
using namespace std;

struct tree{
    int left, right, data;
};

int main(){
    //
    int n;
    tree t[maxn];
    int key[maxn];
    cin >> n;
    for(int i=0; i<n;i++){
        cin >> t[i].left >> t[i].right;
    }
    for(int i=0; i<n; i++){
        cin >> key[i];
    }

    //
    sort(key, key+n);

    // 中序
    int nd= 0, i= 0;
    vector<int> v;
    while(nd!=-1||!v.empty()){
        while(nd!=-1){
            v.push_back(nd);
            nd= t[nd].left;
        }

        if(!v.empty()){
            nd= v.back();
            v.pop_back();
            t[nd].data= key[i];
            nd= t[nd].right;
            i++;
        }
    }

    //level
    nd= 0;
    queue<int> q;
    q.push(nd);
    while(!q.empty()){
        nd= q.front();
        if(t[nd].left!=Null){
            q.push(t[nd].left);
        }
        if(t[nd].right!=Null){
            q.push(t[nd].right);
        }
        cout << t[nd].data;
        if(q.size()>1) cout << " ";
        q.pop();
    }

    return 0;
}
