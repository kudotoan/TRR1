#include <iostream>
#include <algorithm>
using namespace std;
int n,W,x[100]={0};
int tmp[100];
int vMax=-1e9, wNow=0,vNow=0;
class bag {
    public:
    int value;
    int weight;
};
bag list[100];

istream &operator>>(istream &in, bag &a) {
    in >> a.value;
    in >> a.weight;
    return in;
}

ostream &operator<<(ostream &out, bag a) {
    out << a.value << " " << a.weight;
    return out;
}

bool cmp(bag a, bag b) {
    if ((1.0*a.value/a.weight)>(1.0*b.value/b.weight)) return true;
    return false;
}

void BrandAndBound(int i) {
    for (int j=1; j>=0; j--) {
        x[i]=j;
        vNow+=list[i].value*x[i];
        wNow+=list[i].weight*x[i];
        if (i==n-1) {
            if (vMax<vNow && wNow <= W) {
                vMax=vNow; 
            }
        } else {
            if ((W-wNow>=0) && vNow+(1.0*list[i+1].value*(W-wNow)/list[i+1].weight)>=vMax)
                    BrandAndBound(i+1);
        }
        vNow-=list[i].value*x[i];
        wNow-=list[i].weight*x[i];
    }
}

int main() {
    cin >> n >> W;
    for (int i=0; i<n; i++) cin >> list[i];
    sort(list,list+n,cmp);
    BrandAndBound(0);
    cout << vMax << endl;
    return 0;
}