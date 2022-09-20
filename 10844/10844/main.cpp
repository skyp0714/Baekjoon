//
//  main.cpp
//  10844
//
//  Created by 박하늘 on 2020. 8. 13..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int main(int argc, const char * argv[]) {
    long long int d[101][10];
    int i,j,n;
    for(j=1;j<10;j++) d[1][j]=1;
    d[1][0]=0;
    scanf("%d", &n);
        for(i=2;i<=n;i++){
            d[i][9]=d[i-1][8];
            d[i][0]=d[i-1][1];
            for(j=1;j<9;j++){
                d[i][j]=(d[i-1][j+1]+d[i-1][j-1])%1000000000;
            }
        }
    long long int sum=0;
    for(j=0;j<10;j++) sum=(sum+d[n][j])%1000000000;
        printf("%lld\n",sum);
    return 0;
}
