#include <iostream>
using namespace std;

int n,a[100][100],x[100],fMin=1e9,ans[100][100],c=1e9;
int use[100]={0};
int fNow=0;
int d=0;
void update() {
    if (fNow<fMin) {
        fMin=fNow+a[x[n]][1];
        d=0;
        ans[d][1]=1;
        for (int i=2; i<=n; i++) {
            ans[d][i]=x[i];
        }
        ans[d][n+1]=1;
    }
    if (fNow==fMin) {
        d++;
        ans[d][1]=1;
        for (int i=2; i<=n; i++) {
            ans[d][i]=x[i];
        }
        ans[d][n+1]=1;
    }
}

void Try(int i) {
    for (int j=2; j<=n; j++) {
        if (!use[j]) {
            x[i]=j; use[j]=1;
            fNow+=a[x[i-1]][x[i]];
            if (i==n) update(); else if (fNow+(n-i+1)*c<=fMin) {
                    Try(i+1);
            }
            use[j]=0;
            fNow-=a[x[i-1]][x[i]];
        }
    }
}

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> a[i][j];
            if (a[i][j]<c) c=a[i][j];
        }
    }
    x[1]=1;
    Try(2);
    cout << fMin << endl;
    for (int i=0; i<=d; i++) {
        for (int j=1; j<=n+1; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}