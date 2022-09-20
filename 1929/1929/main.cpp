//
//  main.cpp
//  1929
//
//  Created by 박하늘 on 2020. 9. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#define max 1000010
using namespace std;
int main() {
    int a,b;
    
    bool iscomp[max]={0,};
    iscomp[1]=1;
    cin>>a>>b;
    for(int i=2;i<=b/2;i++){
        for(int j=2*i;j<=b;j+=i){
            iscomp[j]=1;
        }
    }
    for(int i=a;i<=b;i++)
        if(!iscomp[i]) cout<<i<<'\n';
}

