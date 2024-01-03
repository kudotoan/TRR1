#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, a[100][100],x[100]={};
int sumMax=-1e9;
int use[100]={};
int ans[100][100],d=0;
void update() {
    memset(use,0,sizeof(use));
    int sum=0;
    for (int i=1; i<=n; i++) {
        if (x[i]==1) {
            for (int j=1; j<=m; j++) {
                if (a[i][j]==1 && use[j]==1) return;
                sum+=a[i][j];
                if (a[i][j]==1) use[j]=1;
            }
        }
    }
    cout << endl;
    if (sum>sumMax) {
        sumMax=sum;
        d=0;
        for (int i=1; i<=n; i++) {
            ans[d][i]=x[i];
        }
    } else if (sum==sumMax) {
        d++;
        for (int i=1; i<=n; i++) {
            ans[d][i]=x[i];
        }
    }
}

void Try(int i) {
    for (int j=0; j<=1; j++) {
        x[i]=j;
        if (i==n) update(); else Try(i+1);
    }
    
}

int main() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << sumMax << endl;
    for (int i=0; i<=d; i++) {
        for (int j=1; j<=n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}