//
//  main.cpp
//  1406
//
//  Created by 박하늘 on 2020. 9. 9..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    stack<char> left, right;
    string s;
    char c;
    int m,i;
    cin>>s;
    for(i=0;i<s.size();i++) left.push(s[i]);
    cin>>m;
    while(m--){
        cin>>c;
        switch(c){
            case 'L':
                if(!left.empty()){
                right.push(left.top());
                left.pop();
                }
                break;
            case 'D':
                if(!right.empty()){
                    left.push(right.top());
                    right.pop();
                }
                break;
            case 'B':
                if(!left.empty()){
                    left.pop();
                }
                break;
            case 'P':
                cin>>c;
                left.push(c);
                break;
        }
    }
    while(!left.empty()){
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout<<right.top();
        right.pop();
    }
    return 0;
}
