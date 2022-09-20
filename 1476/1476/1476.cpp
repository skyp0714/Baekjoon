#include<iostream>
#define E 15
#define S 28
#define M 19
int main(){
int i,e,s,m;
scanf("%d %d %d",&e,&s,&m);
    if(e==E) e=0;
    if(s==S) s=0;
    if(m==M) m=0;
    for(i=1;i<=E*S*M;i++){
	if(i%E==e&&i%S==s&&i%M==m) break;
}
printf("%d",i);
}
//중국인의 나머지 정리  CRT 참조
