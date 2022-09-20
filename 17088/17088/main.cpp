//
//  main.cpp
//  17088
//
//  Created by 박하늘 on 2021. 4. 24..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int b[100010];
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int min = 2*n;
    for(int i=0; i<n; i++)
        cin >> b[i];
    for(int i=-1; i<2; i++){
        for(int j=-1; j<2; j++){
            int cnt = 0;
            int a[2] = {b[0], b[1]};
            bool done = true;
            b[0] = b[0] + i;
            b[1] = b[1] + j;
            cnt = cnt + abs(i) + abs(j);
            int diff = b[0]-b[1];
            int prev = b[1];
            for(int k=2; k<n; k++){
                int cor = prev - diff;
                if(abs(cor - b[k]) <= 1){
                    cnt = cnt + abs(cor - b[k]);
                    prev = cor;
                }else{
                    done = false;
                    break;
                }
            }
            if(done && min > cnt) min = cnt;
            b[0] = a[0];
            b[1] = a[1];
        }
    }
    if(min == 2*n)  cout << -1;
    else    cout << min;
    return 0;
}
