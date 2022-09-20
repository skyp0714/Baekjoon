//
//  main.cpp
//  10971
//
//  Created by 박하늘 on 2020. 8. 21..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int a[100001],n,w[11][11];
int nextp();
void swap(int i, int j);
void reverse(int s);
int cal();
int main(int argc, const char * argv[]) {
    int i,j,min=1000000*10,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&w[i][j]);
        }
        a[i]=i;
    }
    while(a[0]==0){
        temp=cal();
        if(temp)if(min>temp)min=temp;
        nextp();
    }
    printf("%d",min);
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

int cal(){
    int sum=0;
    for(int i=0;i<n-1;i++){
        if(w[a[i]][a[i+1]]==0) return 0;
        sum+=w[a[i]][a[i+1]];
    }
    if(w[a[n-1]][a[0]]==0) return 0;
    else return sum+=w[a[n-1]][a[0]];
}


