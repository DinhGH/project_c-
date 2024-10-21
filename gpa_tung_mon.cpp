#include<bits/stdc++.h>
using namespace std;
class dtu{
    float phantram;
    float diem;
    public:
        dtu(){}
        void input(){
            cout<<"Nhap %: ";
            cin>>phantram;
            cout<<"Nhap diem: ";
            cin>>diem;
        }
        float getphantram(){
            return phantram;
        }
        float getdiem(){
        	return diem;
		}
};
class nhapdiem:public dtu{
    private:   
        dtu *a;
        float tdc=0,tpt=0;
    public:
        nhapdiem(){}
        void input(){
            a=new dtu[27];
            int i=0;
            while(a[i-1].getphantram()!=0){
                    a[i].input();
                    tdc+=a[i].getphantram()*a[i].getdiem();
                    tpt+=a[i].getphantram();
                    i++; 
            }
        }
        float gettdc(){
            return tdc;
        }
        float gettpt(){
            return tpt;
        }
        ~nhapdiem(){
            delete[] a;
        }
};
class inputwish: public nhapdiem{
    float diemcandat,t;
    string gpa;
    public:
        inputwish(){}
        void input(){
            nhapdiem::input();
            cout<<"Nhap diem chu ma ban muon: ";
            cin>>gpa;
            if(gpa=="A+")
                t=9.45;
            else if(gpa=="A")
                t=8.45;
            else if(gpa=="A-")
				t=7.95;
			else if(gpa=="B+")
				t=7.45;
			else if(gpa=="B")
				t=6.95;
			else if(gpa=="B-")
				t=6.45;
			else if(gpa=="C+")
				t=5.95;
			else if(gpa=="C")
				t=5.45;
			else if(gpa=="C-")
				t=4.45;
			else if(gpa=="D")
				t=3.95;
   		}
        void text(){
            float s=(t-gettdc())/(1-gettpt()); 
            if(s>=8.5)
                cout<<"Ban phai co gang that nhieu de dat "<<s<<" cac phan tram con lai!";
            else if(s>5)
                cout<<"Chi can hoc vua vua la dat duoc "<<s<<" de hoan thanh muc tieu roi!";
            else cout<<"Thoai mai cung dat duoc "<<s<<" nhu choi!";
        }
};
int main(){
    inputwish q;
    q.input();q.text();
    return 0;
}