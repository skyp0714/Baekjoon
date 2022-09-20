//
//  main.cpp
//  1212
//
//  Created by 박하늘 on 2020. 9. 22..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;
int main(int argc, const char * argv[]) {
    stack<int> bi,oc;
    char a;
    int temp;
    while(1){
        scanf("%c",&a);
        if(a=='\n') break;
        oc.push(a-'0');
    }
    while(!oc.empty()){
        temp=oc.top();
        for(int i=0;i<3;i++){
            bi.push(temp%2);
            temp/=2;
        }
        oc.pop();
    }
    if(!bi.top()&&bi.size()==3){
        cout<<0;
        return 0;
    }
    while(!bi.top()) bi.pop();
    while(!bi.empty()){
        cout<<bi.top();
        bi.pop();
    }
return 0;
}
