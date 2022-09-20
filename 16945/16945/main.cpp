//
//  main.cpp
//  16945
//
//  Created by 박하늘 on 2021. 5. 9..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
int mb[8][3][3] = {
    {8, 1, 6, 3, 5, 7, 4, 9, 2},
    {6, 1, 8, 7, 5, 3, 2, 9, 4},
    {2, 9, 4, 7, 5, 3, 6, 1, 8},
    {4, 9, 2, 3, 5, 7, 8, 1, 6},
    {6, 7, 2, 1, 5, 9, 8, 3, 4},
    {8, 3, 4, 1, 5, 9, 6, 7, 2},
    {2, 7, 6, 9, 5, 1, 4, 3, 8},
    {4, 3, 8, 9, 5, 1, 2, 7, 6},
};
int map[3][3];
int find_cost(int k);
int main() {
    int i, j, ans = 100;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            cin >> map[i][j];
    
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(int k=0; k<8; k++){
                int tmp = find_cost(k);
                if(ans > tmp) ans = tmp;
            }
        }
    }
    cout << ans;
    return 0;
}
int find_cost(int k){
    int sum = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            sum += abs(map[i][j]-mb[k][i][j]);
        }
    }
    return sum;
}
