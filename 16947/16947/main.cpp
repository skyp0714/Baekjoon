//
//  main.cpp
//  16947
//
//  Created by 박하늘 on 2021. 4. 1..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
#define max 3000+1

using namespace std;
vector<int> station[max];
int chk[max], dis[max];

int n;
int find_cycle(int x, int p);
int main(int argc, const char * argv[]) {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        station[a].push_back(b);
        station[b].push_back(a);
    }
    find_cycle(1,-1);
    queue<int> bfs;
    for(int i=1; i<=n ; i++){
        if(chk[i]==2){
            bfs.push(i);
            dis[i]=0;
        }else dis[i]=-1;
    }
    while(!bfs.empty()){
        int x = bfs.front();
        bfs.pop();
        for(int y:station[x]){
            if(dis[y] == -1){
                bfs.push(y);
                dis[y] = dis[x] + 1;
            }
        }
    }
    for(int i=1; i<=n; i++) cout<<dis[i]<<' ';
    cout<<endl;
}
int find_cycle(int x, int p){
    // return - included, found: started index / excluded, found: -2 / not found: -1
    // chk - not visited: 0 / visited: 1 / visited, cycle: 2
    if(chk[x]==1) return x; //cycle founded
    chk[x] = 1;
    for(int y : station[x]){
        if(y == p) continue;
        int cond = find_cycle(y, x);
        if(cond == -2) return -2;
        if(cond > 0){
            chk[x] = 2;
            if(x == cond) return -2;
            else return cond;
        }
    }
    return -1;
}
