#include <iostream>
using namespace std;
int n,a[1000]={};
int ok=0;
void khoitao() {
    for (int i=1; i<=n; i++) {
        a[i]=0;
    }
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
    cin >> n;
    khoitao();
    while (!ok) {
        print();
        sinh();
    }
    return 0;
}