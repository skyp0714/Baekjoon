//
//  main.cpp
//  2609
//
//  Created by 박하늘 on 2020. 9. 19..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int gcd(int, int);
int lcm(int, int);
int main(int argc, const char * argv[]) {
    int a,b;
    cin>>a>>b;
    cout<<gcd(a,b)<<'\n'<<lcm(a,b);
    return 0;
}
int gcd(int a, int b){
    if(a==b) return a;
    else if(a==1) return 1;
    else if(b==1) return 1;
    else return a>b ? gcd(a-b,b) : gcd(a,b-a);
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}

