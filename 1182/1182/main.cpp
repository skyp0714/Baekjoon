//
//  main.cpp
//  1182
//
//  Created by 박하늘 on 2020. 8. 29..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,s,sum,a[20],cnt=0;
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=1;i<(1<<n);i++){
        sum=0;
        for(int k=0;k<n;k++){
            if(i&(1<<k)) sum+=a[k];
        }
        if(sum==s)cnt++;
    }
    cout<<cnt;
    return 0;
}
