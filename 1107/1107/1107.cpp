//ppt  참조할 것. 더 좋은방법이 있다.

int ch, d[10],m;
int abs(int a);
int num(int a);
bool check(int a);
int main(){
int i,j,temp,chk,cnt=0;
scanf("%d %d",&ch, &m);
int ans=abs(ch-100);
for(i=0;i<m;i++) scanf("%d",&d[i]);
for(i=2*ch;i>=0;i--){
		chk=1;
		temp=i;
			while(temp==0){
				if(check(temp%10)) chk=0;
				temp/=10;
			}
			if(chk){
			temp=num(i);
			if(ans>temp)ans=temp;
			}
}
printf("%d",ans);
}
bool check(int a){
	for(int i=0;i<m;i++) 
		if(d[i]==a) return true;
	return false;
}
int abs(int a){
return a>0 ? a: -a;
}
int num(int c){
int cnt=0, temp;
	temp=c;
	while(c){
	c/=10;
	cnt++;
	}
	return abs(ch-temp)+cnt;
}