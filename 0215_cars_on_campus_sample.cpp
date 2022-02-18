# include <cstdio>
# include <algorithm>
# include <string>
# include <map>
# include <iostream>
# include <vector>
using namespace std;

const int debug = 0;
const int sizea = 10050;
const int range = 24*60*60;

int sumcnt[range];
string ToWatch(int time_point)
{
    char str[50];
    sprintf(str,"%02d:%02d:%02d",time_point/60/60,time_point%(60*60)/60,time_point%60);
    return string(str);
}
struct Log
{
    string name;
	int type;// 1 for out
    int time;
    void Print()
    {
	    cout << name << ' ' << ToWatch(time) << ' ' << type << endl;
	}
    bool match (const Log& cmper) const
      {
	    return name==cmper.name&&time<cmper.time&&type==0&&cmper.type==1;  
	  }
    bool operator < (const Log& cmper) const
      {
	    if (name!=cmper.name)// name -- time -- type
	        return name < cmper.name;
        else if (time != cmper.time)
            return time < cmper.time;
        else 
            return type <  cmper.type;
	  }
} car_log[sizea];
int ToDec(int hour,int min,int sec)
{
    return ( hour * 60 + min)*60 + sec;
}

typedef pair<int,int> time_range;
int main ()
{
	int i,j;
	int n,k;
    scanf("%d%d",&n,&k);
    string tmp;
    for (i=0;i<n;i++)
      {
        cin >> car_log[i].name;
		int hour,min,sec;
		scanf("%d:%d:%d",&hour,&min,&sec);
        car_log[i].time = ToDec(hour,min,sec);
        cin >> tmp;
		car_log[i].type = tmp == "out";
	  }
     sort(car_log,car_log+n);if (debug)for (i=0;i<n;i++) car_log[i].Print();
     map<string,int > index;
     int maxrange = -1;
     for (i=0;i<n;i++)
       {
	     if (i+1<n&&car_log[i].match(car_log[i+1]))//按字母表排序 相同的紧贴
			 index[car_log[i].name] += car_log[i+1].time - car_log[i].time;//用车牌索引停放时间
			 if (index[car_log[i].name] > maxrange)    maxrange = index[car_log[i].name];
			 sumcnt[car_log[i].time]++,sumcnt[car_log[i+1].time]--;
	       }
	   }
     for (int i=1;i<range;i++)
       sumcnt[i] += sumcnt[i-1]; 
     while (k--)
     {
	   int hour,min,sec;
	   scanf("%d:%d:%d",&hour,&min,&sec);
	   printf("%d\n",sumcnt[ToDec(hour,min,sec)]);//每个时间存放的车辆数
	 }
	 map<string,int>::iterator it;
	 for (it = index.begin();it!=index.end();it++)
	   if (it->second==maxrange) //输出最大停放时间的车辆牌照
	      cout << it->first << ' ';
	 cout << ToWatch(maxrange) << endl;   //输出最大的停放时间
     return 0; 
}
