int main(){
int end,n,m,i,t,x,y;
scanf("%d",&t);
while(t--){
	scanf("%d %d %d %d",m,n,x,y);
	end=n*m/gcd(n,m);
	for(i=x;i<=end;i+=m){
		if(i%n==y%n) break;
	}
	if(i>end) printf("-1\n");
	else printf("%d\n",i);
}

}
int gcd(int a, int b){
	if(a==b)return a;
	else if(a==1||b==1) return a*b;
	else return a>b?gcd(a-b:b):gcd(a,b-a);
}