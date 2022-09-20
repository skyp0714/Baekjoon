//
//  main.cpp
//  15658
//
//  Created by 박하늘 on 2021. 4. 11..
//  Copyright © 2021년 박하늘. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int minimum=1000000000, maximum=-1000000000, n, a[12];
void go(int, int, int, int, int, int);
int main(int argc, const char * argv[]) {
    int op[4];
    cin >> n;
    for(int i=0; i<n; i++)  cin >> a[i];
    for(int i=0; i<4; i++)  cin >> op[i];
    go(0, a[0], op[0], op[1], op[2], op[3]);
    cout << maximum << '\n' << minimum;
    return 0;
}
void go(int idx, int sum, int plus, int minus, int mul, int div){
    if(idx == n-1){
        if(sum < minimum) minimum = sum;
        if(sum > maximum) maximum= sum;
        return;
    }
    idx++;
    if(plus) go(idx, sum+a[idx], plus-1, minus, mul, div);
    if(minus) go(idx, sum-a[idx], plus, minus-1, mul, div);
    if(mul) go(idx, sum*a[idx], plus, minus, mul-1, div);
    if(div) go(idx, sum/a[idx], plus, minus, mul, div-1);
    return;
}
