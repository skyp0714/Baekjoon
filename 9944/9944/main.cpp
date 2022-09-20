#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
char map[31][31];
int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, n, m;
int go(int x, int y);
bool isinside(int x, int y){
    return x>=0 && x<n && y>=0 && y<m;
}
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 0;
    while(cin >> n >> m){
        t++;
        int min = 1000001;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin >> map[i][j];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == '.'){
                    map[i][j] = '#';
                    int tmp = go(i, j);
                    map[i][j] = '.';
                    if(min > tmp) min = tmp;
                }
            }
        }
        if(min == 1000001) min = -1;
        cout << "Case " << t << ": " << min << '\n';
    }
    return 0;
}
int go(int x, int y){
    int i, min = 1000001;
    int cnt;
    for(i=0; i<4; i++){
        
        int nx = x + dx[i], ny = y + dy[i];
        cnt = 0;
        
        while(isinside(nx, ny)){
            if(map[nx][ny] == '.'){
                cnt++;
                map[nx][ny] = '#';
                nx += dx[i]; ny += dy[i];
            }else{
                break;
            }
        }
        
        if(cnt){
            nx = nx - dx[i]; ny = ny - dy[i];
            int tmp = go(nx, ny);
            if(min > tmp) min = tmp;
            while(cnt--){
                map[nx][ny] = '.';
                nx -= dx[i]; ny -= dy[i];
            }
        }
        
    }
    if(min == 1000001){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(map[i][j] == '.'){
                    return min;
                }
            }
        }
        return 0;
    }
    return min+1;
}
