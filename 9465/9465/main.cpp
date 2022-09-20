//
//  main.cpp
//  9465
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int max(int a, int b);
int main(int argc, const char * argv[]) {
    int a[100001][2],d[100001][3],i,j,n,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(j=0;j<2;j++)
            for(i=0;i<n;i++) scanf("%d",&a[i][j]);
        d[0][0]=0;
        d[0][1]=a[0][0];
        d[0][2]=a[0][1];
        for(i=1;i<n;i++){
            d[i][0]=max(d[i-1][1],d[i-1][2]);
            d[i][1]=max(d[i-1][2],d[i-1][0])+a[i][0];
            d[i][2]=max(d[i-1][1],d[i-1][0])+a[i][1];
        }
        printf("%d\n",max(max(d[n-1][0],d[n-1][1]),d[n-1][2]));
    }
    return 0;
}
int max(int a, int b){
    return a>b ? a: b;
}
