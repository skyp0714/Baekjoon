//
//  main.cpp
//  1748
//
//  Created by 박하늘 on 2020. 9. 11..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(){
    long long int n,num=10,len=1,ans=0, temp;
    scanf("%lld",&n);
    temp=n;
    while(n){
        if(n/10) ans+=(num*0.9)*len;
        else ans+=len*(temp-(num/10)+1);
        num*=10;
        len++;
        n/=10;
    }
    printf("%lld",ans);
}
