#include <iostream>
#include <algorithm>
using namespace std;
int n,W,x[100]={0}, ans[100]={0};
int vMax=-1e9;

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

void update() {
    int sumW=0, sumV=0;
    for (int i=1; i<=n; i++) {
        sumW+=x[i]*list[i].weight;
        sumV+=x[i]*list[i].value;
    }
    if (sumW<=W && sumV>vMax) {
        swap(sumV,vMax);
        for(int i=1; i<=n; i++) {
            ans[i]=x[i];
        }
    }
}

void Try(int i) {
    for (int j=0; j<=1; j++) {
        x[i]=j;
        if (i==n) update(); else Try(i+1);
    }
    
}

int main() {
    cin >> n >> W;
    for (int i=1; i<=n; i++) cin >> list[i];
    Try(1);
    cout << vMax << endl;
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    return 0;
}