//
//  main.cpp
//  16943
//
//  Created by 박하늘 on 2021. 4. 22..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    int b;
    cin >> s >> b;
    if(stoi(s) > b){
        do{
            if(stoi(s) <= b && s[0] != '0'){
                cout << s;
                return 0;
            }
        }while(prev_permutation(s.begin(), s.end()));
    }else{
        do{
            if(stoi(s)>b){
                prev_permutation(s.begin(), s.end());
                if(s[0] != '0'){
                    cout << s;
                    return 0;
                }
                next_permutation(s.begin(), s.end());
            }
        }while(next_permutation(s.begin(), s.end()));
    }
    prev_permutation(s.begin(), s.end());
    if(stoi(s) <= b && s[0] != '0')
        cout << s;
    else
        cout << -1;
    return 0;
}
