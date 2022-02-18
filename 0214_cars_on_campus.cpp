#include<cstdio>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define maxn 10050
const int range= 24*60*60;

int sumcnt[range]={0};

string toWatch(int time_point){
    char str[50];
    sprintf(str, "%02d:%02d:%02d", time_point/60/60, time_point%(60*60)/60, time_point%60);
    return str;
}

struct log{
    string name;
    int type;
    int time;

   bool match(const log& cmper) const{
       return name==cmper.name&& time<cmper.time&& type==0 &&cmper.type==1;
   }
   bool operator < (const log& cmper) const{// 先按车牌，再按时间，最后按状态。事实上，不会出现同时出入的情况。
       if(name!=cmper.name){
           return name< cmper.name;
       }
       else if(time!= cmper.time){
           return time<cmper.time;
       }else{
           return type< cmper.type;
       }
   }
} car_log[maxn];

int toDec(int hour, int min, int sec){//转化为秒数
    return (hour*60+ min)*60+ sec;
}

int main(){
    int n, k;
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> car_log[i].name;
        int hour, min, sec;
        scanf("%d:%d:%d", &hour, &min, &sec);
        car_log[i].time= toDec(hour, min, sec);
        string status;
        cin >> status;
        if(status== "out") car_log[i].type= 1;
        else car_log[i].type= 0;
    }
    //
    sort(car_log, car_log+n);
    int maxrange= -1;
    map<string,int > index;
    for(int i=0; i<n; i++){
        if(i+1<n && car_log[i].match(car_log[i+1])){
            index[car_log[i].name]+= car_log[i+1].time- car_log[i].time;//同一辆车可能进出多次，不能直接用
            if(index[car_log[i].name]> maxrange) maxrange= index[car_log[i].name];
            sumcnt[car_log[i].time]++;// 先记录变化量
            sumcnt[car_log[i+1].time]--;
        }
        
    }
    
    //
    for(int i=1; i<range; i++){
        sumcnt[i]+= sumcnt[i-1];//累计求和得每个时刻的停放量
    }
    while(k--){
        int hour, min, sec;
        scanf("%d:%d:%d", &hour, &min, &sec);
        printf("%d\n", sumcnt[toDec(hour, min, sec)]);
    }

    //
    map<string, int>:: iterator it;
    for(it= index.begin(); it!=index.end(); it++){
        if(it->second== maxrange){
            cout << it->first << " ";
        }
    }
    cout << toWatch(maxrange) << endl;

    // for(int i=0; i<n; i++){
    //     cout << car_log[i].name << " "<< car_log[i].time << endl;
    // }
    return 0;
}
