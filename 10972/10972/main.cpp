//
//  main.cpp
//  10972
//
//  Created by 박하늘 on 2020. 8. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int a[100001],n;
void swap(int i, int j);
void reverse(int s);
int main(int argc, const char * argv[]) {
    int i,temp1=-1,temp2=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(i)if(a[i]>a[i-1])temp1=i-1;
    }
    if(temp1==-1){
        printf("%d",-1);
        return 0;
    }
    for(i=temp1;i<n;i++){
        if(a[i]>a[temp1])temp2=i;
    }
    swap(temp1,temp2);
    reverse(temp1+1);
    for(i=0;i<n;i++)printf("%d ",a[i]);
    return 0;
}
void swap(int i, int j){
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
    return;
}
void reverse(int s){
    int e=n;
    for(int i=s;i<(s+n)/2;i++){
        swap(i,--e);
    }
    return;
}
