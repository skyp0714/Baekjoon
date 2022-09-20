//
//  main.cpp
//  13460
//
//  Created by 박하늘 on 2021. 4. 18..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int n, m, dx[4] = {-1, 0, 0, 1}, dy[4] = {0, 1, -1, 0};
char map[20][20];
int go(int , int, pair<int, int>, pair<int, int>);
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    int i, j;
    pair<int, int> r, b;
    for(i=0; i<n; i++){
        for(j=0; j<m;j++){
            cin >> map[i][j];
            if(map[i][j] == 'R'){
                r = make_pair(i, j);
                map[i][j] = '.';
            }else if(map[i][j] == 'B'){
                b = make_pair(i, j);
                map[i][j] = '.';
            }
        }
    }
    int ans = go(0, -1, r, b);
    if(ans > 10 || ans == 0) cout << -1;
    else cout << ans;
    return 0;
}
int go(int time, int prev, pair<int, int> r, pair<int, int> b){
    if(time > 10) return 11;
    int min = 11;
    for(int i=0; i<4; i++){
        if(i == prev || i + prev == 3) continue;
        pair<int, int> nr = r, nb = b;
        bool rin = false, bin = false;
        while(map[nr.first + dx[i]][nr.second + dy[i]] != '#'){
            if(nr.first + dx[i] == nb.first && nr.second + dy[i] == nb.second) break;
            nr.first += dx[i]; nr.second += dy[i];
            if(map[nr.first][nr.second] == 'O'){
                rin = true;
                nr = make_pair(-1, -1);
                break;
            }
        }
        while(map[nb.first + dx[i]][nb.second + dy[i]] != '#'){
            if(nb.first + dx[i] == nr.first && nb.second + dy[i] == nr.second) break;
            nb.first += dx[i]; nb.second += dy[i];
            if(map[nb.first][nb.second] == 'O'){
                bin = true;
                nb = make_pair(-1, -1);
                break;
            }
        }
        if(bin) continue;
        if(rin){
            if(time+1 < min) min = time+1;
        }else{
            while(map[nr.first + dx[i]][nr.second + dy[i]] != '#'){
                if(nr.first + dx[i] == nb.first && nr.second + dy[i] == nb.second) break;
                nr.first += dx[i]; nr.second += dy[i];
            }
            if(nr == r && nb == b) continue;
            int temp = go(time+1, i, nr, nb);
            if(temp>0 && temp < min) min = temp;
        }
    }
    if(min == 11) return 0;
    return min;
}
