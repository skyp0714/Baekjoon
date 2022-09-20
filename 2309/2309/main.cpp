//
//  main.cpp
//  2309
//
//  Created by 박하늘 on 2020. 9. 11..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
int main(){
    int n,i,j, a[9],sum=0,chk=0,temp;
    n=9;
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i]<a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    
    
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(sum-a[i]-a[j]==100) {
                chk=1;
                break;
            }
        }
        if(chk==1) break;
    }
    for(int k=0;k<n;k++){
        if(k!=i&&k!=j) printf("%d\n",a[k]);
    }
}
