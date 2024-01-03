#include <iostream>
#include <cstring>
using namespace std;
int n, a[100],check[100]={};
int ans[100][100],Tmin=1e9,d=0;
int v[100][100];

void update() {
    int sum=0;
    for (int i=1; i<=n; i++) {
        sum+=v[i][a[i]];
    }
    if (sum<Tmin) {
        Tmin=sum;
        d=0;
        for (int i=1; i<=n; i++) {
            ans[d][i]=a[i];
        }
    } else if (sum==Tmin) {
        d++;
        for (int i=1; i<=n; i++) {
            ans[d][i]=a[i];
        }
    }
}

void Try(int i) {
    for (int j=1; j<=n; j++) {
        if (!check[j]) {
            a[i]=j;
            check[j]=1;
            if (i==n) update(); else {
                Try(i+1);
            }
            check[j]=0;
        }
    }
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> v[i][j];
        }
    }
    Try(1);
    cout << Tmin << endl;
    for (int i=0; i<=d; i++) {
        for (int j=1; j<=n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}