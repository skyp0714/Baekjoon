//
//  main.cpp
//  1978
//
//  Created by 박하늘 on 2020. 9. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int t, n, cnt=0;
    bool ispn;
    cin>>t;
    while(t--){
        ispn=true;
        cin>>n;
        for(int i=2;i*i<=n;i++){
            if(n%i==0) ispn=false;
        }
        if(ispn&&n!=1) cnt++;
    }
    cout<<cnt;
}
