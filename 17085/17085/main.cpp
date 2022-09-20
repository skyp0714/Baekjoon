#include <iostream>
using namespace std;
char map[15][15];
int n, m, dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
void change_map(int x, int y , int len, char a);
int max_cross(int x, int y);
int area(int len){
    return len * 4 + 1;
}
bool isinside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
int find_len(int, int);
int main() {
    int max, ans = 0;
    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> map[i][j];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == '#'){
                int len = find_len(i, j);
                for(int k=0;k<=len;k++){
                    change_map(i, j, k, '.');
                    max = max_cross(i, j) * area(k);
                    if(max > ans) ans = max;
                    change_map(i, j, k, '#');
                }
            }
        }
    }
    cout << ans;
    return 0;
}
int max_cross(int x, int y){
    int i, j, max = 0;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(map[i][j] == '#'){
                int len = find_len(i, j);
                if(max < len) max = len;
            }
        }
    }
    return area(max);
}
void change_map(int x, int y , int len, char a){
    map[x][y] = a;
    for(int i=0; i<4; i++){
        int nx = x + dx[i], ny = y+ dy[i];
        for(int j=0; j<len; j++){
            map[nx][ny] = a;
            nx += dx[i]; ny += dy[i];
        }
    }
    return;
}
int find_len(int x, int y){
    int len = 0, i;
    while(true){
        len++;
        for(i=0; i<4; i++){
            int nx = x + len * dx[i], ny = y + len * dy[i];
            if(!isinside(nx, ny)) break;
            if(map[nx][ny] != '#') break;
        }
        if(i != 4){
            len--;
            break;
        }
    }
    return len;
}
