//
//  main.cpp
//  14888
//
//  Created by 박하늘 on 2021. 4. 6..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, const char * argv[]) {
    int n, a[12], op;
    vector<int> v;
    cin >> n;
    for(int i=0; i<n; i++)  cin >> a[i];
    for(int i=0; i<4; i++){
        cin >> op;
        for(int j=0; j<op; j++){
            v.push_back(i);
        }
    }
    int max = -1000000000, min = 1000000000;
    do{
        int num = a[0];
        for(int i=0; i<n-1; i++){
            switch(v[i]){
                case 0:
                    num = num + a[i+1];
                    break;
                case 1:
                    num = num - a[i+1];
                    break;
                case 2:
                    num = num * a[i+1];
                    break;
                case 3:
                    num = num / a[i+1];
                    break;
            }
        }
        if(max < num) max = num;
        if(min > num) min = num;
    }while(next_permutation(v.begin(), v.end()));
    cout << max << '\n' << min;
    return 0;
}
