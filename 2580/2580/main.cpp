//
//  main.cpp
//  2580
//
//  Created by 박하늘 on 2021. 4. 12..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int s[9][9];
bool c1[9][10], c2[9][10], c3[9][10];
void go(int);
int main(int argc, const char * argv[]) {
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> s[i][j];
            if(s[i][j]){
                c1[i][s[i][j]] = true;
                c2[j][s[i][j]] = true;
                c3[3 * (i/3) + (j/3)][s[i][j]] = true;
            }
        }
    }
    go(0);
    return 0;
}
void go(int z){
    if(z == 81){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                cout << s[i][j] << " ";
            }
            cout << '\n';
        }
        exit(0);
    }
    int x = z / 9, y = z % 9;
    if(s[x][y]){
        go(z+1);
    }else{
        for(int i=1; i<=9; i++){
            if(c1[x][i]) continue;
            if(c2[y][i]) continue;
            if(c3[3 * (x/3) + (y/3)][i]) continue;
            s[x][y] = i;
            c1[x][i] = true;
            c2[y][i] = true;
            c3[3 * (x/3) + (y/3)][i] = true;
            go(z+1);
            s[x][y] = 0;
            c1[x][i] = false;
            c2[y][i] = false;
            c3[3 * (x/3) + (y/3)][i] = false;
        }
    }
    return;
}
