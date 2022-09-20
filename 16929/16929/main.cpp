//
//  main.cpp
//  16929
//
//  Created by 박하늘 on 2021. 1. 17..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#define max_length 60
#define max_ways 4
using namespace std;
bool dfs(int,int,int);
bool is_inside(int,int);
int n,m;
char a[max_length][max_length];
int chk[max_length][max_length];
int main(){
    cin>>n>>m;
    for(int xi=0;xi<n;xi++){
        for(int yi=0;yi<m;yi++){
            cin>>a[xi][yi];
        }
    }
    for(int xi=0;xi<n;xi++){
        for(int yi=0;yi<m;yi++){
            if( !chk[xi][yi] && dfs(xi,yi,max_ways+1) ){
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
bool dfs(int x,int y, int prev_direction){
    if(chk[x][y]) return true;
    chk[x][y]=1;
    int dx[max_ways]={1,0,-1,0};
    int dy[max_ways]={0,1,0,-1};
    for(int di=0;di<max_ways;di++){
        if(di==prev_direction) continue;
        int nx=x+dx[di];
        int ny=y+dy[di];
        if(is_inside(nx,ny) && a[nx][ny]==a[x][y]){
            if(dfs(nx,ny,(di+2)%4)){
                return true;
            }
        }
    }
    return false;
}
bool is_inside(int x, int y){
    return (x>=0) && (x<n) && (y>=0) && (y<m);
}
