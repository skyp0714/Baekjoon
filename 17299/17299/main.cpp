//
//  main.cpp
//  17299
//
//  Created by 박하늘 on 2020. 9. 19..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
#define max 1000000
int n,a[max],nge[max],f[max+1];
int main(int argc, const char * argv[]) {
    stack<int> seq;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        f[a[i]]++;
    }
    seq.push(0);
    for(int i=1;i<n;i++){
        while(!seq.empty()&&f[a[seq.top()]]<f[a[i]]){
            nge[seq.top()]=a[i];
            seq.pop();
        }
        seq.push(i);
    }
    while(!seq.empty()){
        nge[seq.top()]=-1;
        seq.pop();
    }
    for(int i=0;i<n;i++) cout<<nge[i]<<' ';
    return 0;
}

