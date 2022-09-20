//
//  main.cpp
//  1991
//
//  Created by 박하늘 on 2021. 4. 4..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node {
    int left;
    int right;
};
Node a[30];
void preorder(int);
void inorder(int);
void postorder(int);
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char b[3];
        for(int j=0; j<3;j++){
            cin >> b[j];
            if(b[j] == '.') b[j] = -1;
            else b[j] = b[j] - 'A';
        }
        a[b[0]].left = b[1];
        a[b[0]].right = b[2];
    }
    preorder(0);
    cout << '\n';
    inorder(0);
    cout << '\n';
    postorder(0);
    cout << '\n';
    return 0;
}
void preorder(int x){
    if(x == -1) return;
    cout << (char)('A' + x);
    preorder(a[x].left);
    preorder(a[x].right);
    return;
}
void inorder(int x){
    if(x == -1) return;
    inorder(a[x].left);
    cout << (char)('A' + x);
    inorder(a[x].right);
    return;
}
void postorder(int x){
    if(x == -1) return;
    postorder(a[x].left);
    postorder(a[x].right);
    cout << (char)('A' + x);
    return;
}
