//
//  main.cpp
//  1158
//
//  Created by 박하늘 on 2020. 9. 9..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int main(int argc, const char * argv[]) {
    int n,k,i;
    queue<int> q;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++) q.push(i);
    i=0;
    cout<<'<';
    while(!q.empty()){
        for(int i=0;i<k-1;i++){
            q.push(q.front());
            q.pop();
        }
        if(i==n-1) printf("%d>",q.front());
        else printf("%d, ",q.front());
        i++;
        q.pop();
    }
    return 0;
}
