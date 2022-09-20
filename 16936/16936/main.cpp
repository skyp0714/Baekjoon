//
//  main.cpp
//  16936
//
//  Created by 박하늘 on 2021. 4. 20..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    vector<pair<long long int, long long int>> b;
    cin >> n;
    for(int i=0; i<n; i++){
        long long int x, y=0;
        cin >> x;
        long long int tmp = x;
        while(x%3 == 0){
            y++;
            x /= 3;
        }
        b.push_back(make_pair(tmp, y));
    }
    struct {
        bool operator()(pair<long long int, long long int> a1, pair<long long int, long long int> a2) const {
            if(a1.second == a2.second) return a1.first < a2.first;
            else return a1.second > a2.second;
        }
    } customLess;
    sort(b.begin(), b.end(), customLess);
    for(pair<long long int, long long int> p : b){
        cout << p.first << " ";
    }
    return 0;
}
