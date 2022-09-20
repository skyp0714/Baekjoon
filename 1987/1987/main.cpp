//
//  main.cpp
//  1987
//
//  Created by 박하늘 on 2021. 4. 17..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
char map[21][21];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool chk1[30], chk2[21][21];
int r, c;
int go(int, int);
bool check(int nx, int ny);
int main(int argc, const char * argv[]) {
    cin >> r >> c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> map[i][j];
        }
    }
    cout << go(0,0);
    
    return 0;
}
bool check(int x, int y){
    if(x>=0 && x<r && y>=0 && y<c)
        if(!chk1[map[x][y]-'A'] && !chk2[x][y])
            return true;
    return false;
}
int go(int x, int y){
    chk1[map[x][y] - 'A'] = true;
    chk2[x][y] = true;
    int nx, ny, temp = 0, max = 0;
    for(int i=0; i<4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if(check(nx, ny))
            temp = go(nx, ny);
        if(temp > max) max = temp;
    }
    chk1[map[x][y] - 'A'] = false;
    chk2[x][y] = false;
    return max + 1;
}
