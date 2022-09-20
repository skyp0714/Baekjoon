//
//  main.cpp
//  14002
//
//  Created by 박하늘 on 2020. 8. 16..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int  a[1001],d[1001],v[1001];
void print(int i);
int main(int argc, const char * argv[]) {
    int n, i,j,ans=1,s=1;
    scanf("%d", &n);
    for(i=1;i<=n;i++){
        d[i]=1;
        scanf("%d",&a[i]);
    }
    for(i=2;i<=n;i++){
        for(j=1;j<i;j++){
            if(a[j]<a[i]&&d[i]<d[j]+1){
                d[i]=d[j]+1;
                v[i]=j;
            }
        }
    }
    for(i=1;i<=n;i++){
        if(ans<d[i]){
            ans=d[i];
            s=i;
        }
    }
    printf("%d\n",ans);
    print(s);
    return 0;
}
void print(int i){
    if(i==0) return;
    print(v[i]);
    printf("%d ",a[i]);
    return;
}
