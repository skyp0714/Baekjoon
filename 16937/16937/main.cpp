//
//  main.cpp
//  16937
//
//  Created by 박하늘 on 2021. 4. 20..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int h, w;
int maximum(int a, int b){
    if(a>b) return a;
    else return b;
}
bool con(int x1, int y1, int x2, int y2){
    return (x1 + x2 <= h && maximum(y1, y2) <= w) || (x1 + x2 <= w && maximum(y1, y2) <= h);
}
int main(int argc, const char * argv[]) {
    int n, x, y;
    cin >> h >> w >> n;
    vector<pair<int, int>> box;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        box.push_back(make_pair(x, y));
    }
    int max = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            int x1 = box[i].first, y1 = box[i].second;
            int x2 = box[j].first, y2 = box[j].second;
            if(con(x1,y1,x2,y2) || con(x1,y1,y2,x2) || con(y1,x1,x2,y2) || con(y1,x1,y2,x2)){
                int area = x1*y1 + x2*y2;
                if(area > max) max = area;
            }
        }
    }
    cout << max;
    return 0;
}
