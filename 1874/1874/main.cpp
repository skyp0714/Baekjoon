//
//  main.cpp
//  1874
//
//  Created by 박하늘 on 2020. 9. 8..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <stack>
#define max 100000
using namespace std;
int main(int argc, const char * argv[]) {
    int n,cur=0,a,top=0,i=0,cnt=0;
    stack<int> stack;
    char ans[max*2];
    scanf("%d",&n);
    while(cnt<n){
        scanf("%d",&a);
        cnt++;
        if(a>cur){
            while(a>cur){
                ans[i++]='+';
                cur++;
                stack.push(cur);
            }
            ans[i++]='-';
            stack.pop();
        }else if(a<cur){
            if(stack.top()==a){
                ans[i++]='-';
                stack.pop();
            }else{
                while(cnt<n){
                    scanf("%d",&a);
                    cnt++;
                }
                cout<<"NO"<<'\n';
                exit(0);
            }
        }
    }
    if(top==0&&cur==n){
        for(i=0;i<2*n;i++){
            cout<<ans[i]<<'\n';
        }
    }
    return 0;
}
