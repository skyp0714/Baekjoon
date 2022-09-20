#include <iostream>
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int n,m,a[500][500],chk[500][500];
int move(int x, int y, int m);
int tetra(int x, int y, int i);
int main(){
int sum,ans=0,i,j;
scanf("%d %d",&n,&m);
for(i=0;i<n;i++)
	for(j=0;j<m;j++)scanf("%d",&a[i][j]);
    
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		sum=move(i,j,3);
		if(sum>ans) ans=sum;
	}
}
	printf("%d",ans);
}
int move(int x,int y, int l){
	int i,nx,ny,temp,max=0;
	if(l==0) return a[x][y];
	chk[x][y]=1;
	for(i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if((nx>=0)&&(nx<n)&&(ny>=0)&&(ny<m)){
            if((chk[nx][ny])==0){
			temp=move(nx,ny,l-1);
			if(max<temp)max=temp;
            }
		}
	}
    if(l==3){
        if(x==0&&y!=0)temp=tetra(x,y,0);
        else if(y==0&&x!=0)temp=tetra(x,y,1);
        else if(x==n-1&&y!=m-1) temp=tetra(x,y,2);
        else if(y==m-1&&x!=n-1) temp=tetra(x,y,3);
        else if(((x==n-1)&&(y==m-1))||(x*y==0)){
        }else{
            for(i=0;i<4;i++){
                temp=tetra(x,y,i);
                if(max<temp)max=temp;
            }
        }
        if(max<temp)max=temp;
    }
chk[x][y]=0;
return a[x][y]+max;
}
int tetra(int x, int y, int i){
    int j,sum=0;
    for(j=0;j<4;j++){
        if(j!=i)sum+=a[x+dx[j]][y+dy[j]];
    }
    return sum;
}
