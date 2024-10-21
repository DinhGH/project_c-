#include<bits/stdc++.h>
using namespace std;
class account{
	string mathe;
	long int sodu;
	public:
		account(){
		}
		void setsodu(long int sd){
			sodu+=sd;
		}
		void setsodutru(long int sd){
			sodu-=sd;
		}
		void input(string m){
//			cout<<"Nhap ma so the: ";
//			cin>>mathe;
			mathe=m;
		}
		void inputsd(){
			cout<<"So du: 0"<<endl;
			sodu=0;
		}
		string getmathe(){
			return mathe;
		}
		long int getsodu(){
			return sodu;
		}
};
class nhapaccount:public account{
	protected:
	account *a;
	private:
	int dodai;
	public:
		nhapaccount(){
		}
		void input(){
			int i=0;
			a=new account[10];
			while(27){
				skip:
				string s;
				cout<<"Nhap ma so the: ";
				cin>>s;
				if(s=="0")break;
				a[i].input(s);
				int j=0;
				while(j<i){
					if(a[j].getmathe()==a[i].getmathe()){
						cout<<"Loi: ma the trung nhau!\n";goto skip;
					}j++;
				}
				a[i].inputsd();
				i++;
				dodai=i;
			}
		}
		int getdodai(){
			return dodai;
		}
		~nhapaccount(){
			delete[] a;
		}
};
class mainprogram:public nhapaccount{
	private:
		string tk;
		long int sd;
	public:
		thaotac(){
		}
		void input(){
			nhapaccount::input();
		}		
		void naptien(){
			it:
			cout<<"Nhap ma the cua ban: ";
			cin>>tk;
			if(tk!="0"){
				int dem=0;
				for(int k=0;k<getdodai();k++){
					if(tk!=a[k].getmathe())
						dem++;
				}
				if(dem==getdodai()){
					cout<<"Khong tim thay the!"<<endl;
					goto it;
				}
				cout<<"Nhap so tien muon nap: ";
				cin>>sd;
				
				int i=0;
				while(27){
					if(tk==a[i].getmathe()){
						a[i].setsodu(sd);
						cout<<"Nap thanh cong "<<sd<<" dollar"<<endl;
						break;
					}i++;
				}
			}
		}
		void ruttien(){
			it:
			cout<<"Nhap ma the cua ban: ";
			cin>>tk;
			if(tk!="0"){	
				int dem=0;
				for(int k=0;k<getdodai();k++){
					if(tk!=a[k].getmathe())
						dem++;
				}
				if(dem==getdodai()){
					cout<<"Khong tim thay the!"<<endl;
					goto it;
				}
				cout<<"Nhap so tien muon rut: ";
				cin>>sd;
				int i=0;
				while(27){
					if(tk==a[i].getmathe()){
						if(sd>a[i].getsodu()){
							cout<<"So du khong du!"<<endl;break;
						}
						a[i].setsodutru(sd);
						cout<<"Rut thanh cong "<<sd<<" dollar"<<endl;
						break;
					}i++;
				}
			}
		}
		void chuyentien(){
			string tk1,tk2;
			it:
			cout<<"Nhap tai khoan nguon: ";
			cin>>tk1;
			if(tk1!="0"){
				int dem=0;
				for(int k=0;k<getdodai();k++){
					if(tk1!=a[k].getmathe())
						dem++;
				}
				if(dem==getdodai()){
					cout<<"Khong tim thay the!"<<endl;
					goto it;
				}
			}
			it1:
			cout<<"Nhap tai khoan dich: ";
			cin>>tk2;
			if(tk2!="0"){
				int dem=0;
				for(int k=0;k<getdodai();k++){
					if(tk2!=a[k].getmathe())
						dem++;
				}
				if(dem==getdodai() | tk1==tk2){
					cout<<"Khong tim thay the! hoac the trung nhau!"<<endl;
					goto it1;
				}
			}
			s1:
			cout<<"Nhap so tien: ";
			int tien;
			cin>>tien;
			for(int i=0;i<getdodai();i++){
				if(tk1==a[i].getmathe()){
					if(tien>a[i].getsodu()){
						cout<<"Tai khoan khong du! \n";goto s1;
					}
					else {
						a[i].setsodutru(tien);
					}
				}
				if(tk2==a[i].getmathe()){
					a[i].setsodu(tien);
				}
			}
			cout<<"Chuyen thanh cong!";
		}
		void kiemtra(){
			cout<<"Nhap ma the muon kiem tra: ";
			cin>>tk;
			int i=0;
			while(27){
				if(tk==a[i].getmathe()){
					cout<<"So du: "<<a[i].getsodu()<<endl;
					break;
				}i++;
			}
		}
};
int main(){
	mainprogram s;
	s.input();
	int t;
	while(27){
		cout<<"Option: "<<endl<<"1.Nap tien\n"<<"2.Rut tien\n"<<"3.chuyen tien\n4.Kiem tra so du\n=>";
		cin>>t;
		if(t==0)break;
		switch(t){
			case 1:
				s.naptien();
				break;
			case 2:
				s.ruttien();
				break;
			case 3:
				s.chuyentien();
				break;
			case 4:
				s.kiemtra();
				break;
		}
	}
	return 0;
}
