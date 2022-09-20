//
//  main.cpp
//  1339
//
//  Created by 박하늘 on 2021. 4. 6..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, const char * argv[]) {
    int chk[30] = {0,}, order[30];
    int n, cnt=0;
    string str[10];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> str[i];
        for(int j=0; j<str[i].length(); j++){
            if(!chk[str[i][j]-'A']){
                chk[str[i][j]-'A'] = 1;
                order[str[i][j]-'A'] = cnt;
                cnt++;
            }
        }
    }
    vector<int> v;
    int max = -1;
    for(int i=9; i>9-cnt; i--) v.push_back(i);
    do{
        int sum = 0;
        for(int i=0; i<n; i++){
            int add = 0;
            for(int j=0; j<str[i].length(); j++){
                add = add * 10 + v[order[str[i][j]-'A']];
            }
            sum += add;
        }
        if(max < sum) max = sum;
    }while(prev_permutation(v.begin(), v.end()));
    
    cout << max;
    return 0;
}
