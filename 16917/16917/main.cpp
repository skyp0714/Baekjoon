//
//  main.cpp
//  16917
//
//  Created by 박하늘 on 2021. 4. 20..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int cost[3], x, y;
int main(int argc, const char * argv[]) {
    for(int i=0; i<3; i++)
        cin >> cost[i];
    cin >> x >> y;
    int ans = 0, diff = x - y;
    if(cost[0] + cost[1] > 2 * cost[2]){
        if(diff > 0){
            ans = y * 2 * cost[2];
            if(cost[0] > 2 * cost[2]){
                ans += diff * 2 * cost[2];
            }else{
                ans += diff * cost[0];
            }
        }else{
            ans = x * 2 * cost[2];
            if(cost[1] > 2 * cost[2]){
                ans -= diff * 2 * cost[2];
            }else{
                ans -= diff * cost[1];
            }
        }
    }else{
        ans = y * cost[1] + x * cost[0];
    }
    cout << ans;
    return 0;
}
