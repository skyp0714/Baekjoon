//
//  main.cpp
//  1086
//
//  Created by SKY on 2022/01/05.
//

#include <iostream>
#include <cstring>
#define MAX (1<<16)
using namespace std;
long long dp[MAX][100];
bool used[MAX];
int rem[15], len[15], n, k, moddec[51];
string temp[15];
int stor(string a);
long long fact(int a){
    return (a==1) ? 1 : fact(a-1)*a;
}
long long gcd(long long a, long long b){
    return (b%a==0) ? a : gcd(b%a,a);
}
void init();
int main() {
    init();
    int i;
    dp[0][0] = 1;
    for(i=0;i<(1<<n)-1;i++){
        for(int j=0; j<k; j++){
            if(!dp[i][j]) continue;
            for(int p=0;p<n;p++){
                if(((1<<p)&i) != 0) continue;
                int r = (j*moddec[len[p]] + rem[p])%k;
                dp[i+(1<<p)][r] += dp[i][j];
            }
        }
    }
    if(!dp[i][0]){
        cout << "0/1";
        return 0;
    }
    long long g = gcd(dp[i][0], fact(n));
    cout << dp[i][0]/g << '/' << fact(n)/g;
    return 0;
}
void init(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> temp[i];
        len[i] = temp[i].length();
    }
    cin >> k;
    for(int i=0; i<n;i++){
        rem[i] = stor(temp[i]);
    }
    moddec[0] = 1;
    for(int i=1; i<51;i++){
        moddec[i] = (moddec[i-1]*10)%k;
    }
}
int stor(string a){
    int remainder=0;
    for(int i=0; i<a.length();i++){
        remainder = (remainder*10 + (a[i]-'0'))%k;
    }
    return remainder;
}
