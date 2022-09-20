//
//  main.cpp
//  3085
//
//  Created by 박하늘 on 2020. 9. 11..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
char c[50][50];
int n;
int solve();
void swap(int,int,int,int);
int main(){
    int i,j,ans=0, num;
    scanf("%d\n",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%c",&c[i][j]);
        }
        cin.ignore();
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i<n-1){
                if(c[i][j]!=c[i+1][j]){
                    swap(i,j,i+1,j);
                    num=solve();
                    if(ans<solve()) ans=num;
                    swap(i,j,i+1,j);
                }
            }
            if(j<n-1){
                if(c[i][j]!=c[i][j+1]){
                    swap(i,j,i,j+1);
                    num=solve();
                    if(ans<num) ans=num;
                    swap(i,j,i,j+1);
                }
            }
        }
    }
    printf("%d",ans);
}
int solve(){
    int i,j,cnt=1,max=0;
    char temp;
    for(i=0;i<n;i++){
        temp=c[i][0];
        cnt=1;
        for(j=1;j<n;j++){
            if(temp==c[i][j]) cnt++;
            else cnt=1;
            if(max<cnt) max=cnt;
            temp=c[i][j];
        }
    }
    cnt=1;
    for(j=0;j<n;j++){
        temp=c[0][j];
        cnt=1;
        for(i=1;i<n;i++){
            if(temp==c[i][j]) cnt++;
            else cnt=1;
            if(max<cnt) max=cnt;
            temp=c[i][j];
        }
    }
    return max;
}
void swap(int x1,int y1,int x2,int y2){
    char temp;
    temp=c[x1][y1];
    c[x1][y1]=c[x2][y2];
    c[x2][y2]=temp;
    return;
}

