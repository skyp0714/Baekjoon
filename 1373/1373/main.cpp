//
//  main.cpp
//  1373
//
//  Created by 박하늘 on 2020. 9. 21..
//  Copyright © 2020년 박하늘. All rights reserved.
//

#include <iostream>
#include <string.h>
#define max_length 1000010
using namespace std;

int main(int argc, const char * argv[]) {
    char s[max_length],add_zero[10]="000",new_s[max_length]="";
    cin>>s;
    strncat(new_s, add_zero, (3-strlen(s)%3)%3);
    strcat(new_s,s);
    for(int i=0;i<strlen(new_s);i=i+3) cout << (new_s[i]-'0')*4+(new_s[i+1]-'0')*2+(new_s[i+2]-'0');
    return 0;
}

