//
//  main.cpp
//  1040
//
//  Created by 박하늘 on 2021. 4. 3..
//  Copyright © 2021년 박하늘. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

#define max 10
string solve(string, int, bool);
int maximum(int, int);
bool used[max], start_flag = true;
int main(int argc, const char * argv[]) {
    int k;
    string number, answer;
    cin >> number >> k ;
    answer = solve(number, k, true);
    
    if(answer == "wrong"){
        int length = maximum(k, number.length()+1);
        number = "1";
        for(int i=1; i<length; i++){
            number.append("0");
        }
        answer = solve(number, k, true);
    }

    cout << answer;
    return 0;
}
int maximum(int a, int b){
    return a>b ? a : b;
}
string solve(string number, int k, bool bigger){
    string answer = "wrong";
    int i;
    if(number.empty()){
        if(k == 0) return "";
        else return "wrong";
    }
    
    if(bigger)  i = number.front() - '0';
    else if(start_flag) i = 1;
    else i = 0;
    start_flag = false;
    
    number = number.replace(0, 1,"");
    for(; i<max; i++){
        if(used[i] == true && k <= number.length()){
            answer = solve(number, k, bigger);
        }else if(used[i] == false && k > 0){
            used[i] = true;
            answer = solve(number, k-1, bigger);
            used[i] = false;
        }
        if(answer != "wrong"){
            used[i] = true;
            break;
        }
        bigger = false;
    }
    
    if(i == max) return "wrong";
    return to_string(i).append(answer);
}
