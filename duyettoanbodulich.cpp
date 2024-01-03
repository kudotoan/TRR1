#include <iostream>
#include <cstring>
using namespace std;
int n, a[100]; int check[100];
int ans[100]={},vMin=1e9;
int v[100][100];
void update() {
    int sum=v[1][a[1]];
    for (int i=1; i<n-1; i++) {
        sum+=v[a[i]][a[i+1]];
    }
    sum+=v[a[n-1]][1];
    if (vMin>sum) {
        vMin=sum;
        for (int i=2; i<=n; i++) {
            ans[i]=a[i-1];
        }
    }
}

void Try(int i) {
    for (int j=2; j<=n; j++) {
        if (!check[j]) {
            a[i]=j;
            check[j]=1;
            if (i==n-1) update(); else {
                Try(i+1);
            }
            check[j]=0;
        }
    }
}

int main() {
    cin >> n;
    ans[1]=1;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i==j) {
                v[i][j]=0;
                continue;
            }
            cin >> v[i][j];
        }
    }
    // for (int i=1; i<=n; i++) {
    //     for (int j=1; j<=n; j++) {
    //         cout << v[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    memset(check,0,sizeof(check));
    Try(1);
    cout << vMin << endl;
    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[1] << endl;
    return 0;
}