#include <iostream>
#include <cstring>
using namespace std;
int n, a[100]={},cot[100]={}, cx[100]={}, cn[100]={}, kq[100][100];

void print() {
    memset(kq,0,sizeof(kq));
    for (int i=1; i<=n; i++) {
        kq[i][a[i]]++;
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cout << kq[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Try(int i) {
    for (int j=1; j<=n; j++) {
        if (!cot[j] && !cx[i-j+n] && !cn[i+j-1]) {
            a[i]=j;
            cot[j]=cx[i-j+n]=cn[i+j-1]=1;
            if (i==n) print(); else {
                Try(i+1);
            }
            cot[j]=cx[i-j+n]=cn[i+j-1]=0;
        }
    }
}

int main() {
    cin >> n;
    Try(1);
    return 0;
}