//
//  main.cpp
//  16197
//
//  Created by 박하늘 on 2021. 4. 11..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int n,m;
int isOut(int, int);
void go(int, int, int, int, int);
int minimum = 20, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
char map[22][22];
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    int x1=-1, x2, y1, y2;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
            if(map[i][j] == 'o'){
                if(x1==-1){
                    x1 = i; y1 = j;
                }else{
                    x2 = i; y2 = j;
                }
            }
        }
    }
    go(0, x1, y1, x2, y2);
    if(minimum == 20) minimum = -1;
    cout << minimum;
    return 0;
}
int isOut(int x, int y){
    if(x<=n && x>0 && y<=m && y>0) return 0;
    return 1;
}
void go(int cnt, int x1, int y1, int x2, int y2){
    if(cnt > 10){
        return;
    }
    int out = isOut(x1, y1) + isOut(x2, y2);
    if(out == 1){
        if(cnt < minimum) minimum = cnt;
        return;
    }else if(out == 2){
        return;
    }
    for(int i=0; i<4; i++){
        int nx1 = x1 + dx[i], ny1 = y1 + dy[i], nx2 = x2 + dx[i], ny2 = y2 + dy[i];
        if(map[nx1][ny1]=='#'){
            nx1 = x1; ny1 = y1;
        }
        if(map[nx2][ny2]=='#'){
            nx2 = x2; ny2 = y2;
        }
        go(cnt+1, nx1, ny1, nx2, ny2);
    }
    return;
}
