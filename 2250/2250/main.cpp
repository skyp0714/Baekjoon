//
//  main.cpp
//  2250
//
//  Created by 박하늘 on 2021. 4. 4..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;
#define max_node 10010
struct Node {
    int left;
    int right;
};
Node tree[max_node];
void inorder(int, int);
int cnt, max_level;
int small[max_node], big[max_node], par[max_node];
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].left = b;
        par[b]++;
        tree[a].right = c;
        par[c]++;
        small[i] = n;
    }
    int root = 1;
    for(int i=1; i<=n; i++){
        if(!par[i]){
            root = i;
            break;
        }
    }
    inorder(root, 0);
    int max = -1, answer;
    for(int i=0; i<=max_level; i++){
        int temp = big[i] - small[i];
        if(temp > max){
            max = temp;
            answer = i;
        }
    }
    cout << answer + 1 << " " << max + 1;
    return 0;
}
void inorder(int x, int level){
    if(x == -1) return;
    if(level > max_level) max_level = level;
    inorder(tree[x].left, level+1);
    if(small[level] > cnt) small[level] = cnt;
    if(big[level] < cnt) big[level] = cnt;
    cnt++;
    inorder(tree[x].right, level+1);
    return;
}
