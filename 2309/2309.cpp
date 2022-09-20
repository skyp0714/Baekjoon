no. 2309
#include <iostream>
int main(){
int n,i,j, a[9],sum,chk=0;
n=9;
for(i=0;i<n;i++) {
scanf("%d",a[i]);
sum+=a[i];
}
for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		if(a[i]>a)[j]) swap(i,j);
	}
}


for(i=0;i<n;i++){
	for(j=0;j<n;j++{
			if(sum-a[i]-a[j]==100) {
				chk=1;
				break;
			}
	}
	if(chk==1) break;
}
for(int k=0;k<n;k++){
	if(k!=i&&k!=j) printf("%d\n",a[k]);
}
}