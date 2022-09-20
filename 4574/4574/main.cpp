//
//  main.cpp
//  4574
//
//  Created by 박하늘 on 2021. 4. 12..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
int s[9][9], dx[2] = {0,1}, dy[2] = {1,0};
bool c1[9][10], c2[9][10], c3[9][10], domino[10][10];
bool go(int);
int box(int x, int y){
    return 3 * (x/3) + (y/3);
}
void check(int x, int y, int num1, bool tf, int num2){
    s[x][y] = num2;
    c1[x][num1] = tf;
    c2[y][num1] = tf;
    c3[box(x, y)][num1] = tf;
    return;
}
bool can(int x, int y, int num){
    return c1[x][num] == false && c2[y][num] == false && c3[box(x,y)][num] == false;
}
bool out_range(int x, int y){
    if(x>=0 && x<9 && y>=0 && y<9) return false;
    return true;
}
int main(int argc, const char * argv[]) {
    int m, tc = 1;
    int n1, n2, x1, y1, x2, y2;
    string s1, s2;
    while(true){
        memset(s, 0, sizeof(s));
        memset(c1, false, sizeof(c1));
        memset(c2, false, sizeof(c2));
        memset(c3, false, sizeof(c3));
        memset(domino, false, sizeof(domino));
        cin >> m;
        if(m == 0) break;
        for(int i=0; i<m; i++){
            cin >> n1 >> s1 >> n2 >> s2;
            x1 = s1[0] - 'A'; y1 = s1[1] - '1';
            x2 = s2[0] - 'A'; y2 = s2[1] - '1';
            check(x1, y1, n1, true, n1);
            check(x2, y2, n2, true, n2);
            domino[n1][n2] = domino[n2][n1] = true;
        }
        for(int i=1; i<10; i++){
            cin >> s1;
            x1 = s1[0] - 'A'; y1 = s1[1] - '1';
            check(x1, y1, i, true, i);
        }
        cout << "Puzzle " << tc << '\n';
        go(0);
        tc++;
    }
    return 0;
}
bool go(int z){
    if(z == 81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << s[i][j];
            }
            cout << '\n';
        }
        return true;
    }
    int x = z / 9, y = z % 9;
    if(s[x][y]){
        return go(z+1);
    }else{
        int nx, ny;
        for(int k=0; k<2; k++){
            nx = x + dx[k];
            ny = y + dy[k];
            if(out_range(nx, ny)) continue;
            if(s[nx][ny]) continue;
            for(int i=1; i<10; i++){
                for(int j=1; j<10; j++){
                    if(i == j) continue;
                    if(domino[i][j]) continue;
                    if(can(x,y,i) && can(nx,ny,j)){
                        check(x, y, i, true, i);
                        check(nx, ny, j, true, j);
                        domino[i][j] = domino[j][i] = true;
                        if(go(z+1)){
                            return true;
                        }
                        check(x, y, i, false, 0);
                        check(nx, ny, j, false, 0);
                        domino[i][j] = domino[j][i] = false;
                    }
                }
            }
        }
    }
    return false;
}
