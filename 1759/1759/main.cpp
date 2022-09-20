//
//  main.cpp
//  1759
//
//  Created by 박하늘 on 2020. 8. 26..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

void go(int,string);
bool chk(string);
int l,c;
char a[20];
int main(int argc, const char * argv[]) {
    cin>>l>>c;
    for(int i=0;i<c;i++){
        cin>>a[i];
    }
    sort(a,a+c);
    go(0,"");
    
    return 0;
}
void go(int i,string pass){
    if(pass.length()==l){
        if(chk(pass)) cout<<pass<<endl;
        return;
    }
    if(i>=c) return;
    go(i+1,pass+a[i]);
    go(i+1,pass);
}
bool chk(string pass){
    int cnt=0;
    for(char x:pass){
        if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u') cnt++;
    }
    if(cnt>0&&pass.length()-cnt>1) return true;
    else return false;
}
