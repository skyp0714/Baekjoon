//
//  main.cpp
//  11724
//
//  Created by 박하늘 on 2020. 9. 2..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#define max 1010
using namespace std;
bool check[max];
vector<int> v[max];
void dfs(int);
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n,m,a,b,cnt=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            cnt++;
            dfs(i);
        }
    }
    cout<<cnt;
    return 0;
}
void dfs(int s){
    check[s]=true;
    for(int i=0;i<v[s].size();i++){
        int next=v[s][i];
        if(!check[next]) dfs(next);
    }
    return;
}
