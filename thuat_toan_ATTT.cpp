#include <iostream>
#include <cmath>
#include <vector>
#include <gmpxx.h>
using namespace std;

// Chuyển phần tử sang mảng 
void chuyen_typedef(long long x,int t,vector<long long>& X){
	for(int i=t-1; i>=0; i--){
		X[i] = x/static_cast<long long>(pow(2,i*8));
		x = x - X[i]*static_cast<long long>(pow(2,i*8));
	}
}


// Thuật toán cộng chính xác bội 
void thuat_toan_cong(int &m, int w, vector<long long>& X, vector<long long>& Y, vector<long long>& C){
    long long tmp = X[0] + Y[0];
    if (tmp > pow(2, w)){
        do {
            tmp= tmp - pow(2,w);
        }while(tmp > 0);
        tmp= tmp + pow(2,w);
        C[0]= tmp;
        m= 1;
    } else if (tmp< pow(2,w) and tmp> 0){
        C[0]= tmp;
        m= 0;
    } else if (tmp== pow(2,w) or tmp== 0){
        C[0]= 0;
        m= 0;
    }

    for (int i= 1; i < 4; i++){
        tmp= X[i] + Y[i] + m;
        if (tmp > pow(2,w)){
            do {
                tmp= tmp - pow(2,w);
            } while (tmp > 0);
            tmp= tmp + pow(2,w);
            C[i]= tmp;
            m= 1;
        } else if (tmp < pow(2,w) and tmp > 0){
            C[i]= tmp;
            m= 0;
        } else if (tmp== pow(2,w) or tmp == 0){
            C[i]= 0;
            m= 0;
        }
    }
}

// Thuật toán trừ chính xác bội
void thuat_toan_tru(int &n, int w, vector<long long>& X, vector<long long>& Y, vector<long long>& D){
    long long tmp1= X[0] - Y[0];
    if(tmp1 > pow(2,w)){
        do {
            tmp1= tmp1 - pow(2,w);
        }while(tmp1 > 0);
        tmp1= tmp1 + pow(2,w);
        D[0]= tmp1;
        n= 1;
    }else if(tmp1 < pow(2,w) and tmp1 > 0){
        D[0] = tmp1;
        n = 0;
    }else if(tmp1== 0 or tmp1 == pow(2,w)){
        D[0]= 0;
        n= 0;
    }else{
        do{
            tmp1 = tmp1 + pow(2,w);
        }while(tmp1 < 0);
        D[0]= tmp1;
        n= 1;
    }

    for (int i = 1; i < 4; i++){
        tmp1= X[i] - Y[i] - n;
        if(tmp1 > pow(2,w)){
            do{
                tmp1= tmp1 - pow(2,w);
            }while(tmp1 > 0);
            tmp1= tmp1 + pow(2,w);
            D[i]= tmp1;
            n= 1;
        }else if(tmp1 < pow(2,w) and tmp1 > 0){
            D[i]= tmp1;
            n= 0;
        }else if(tmp1 == 0 or tmp1 ==  pow(2,w)){
            D[i] = 0;
            n = 0;
        }else{
            do{
                tmp1 = tmp1 + pow(2,w);
            }while(tmp1 < 0);
            D[i]= tmp1;
            n= 1;
        }
    }
}

// thuật toán cộng trường Fp
void thuat_toan_cong_tren_Fp(long long p_cong,int t,int &g, int w ,vector<long long>& X,vector<long long>& E){
	if(g==1){
		int x=0;
		vector<long long> P;
		P.resize(t);
		chuyen_typedef(p_cong,t,P);
		thuat_toan_tru(x,w,X,P,E); // thu được kết quả thuật toán E
	}else{
		E = X;
	}
}

// thuật toán tru trường Fp
void thuat_toan_tru_tren_Fp(long long p_tru,int t,int &g, int w ,vector<long long>& X,vector<long long>& F){
	if(g==1){
		int y=0;
		vector<long long> P;
		P.resize(t);
		chuyen_typedef(p_tru,t,P);
		thuat_toan_cong(y,w,X,P,F); // thu được kết quả thuật toán F
	}else{
		F = X;
	}
}

// Hàm hiển thị
void hienthi(int x,int t,vector<long long>& C) {
    cout << "\nKet qua thuat toan: " << x << " " << "C[ ";
    for(int i = t-1; i >= 0; i--){
        cout << C[i] << " ";
    }
    cout << "]\n";
}

