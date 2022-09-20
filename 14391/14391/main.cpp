//
//  main.cpp
//  14391
//
//  Created by 박하늘 on 2020. 8. 29..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int sol();
int a[4][4],c[4][4],n,m;
int main(int argc, const char * argv[]) {
    int max=0,temp;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) scanf("%1d",&a[i][j]);
    for(int i=0;i<(1<<n*m);i++){
        for(int j=0;j<n*m;j++){
            if(i&(1<<j)) c[j/m][j%m]=1;
            else c[j/m][j%m]=0;
        }
        temp=sol();
        if(temp>max)max=temp;
    }
    cout<<max;
    return 0;
}
int sol(){
    int i,j,temp,sum=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            temp=0;
            while(!c[i][j]&&j<m){
                temp=temp*10+a[i][j];
                j++;
            }
            sum+=temp;
        }
    }
    for(j=0;j<m;j++){
        for(i=0;i<n;i++){
            temp=0;
            while(c[i][j]&&i<n){
                temp=temp*10+a[i][j];
                i++;
            }
            sum+=temp;
        }
    }
    return sum;
}
