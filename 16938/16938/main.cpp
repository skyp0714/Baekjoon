//
//  main.cpp
//  16938
//
//  Created by 박하늘 on 2021. 4. 22..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int inf, sup, dif;
int go(int sum, int first, int idx, int last, vector<int> a);
int main(int argc, const char * argv[]) {
    vector<int> a;
    int n, tmp;
    cin >> n >> inf >> sup >> dif;
    for(int i=0; i<n; i++){
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(), a.end());
    cout << go(0, 0, 0, 0, a);
    return 0;
}
int go(int sum, int first, int idx, int last, vector<int> a){
    int ans = 0;
    if(idx >= a.size()){
        if(sum >= inf && sum <= sup && last - first >= dif){
            return 1;
        }else{
            return 0;
        }
    }
    if(first){
        if(a[a.size()-1] < first + dif || sum > sup){
            return 0;
        }else{
            ans += go(sum+a[idx], first, idx+1, a[idx], a);
            ans += go(sum, first, idx+1, last, a);
        }
    }else{
        ans += go(sum+a[idx], a[idx], idx+1, a[idx], a);
        ans += go(sum, first, idx+1, last, a);
    }
    return ans;
}
