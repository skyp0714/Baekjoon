//
//  main.cpp
//  1912
//
//  Created by 박하늘 on 2020. 8. 16..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    int n,sum,max,num;
    scanf("%d",&n);
    scanf("%d",&num);
    max=num;
    sum=num;
    for(int i=1;i<n;i++){
        scanf("%d",&num);
        if(sum>0) sum+=num;
        else sum=num;
        max=(max>sum)?max:sum;
    }
    printf("%d",max);
    return 0;
}
