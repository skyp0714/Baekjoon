//
//  main.cpp
//  14225
//
//  Created by 박하늘 on 2021. 4. 11..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int n, a[20];
bool c[20 * 100000 + 1];
void go(int i, int sum);
int main(int argc, const char * argv[]) {
    int i;
    cin >> n;
    for(i=0; i<n; i++) cin >> a[i];
    go(0, 0);
    for(i=1;; i++){
        if(!c[i]) break;
    }
    cout << i;
    return 0;
}
void go(int i, int sum){
    if(i==n){
        c[sum] = true;
        return;
    }
    go(i+1, sum+a[i]);
    go(i+1, sum);
}
