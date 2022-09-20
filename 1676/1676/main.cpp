//
//  main.cpp
//  1676
//
//  Created by 박하늘 on 2020. 9. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,ans=0;
    cin>>n;
    while(n){
        n/=5;
        ans+=n;
    }
    cout<<ans;
}
