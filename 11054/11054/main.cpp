//
//  main.cpp
//  11054
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <iostream>
int a[1000],d[1000],n;
int inc(int e);
int dec(int s);
int main(int argc, const char * argv[]) {
    int i,ans=0;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        d[i]=1;
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        d[i]=inc(i)+dec(i)-1;
        if(ans<d[i]) ans=d[i];
    }
    printf("%d",ans);
    return 0;
}
int inc(int e){
    int i,j,f[1000];
    if(e==0) return 1;
    f[0]=1;
    for(i=1;i<e+1;i++){
        f[i]=1;
        for(j=0;j<i;j++){
            if(a[j]<a[i]) f[i]=(f[i]>f[j]+1)?f[i]:(f[j]+1);
        }
    }
    return f[e];
}
int dec(int s){
    int i,j,f[1000];
    if(s==n-1) return 1;
    f[n-1]=1;
    for(i=n-2;i>=s;i--){
        f[i]=1;
        for(j=n-1;j>i;j--){
            if(a[j]<a[i]) f[i]=(f[i]>f[j]+1)?f[i]:(f[j]+1);
        }
    }
    return f[s];
}
