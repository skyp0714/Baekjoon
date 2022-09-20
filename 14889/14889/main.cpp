//
//  main.cpp
//  14889
//
//  Created by 박하늘 on 2020. 8. 28..
//  Copyright © 2020년 박하늘. All rights reserved.
//
// all case can be iterated by means of bitmask
#include <iostream>
int s[20][20],a[10],b[10],n;
int team(int,int,int);
int difference();
int main(int argc, const char * argv[]) {
    int ans;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++) scanf("%d",&s[i][j]);
    ans=team(-1,-1,-1);
    printf("%d",ans);
    return 0;
}
int team(int i, int ai, int bi){
    int min,temp;
    if(ai==n/2-1){
        if(bi==n/2-1) return difference();
        else{
            b[bi+1]=i+1;
            return team(i+1,ai,bi+1);
        }
    }else if(bi==n/2-1){
        a[ai+1]=i+1;
        return team(i+1,ai+1,bi);
    }
    a[ai+1]=i+1;
    min=team(i+1,ai+1,bi);
    if(min==0) return 0;
    else{
        b[bi+1]=i+1;
        temp=team(i+1,ai,bi+1);
        if(min>temp) min=temp;
    }
    return min;
}
int difference(){
    int an=0,bn=0,i,j;
    for(i=0;i<n/2;i++){
        for(j=i+1;j<n/2;j++){
            an+=s[a[i]][a[j]]+s[a[j]][a[i]];
            bn+=s[b[i]][b[j]]+s[b[j]][b[i]];
        }
    }
    return an>bn? an-bn: bn-an;
}
