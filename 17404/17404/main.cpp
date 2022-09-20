//
//  main.cpp
//  17404
//
//  Created by 박하늘 on 2020. 8. 18..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#define max 1000*1000
int solve(int,int);
int min(int a, int b);
int main(int argc, const char * argv[]) {
    int i,j,k,temp,ans=max;
    int a[1001][3],n,d[1001][3];
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<3;j++) scanf("%d",&a[i][j]);
    for(i=0;i<3;i++){
        for(k=0;k<3;k++){
            if(i!=k)d[0][k]=max;
            else d[0][k]=a[0][k];
        }
        for(j=1;j<n;j++){
            d[j][0]=min(d[j-1][1],d[j-1][2])+a[j][0];
            d[j][1]=min(d[j-1][0],d[j-1][2])+a[j][1];
            d[j][2]=min(d[j-1][0],d[j-1][1])+a[j][2];
        }
        for(k=0;k<3;k++){
            if(i!=k) temp=d[n-1][k];
            if(ans>temp) ans=temp;
        }
    }
    printf("%d",ans);
    return 0;
}
int min(int a, int b){
    return a>b ? b : a;
}
