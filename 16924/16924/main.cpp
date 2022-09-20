//
//  main.cpp
//  16924
//
//  Created by 박하늘 on 2021. 4. 20..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
struct cross{
    int x;
    int y;
    int length;
};
vector<cross> c;
char map[101][101];
int chk[101][101], n, m;
void check_cross(int, int);
int main(int argc, const char * argv[]) {
    
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> map[i][j];
            chk[i][j] = 1;
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] == '*'){
                check_cross(i, j);
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(map[i][j] == '*' && chk[i][j] == 1){
                cout << -1;
                return 0;
            }
        }
    }
    cout << c.size() << '\n';
    for(cross d : c){
        cout << d.x << " " <<d.y << " " << d.length << '\n';
    }
    return 0;
}
void check_cross(int x, int y){
    int len = 1;
    while(true){
        int lx = x-len, hx = x+len, ly = y-len, hy = y+len;
        if(hx <= n && lx > 0 && hy <= m && ly > 0){
            if(map[x][hy] == '*' && map[x][ly] == '*' && map[lx][y] == '*' && map[hx][y] == '*'){
                chk[x][y] = chk[lx][y] = chk[hx][y] = chk[x][ly] = chk[x][hy] = 0;
                cross d = {x, y, len};
                if(!c.empty())
                    if(c.back().x == x && c.back().y == y)
                        c.pop_back();
                c.push_back(d);
                len++;
            }else{
                break;
            }
        }else{
            break;
        }
    }
}
