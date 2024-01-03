#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100],ok=0;

void khoitao() {
    for (int i=1; i<=n; i++) {
        a[i]=i;
    }
}

void print() {
    for (int i=1; i<=n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void sinh() {
    int i=n-1;
    while (a[i]>a[i+1])i--;
    if (i==0) ok=1; else {
        int j=n;
        while (a[j]<a[i]) j--;
        swap(a[i],a[j]);
        // sort(a+i+1, a+n+1);
        reverse(a+i+1,a+n+1);
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