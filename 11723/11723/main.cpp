//
//  main.cpp
//  11723
//
//  Created by 박하늘 on 2020. 8. 29..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int m,x,s=0;
    string op;
    cin>>m;
    while(m--){
        cin>>op;
        if(op!="all"&&op!="empty"){
            cin>>x;
            x--;
        }
        if(op=="add"){
            s=s|(1<<x);
        }else if(op=="remove"){
            s=s&(~(1<<x));
        }else if(op=="check"){
            if(s&(1<<x)) cout<<1<<'\n';
            else cout<<0<<'\n';
        }else if(op=="toggle"){
            s=s^(1<<x);
        }else if(op=="all"){
            s=(1<<21)-1;
        }else if(op=="empty"){
            s=0;
        }
    }
    return 0;
}
