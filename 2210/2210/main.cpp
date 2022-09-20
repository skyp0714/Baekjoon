//
//  main.cpp
//  2210
//
//  Created by 박하늘 on 2021. 5. 2..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
bool chk[1000000];
int map[5][5], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, cnt;
void go(int, int, int, int);
bool isin(int x, int y){
    return x>=0 && x<5 && y>=0 && y<5;
}
int main(int argc, const char * argv[]) {
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> map[i][j];
            
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            go(i, j, 0, 0);
    
    cout << cnt;
    return 0;
}
void go(int x, int y, int len, int num){
    if(len >= 6){
        if(!chk[num]){
            cnt++;
            chk[num] = true;
        }
        return;
    }
    for(int i=0; i<4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if(isin(nx, ny)) go(nx, ny, len+1, num*10 + map[nx][ny]);
    }
    return;
}
