//
//  main.cpp
//  2150
//
//  Created by SKY on 2022/01/10.
//

#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
bool visit[10001];
vector<int> g[10001], revg[10001], scc[10001];
vector<pair<int, int>> order;
stack<int> st;

void dfs(int x){
    visit[x] = 1;
    for(int a : g[x]){
        if(!visit[a]) dfs(a);
    }
    st.push(x);
}
void revdfs(int x, int cnt){
    visit[x] = 1;
    scc[cnt].push_back(x);
    for(int a : revg[x]){
        if(!visit[a]) revdfs(a, cnt);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v, e, a, b, i, cnt = 0;
    cin >> v >> e;
    for(i=0; i<e; i++){
        cin >> a >> b;
        g[a].push_back(b);
        revg[b].push_back(a);
    }
    for(i=1; i<=v; i++){
        if(!visit[i]) dfs(i);
    }
    memset(visit, 0, sizeof(visit));
    while(!st.empty()){
        a = st.top();
        st.pop();
        if(visit[a]) continue;
        revdfs(a, cnt);
        cnt++;
    }
    cout << cnt << '\n';
    for(i=0; i<cnt; i++){
        sort(scc[i].begin(), scc[i].end());
        order.push_back({scc[i][0], i});
    }
    sort(order.begin(), order.end());
    for(i=0; i<cnt; i++){
        for(int a : scc[order[i].second]){
            cout << a << ' ';
        }
        cout << -1 <<'\n';
    }
}
