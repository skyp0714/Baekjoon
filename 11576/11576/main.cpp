//
//  main.cpp
//  11576
//
//  Created by 박하늘 on 2020. 9. 22..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
#define max_len 36
using namespace std;
int main(int argc, const char * argv[]) {
    int a,b,m,temp;
    cin>> a >> b >> m ;
    long long int n=0;
    for(int i=0;i<m;i++){
        cin>> temp;
        n=n*a+temp;
    }
    stack<int> bc;
    while(n){
        bc.push(n%b);
        n/=b;
    }
    while(!bc.empty()){
        cout<<bc.top()<<" ";
        bc.pop();
    }
}
