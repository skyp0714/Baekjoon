//
//  main.cpp
//  2156
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int max(int, int, int);
int main(int argc, const char * argv[]) {
    int d[10001],i,n,a[10001],ans;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    d[0]=a[0];
    d[1]=a[0]+a[1];
    d[2]=max(d[1],d[0]+a[2],a[1]+a[2]);
    ans=d[2];
    for(i=3;i<n;i++){
        d[i]=max(d[i-1],d[i-2]+a[i],d[i-3]+a[i-1]+a[i]);
        ans=max(ans,0,d[i]);
    }
    printf("%d",ans);
    return 0;
}
int max(int a, int b, int c){
    int n;
    n=a>b?a:b;
    return n>c ?n:c;
}
