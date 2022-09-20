no. 2309
#include <iostream>
char c[50][50];
int main(){
int n,i,j,ans=0, num; 
scanf("%d",&n);
for(i=0;i<n;i++)
	for(j=0;j<n;j++)
		scanf("%c",&c[i][j]);

for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(c[i][j]!=c[i+1][j]){
		swap(i,j,i+1,j);
		num=solve();
		if(ans<solve()) ans=num;
		swap(i,j,i+1,j);
		}
		if(c[i][j]!=c[i][j+1]){
		swap(i,j,i,j+1);
		num=solve();
		if(ans<num) ans=num;
		swap(i,j,i,j+1);
		}
	}
}
printf("%d",ans);
}
int solve(){
int i,j,cnt=0,max=0;
char temp;
for(i=0;i<n;i++){
	temp=c[i][0];
	for(j=1;j<n;j++){
	if(temp==c[i][j]) cnt++;
	else cnt=0;
	if(max<cnt) max=cnt;
	temp=c[i][j];
	}
}
for(j=0;j<n;j++){
	temp=c[0][j];
	for(i=1;i<n;i++){
	if(temp==c[i][j]) cnt++;
	else cnt=0;
	if(max<cnt) max=cnt;
	temp=c[i][j];
	}
}
return max;
}