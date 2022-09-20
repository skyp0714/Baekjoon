//
//  main.cpp
//  11057
//
//  Created by 박하늘 on 2020. 8. 17..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    long long int n,d[1001][10],mod=10007;
    scanf("%lld",&n);
    for (int i=0; i<10; i++) d[1][i] = 1;
    for (int i=2; i<=n; i++) {
        d[i][0]=d[i-1][0];
        for (int j=1; j<10; j++) {
            d[i][j]=(d[i-1][j]+d[i][j-1])%mod;
        }
    }
    long long ans = 0;
    for (int i=0; i<10; i++) ans += d[n][i];
    ans %= mod;
    printf("%lld",ans);
    return 0;
}
