//
//  main.cpp
//  2422
//
//  Created by 박하늘 on 2021. 5. 2..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool chk[201][201];
int cnt, n;
int go(int, int, vector<int>);
int main(int argc, const char * argv[]) {
    int m, a, b;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> a >> b;
        chk[a][b] = true;
        chk[b][a] = true;
    }
    vector<int> used;
    cout << go(0, 0, used);
    return 0;
}
int go(int x, int prev, vector<int> used){
    int ans = 0, j;
    if(x == 3){
        cnt++;
        return 1;
    }
    int len = used.size();
    for(int i=prev+1; i<=n; i++){
        for(j=0; j<len; j++){
            if(chk[i][used[j]]) break;
        }
        if(j==len){
            used.push_back(i);
            ans += go(x+1, i, used);
            used.pop_back();
        }
    }
    return ans;
}
