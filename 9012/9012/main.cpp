//
//  main.cpp
//  9012
//
//  Created by 박하늘 on 2020. 9. 8..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    stack<char> a;
    char c;
    int t,chk;
    cin>>t;
    cin.ignore();
    while(t--){
        chk=0;
        string s;
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            c=s.at(i);
            if(c=='(') a.push(c);
            else if(c==')'){
                if(!a.empty()){
                    if(a.top()=='(') a.pop();
                    else chk=1;
                }else chk=1;
            }
        }
        if(chk) cout<<"NO"<<'\n';
        else{
            if(a.empty()) cout<<"YES"<<'\n';
            else cout<<"NO"<<'\n';
        }
        while(!a.empty()) a.pop();
    }
    return 0;
}
