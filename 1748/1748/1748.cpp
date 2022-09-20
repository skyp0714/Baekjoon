int main(){
int n,num=10,len=1,ans, temp;
scanf("%d",&n);
temp=n;
while(n){
	if(n/10) ans+=(num*0.9)*len;
	else ans+=len*(temp%num+1);
	num*=10;
	len++;
	n/=10;
}
printf("%d",ans);
}