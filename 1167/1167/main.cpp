//
//  main.cpp
//  1167
//
//  Created by 박하늘 on 2021. 4. 4..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define max 100001
int n, dist[max], chk[max];
vector<pair<int, int>> p[max];
int bfs(int);
int diam();
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a;
        while(1){
            cin >> b;
            if(b == -1) break;
            cin >> c;
            p[a].push_back(make_pair(b, c));
        }
    }
    cout << diam();
    return 0;
}
int diam(){
    int x = bfs(1);
    x = bfs(x);
    return dist[x];
}
int bfs(int x){
    for(int i = 0 ;i<=n; i++){
        chk[i] = 0;
        dist[i] = 0;
    }
    queue<int> q;
    q.push(x);
    chk[x] = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(pair<int, int> y : p[x]){
            if(!chk[y.first]){
                q.push(y.first);
                dist[y.first] = dist[x] + y.second;
                chk[y.first] = 1;
            }
        }
    }
    int m = -1;
    for(int i=1; i<=n; i++){
        if(m < dist[i]){
            m = dist[i];
            x = i;
        }
    }
    return x;
}
