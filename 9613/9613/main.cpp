//
//  main.cpp
//  9613
//
//  Created by 박하늘 on 2020. 9. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#define max 100
using namespace std;
int gcd(int, int);
int main(int argc, const char * argv[]) {
    int t,n,a[max];
    long long int ans=0;
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                ans+=gcd(a[i],a[j]);
        cout<<ans<<'\n';
    }
    return 0;
}
int gcd(int a, int b){
    if(a==b) return a;
    else if(a==1||b==1) return 1;
    else return a>b ? gcd(a-b,b):gcd(a,b-a);
}
