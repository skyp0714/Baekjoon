//
//  main.cpp
//  4196
//
//  Created by SKY on 2022/01/10.
//

#include <iostream>
#include <stack>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int visit[100001];
vector<int> g[100001], revg[100001];
stack<int> st;
int sccin[100001];

void dfs(int x){
    visit[x] = 1;
    for(int a : g[x]){
        if(!visit[a]) dfs(a);
    }
    st.push(x);
}
void revdfs(int x, int scc_id){
    visit[x] = scc_id;
    for(int a : revg[x]){
        if(!visit[a]) revdfs(a, scc_id);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int v, e, a, b, i, scc_id = 1, tc = 0, scc_cnt = 0;
    cin >> tc;
    while(tc){
        tc--;
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
            revdfs(a, scc_id);
            scc_id++;
        }
        for(i=1; i<=v; i++){
            for(int a: g[i]){
                if(visit[i] == visit[a])continue;
                sccin[visit[a]]++;
            }
        }
        for(i=1; i<scc_id; i++){
            if(sccin[i]) continue;
            scc_cnt++;
        }
        cout << scc_cnt << '\n';
        
        scc_id = 1;
        scc_cnt = 0;
        for(i=1; i<v; i++){
            g[i].clear();
            revg[i].clear();
            sccin[i] = 0;
        }
        memset(visit, 0, sizeof(visit));
    }
}
