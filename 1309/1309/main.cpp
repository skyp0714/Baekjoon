//
//  main.cpp
//  1309
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int i,n,d[100001][2];
    scanf("%d",&n);
    d[1][0]=1;
    d[1][1]=2;
    for(i=2;i<=n+1;i++){
        d[i][0]=(d[i-1][0]+d[i-1][1])%9901;
        d[i][1]=((d[i-1][0]+d[i-1][0])%9901+d[i-1][1])%9901;
    }
    printf("%d",d[n+1][0]);
    return 0;
}
/*
 s[i]=s[i-1]*2+s[i-2];
 
 d[i]=s[i]-s[i-1];
 */
