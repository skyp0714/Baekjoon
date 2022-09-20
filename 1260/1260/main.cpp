//
//  main.cpp
//  1260
//
//  Created by 박하늘 on 2020. 9. 1..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <queue>
#define max_n 1000
#define max_m 10000
using namespace std;
int check[max_n+1],n;
int adj[max_n+1][max_n+1];
queue<int> q;
void dfs(int);
void bfs(int);
int main(int argc, const char * argv[]) {
    int m,s,a,b;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a][b]=1;
        adj[b][a]=1;
    }
    dfs(s);
    for(int i=0;i<=n;i++) check[i]=0;
    cout<<endl;
    bfs(s);
    return 0;
}
void dfs(int s){
    cout<<s<<" ";
    check[s]=1;
    for(int i=1;i<=n;i++){
        if(adj[s][i]&&check[i]==0) dfs(i);
    }
    return;
}
void bfs(int s){
    check[s]=1;
    q.push(s);
    while(!q.empty()){
        int x=q.front();
        cout<<x<<" ";
        q.pop();
        for(int i=1;i<=n;i++){
            if(adj[x][i]&&check[i]==0){
                q.push(i);
                check[i]=1;
            }
        }
    }
}
