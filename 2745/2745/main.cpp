//
//  main.cpp
//  2745
//
//  Created by 박하늘 on 2020. 9. 22..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int b,i,temp,len;
    long long int n=0;
    char a[100000];
    for(i=0;i<100;i++){
        scanf("%c",&a[i]);
        if(a[i]==' ') break;
    }
    len=i-1;
    cin>>b;
    for(i=0;i<=len;i++){
        if(a[i]>='A') temp=a[i]-'A'+10;
        else temp=a[i]-'0';
        n=b*n+temp;
    }
    cout<<n;
}
