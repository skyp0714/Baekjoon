//
//  main.cpp
//  2089
//
//  Created by 박하늘 on 2020. 9. 22..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int rem(long long int, int);
long long int div(long long int, int);
int main(int argc, const char * argv[]) {
    long long int a;
    stack<int> nbi;
    cin>>a;
    if(a==0) nbi.push(0);
    while(a){
        nbi.push(rem(a,-2));
        a=div(a,-2);
    }
    while(!nbi.empty()){
        cout<<nbi.top();
        nbi.pop();
    }
}
int rem(long long int a, int b){
    return a>0 ? a%2 : (-a)%2;
}
long long int div(long long int a, int b){
    if(a>0) return -(a/2);
    else return (-a)%2 ? (-a)/2+1 : (-a)/2;
}
