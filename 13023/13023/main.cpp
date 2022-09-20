//
//  main.cpp
//  13023
//
//  Created by 박하늘 on 2020. 8. 30..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#define max 2000
using namespace std;
vector<int> v[max];
bool chk[max];
void dfs(int x,int depth);
int main(int argc, const char * argv[]) {
    int n,m,i,a,b;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=0;i<n;i++){
        dfs(i,0);
    }
    cout<<0;
    return 0;
}
void dfs(int x,int depth){
    chk[x]=1;
    if(depth==4){
        cout<<1;
        exit(0);
    }
    for(int i=0;i<v[x].size();i++){
        if(!chk[v[x][i]]) dfs(v[x][i],depth+1);
    }
    chk[x]=0;
}
