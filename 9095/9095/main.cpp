//
//  main.cpp
//  9095
//
//  Created by 박하늘 on 2020. 8. 13..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int main(int argc, const char * argv[]) {
    int d[12],n,t;
    scanf("%d",&t);
    while(t--){
        d[0]=1;
        d[1]=2;
        d[2]=4;
        scanf("%d",&n);
            for(int i=3;i<n;i++) d[i]=d[i-1]+d[i-2]+d[i-3];
        printf("%d\n",d[n-1]);
    }
    return 0;
}

