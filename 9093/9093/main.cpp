//
//  main.cpp
//  9093
//
//  Created by 박하늘 on 2020. 9. 8..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    stack<char> a;
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string s;
        getline(cin,s);
        for(int i=0;i<s.size();i++){
            char c=s.at(i);
            if(c==' '){
                while(a.size()>0){
                    cout<<a.top();
                    a.pop();
                }
            cout<<c;
            }else a.push(c);
        }
        while(a.size()>0){
            cout<<a.top();
            a.pop();
        }
        cout<<'\n';
    }
}
