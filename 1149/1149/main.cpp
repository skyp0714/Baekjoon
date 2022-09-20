//
//  main.cpp
//  1149
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int min(int a, int b);
int main(int argc, const char * argv[]) {
    int a[1001][3],d[1001][3],i,j,n;
    for(j=0;j<3;j++)d[0][j]=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        for(j=0;j<3;j++) scanf("%d",&a[i][j]);
    for(i=1;i<=n;i++){
        d[i][0]=min(d[i-1][1],d[i-1][2])+a[i][0];
        d[i][1]=min(d[i-1][0],d[i-1][2])+a[i][1];
        d[i][2]=min(d[i-1][1],d[i-1][0])+a[i][2];
    }
    printf("%d",min(min(d[n][0],d[n][1]),d[n][2]));
    return 0;
}
int min(int a, int b){
    return a>b ? b : a;
}
