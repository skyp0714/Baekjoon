//
//  main.cpp
//  2146
//
//  Created by 박하늘 on 2021. 4. 2..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define max 100
#define dir 4
int chk[max][max], dist[max][max], g[max][max], n, num = 0;
int dx[dir] = {0, 0, 1, -1}, dy[dir] = {1, -1, 0, 0};
bool isInside(int, int);
void color(int, int);
void printMap(int(*map)[max]);
int solve();
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> g[i][j];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(g[i][j])color(i, j);
    int min = solve();
    cout << min;
    return 0;
}
bool isInside(int x, int y){
    if(x>=0 && x<n && y>=0 && y<n)
        return true;
    return false;
}
void color(int x, int y){
    if(chk[x][y]) return;
    chk[x][y] = 1;
    num++;
    queue<int> qx, qy;
    qx.push(x); qy.push(y);
    while(!qx.empty()){
        x = qx.front(); y = qy.front();
        g[x][y] = num;
        qx.pop(); qy.pop();
        for(int i=0; i<dir; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isInside(nx, ny) && g[nx][ny] && chk[nx][ny]==0){
                qx.push(nx); qy.push(ny);
                chk[nx][ny] = 1;
            }
        }
    }
    return;
}
void printMap(int (*map)[max]){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << map[i][j] << ' ';
        }
        cout<<'\n';
    }
}
int solve(){
    queue<int> qx, qy;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(g[i][j]){
                qx.push(i); qy.push(j);
            }
        }
    }
    int x, y, min = 2*max;
    while(!qx.empty()){
        x = qx.front(); y = qy.front();
        qx.pop(); qy.pop();
        for(int i=0; i<dir; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(isInside(nx, ny)){
                if(g[nx][ny]){
                    if(g[x][y] != g[nx][ny])
                        if(min > dist[x][y] + dist[nx][ny])
                            min = dist[x][y] + dist[nx][ny];
                }else{
                qx.push(nx); qy.push(ny);
                g[nx][ny] = g[x][y];
                dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
    return min;
}
