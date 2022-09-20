//
//  main.cpp
//  16953
//
//  Created by 박하늘 on 2021. 5. 9..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#define ll long long
using namespace std;
ll a, b;
ll go(ll a, ll num);
ll min(ll a, ll b){
    return a>b ? b : a;
}
int main(int argc, const char * argv[]) {
    cin >> a >> b;
    ll ans = go(a,1);
    if(ans == 50) ans = -1;
    cout << ans;
    return 0;
}
ll go(ll a, ll num){
    if(a > b) return 50;
    if(a == b) return num;
    int ans = 50;
    ans = min(ans, go(2*a, num+1));
    ans = min(ans, go(10*a + 1, num+1));
    if(ans == 50) return 50;
    return ans;
}
