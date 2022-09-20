//
//  main.cpp
//  16198
//
//  Created by 박하늘 on 2021. 4. 11..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int go(vector<int> &w){
    int n = w.size();
    if(n == 2) return 0;
    int ans = 0;
    for(int i=1; i<n-1; i++){
        int energy = w[i-1] * w[i+1];
        vector<int> b(w);
        b.erase(b.begin()+i);
        energy += go(b);
        if(ans < energy){
            ans = energy;
        }
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    int n, a;
    cin >> n;
    vector<int> w(n);
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    cout << go(w);
    return 0;
}
