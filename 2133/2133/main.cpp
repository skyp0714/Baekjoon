//
//  main.cpp
//  2133
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int d[31][4],n,i;
    scanf("%d",&n);
    d[0][0]=1;
    d[0][1]=0;
    d[0][2]=0;
    d[0][3]=0;
    for(i=1;i<=n;i++){
        d[i][0]=d[i-1][1]+d[i-1][3];
        d[i][1]=d[i-1][0]*2+d[i-1][2];
        d[i][2]=d[i-1][1];
        d[i][3]=d[i-1][0];
    }
    printf("%d",d[n][0]);
    return 0;
}
