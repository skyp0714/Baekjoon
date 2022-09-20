//
//  main.cpp
//  1699
//
//  Created by 박하늘 on 2020. 8. 16..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int i,j,n,d[100001];
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        d[i]=i;
        for(j=1;j*j<=i;j++){
            if(d[i]>1+d[i-j*j]) d[i]=1+d[i-j*j];
        }
    }
    printf("%d",d[n]);
    return 0;
}
