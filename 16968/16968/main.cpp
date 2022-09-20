//
//  main.cpp
//  16968
//
//  Created by 박하늘 on 2021. 4. 20..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    cin >> s;
    int ans = 1, mul_c= 26, mul_i = 10;
    char prev = '0';
    for(char x : s){
        if(x == prev){
            if(x == 'd')
                mul_i = 9;
            else
                mul_c = 25;
        }else{
            mul_c= 26;
            mul_i = 10;
        }
        if(x == 'd')
            ans *= mul_i;
        else
            ans *= mul_c;
        prev = x;
    }
    cout << ans;
    return 0;
}
