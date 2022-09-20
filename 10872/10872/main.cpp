//
//  main.cpp
//  10872
//
//  Created by 박하늘 on 2020. 9. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int fact(int);
int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    cout<<fact(n);
}
int fact(int n){
    if(n<=1) return 1;
    else return n*fact(n-1);
}
