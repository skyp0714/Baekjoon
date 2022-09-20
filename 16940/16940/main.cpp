//
//  main.cpp
//  16940
//
//  Created by 박하늘 on 2021. 4. 2..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define max 100010

vector<int> p[max];
int chk[max], order[max], n, par[max];
int bfs(int n);
int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=1; i<n; i++){
        int a,b;
        cin >> a >> b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    for(int i=0; i<n; i++) cin >> order[i+1];
    int ans = bfs(1);
    cout << ans;
    return 0;
}

int bfs(int x){
    queue<int> q;
    chk[x] = 1;
    int m = 1;
    q.push(x);
    for(int i=1; i<=n; i++){
        if(q.empty()) return false;
        int cnt = 0;
        x = q.front();
        q.pop();
        for(int y: p[x]){
            if(!chk[y]){
            par[y] = x;
            cnt++;
            }
        }
        for(int j=1; j<=cnt; j++){
            if(m+j>n || par[order[m+j]]!=x) return false;
            chk[order[m+j]] = 1;
            q.push(order[m+j]);
        }
        m += cnt;
    }
    return true;
}
