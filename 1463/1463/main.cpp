//
//  main.cpp
//  1463
//
//  Created by 박하늘 on 2020. 8. 13..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int min(int a,int b);
int main(int argc, const char * argv[]) {
    int i,n;
    scanf("%d", &n);
    int a[1000001];
    a[1]=0;
    for(i=2;i<=n;i++){
        a[i]=a[i-1]+1;
        if(i%3==0) a[i]=min(a[i],a[i/3]+1);
        if(i%2==0) a[i]=min(a[i],a[i/2]+1);
    }
    printf("%d", a[n]);
    return 0;
}
int min(int a,int b){
    return a>b?b:a;
}
