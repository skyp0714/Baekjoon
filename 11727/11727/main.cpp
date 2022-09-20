//
//  main.cpp
//  11727
//
//  Created by 박하늘 on 2020. 8. 13..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#define mod 10007
int main(int argc, const char * argv[]) {
    int a,b,c,n;
    a=0;
    b=0;
    c=1;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        a=b;
        b=c;
        c=((2*a)%mod+b)%mod;
    }
    printf("%d",c);
    return 0;
}


