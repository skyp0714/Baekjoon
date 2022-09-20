//
//  main.cpp
//  2529
//
//  Created by 박하늘 on 2020. 8. 28..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int n,cnt,check[10];
string ans[20000];
char a[10];
void go(int index, string num);
bool good(char, char, char);
int main(int argc, const char * argv[]) {
    int i;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    go(0,"");
    cout<<ans[cnt-1]<<endl<<ans[0];
    return 0;
}
void go(int index, string num) {
    if (index == n+1) {
        ans[cnt]=num;
        cnt++;
        return;
    }
    for (int i=0; i<=9; i++) {
        if (check[i]) continue;
        if (index == 0 || good(num[index-1], i+'0', a[index-1])) {
            check[i] = true;
            go(index+1, num+to_string(i));
            check[i] = false;
        }
    }
}
bool good(char a, char b, char op){
switch(op){
    case '>':
        if(a>b) return true;
        break;
    case '<':
        if(a<b) return true;
        break;
}
    return false;
}
