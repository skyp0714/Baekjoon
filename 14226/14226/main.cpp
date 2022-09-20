//
//  main.cpp
//  14226
//
//  Created by 박하늘 on 2021. 4. 3..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

#define max 1001
int dist[max][max];
int bfs(int, int, int);
bool go(int, int);
int main(int argc, const char * argv[]) {
    int s;
    cin >> s ;
    int ans = bfs(1, 0, s);
    cout << ans << '\n';
    return 0;
}
bool go(int s, int c){
    if(s>=0 && s<max && c>=0 && c<max && dist[s][c]==0) return true;
    return false;
}
int bfs(int s, int c, int goal){
    queue<int> qs, qc;
    qs.push(s);
    qc.push(c);
    dist[s][c] = 1;
    while(!qs.empty()){
        s = qs.front(); c = qc.front();
        qs.pop(); qc.pop();
        int next[3][2];
        next[0][0] = s;    next[0][1] = s;
        next[1][0] = s + c; next[1][1] = c;
        next[2][0] = s - 1; next[2][1] = c;
        for(int i=0; i<3; i++){
            if(go(next[i][0], next[i][1])){
                qs.push(next[i][0]); qc.push(next[i][1]);
                dist[next[i][0]][next[i][1]] = dist[s][c] + 1;
            }
        }
    }
    int min = max;
    for(int i=0; i<max; i++){
        if(dist[goal][i] && min > dist[goal][i]) min = dist[goal][i];
    }
    return min-1;
}
