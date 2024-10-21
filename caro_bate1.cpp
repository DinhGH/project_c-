#include<iostream>
using namespace std;
void input(char a[3][3],int &dem){
	int i,j;
	do{
		if(dem%2==0)cout<<"Play o: ";
		else cout<<"Play x: ";
	cin>>i>>j;
	}while(i<0|i>3|j<0|j>3);
	if(a[i][j]=='_'){
		if(dem%2==0)
			a[i][j]='o';
		else a[i][j]='x';
	}
	else dem--;
}
void out(char a[3][3]){
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	char a[3][3]={{'_','_','_'},{'_','_','_'},{'_','_','_'}};
	int dem=0,kq=0,counto,countx;
	while(7){
	input(a,dem);
	dem++;
	out(a);
	for(int i=0;i<3;i++){
		counto=0;countx=0;
		for(int j=0;j<3;j++){
			if(a[i][j]=='x')
				countx++;
			if(a[i][j]=='o')
				counto++;
		}
		if(counto==3|countx==3)kq=1;
	}
	
	if(a[1][1]==a[0][0]&&a[1][1]==a[2][2]&&(a[1][1]=='x'|a[1][1]=='o'))kq=1;
	if(a[1][1]==a[0][2]&&a[1][1]==a[2][0]&&(a[1][1]=='x'|a[1][1]=='o'))kq=1;
	if(kq==1&&dem%2==0){
		cout<<"Play 'x': win";
		break;
	}
	else if(kq==1&&dem%2==1){
		cout<<"Play 'o': win";
		break;
	}
	int hoa=9;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
		    if(a[i][j]!='_')
				hoa--;
			if(hoa==0){
			cout<<"Draw";
			return 0;
		}}
	}
	cout<<endl;
	}
}
