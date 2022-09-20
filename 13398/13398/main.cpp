//
//  main.cpp
//  13398
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int i,n,a[100000],dl[100000]={0,},dr[100000]={0,},ans,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    if(n==1){
        printf("%d",a[0]);
        return 0;
    }
    dl[0]=a[0];
    ans=a[0];
    for(i=1;i<n;i++){
        if(dl[i-1]>0) dl[i]=dl[i-1]+a[i];
        else dl[i]=a[i];
    }
    dr[n-1]=a[n-1];
    for(i=n-2;i>=0;i--){
        if(dr[i+1]>0) dr[i]=dr[i+1]+a[i];
        else dr[i]=a[i];
    }
    for(i=0;i<n;i++){
        if(i==0)temp=dr[1];
        else if(i==n-1) temp=dl[n-2];
        else temp=dl[i-1]+dr[i+1];
        temp=temp>dl[i]? temp: dl[i];
        if(ans<temp) ans=temp;
    }
    printf("%d",ans);
    return 0;
}
