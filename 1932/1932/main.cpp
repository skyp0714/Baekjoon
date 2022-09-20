//
//  main.cpp
//  1932
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int d[500][500],a[500][500],n,i,j,max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<=i;j++) scanf("%d",&a[i][j]);
    for(i=0;i<n;i++){
        d[i][0]=d[i-1][0]+a[i][0];
        d[i][i]=d[i-1][i-1]+a[i][i];
        for(j=1;j<i;j++){
            d[i][j]=(d[i-1][j-1]+a[i][j]>d[i-1][j]+a[i][j])?d[i-1][j-1]+a[i][j]:d[i-1][j]+a[i][j];
        }
    }
    max=d[n-1][0];
    for(j=1;j<n;j++){
        if(max<d[n-1][j]) max=d[n-1][j];
    }
    printf("%d",max);
    return 0;
}
