#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const double eps = 1.e-8;
int f[100005];
double a[100005];
double r;

double get(int x) {
    if (a[x] > -1.) {
        return a[x];
    }
    return a[x] = get(f[x]) * r;
}

int main() {
int n;
double p;
    scanf("%d%lf%lf",&n,&p,&r);
    r /= 100.;
    r += 1.;
    for (int i = 0; i < n; ++i) {
        scanf("%d",f + i);
        a[i] = (f[i] < 0)?p:(-1.e6); 
    }
    
    double answer = -1.e6;
    int num;
    for (int i = 0; i < n; ++i) {
        double may = get(i);
        if (may >= answer + eps) {
            answer = may;
            num = 1;
        }
        else if ((may + eps > answer) && (may < answer + eps)) {
            ++num;
        }
    }
    printf("%.2lf %d\n", answer, num);
    return 0;
}
