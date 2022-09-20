//
//  main.cpp
//  3019
//
//  Created by 박하늘 on 2021. 5. 2..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> tetris[7];
int field[100];
void init();
int main(int argc, const char * argv[]) {
    init();
    int c, p, cnt = 0, i, j, k;
    cin >> c >> p;
    p--;
    for(int i=0; i<c; i++)
        cin >> field[i];
    for(i=0; i<c; i++){
        for(j=0; j<tetris[p].size(); j++){
            for(k=0; k<tetris[p][j].size(); k++){
                if(i + k >= c) break;
                if(field[i + k] != field[i] + tetris[p][j][k]) break;
            }
            if(k == tetris[p][j].size()) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
void init(){
    vector<int> a;
    a = {0};
    tetris[0].push_back(a);
    a = {0, 0, 0, 0};
    tetris[0].push_back(a);
    a = {0, 0};
    tetris[1].push_back(a);
    a = {0, 0, 1};
    tetris[2].push_back(a);
    a = {0, -1};
    tetris[2].push_back(a);
    a = {0, -1, -1};
    tetris[3].push_back(a);
    a = {0, 1};
    tetris[3].push_back(a);
    a = {0, 0, 0};
    tetris[4].push_back(a);
    a = {0, -1, 0};
    tetris[4].push_back(a);
    a = {0, -1};
    tetris[4].push_back(a);
    a = {0, 1};
    tetris[4].push_back(a);
    a = {0, 0, 0};
    tetris[5].push_back(a);
    a = {0, 0};
    tetris[5].push_back(a);
    a = {0, 1, 1};
    tetris[5].push_back(a);
    a = {0, -2};
    tetris[5].push_back(a);
    a = {0, 0, 0};
    tetris[6].push_back(a);
    a = {0, 0};
    tetris[6].push_back(a);
    a = {0, 0, -1};
    tetris[6].push_back(a);
    a = {0, 2};
    tetris[6].push_back(a);
    return;
}
