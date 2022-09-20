//
//  main.cpp
//  17089
//
//  Created by 박하늘 on 2021. 5. 4..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);    ios_base::sync_with_stdio(false);
    int n, m, a, b, i, j, min = 5000, tmp;
    cin >> n >> m;
    vector<vector<int>> frnd(n+1);
    for(i=0; i<m; i++){
        cin >> a >> b;
        frnd[a].push_back(b);
        frnd[b].push_back(a);
    }
    for(i=1;i<n;i++)    sort(frnd[i].begin(), frnd[i].end());
    
    for(i=1; i<=n; i++){
        for(j=0; j<frnd[i].size(); j++){
            a = i;
            b = frnd[i][j];
            if(a < b) continue;
            int x=0, y=0;
            while(x<frnd[a].size() && y<frnd[b].size()){
                if(frnd[a][x] < frnd[b][y]){
                    x++;
                }else if(frnd[a][x] > frnd[b][y]){
                    y++;
                }else{
                    int c = frnd[a][x];
                    tmp = frnd[a].size() + frnd[b].size() + frnd[c].size() - 6;
                    if(min > tmp) min = tmp;
                    x++; y++;
                }
            }
        }
    }
    if(min == 5000) min = -1;
    cout << min;
    return 0;
}
