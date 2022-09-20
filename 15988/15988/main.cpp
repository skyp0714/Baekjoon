//
//  main.cpp
//  15988
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#define mod 1000000009
int main(int argc, const char * argv[]) {
    long long int d[1000001],temp=4;
    int n,t;
    for(int i=1;i<1000001;i++) d[i]=0;
    d[0]=0;
    d[1]=1;
    d[2]=2;
    d[3]=4;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        if(d[n]) printf("%lld\n",d[n]);
        else{
        for(int i=temp;i<=n;i++){
            d[i]=((d[i-1]+d[i-2])%mod+d[i-3])%mod;
        }
        temp=n;
        printf("%lld\n",d[n]);
        }
    }
    return 0;
}
