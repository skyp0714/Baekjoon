//
//  main.cpp
//  16964
//
//  Created by 박하늘 on 2021. 4. 2..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define max 100010
vector<int> a[max];
int n, order[max], chk[max], b[max],idx,ans=1;
void dfs(int x);
int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i=1; i<n; i++){
        int x, y;
        cin >> x >> y;
        a[x-1].push_back(y-1);
        a[y-1].push_back(x-1);
    }
    for(int i=0; i<n; i++){
        cin >> b[i];
        b[i]--;
        order[b[i]] = i;
    }
    for (int i=0; i<n; i++) {
        sort(a[i].begin(), a[i].end(), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }
    dfs(0);
    cout << ans;
    return 0;
}
void dfs(int x){
    chk[x] = 1;
    if(b[idx] != x) ans = 0;
    idx++;
    for(int y : a[x]){
        if(!chk[y]) dfs(y);
    }
    return;
}
