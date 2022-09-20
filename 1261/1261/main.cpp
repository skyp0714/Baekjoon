//
//  main.cpp
//  1261
//
//  Created by 박하늘 on 2021. 4. 4..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

#define max 100
#define dir 4
#define x first
#define y second
int cnt[max][max], map[max][max];
int bfs(pair<int, int>, pair<int, int>);
bool go(pair<int, int>);
int dx[dir] = {0, 0, 1, -1}, dy[dir] = {1, -1, 0, 0};
int n, m;
int main(int argc, const char * argv[]) {
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
            cnt[i][j] = -1;
        }
    }
    int ans = bfs(make_pair(0, 0), make_pair(n-1, m-1));
    cout << ans;
    return 0;
}
bool go(pair<int, int> p){
    if(p.x>=0 && p.x<n && p.y>=0 && p.y<m){
        if(cnt[p.x][p.y] == -1) return true;
    }
    return false;
}
int bfs(pair<int, int> p, pair<int, int> goal){
    deque<pair<int, int>> q;
    q.push_back(p);
    cnt[p.x][p.y] = 0;
    while(!q.empty()){
        p = q.front();
        q.pop_front();
        if(p == goal) return cnt[p.x][p.y];
        pair<int, int> next;
        for(int i=0; i<dir; i++){
            next = make_pair(p.x + dx[i], p.y + dy[i]);
            if(go(next)){
                if(map[next.x][next.y]){
                    q.push_back(next);
                    cnt[next.x][next.y] = cnt[p.x][p.y] + 1;
                }
                else{
                    q.push_front(next);
                    cnt[next.x][next.y] = cnt[p.x][p.y];
                }
                
            }
        }
    }
    return 0;
}
