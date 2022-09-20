//
//  main.cpp
//  15649
//
//  Created by 박하늘 on 2020. 8. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
bool c[9];
int a[8];
void go(int index,int n, int m);
int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d %d",&n, &m);
    go(0,n,m);
    return 0;
}
void go(int index, int n, int m){
    int i;
    if(index==m){
        for(i=0;i<m;i++) printf("%d ",a[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++){
        if(c[i]) continue;
        c[i]=true; a[index]=i;
        go(index+1,n,m);
        c[i]=false;
    }
}
