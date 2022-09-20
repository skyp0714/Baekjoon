//
//  main.cpp
//  1806
//
//  Created by 박하늘 on 2021. 7. 7..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int a[100001];
int main(int argc, const char * argv[]) {
    int n, m, i, j, ans=100001;
    cin >> n >> m;
    for(i=0; i<n; i++) cin >> a[i];
    i=0; j=0;
    int sum = a[0];
    while(j < n){
        if(sum < m){
            j++;
            sum += a[j];
        }else if(sum >= m){
            if(j-i+1 < ans) ans = j-i+1;
            sum -= a[i];
            i++;
        }
    }
    if(ans == 100001) ans = 0;
    cout << ans;
    return 0;
}
