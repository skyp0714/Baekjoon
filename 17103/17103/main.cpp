//
//  main.cpp
//  17103
//
//  Created by 박하늘 on 2020. 9. 22..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#define max 1000000
using namespace std;
int goldbach(int);
void findpn();
int pn[max+1];
int main(int argc, const char * argv[]) {
    int t,n;
    cin>>t;
    findpn();
    while(t--){
        cin>>n;
        cout<<goldbach(n)<<'\n';
    }
}
void findpn(){
    int i,j;
    for(i=2;i<=max/2;i++){
        if(pn[i])continue;
        for(j=2*i;j<max;j+=i){
            pn[j]=1;
        }
    }
    return;
}
int goldbach(int n){
    int i,cnt=0;
    for(i=2;i<=n/2;i++){
        if(pn[i]+pn[n-i]==0) cnt++;
    }
    return cnt;
}
