//
//  main.cpp
//  17087
//
//  Created by 박하늘 on 2020. 9. 21..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#define max_n 100000
using namespace std;
int gcd(int, int);
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,s,a[max_n],temp=0;
    cin>>n>>s;
    for(int i=0;i<n;i++){
        cin>>a[i];
        a[i]= s>a[i] ? (s-a[i]) : (a[i]-s);
        if(i>0) temp=gcd(a[i],temp);
        else temp=a[i];
    }
    cout<<temp;
    return 0;
}
int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}
