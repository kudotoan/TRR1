#include <iostream>
using namespace std;
int n,k,a[1000]={};
int ok=0;
void khoitao() {
    for (int i=1; i<=n; i++) {
        a[i]=0;
    }
}

bool check() {
    int i=1;
    int cntA=0;
    while (i<=n) {
        int da=0;
        while (a[i]==1 && i<=n) {
            da++;
            i++;
        }
        i++;
        if (da==k) cntA++;
    }
    if (cntA==1) return true;
    return false;
}

void print() {
    for (int i=1; i<=n; i++)
        if (a[i]==1) cout << "A" << " "; else cout << "B" << " ";
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
    cin >> n >> k;
    khoitao();
    while (!ok) {
        if (check()) print();
        sinh();
    }
    return 0;
}