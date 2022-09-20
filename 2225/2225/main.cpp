//
//  main.cpp
//  2225
//
//  Created by 박하늘 on 2020. 8. 16..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int d[201][201]={0,},n,i,j,k;
    scanf("%d %d",&n,&k);
    for(i=0;i<=n;i++){
        for(j=0;j<=k;j++){
            if(j==0)d[i][j]=0;
            else if(i==0) d[i][j]=1;
            else if(j==1) d[i][j]=1;
            else d[i][j]=(d[i][j-1]+d[i-1][j])%1000000000;
        }
    }
    printf("%d",d[n][k]);
    return 0;
}
/* 위의 결과를 1차원 다이나믹으로 바꿀 수 있다.
 n,m
 d[0]=1;
 for(i=1;i<=n;i++){
 for(j=1;j<=ㅡ;j++){
 d[j]+=d[j-1];
 }
 }
 그림 그려서 참조
 */