int main(){
	long long a,b,p,m;
	int x=0,y=0;
	int t,w;
	int luachonnhap,luachontrove,luachonthuattoan;
	int check=0;
	int nhap_2,check_2=0;
	int check_3=0, check_4=0;
	vector<long long> A,B,C,D; // C lưu thuật toán cộng , D lưu thuật toán trừ chính xác bội
	vector<long long> E,F; // E thuật toán cộng trường Fp , F là thuật toán trừ trường Fp
	luachon_nhap:
		cout << "--------------------------------------"<< endl;
		cout << "1.Nhap modulo p va w " << endl;
		cout << "2.Thoat"<< endl;
		cout << "--------------------------------------"<< endl;
		cout << "Nhap lua chon cua ban : "; cin >> luachonnhap;
		switch(luachonnhap){
			case 1:{
				system("cls");
				do{
					cout << "Nhap w = " ; cin >> w;
					cout << "Nhap p = " ; cin >> p;
				}while(p<=0 or w<=0);
				m = static_cast<long long>(log2(p));
				t = static_cast<int>(m/w+1);
				system("cls");
				luachon_nhap1:
					cout << "1.Hien thi ket qua cu"<< endl;
					cout << "2.Nhap lai tu dau"<< endl;
					cout << "3.Tro ve"<< endl;
					cout << "Nhap lua chon: " ; cin >> nhap_2;
					if(nhap_2==1){
						if(check_2==0){
							cout << "\nCHUA CO DU LIEU!!!" << endl;
							goto luachon_nhap1;
						}
						if(check_2==1){
							system("cls");
							goto luachon_thuattoan;
						}
					}else if(nhap_2==2){
						system("cls");
						A.resize(t),B.resize(t),C.resize(t),D.resize(t);
						cout << "Nhap:" << endl;
						cout << "a = " ; cin >> a;
						cout << "b = " ; cin >> b;
						chuyen_typedef(a,t,A);
						chuyen_typedef(b,t,B);
						check_2=1;
						system("cls");
						goto luachon_thuattoan;
					}
					else if(nhap_2==3){
						system("cls");
						goto luachon_nhap;
					}else{
						cout << "\nHAY NHAP LAI!!!" << endl;
						goto luachon_nhap1;
					}
				}
			
			case 2:{
				exit(0);
			}
			
			default:{
				system("cls");
				cout << "LUA CHON CUA BAN KHONG PHU HOP, HAY NHAP LAI!!!"<< endl;
				goto luachon_nhap;
			}
			
			//lựa chọn thuật toán
			luachon_thuattoan:
				cout << "----------LUA CHON THUAT TOAN---------"<< endl;
				cout <<"1.Thuat toan cong chinh xac boi" << endl;
				cout <<"2.Thuat toan tru chinh xac boi" << endl;
				cout <<"3.Thuat toan cong Fp"<< endl;
				cout <<"4.Thuat toan tru Fp"<< endl;
				cout <<"5.Thuat toan nhan" << endl;
				cout <<"6.thoat"<<endl;
				cout << "--------------------------------------"<< endl;
				cout << "So a = " << a <<"\nSo b = " << b << endl;
				cout <<"Nhap lua chon : ";cin >> luachonthuattoan;
				switch(luachonthuattoan){
					case 1:{
						thuat_toan_cong (x,w,A,B,C);
						hienthi(x,t,C);
						check_3=1;
						goto luachon_trove;
					}
					case 2:{
						thuat_toan_tru(y,w,A,B,D);
						hienthi(y,t,D);
						check_4=1;
						goto luachon_trove;
					}
					
					case 3:{
						if(check_3==0){
							system("cls");
							cout << "HAY TINH THUAT TOAN CONG CHINH XAC BOI TRUOC!!!" << endl;
							goto luachon_thuattoan;
						}else{
							E.resize(t);
							thuat_toan_cong_tren_Fp(p,t,x,w,C,E);
							hienthi(x,t,E);
							goto luachon_trove;
						}
					}
					
					case 4:{
						if(check_4==0){
							system("cls");
							cout << "HAY TINH THUAT TOAN TRU CHINH XAC BOI TRUOC!!!" << endl;
							goto luachon_thuattoan;
						}else{
							F.resize(t);
							thuat_toan_tru_tren_Fp(p,t,y,w,D,F);
							hienthi(y,t,F);
							goto luachon_trove;
						}
						break;
					}
					
					
					case 6:{
						exit(0);
					}
					
					default:{
						system("cls");
						cout << "\nNHAP LAI LUA CHON!!!" << endl;
						goto luachon_thuattoan;
					}
				}
				
			//lựa chọn sau khi giải thuật toán
			luachon_trove:
				cout << "\n1.Tro ve" << endl;
				cout << "2.Nhap lai thuat toan"<< endl;
				cout << "Nhap lua chon: "; cin >> luachontrove;
				if(luachontrove<=0 or luachontrove>2){
					cout << "\nNHAP LAI LUA CHON" << endl;
					goto luachon_trove;
				}else if(luachontrove==1){
					system("cls");
					goto luachon_nhap;
				}else if(luachontrove==2){
					system("cls");
					goto luachon_thuattoan;
				}
		}
	return 0;
}