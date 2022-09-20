//
//  main.cpp
//  10819
//
//  Created by 박하늘 on 2020. 8. 21..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int a[100001],n;
int nextp();
void swap(int i, int j);
void reverse(int s);
void sort();
int cal();
int abs(int a);
int main(int argc, const char * argv[]) {
    int i,max=0,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    sort();
    while(nextp()){
        temp=cal();
        if(max<temp)max=temp;
    }
    printf("%d",max);
    return 0;
}
int nextp(){
    int i,temp1=-1,temp2=0;
    for(i=0;i<n;i++){
        if(i)if(a[i]>a[i-1])temp1=i-1;
    }
    if(temp1==-1){
        return 0;
    }
    for(i=temp1;i<n;i++){
        if(a[i]>a[temp1])temp2=i;
    }
    swap(temp1,temp2);
    reverse(temp1+1);
    return 1;
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
void sort(){
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]>a[j])swap(i,j);
        }
    }
}
int cal(){
    int sum=0;
    for(int i=0;i<n-1;i++){
        sum+=abs(a[i]-a[i+1]);
    }
    return sum;
}
int abs(int a){
    return a>0 ?a:-a;
}
