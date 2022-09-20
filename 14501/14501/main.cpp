//
//  main.cpp
//  14501
//
//  Created by 박하늘 on 2020. 8. 28..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int go(int,int);
int t[20],p[20];
int main(int argc, const char * argv[]) {
    int ans,n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)    scanf("%d %d",&t[i],&p[i]);
    ans=go(0,n);
    printf("%d",ans);
    return 0;
}
int go(int i, int n){
    int a,b;
    if(i>=n) return 0;
    b=go(i+1,n);
    if(i+t[i]>n) return b;
    else a=go(i+t[i],n)+p[i];
    return a>b?a:b;
}

