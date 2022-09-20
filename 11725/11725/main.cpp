//
//  main.cpp
//  11725
//
//  Created by 박하늘 on 2021. 4. 4..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define max 100001
int n, par[max], chk[max];
vector<int> p[max];
void bfs(int);
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=1; i<n; i++){
        int a, b;
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    bfs(1);
    for(int i=2; i<=n; i++){
        cout << par[i] << '\n';
    }
    return 0;
}
void bfs(int x){
    queue<int> q;
    q.push(x);
    chk[x] = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int y : p[x]){
            if(!chk[y]){
                q.push(y);
                par[y] = x;
                chk[y] = 1;
            }
        }
    }
    return;
}
