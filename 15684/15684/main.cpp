//
//  main.cpp
//  15684
//
//  Created by 박하늘 on 2021. 5. 8..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int map[30][10], n, m ,h;
int go(int, int, int);
bool check();
int result(int);
bool inside(int x, int y){
    return x>=0 && x<h && y>=0 && y<n;
}
int main(int argc, const char * argv[]) {
    cin >> n >> m >> h;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = 1;
        map[a-1][b] = -1;
    }
    int ans = go(0, 0, -1);
    cout << ans;
    return 0;
}
int result(int y){
    int x = 0;
    while(inside(x, y)){
        if(map[x][y] == 0){
            x++;
        }else{
            y += map[x][y]; x++;
        }
    }
    return y;
}
bool check(){
    for(int i=0; i<n; i++){
        if(result(i) != i) return false;
    }
    return true;
}
int go(int cur, int x, int y){
    int i, j, min = 5;
    if(check()) return cur;
    if(cur >= 3) return -1;
    for(i=x; i<h; i++){
        j = i==x ? y+1 : 0;
        for(;j<n-1; j++){
            if(map[i][j] == 0 && map[i][j+1] == 0){
                map[i][j] = 1;
                map[i][j+1] = -1;
                int tmp = go(cur+1, i, j);
                if(tmp>=0 && tmp < min) min = tmp;
                map[i][j] = 0;
                map[i][j+1] = 0;
            }
        }
    }
    if(min == 5) min = -1;
    return min;
}
