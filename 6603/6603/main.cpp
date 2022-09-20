//
//  main.cpp
//  6603
//
//  Created by 박하늘 on 2020. 8. 21..
//  Copyright © 2020년 박하늘. All rights reserved.
//
/*int nextp();
 void swap(int , int);
 void reverse(int);*/
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int i,k;
    while(cin>>k&&k){
    int b[13],a[13]={0,};
    for(i=0;i<6;i++)    a[i]=1;
    for(i=0;i<k;i++) cin>>b[i];
    do{
        for(int i=0;i<k;i++){
            if(a[i]) cout<<b[i]<<" ";
        }
        cout<<endl;
    }while(prev_permutation(a, a+k));
    cout<<endl;
    }
    return 0;
}
/*int nextp(){
    int i,temp1=-1,temp2=0;
    for(i=0;i<n;i++){
        if(i)if(a[i]<a[i-1])temp1=i-1;
    }
    if(temp1==-1){
        return 0;
    }
    for(i=temp1;i<n;i++){
        if(a[i]<a[temp1])temp2=i;
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
*/
