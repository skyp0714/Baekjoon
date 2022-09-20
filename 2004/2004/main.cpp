//
//  main.cpp
//  2004
//
//  Created by 박하늘 on 2020. 9. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n,k,m;
    cin>>n>>k;
    m=n-k;
    int num2=0,num5=0,a=n,b=k,c=m;
    while(n||a){
        n/=5;k/=5;m/=5;
        a/=2;b/=2;c/=2;
        num2=num2+a-b-c;
        num5=num5+n-k-m;
    }
    cout<<(num2>num5 ? num5 : num2);
}
