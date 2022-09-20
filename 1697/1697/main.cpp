//
//  main.cpp
//  1697
//
//  Created by 박하늘 on 2021. 4. 3..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

#define max 100000 + 1
int chk[max], dist[max];
int bfs(int, int);
bool go(int);
int main(int argc, const char * argv[]) {
    int n,k;
    cin >> n >> k;
    int ans = bfs(n, k);
    cout << ans;
    return 0;
}
bool go(int x){
    if(x>=0 && x<max && chk[x]==0) return true;
    return false;
}
int bfs(int x, int goal){
    queue<int> q;
    q.push(x);
    chk[x] = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        if(x == goal) return dist[x];
        int nx[3];
        nx[0] = x - 1; nx[1] = x + 1; nx[2] = 2 * x;
        for(int i=0; i<3; i++){
            if(go(nx[i])){
                q.push(nx[i]);
                chk[nx[i]] = 1;
                dist[nx[i]] = dist[x] + 1;
            }
        }
    }
    return 0;
}
