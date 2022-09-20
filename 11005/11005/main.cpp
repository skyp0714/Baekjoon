//
//  main.cpp
//  11005
//
//  Created by 박하늘 on 2020. 9. 22..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
#define max 36
using namespace std;
int main(int argc, const char * argv[]) {
    long long int n;
    stack<int> bc;
    int b;
    char itoc[max];
    for(int i=0;i<max;i++){
        if(i<10) itoc[i]='0'+i;
        else itoc[i]='A'+i-10;
    }
    cin>>n>>b;
    while(n){
        bc.push(n%b);
        n/=b;
    }
    while(!bc.empty()){
        cout<<itoc[bc.top()];
        bc.pop();
    }
}
