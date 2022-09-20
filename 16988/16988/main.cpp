//
//  main.cpp
//  16988
//
//  Created by 박하늘 on 2021. 5. 8..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int map[20][20], n, m, dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};
bool chk[20][20];
int find_group(int x, int y);
bool dead(int x, int y);
bool isinside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
int go(int x, int y);
vector<vector<int>> group;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int max = -1;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> map[i][j];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 2 && chk[i][j] == false){
                int num = find_group(i, j);
                vector<int> a = {i, j, num};
                group.push_back(a);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                int tmp = go(i, j);
                if(max < tmp) max = tmp;
                map[i][j] = 0;
            }
        }
    }
    cout << max;
    return 0;
}
int find_group(int x, int y){
    chk[x][y] = true;
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isinside(nx, ny)){
                if(map[nx][ny] == 2 && chk[nx][ny] == false){
                    q.push(make_pair(nx, ny));
                    cnt++;
                    chk[nx][ny] = true;
                }
            }
        }
    }
    return cnt;
}
int killed_num(){
    int sum = 0;
    for(auto g : group){
        if(dead(g[0], g[1])){
            sum += g[2];
        }
    }
    return sum;
}
bool dead(int x, int y){
    memset(chk, false, sizeof(chk));
    chk[x][y] = true;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isinside(nx, ny)){
                if(map[nx][ny] == 2 && chk[nx][ny] == false){
                    q.push(make_pair(nx, ny));
                    chk[nx][ny] = true;
                }else if(map[nx][ny] == 0){
                    return false;
                }
            }
        }
    }
    return true;
}
int go(int x, int y){
    int i, j, max = -1, tmp;
    for(i=x; i<n; i++){
        j = (i==x) ? y+1 : 0;
        for(; j<m; j++){
            if(map[i][j] == 0){
                map[i][j] = 1;
                tmp = killed_num();
                if(max < tmp) max = tmp;
                map[i][j] = 0;
            }
        }
    }
    return max;
}
