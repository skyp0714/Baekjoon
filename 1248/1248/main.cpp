//
//  main.cpp
//  1248
//
//  Created by 박하늘 on 2020. 8. 28..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int sign[10][10],ans[10];
bool go(int index);
bool check(int index);
int main(int argc, const char * argv[]) {
    cin>>n;
    char a;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            cin>>a;
            if(a=='0') sign[i][j]=0;
            if(a=='+') sign[i][j]=1;
            if(a=='-') sign[i][j]=-1;
        }
    }
    if(go(0)) for(int i=0;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}
bool go(int index){
    if(index==n) return true;
    if (sign[index][index] == 0) {
        ans[index] = 0;
        return check(index) && go(index+1);
    }
    for(int i=1;i<=10;i++){
        ans[index]=sign[index][index]*i;
        if(check(index)&&go(index+1)) return true;
    }
    return false;
}
bool check(int index){
    int sum=0;
    for(int i=index;i>=0;i--){
        sum+=ans[i];
        if(sum>0&&sign[i][index]!=1) return false;
        else if(sum==0&&sign[i][index]!=0) return false;
        else if(sum<0&&sign[i][index]!=-1) return false;
    }
    return true;
}
