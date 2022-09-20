//
//  main.cpp
//  15990
//
//  Created by 박하늘 on 2020. 8. 13..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int t,n,i,j;
    long long int d[100001][4];
    for(i=0;i<100001;i++)
        for(j=0;j<4;j++) d[i][j]=0;
    d[1][1]=1;
    d[1][0]=1;
    d[2][2]=1;
    d[2][0]=1;
    d[3][1]=1;
    d[3][2]=1;
    d[3][3]=1;
    d[3][0]=3;
    scanf("%d",&t);
    while(t--){
        scanf("%d", &n);
        if(d[n][0]) printf("%lld\n",d[n][0]);
        else{
        for(i=4;i<=n;i++){
                if(!d[i][0]){
                d[i][1]=(d[i-1][2]+d[i-1][3])%1000000009;
                d[i][2]=(d[i-2][1]+d[i-2][3])%1000000009;
                d[i][3]=(d[i-3][1]+d[i-3][2])%1000000009;
                d[i][0]=((d[i][1]+d[i][2])%1000000009+d[i][3])%1000000009;
                }
            }
            printf("%lld\n",d[n][0]);
        }
    }
    return 0;
}
