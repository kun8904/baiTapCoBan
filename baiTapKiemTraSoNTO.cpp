#include <iostream>
#include <math.h>
// viết chương trình nhập vào 1 số nguyên dươngn . Kiểm tra xem số n có phải là số nguyên tố không.
using namespace std;

//void kiem_tra_so_nguyen_to(int &n){
//	n = float(n);
//	int run = 0, i = 1;//bộ đếm
//	do{
//		if(n%i == 0){
//			run++;
//		}
//		i++;
//	}while( run < 2 && i < sqrt(n));
//	if(run < 2 && i != sqrt(n)){
//		cout << "So " << n <<" la so nguyen to" << endl;
//	}else{
//		cout << "So " << n <<" khong la so nguyen to" << endl;
//	}
//}

bool kiem_tra_so_nguyen_to(int &n) {
    if (n <= 1) 
        return false;
    
    for (int i = 2; i <= sqrt(n); ++i) { 
        if (n % i == 0) 
            return false; 
    }
    return true; 
}

int main(){
	int n;
	cout << "Nhap so :" ;
	cin >> n;
	// kiem_tra_so_nguyen_to(n);
	if (kiem_tra_so_nguyen_to(n)) {
        cout << n << " la so nguyen to." << endl;
    } else {
        cout << n << " khong la so nguyen to." << endl;
    }
}