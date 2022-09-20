//
//  main.cpp
//  2925
//
//  Created by 박하늘 on 2021. 4. 5..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#define max 10
using namespace std;
int k;
vector<int> v;
char a[max];
bool chk();
int main(int argc, const char * argv[]) {
    cin >> k;
    for(int i=0; i<k; i++)  cin >> a[i];
    for(int i=9; i>=9-k; i--){
        v.push_back(i);
    }
    do{
        if(chk()) break;
    }while(prev_permutation(v.begin(), v.end()));
    for(int i=0; i<=k; i++) cout << v[i];
    cout << '\n';
    v.clear();
    for(int i=0; i<=k; i++){
        v.push_back(i);
    }
    do{
        if(chk()) break;
    }while(next_permutation(v.begin(), v.end()));
    for(int i=0; i<=k; i++) cout << v[i];
    return 0;
}
bool chk(){
    for(int i=0; i<k; i++){
        if(a[i] == '>'){
            if(v[i]<=v[i+1]) return false;
        }else{
            if(v[i]>=v[i+1]) return false;
        }
    }
    return true;
}
