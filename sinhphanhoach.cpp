#include <iostream>
using namespace std;
int n,ok=0,cnt,a[100];

void khoitao() {
    cnt=1;
    a[1]=n;
}

void print() {
    for (int i=1; i<=cnt; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void sinh() {
    int i=cnt;
    while (a[i]==1) i--;
    if (i==0) ok=1; else {
        a[i]--;
        int thuong=(cnt-i+1)/a[i];
        int du=(cnt-i+1)%a[i];
        cnt=i;
        for (int j=1; j<=thuong; j++) {
            a[i+j]=a[i];
            cnt++;
        }
        if (du!=0) a[++cnt]=du;

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