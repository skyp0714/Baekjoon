//
//  main.cpp
//  1707
//
//  Created by 박하늘 on 2020. 9. 2..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
#define max_n 20001
#define max_m 200001
using namespace std;
int group[max_n];
vector<int> v[max_n];
bool dfs(int,int);
int main(int argc, const char * argv[]) {
    int n,m,a,b,t,i;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=1;i<=n;i++)    group[i]=0;
        for(i=0;i<m;i++){
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=1;i<=n;i++){
            if(!group[i]){
                if(!dfs(i,1)){
                    cout<<"NO"<<endl;
                    i=0;
                    break;
                }
            }
        }
        if(i) cout<<"YES"<<endl;
        for(i=1;i<=n;i++) v[i].clear();
    }
    return 0;
}
bool dfs(int s,int g){
    group[s]=g;
    for(int i=0;i<v[s].size();i++){
        int next=v[s][i];
        if(!group[next]){
            if(!dfs(next,3-g)) return false;
        }
        if(group[next]==group[s]) return false;
    }
    return true;
}
