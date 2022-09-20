//
//  main.cpp
//  6064
//
//  Created by 박하늘 on 2020. 9. 11..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int gcd(int a, int b);
int main(){
    int end,n,m,i,t,x,y;
    scanf("%d",&t);
    cin.ignore();
    while(t--){
        cin>>m>>n>>x>>y;
        end=(n*m)/gcd(n,m);
        for(i=x;i<=end;i+=m){
            if(i%n==y%n) break;
        }
        if(i>end) printf("-1\n");
        else printf("%d\n",i);
    }
    
}
int gcd(int a, int b){
    if(a==b)return a;
    else if(a==1||b==1) return 1;
    else return a>b?gcd(a-b,b):gcd(a,b-a);
}

