//
//  main.cpp
//  17413
//
//  Created by 박하늘 on 2020. 9. 19..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    string s;
    stack<char> word;
    bool isin=false;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s.at(i)=='<'){
            while(!word.empty()){
                cout<<word.top();
                word.pop();
            }
            isin=true;
            cout<<'<';
        }else if(s.at(i)=='>'){
            isin=false;
            cout<<'>';
        }else if(isin){
            cout<<s.at(i);
        }else if(s.at(i)==' '){
            while(!word.empty()){
                cout<<word.top();
                word.pop();
            }
            cout<<s.at(i);
        }else{
            word.push(s.at(i));
        }
    }
    while(!word.empty()){
        cout<<word.top();
        word.pop();
    }
}
