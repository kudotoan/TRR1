#include <iostream>
#include <cmath>
using namespace std;
int check(long long n) {
    long long sum=1;
    for (int i=2; i<=sqrt(n); i++) {
        if (n%i==0) {
            sum+=i;
            sum+=n/i;
        }
    }
    if (sum==n) return 1;
    return 0;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        cout << check(n) << endl;
    }
    return 0;
} 