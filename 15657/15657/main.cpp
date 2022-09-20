//
//  main.cpp
//  15657
//
//  Created by 박하늘 on 2020. 8. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int a[8],d[9];
void sort(int n);
void swap(int i, int j);
void go(int index,int n, int m);
int main(int argc, const char * argv[]) {
    int n,m;
    scanf("%d %d",&n, &m);
    for(int i=1;i<=n;i++) scanf("%d",&d[i]);
    sort(n);
    go(0,n,m);
    return 0;
}
void sort(int n){
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(d[i]>d[j]) swap(i,j);
        }
    }
}
void swap(int i, int j){
    int temp;
    temp=d[i];
    d[i]=d[j];
    d[j]=temp;
}
void go(int index, int n, int m){
    int i;
    if(index==m){
        for(i=0;i<m;i++) printf("%d ",a[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=n;i++){
        if(index)if(d[i]<a[index-1]) continue;
        a[index]=d[i];
        go(index+1,n,m);
    }
}
