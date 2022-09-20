//
//  main.cpp
//  2193
//
//  Created by 박하늘 on 2020. 8. 16..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    long long int d[100][2],i,j,n;
    for(j=0;j<2;j++)d[1][j]=j;
    scanf("%lld",&n);
    for(i=2;i<=n;i++){
        d[i][0]=d[i-1][0]+d[i-1][1];
        d[i][1]=d[i-1][0];
    }
    printf("%lld",d[n][0]+d[n][1]);
    return 0;
}
