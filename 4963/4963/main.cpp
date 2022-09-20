//
//  main.cpp
//  4963
//
//  Created by 박하늘 on 2020. 9. 2..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define max 50
using namespace std;
int a[max][max],check[max][max],w,h;
int dx[8]={1,0,-1,0,1,-1,1,-1},dy[8]={0,1,0,-1,1,1,-1,-1};
void dfs(int x, int y);
int main(int argc, const char * argv[]) {
    int i,j,cnt;
    while(1){
        cin>>h>>w;
        if(w*h==0) break;
        cnt=0;
        for(i=0;i<w;i++){
            for(j=0;j<h;j++){
                cin>>a[i][j];
                check[i][j]=0;
            }
        }
        for(i=0;i<w;i++){
            for(j=0;j<h;j++){
                if(!check[i][j]&&a[i][j]){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
void dfs(int x, int y){
    int nx,ny;
    check[x][y]=1;
    for(int i=0;i<8;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx>=0&&nx<w&&ny>=0&&ny<h){
            if(!check[nx][ny]&&a[nx][ny]) dfs(nx,ny);
        }
    }
}
