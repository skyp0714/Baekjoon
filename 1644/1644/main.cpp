//
//  main.cpp
//  1644
//
//  Created by 박하늘 on 2021. 7. 7..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;
bool isprime[4000001];
int a[1000000];
int main(int argc, const char * argv[]) {
    int n, i, j, cnt = 0;
    cin >> n;
    memset(isprime, true, sizeof(isprime));
    isprime[0] = isprime[1] = false;
    for(i=2;i<4000000;i++){
        for(j=2;(i*j<=4000000);j++){
            isprime[i*j] = false;
        }
    }
    int end = 0;
    for(i=2;i<=n;i++){
        if(isprime[i]){
            a[end] = i;
            end++;
        }
    }
    
    i=0; j=0;
    int sum = a[0];
    while(j < end){
        if(sum == n){
            cnt++;
            j++;
            sum += a[j];
        }else if(sum < n){
            j++;
            sum += a[j];
        }else if(sum > n){
            sum -= a[i];
            i++;
        }
    }
    cout << cnt;
    
    return 0;
}

