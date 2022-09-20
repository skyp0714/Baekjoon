//
//  main.cpp
//  6588
//
//  Created by 박하늘 on 2020. 9. 20..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#define max 1000010
using namespace std;
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    int a;
    bool ispn[max]={0,},isgb=0;
	ispn[0]=1;
    ispn[1]=1;
    for(int i=2;i*i<=max;i++){
        for(int j=2*i;j<=max;j+=i){
            ispn[j]=1;
        }
    }
    cin>>a;
    while(a){
        isgb=1;
        for(int i=2;i<=a/2;i++){
            if(ispn[i]||ispn[a-i]) continue;
            cout<< a << " = " << i << " + " << a-i <<'\n';
            isgb=0;
            break;
        }
        if(isgb) cout<<"Goldbach's conjecture is wrong."<<endl;
        cin>>a;
    }
	return 0;
}
