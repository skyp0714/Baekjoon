//
//  main.cpp
//  16922
//
//  Created by 박하늘 on 2021. 4. 20..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, i, j, k, cnt = 0;
    int sum[1050] = {0, };
    cin >> n;
    for(i=0; i<=n; i++){
        for(j=0; j<=n-i; j++){
            for(k=0; k<=n-i-j; k++){
                sum[i + 5 * j + 10 * k + 50 * (n-i-j-k)] = 1;
            }
        }
    }
    for(int i=1; i<=1000; i++){
        if(sum[i]) cnt++;
    }
    cout << cnt;
    return 0;
}
