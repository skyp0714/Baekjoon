//
//  main.cpp
//  1107
//
//  Created by 박하늘 on 2020. 9. 11..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
//ppt  참조할 것. 더 좋은방법이 있다.
#define max 500000
int ch, d[10],m;
int abs(int a);
int num(int a);
bool check(int a);
int main(){
    int i,temp,chk;
    cin>>ch>>m;
    int ans=abs(ch-100);
    for(i=0;i<m;i++) cin>>d[i];
    for(i=max*2;i>=0;i--){
        chk=1;
        temp=i;
        if(i==0&&check(0)) chk=0;
        while(temp!=0){
            if(check(temp%10)) chk=0;
            temp/=10;
        }
        if(chk){
            temp=num(i);
            if(ans>temp)ans=temp;
        }
    }
    printf("%d",ans);
}
bool check(int a){
    for(int i=0;i<m;i++)
        if(d[i]==a) return true;
    return false;
}
int abs(int a){
    return a>0 ? a: -a;
}
int num(int c){
    int cnt=0, temp;
    temp=c;
    if(c==0)cnt=1;
    while(c){
        c/=10;
        cnt++;
    }
    return abs(ch-temp)+cnt;
}

