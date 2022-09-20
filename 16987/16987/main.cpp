//
//  main.cpp
//  16987
//
//  Created by 박하늘 on 2021. 5. 6..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
int n, s[8], w[8];
bool chk[8];
int go(int);
void collision(int x, int y);
void recover(int x, int y);
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> s[i] >> w[i];
    cout << go(0);
    return 0;
}
void collision(int x, int y){
    s[x] -= w[y];
    s[y] -= w[x];
    if(s[x] <= 0)   chk[x] = true;
    if(s[y] <= 0)   chk[y] = true;
    return;
}
void recover(int x, int y){
    if(s[x] <= 0)   chk[x] = false;
    if(s[y] <= 0)   chk[y] = false;
    s[x] += w[y];
    s[y] += w[x];
    return;
}
int go(int idx){
    if(idx == n){
        int cnt = 0;
        for(int i=0; i<n; i++)
            if(chk[i]) cnt++;
        return cnt;
    }
    if(chk[idx]) return go(idx+1);
    int max = -1, tmp;
    for(int i=0; i<n; i++){
        if(i == idx || chk[i]) continue;
        collision(idx, i);
        tmp = go(idx+1);
        if(tmp > max) max = tmp;
        recover(idx, i);
    }
    if(max == -1) return go(n);
    return max;
}
