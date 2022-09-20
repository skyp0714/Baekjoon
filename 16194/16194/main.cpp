//
//  main.cpp
//  16194
//
//  Created by 박하늘 on 2020. 8. 13..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int min(int a, int b);
int main(int argc, const char * argv[]) {
    int n,i,j,a[1001],d[1001];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        d[i]=1000*10000;
    }
    d[0]=0;
    d[1]=a[1];
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++) d[i]=min(d[i-j]+a[j],d[i]);
    printf("%d",d[n]);
}
int min(int a, int b){
    return (a<b ? a: b);
}
