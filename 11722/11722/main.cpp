//
//  main.cpp
//  11722
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n, i,j, a[1000],d[1000],ans=1;
    scanf("%d", &n);
    for(i=0;i<n;i++){
        d[i]=1;
        scanf("%d",&a[i]);
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[j]>a[i]) d[i]=(d[i]>d[j]+1)?d[i]:(d[j]+1);
        }
    }
    for(i=0;i<n;i++)if(ans<d[i]) ans=d[i];
    printf("%d",ans);
    return 0;
}
