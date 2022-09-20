//
//  main.cpp
//  4902
//
//  Created by 박하늘 on 2021. 5. 9..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector<vector<int>> tri, subsum;
int sub_max(int x, int y);
bool isinside(int x, int y){
    if(x>=0 && x<n)
        if(y>=0 && y<tri[x].size()) return true;
    return false;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i, j, max, ans, t=0;
    while(true){
        t++;
        cin >> n;
        if(n == 0) break;
        tri.clear();
        subsum.clear();
        for(i=0; i<n; i++){
            vector<int> a, b;
            int sum = 0;
            for(j=0; j<2*i+1; j++){
                int c;
                cin >> c;
                sum += c;
                a.push_back(c);
                b.push_back(sum);
            }
            tri.push_back(a);
            subsum.push_back(b);
        }
        ans = -2000;
        for(i=0; i<tri.size(); i++){
            for(j=0; j<tri[i].size(); j++){
                max = sub_max(i, j);
                if(max > ans) ans = max;
            }
        }
        cout << t << ". " << ans << '\n';
    }
    return 0;
}
int sub_max(int x, int y){
    int level = x, ly = y, ry = y;
    int sum = tri[x][y], max = tri[x][y];
    for(int i=1; ;i++){
        if(y%2 == 0){
            level = x + i;
            ry = y + 2 * i;
        }else{
            level = x - i;
            ly = y - 2 * i;
        }
        if(isinside(level, ly) && isinside(level, ry)){
            if(ly == 0) sum += subsum[level][ry];
            else sum += (subsum[level][ry] - subsum[level][ly-1]);
            if(sum > max) max = sum;
        }else break;
    }
    return max;
}
