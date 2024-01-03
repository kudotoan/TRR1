#include <iostream>
using namespace std;
int n,k,ok=0, a[1000]={};
void khoitao() {  
    for (int i=1; i<=k; i++) a[i]=i;
}
void print() {
    for (int i=1; i<=k; i++) cout << a[i] << " ";
    cout << endl;
}

void sinh() {
    int i=k;
    while (a[i]==n-k+i) i--;
    if (i!=0) {
        a[i]++;
        for (int j=i+1; j<=k; j++) a[j]=a[j-1]+1;
    } else ok=1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    cin >> n >> k;
    khoitao(); 
    while (!ok) { 
        print(); 
        sinh();
    }
    return 0;
}