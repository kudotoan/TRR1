#include <iostream>
using namespace std;
int n,k,a[1000]={}, A[100000];
int ok=0;
void khoitao() {
    for (int i=1; i<=n; i++) {
        a[i]=0;
    }
}

bool check() {
    int cnt=0;
    for (int i=1; i<=n; i++) cnt+=a[i]; 
    if (cnt!=k) return false;
    int nho=-1e9;
    int i=1;
    while (i<=n) {
        if (a[i]!=1) {
            i++;
            continue;
        }
        if (nho<A[i]) nho=A[i]; else return false;
        i++;
    }
    return true;
}

void print() {
    for (int i=1; i<=n; i++)
        if (a[i]==1) cout << A[i] << " ";
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
    for (int i=1; i<=n; i++) {
        cin >> A[i];
    }
    khoitao();
    while (!ok) {
        if (check()) print();
        sinh();
    }
    return 0;
}