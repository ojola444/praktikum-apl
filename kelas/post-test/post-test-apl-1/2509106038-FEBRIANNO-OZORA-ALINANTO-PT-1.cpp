#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int status = 0;
    
    string inputNama, inputPass;
    int percobaan = 1;
    
    while(percobaan <= 3){
        cout << "masukkan nama : "; cin >> inputNama;
        cout << "masukkan Password : "; cin >> inputPass;
        if( inputNama == "Ozora" && inputPass == "038"){
            status = 1;
            break;
        }else {
            cout << "nama atau password salah, coba lagi" << endl;
            percobaan++;
        }
    }
    
    if(percobaan >= 3){
        status = 3;
    }
    
    if (status == 1){
        cout << "login berhasil" << endl;
        double target;
        while (true)
        {
            int input;
            cout << "[1] konverter Meter ke kilometer dan centimeter" << endl;
            cout << "[2] konverter Kilometer ke Meter dan centimeter" << endl;
            cout << "[3] konverter centimeter ke Meter dan Kilometer" << endl;
            cout << "[0] selesai" << endl;
            
            cout << "Masukkan pilihan : "; cin >> input;
            
            if (input == 1){
                
                cout << "masukkan angka : "; cin >> target;
                if (target > 0){
                double hasilKm = target / 1000; 
                double hasilCm = target * 100;
                cout << "hasil ke Kilometer : " << fixed << setprecision(2) <<  hasilKm << " Kilometer" << endl;
                cout << "hasil ke Centimeter : " << fixed << setprecision(2) <<  hasilCm << " Centimeter" << endl;
                }
                else 
                cout << "angka tidak bisa minus";

            } 
            else if (input == 2){
                
                cout << "masukkan angka : "; cin >> target;
                
                if (target > 0) {
                double hasilM = target * 1000;
                double hasilCm = target * 100000;
                cout << "hasil ke Meter : " << fixed << setprecision(2) <<  hasilM << " Meter" << endl;
                cout << "hasil ke Centimeter : " << fixed << setprecision(2) <<  hasilCm << " Centimeter" << endl;
                }
                else 
                cout << "angka tidak bisa minus";
            }
            else if (input == 3){
                cout << "masukkan angka : "; cin >> target;
                
                if (target > 0) {
                double hasilM = target / 100;
                double hasilKm = target / 100000;
                cout << "hasil ke Meter : " << fixed << setprecision(2) << hasilM << " Meter" << endl;
                cout << "hasil ke Kilometer : " << fixed << setprecision(2) << hasilKm << " Kilometer" << endl;
                }
                else 
                cout << "angka tidak bisa minus";
            }
            else if (input == 0){
                break;
            }
            else {
                cout << "hasil tidak ada" << endl;
            }

        }
        
    }
    
    else if (status > 1) {
        cout << "terlalu banyak mengulang";
    }

 return 0;
}