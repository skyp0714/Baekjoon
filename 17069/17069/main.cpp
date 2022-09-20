//
//  main.cpp
//  17069
//
//  Created by 박하늘 on 2021. 5. 5..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#define ll long long
using namespace std;
vector<vector<int>> ns(3);
void init();
ll d[32][32][3];
ll map[32][32], n, dx[3] = {0, 1, 1}, dy[3] = {1, 0, 1};
ll go(int x, int y, int status);
bool isinside(int x, int y){
    return x>=0 && x<n && y>=0 && y<n;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    init();
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> map[i][j];
    
    cout << go(0,0,0);
    return 0;
}
void init(){
    vector<int> a;
    a = {0, 2};
    ns[0] = a;
    a = {1, 2};
    ns[1] = a;
    a = {0, 1, 2};
    ns[2] = a;
}
ll go(int x, int y, int status){
    ll sum = 0;
    int nx = x + dx[status], ny = y + dy[status];
    if(!isinside(nx, ny)) return 0;
    else if(nx == n-1 && ny == n-1) return 1;
    if(d[x][y][status]){
        return d[x][y][status];
    }else{
        for(int i=0; i<ns[status].size(); i++){
            if(ns[status][i] == 0 && isinside(nx, ny+1)){
                if(map[nx][ny+1] == 1) continue;
                sum += go(nx, ny, ns[status][i]);
            }
            if(ns[status][i] == 1 && isinside(nx+1, ny)){
                if(map[nx+1][ny] == 1) continue;
                sum += go(nx, ny, ns[status][i]);
            }
            if(ns[status][i] == 2 && isinside(nx+1, ny+1)){
                if(map[nx][ny+1] == 1 || map[nx+1][ny] == 1 || map[nx+1][ny+1] == 1) continue;
                sum += go(nx, ny, ns[status][i]);
            }
        }
    }
    d[x][y][status] = sum;
    return sum;
}
