//
//  main.cpp
//  13549
//
//  Created by 박하늘 on 2021. 4. 4..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

#define max 100000 + 10
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
    if(x>=0 && x<max){
        if(chk[x] == 0) return true;
    }
    return false;
}
int bfs(int x, int goal){
    deque<int> q;
    q.push_back(x);
    chk[x] = 1;
    if(2 * x <max){
        q.push_back(2 * x);
        chk[2 * x] = 1;
    }
    while(!q.empty()){
        x = q.front();
        q.pop_front();
        if(x == goal) return dist[x];
        int nx[2];
        nx[0] = x - 1; nx[1] = x + 1;
        if(go(2*x)){
            q.push_front(2 * x);
            chk[2 * x] = 1;
            dist[2 * x] = dist[x];
        }
        for(int i=0; i<2; i++){
            if(go(nx[i])){
                q.push_back(nx[i]);
                chk[nx[i]] = 1;
                dist[nx[i]] = dist[x] + 1;
            }
        }
    }
    return 0;
}

