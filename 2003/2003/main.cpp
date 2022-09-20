//
//  main.cpp
//  2003
//
//  Created by 박하늘 on 2021. 7. 7..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int a[10001];
int main(int argc, const char * argv[]) {
    int n, m, i, j, cnt=0;
    cin >> n >> m;
    for(i=0; i<n; i++) cin >> a[i];
    i=0; j=0;
    int sum = a[0];
    while(j < n){
        if(sum == m){
            cnt++;
            j++;
            sum += a[j];
        }else if(sum < m){
            j++;
            sum += a[j];
        }else if(sum > m){
            sum -= a[i];
            i++;
        }
    }
    cout << cnt;
    return 0;
}
