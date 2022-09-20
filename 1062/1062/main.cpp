//
//  main.cpp
//  1062
//
//  Created by 박하늘 on 2021. 4. 17..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
string word[50];
int used = 0;
int chk[27], n, k;
char ex[5] = {'a', 'n', 't', 'i', 'c'};
vector<bool> bit;
void preprocess(int);
int main(int argc, const char * argv[]) {
    int i, j;
    cin >> n >> k;
    k = k-5;
    if(k<0){
        cout << 0;
        exit(0);
    }
    for(i=0; i<5; i++){
        chk[ex[i]-'a'] = -1;
    }
    for(i=0; i<n; i++){
        cin >> word[i];
        preprocess(i);
    }
    for(i=0; i<used; i++){
        if(i<k) bit.push_back(true);
        else bit.push_back(false);
    }
    int max = 0, learned = 0;
    do{
        learned = 0;
        for(i=0; i<n; i++){
            int length = word[i].length();
            for(j=0; j<length; j++){
                if(chk[word[i][j]-'a'] == -1){
                }else if(bit[chk[word[i][j]-'a']-1] == false) break;
            }
            if(j == length) learned++;
        }
        if(learned > max) max = learned;
    }while(prev_permutation(bit.begin(), bit.end()));
    cout << max;
    return 0;
}
void preprocess(int idx){
    word[idx].replace(0, 4, "");
    word[idx].replace(word[idx].length()-4, word[idx].length()-1, "");
    int length = word[idx].length();
    for(int i=0; i<length; i++){
        if(chk[word[idx][i]-'a'] == 0){
            used++;
            chk[word[idx][i]-'a'] = used;
        }
    }
    return;
}
