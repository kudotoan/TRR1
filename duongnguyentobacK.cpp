#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n, k, a[100],s[100],ok=0;

void khoitao() {
    for (int i=1; i<=n; i++) {
        a[i]=i;
    }
}

bool snt(int a) {
    if (a<2) return false;
    for (int i=2; i<=sqrt(a); i++) {
        if (a%i==0) return false;
    }
    return true;
}

bool check() {
    for (int i=1; i<=n-k+1; i++) {
        int sum=0;
        for (int j=i; j<=i+k-1; j++) sum+=s[a[j]];
        if (!snt(sum)) return false;
    }
    return true;
}

void print() {
    for (int i=1; i<=n; i++) {
        cout << s[a[i]] << " ";
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
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    khoitao();
    while (!ok) {
        if (check()) print();
        sinh();
    }
    return 0;
}