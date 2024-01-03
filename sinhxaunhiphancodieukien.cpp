#include <iostream>
using namespace std;
int n,m,k,a[1000]={};
int ok=0;
void khoitao() {
    for (int i=1; i<=n; i++) {
        a[i]=0;
    }
}

bool check() {
    int i=1;
    int cnt0=0,cnt1=0;
    while (i<=n) {
        int d0=0;
        while (a[i]==0 && i<=n) {
            d0++;
            i++;
        }
        if (d0==k) cnt0++;
        int d1=0;
        while (a[i]==1 && i<=n) {
            d1++;
            i++;
        }
        if (d1==m) cnt1++;
    }
    // cout << cnt0 << " " << cnt1 << endl;
    if (cnt0==1 && cnt1==1) return true;
    return false;
}

void print() {
    for (int i=1; i<=n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void sinh () {
    int i=n;
    while (a[i]==1) i--;
    if (i==0) {
        ok=1;
        return;
    }
    for (i; i<=n; i++) {
        a[i]=1-a[i];
    }
}

int main() {
    cin >> n >> m >> k;
    khoitao();
    while (!ok) {
        if (check()) print();
        sinh();
    }
    return 0;
}