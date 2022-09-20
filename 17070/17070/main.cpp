//
//  main.cpp
//  17070
//
//  Created by 박하늘 on 2021. 5. 5..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> ns(3);
void init();
int map[16][16], n, dx[3] = {0, 1, 1}, dy[3] = {1, 0, 1};
int go(int x, int y, int status);
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
int go(int x, int y, int status){
    int sum = 0;
    int nx = x + dx[status], ny = y + dy[status];
    if(nx == n-1 && ny == n-1)  return 1;
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
    return sum;
}
