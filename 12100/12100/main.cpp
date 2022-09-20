//
//  main.cpp
//  12100
//
//  Created by 박하늘 on 2021. 4. 18..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <vector>
#define LIMIT 5
using namespace std;
vector<int> gen(int k);
int go(vector<vector<int>> , vector<int>);
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int i, j, max = 0;
    vector<vector<int>> map(n, vector<int> (n));
    for(i=0; i<n; i++){
        for(j=0; j<n;j++){
            cin >> map[i][j];
        }
    }
    for(int k=0; k<(1<<LIMIT*2); k++){
        vector<int> dirs = gen(k);
        int ans = go(map, dirs);
        if(max < ans) max = ans;
    }
    cout << max;
    return 0;
}
vector<int> gen(int k){
    vector<int> dirs(LIMIT);
    for(int i=0; i<LIMIT; i++){
        dirs[i] = (k&3);
        k >>= 2;
    }
    return dirs;
}
int go(vector<vector<int>> map, vector<int> dirs){
    int i, j, n=map.size(), ans = 0;
    vector<vector<int>> a(n, vector<int> (n));
    for(i=0; i<n; i++){
        for(j=0; j<n;j++){
            a[i][j] = map[i][j];
        }
    }
    bool chk_add[20];
    for(int dir : dirs){
        if(dir == 0){
            for(j=0; j<n; j++){
                memset(chk_add, false, sizeof(chk_add));
                for(i=1; i<n; i++){
                    if(a[i][j] == 0) continue;
                    int cur = i;
                    while(cur > 0){
                        if(a[cur-1][j] > 0){
                            if(a[cur-1][j] == a[cur][j] && chk_add[cur-1] == false){
                                a[cur-1][j] *= 2;
                                a[cur][j] = 0;
                                chk_add[cur-1] = true;
                            }
                            break;
                        }else if(a[cur-1][j] == 0){
                            a[cur-1][j] = a[cur][j];
                            a[cur][j] = 0;
                            cur--;
                        }
                    }
                }
            }
        }else if(dir == 1){
            for(i=0; i<n; i++){
                memset(chk_add, false, sizeof(chk_add));
                for(j=n-2; j>=0; j--){
                    if(a[i][j] == 0) continue;
                    int cur = j;
                    while(cur < n-1){
                        if(a[i][cur+1] > 0){
                            if(a[i][cur+1] == a[i][cur] && chk_add[cur+1] == false){
                                a[i][cur+1] *= 2;
                                a[i][cur] = 0;
                                chk_add[cur+1] = true;
                            }
                            break;
                        }else if(a[i][cur+1] == 0){
                            a[i][cur+1] = a[i][cur];
                            a[i][cur] = 0;
                            cur++;
                        }
                    }
                }
            }
        }else if(dir == 2){
            for(j=0; j<n; j++){
                memset(chk_add, false, sizeof(chk_add));
                for(i=n-2; i>=0; i--){
                    if(a[i][j] == 0) continue;
                    int cur = i;
                    while(cur < n-1){
                        if(a[cur+1][j] > 0){
                            if(a[cur+1][j] == a[cur][j] && chk_add[cur+1] == false){
                                a[cur+1][j] *= 2;
                                a[cur][j] = 0;
                                chk_add[cur+1] = true;
                            }
                            break;
                        }else if(a[cur+1][j] == 0){
                            a[cur+1][j] = a[cur][j];
                            a[cur][j] = 0;
                            cur++;
                        }
                    }
                }
            }
        }else if(dir == 3){
            for(i=0; i<n; i++){
                memset(chk_add, false, sizeof(chk_add));
                for(j=1; j<n; j++){
                    if(a[i][j] == 0) continue;
                    int cur = j;
                    while(cur > 0){
                        if(a[i][cur-1] > 0){
                            if(a[i][cur-1] == a[i][cur] && chk_add[cur-1] == false){
                                a[i][cur-1] *= 2;
                                a[i][cur] = 0;
                                chk_add[cur-1] = true;
                            }
                            break;
                        }else if(a[i][cur-1] == 0){
                            a[i][cur-1] = a[i][cur];
                            a[i][cur] = 0;
                            cur--;
                        }
                    }
                }
            }
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n;j++){
            if(ans < a[i][j]) ans = a[i][j];
        }
    }
    return ans;
}

