//
//  main.cpp
//  15686
//
//  Created by 박하늘 on 2021. 4. 25..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
vector<pair<int, int>> home, chi;
bool chk[13];
int n, m, map[50][50], num;
int go(int, int);
int main(int argc, const char * argv[]) {
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j] == 1){
                home.push_back(make_pair(i, j));
            }else if(map[i][j] == 2){
                num++;
                chi.push_back(make_pair(i, j));
            }
        }
    }
    cout << go(0, 0);
    return 0;
}
int go(int idx, int open){
    if(open > m) return 0;
    if(idx >= num){
        if(open != m){
            return 0;
        }else{
            int sum=0;
            for(int i=0; i<home.size(); i++){
                int min = 2*n, tmp = 2*n;
                for(int j=0; j<chi.size(); j++){
                    if(chk[j]){
                        tmp = abs(home[i].first-chi[j].first) + abs(home[i].second-chi[j].second);
                        if(tmp < min) min = tmp;
                    }
                }
                sum += min;
            }
            return sum;
        }
    }
    int min = 2 * n * (n+n);
    int tmp = min;
    if(open < m){
        chk[idx] = true;
        tmp = go(idx+1, open+1);
        if(tmp && min > tmp) min = tmp;
        chk[idx] = false;
    }
    tmp = go(idx+1, open);
    if(tmp && min > tmp) min = tmp;
    return min;
}

