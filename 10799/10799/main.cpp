//
//  main.cpp
//  10799
//
//  Created by 박하늘 on 2020. 9. 19..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    int ans=0;
    char prev=' ';
    stack<char> lazer;
    string s;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s.at(i)=='('){
            lazer.push(s.at(i));
        }else if(s.at(i)==')'){
            lazer.pop();
            if(prev=='('){
                ans+=lazer.size();
            }else{
                ans++;
            }
        }
        prev=s.at(i);
    }
    cout<<ans;
    return 0;
}
