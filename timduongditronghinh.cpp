#include <iostream>
using namespace std;
int n,N,M,a[1000]={};
int ok=0;
void khoitao() {
    for (int i=1; i<=n; i++) {
        a[i]=0;
    }
}

bool check() {
    int sum=0;
    for (int i=1; i<=n; i++) {
        sum+=a[i];
    }
    return sum==N;
}

void print() {
    int d1=1, d0=1;
    for (int i=1; i<=n; i++) {
        if (a[i]==1) cout << "V" << d1++ << " "; else {
            cout << "H" << d0++ << " ";
        }
    }
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
    cin >> N >> M;
    n=N+M;
    khoitao();
    while (!ok) {
        if (check()) print();
        sinh();
    }
    return 0;
}