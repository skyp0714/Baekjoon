//
//  main.cpp
//  17406
//
//  Created by 박하늘 on 2021. 5. 4..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int map_og[50][50], n, m, map[50][50];
int eval();
void rotate(int, int, int);
int main(int argc, const char * argv[]) {
    int k, r, c, s;
    int min = 10000;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> map_og[i][j];
    vector<vector<int>> rot(k, vector<int>(3));
    vector<int> order;
    for(int i=0; i<k; i++){
        cin >> r >> c >> s;
        rot[i] = {r-1, c-1, s};
        order.push_back(i);
    }
    do{
        memcpy(map, map_og, sizeof(map));
        for(int i=0; i<k; i++){
            rotate(rot[order[i]][0], rot[order[i]][1], rot[order[i]][2]);
        }
        int tmp = eval();
        if(min > tmp) min = tmp;
    }while(next_permutation(order.begin(), order.end()));
    cout << min;
    return 0;
}
int eval(){
    int min = 10000, sum;
    for(int i=0; i<n; i++){
        sum = 0;
        for(int j=0; j<m; j++){
            sum += map[i][j];
        }
        if(min > sum) min = sum;
    }
    return min;
}
void rotate(int r, int c, int s){
    int tmp;
    for(int i=1; i<=s; i++){
        tmp = map[r-i][c-i];
        for(int j=0; j<2*i; j++)   map[r-i+j][c-i] = map[r-i+j+1][c-i];
        for(int j=0; j<2*i; j++)   map[r+i][c-i+j] = map[r+i][c-i+j+1];
        for(int j=0; j<2*i; j++)   map[r+i-j][c+i] = map[r+i-j-1][c+i];
        for(int j=0; j<2*i; j++)   map[r-i][c+i-j] = map[r-i][c+i-j-1];
        map[r-i][c-i+1] = tmp;
    }
    return;
}
