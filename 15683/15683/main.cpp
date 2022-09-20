//
//  main.cpp
//  15683
//
//  Created by 박하늘 on 2021. 4. 24..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> dir[5];
pair<int, int> dxy[4] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0), make_pair(0, -1)};
vector<vector<int>> cctv;
int map[10][10], n, m;
int go(int, int a[][10]);
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    vector<int> d[5];
    d[0] = {0};
    d[1] = {0, 2};
    d[2] = {0, 1};
    d[3] = {0, 1 ,2};
    d[4] = {0, 1, 2, 3};
    int times[4] = {4, 2, 4, 4};
    for(int i=0; i<4; i++){
        for(int j=0; j<times[i]; j++){
            dir[i].push_back(d[i]);
            for(int k=0; k< d[i].size(); k++){
                d[i][k] = (d[i][k]+1) % 4;
            }
        }
    }
    dir[4].push_back(d[4]);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] > 0 && map[i][j] < 6){
                vector<int> a = {map[i][j], i, j};
                cctv.push_back(a);
            }
        }
    }
    cout << go(0, map);
    return 0;
}
int go(int idx, int a[][10]){
    if(idx >= cctv.size() ){
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 0)
                    cnt++;
            }
        }
        return cnt;
    }
    int b[10][10];
    int ans = n * m, tmp = n * m;
    for(int i=0; i<dir[cctv[idx][0]-1].size(); i++){
        memcpy(b, a, sizeof(int)*10*10);
        for(int j=0; j<dir[cctv[idx][0]-1][i].size(); j++){
            int x = cctv[idx][1], y= cctv[idx][2];
            while(x>=0 && x<n && y>=0 && y<m){
                if(b[x][y] == 6) break;
                if(b[x][y] == 0) b[x][y] = -1;
                x += dxy[dir[cctv[idx][0]-1][i][j]].first;
                y += dxy[dir[cctv[idx][0]-1][i][j]].second;
            }
        }
        tmp = go(idx+1, b);
        if(ans > tmp) ans = tmp;
    }
    return ans;
}









