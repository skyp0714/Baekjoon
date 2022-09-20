//
//  main.cpp
//  2667
//
//  Created by 박하늘 on 2020. 9. 2..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define max 25
using namespace std;
int a[max][max],b[max*max],check[max][max],cnt,n;
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void dfs(int x, int y);
int main(int argc, const char * argv[]) {
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%1d",&a[i][j]);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]&&!check[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    sort(b,b+cnt);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<b[i]+1<<endl;
    }
    return 0;
}
void dfs(int x, int y){
    int nx,ny;
    check[x][y]=1;
    for(int i=0;i<4;i++){
        nx=x+dx[i];
        ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<n&&!check[nx][ny]&&a[nx][ny]){
            dfs(nx,ny);
            b[cnt]++;
        }
    }
    return;
}
