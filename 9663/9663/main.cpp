//
//  main.cpp
//  9663
//
//  Created by 박하늘 on 2021. 4. 11..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int n, cnt;
vector<pair<int, int>> mem;
void go(int);
bool chk(int, int);
int main(int argc, const char * argv[]) {
    cin >> n;
    go(0);
    cout << cnt;
    return 0;
}
void go(int q){
    if(q == n){
        cnt++;
        return;
    }
    for(int j=0; j<n; j++){
        if(chk(q, j)){
            mem.push_back(make_pair(q, j));
            go(q+1);
            mem.pop_back();
        }
    }
    return;
}
bool chk(int x, int y){
    for(auto p : mem){
        if(p.first == x) return false;
        if(p.second == y) return false;
        if(abs(p.first-x) == abs(p.second-y)) return false;
    }
    return true;
}
