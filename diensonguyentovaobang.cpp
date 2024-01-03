#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int res;
bool a[100500];
int s[6][6];

int get1(int n) {
    return n/10000;
}

int get2(int n) {
    return (n % 10000)/1000;
}

int get3(int n) {
    return (n % 1000)/100;
}

int get4(int n) {
    return (n % 100)/10;
}

int get5(int n) {
    return n % 10;
}

void sang() {
    memset(a,true,sizeof(a));
    a[0]=false;
    a[1]=false;
    for (int i=2; i<=sqrt(100000); i++) {
        if (a[i]) {
            for (int j=i*i; j<=100000; j+=i) {
                a[j]=false;
            }
        }
    }
    for (int i=10000; i<100000; i++) {
        if (get1(i)+get2(i)+get3(i)+get4(i)+get5(i)!=res) a[i]=false;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> res;
    sang();
    for (int i=10000; i<100000; i++) {
        int ok=1;
        if (a[i] && get1(i)!=0 && get2(i)!=0 && get3(i)!=0 && get4(i)!=0 && get5(i)!=0) {
            s[0][0]=get1(i);
            s[0][1]=get2(i);
            s[0][2]=get3(i);
            s[0][3]=get4(i);
            s[0][4]=get5(i);
            for (int j=s[0][0]*10000; j<(s[0][0]+1)*10000; j++) {
                ok=0;
                if (a[j] && get1(j)!=0 && get2(j)!=0 && get3(j)!=0 && get4(j)!=0 && get5(j)!=0) {
                    s[1][0]=get2(j);
                    s[2][0]=get3(j);
                    s[3][0]=get4(j);
                    s[4][0]=get5(j);
                    ok=1;
                    for (int k=s[4][0]*10000; k<(s[4][0]+1)*10000; k++) {
                        ok=0;
                        if (a[k] && s[0][4]==get5(k)) {
                            s[3][1]=get2(k);
                            s[2][2]=get3(k);
                            s[1][3]=get4(k);
                            ok=1;
                            for (int l=s[1][0]*10000; l<(s[1][0]+1)*10000; l++) {
                                ok=0;
                                if (a[l] && s[1][3]==get4(l)) {
                                    s[1][1]=get2(l);
                                    s[1][2]=get3(l);
                                    s[1][4]=get5(l);
                                    ok=1;
                                    for (int m=s[0][1]*10000+s[1][1]*1000; m<s[0][1]*10000+(s[1][1]+1)*1000; m++) {
                                        ok=0;
                                        if (a[m] && get4(m)==s[3][1]) {
                                            s[2][1]=get3(m);
                                            s[4][1]=get5(m);
                                            ok=1;
                                            for (int aa=s[2][0]*10000+s[2][1]*1000+s[2][2]*100; aa<s[2][0]*10000+s[2][1]*1000+(s[2][2]+1)*100; aa++) {
                                                ok=0;
                                                if (a[aa]) {
                                                    s[2][3]=get4(aa);
                                                    s[2][4]=get5(aa);
                                                    ok=1;
                                                    for (int ab=s[0][2]*10000+s[1][2]*1000+s[2][2]*100; ab<s[0][2]*10000+s[1][2]*1000+(s[2][2]+1)*100; ab++) {
                                                        ok=0;
                                                        if (a[ab]) {
                                                            s[3][2]=get4(ab);
                                                            s[4][2]=get5(ab);
                                                            ok=1;
                                                            for (int ac=s[3][0]*10000+s[3][1]*1000+s[3][2]*100; ac<s[3][0]*10000+s[3][1]*1000+(s[3][2]+1)*100;ac++){
                                                                ok=0;
                                                                if (a[ac]) {
                                                                    s[3][3]=get4(ac);
                                                                    s[3][4]=get5(ac);
                                                                    ok=1;
                                                                    for (int ad=s[0][3]*10000+s[1][3]*1000+s[2][3]*100+s[3][3]*10; ad<s[0][3]*10000+s[1][3]*1000+s[2][3]*100+(s[3][3]+1)*10; ad++) {
                                                                        ok=0;
                                                                        if (a[ad]) {
                                                                            s[4][3]=get5(ad);
                                                                            ok=1;
                                                                            for (int ae=0; ae<9; ae++) {
                                                                                ok=0;
                                                                                int tmp1=s[4][0]*10000+s[4][1]*1000+s[4][2]*100+s[4][3]*10+ae;
                                                                                int tmp2=s[0][4]*10000+s[1][4]*1000+s[2][4]*100+s[3][4]*10+ae;
                                                                                int tmp3=s[0][0]*10000+s[1][1]*1000+s[2][2]*100+s[3][3]*10+ae;
                                                                                if (a[tmp1] && a[tmp2] && a[tmp3]) {
                                                                                    s[4][4]=ae;
                                                                                    for (int x=0; x<5; x++) {
                                                                                        for (int y=0; y<5; y++) {
                                                                                            cout << s[x][y];
                                                                                        }
                                                                                        cout << endl;
                                                                                    }
                                                                                    cout << endl;
                                                                                    ok=1;
                                                                                }
                                                                            }
                                                                            if (!ok) continue;
                                                                        }
                                                                    }
                                                                    if (!ok) continue;
                                                                }
                                                            }
                                                            if (!ok) continue;
                                                        }
                                                    }
                                                    if (!ok) continue;
                                                }
                                            }
                                        if (!ok) continue;
                                        }
                                    }
                                    if (!ok) continue;
                                }
                            }
                            if (!ok) continue;
                        }
                    }
                    if (!ok) continue;
                }
            }
            if (!ok) continue;
        } 
       

    }
	return 0;
}
