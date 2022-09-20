//
//  main.cpp
//  16637
//
//  Created by 박하늘 on 2021. 4. 23..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int make_mask(int idx, int end, vector<int> mask);
int cal(vector<int> mask, int end);
int eval(int a, int b, char o);
int num[12];
char op[12];
int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        if(i%2)
            cin >> op[i/2];
        else
            cin >> num[i/2];
    }
    vector<int> mask;
    for(int i=0; i<n/2; i++)
        mask.push_back(0);
    cout << make_mask(0, n/2, mask);
    return 0;
}
int make_mask(int idx, int end, vector<int> mask){
    if(idx >= end){
        return cal(mask, end);
    }
    int max = -2147483648;
    int tmp = make_mask(idx+1, end, mask);
    if(max < tmp) max = tmp;
    mask[idx] = 1;
    tmp = make_mask(idx+2, end, mask);
    if(max < tmp) max = tmp;
    return max;
}
int cal(vector<int> mask, int end){
    char op_new[12];
    int num_new[12];
    int ni=0, oi=0;
    for(int i=0; i<end; i++){
        if(i==0){
            if(mask[i]){
                num_new[ni] = eval(num[i], num[i+1], op[i]);
                ni++;
            }else{
                num_new[ni] = num[i];
                ni++;
                op_new[oi] = op[i];
                oi++;
                num_new[ni] = num[i+1];
                ni++;
            }
        }else{
            if(mask[i]){
                ni--;
                num_new[ni] = eval(num[i], num[i+1], op[i]);
                ni++;
            }else{
                op_new[oi] = op[i];
                oi++;
                num_new[ni] = num[i+1];
                ni++;
            }
        }
    }
    int ans;
    end = oi;
    if(oi){
        ans = eval(num_new[0], num_new[1], op_new[0]);
    }else{
        ans = num_new[0];
    }
    for(int i=1; i<end; i++){
        ans = eval(ans, num_new[i+1], op_new[i]);
    }
    return ans;
}
int eval(int a, int b, char o){
    if(o == '+'){
        return a + b;
    }else if(o == '-'){
        return a - b;
    }else if(o == '*'){
        return a * b;
    }
    return -1;
}
