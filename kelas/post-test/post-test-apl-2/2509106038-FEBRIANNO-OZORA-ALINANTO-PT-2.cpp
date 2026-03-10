#include <iostream>
#include <cmath>
using namespace std;

int main(){
        int status = 0;
    
    string inputNama, inputPass;
    int percobaan = 1;

    struct levelUser{
        string nama;
        string password;
        int uang;
        int status;

    };

    struct levelUser user[20] = {
        {"ozora", "038", 10000, 2},
        {"igor", "444", 999999, 1}
    };

    struct Persona
    {
        string nama;
        int level;
        string arcana;
        string skill[8];
        int harga;
        int panjangSkill;
    };
    struct Persona dataPersona[20] = {
        {"orpheus", 10, "fool", {"agi", "dia", "bash", "tarunda"}, 500, 4},
        {"jack o lantern", 15, "magician", {"bufu", "pulinpa", "mabufu", "shock punch", "freeze boost", "magic boost" }, 750, 6},
        {"archangel", 20, "justice", {"kouha", "single shot", "baisudi", "sukukaja", "holy arrow", "apt pupil"}, 1000, 6}
    };

    struct personaUser
    {
        string user;
        int jumlahPersona;
        struct  Persona listPersona[10];
        
    };

    struct personaUser dataPersonaUser[10];

    string skillItem[5] = {"masukunda", "dekaja", "debilitate", "charge", "concentrate"};
    
    int totalPersona = 3;
    int totalDataUser = 0;
    int totalUser = 2;
    int pilihan, index, indexSkill, indeksUser;
    bool jumlahDataSama;
    
    
    while(percobaan <= 3){
        cout << "menu login, tekan 0 untuk log out" << endl;
        cout << "masukkan nama : "; cin >> inputNama;
        cout << "masukkan Password : "; cin >> inputPass;
        for (int i = 0; i <= totalUser - 1; i++){
            if (inputNama == user[i].nama && inputPass == user[i].password){
                cout << "login berhasil" << endl;
                status = user[i].status;
                indeksUser = i;
                break;
            }
        }
        if( status == 1){
            
            percobaan = 0;
            do {
              cout << "\n = menu velvet room admin =" << endl;
              cout << "1. tampilkan data persona" << endl;
              cout << "2. Tambah persona " << endl;
              cout << "3. update persona" << endl;
              cout << "4. Hapus persona" << endl;
              cout << "0. Keluar" << endl;
              cout << "Pilihan: ";
              cin >> pilihan;
              switch (pilihan) {
                case 1:
                if (totalPersona == 0){
                   cout << "tidak ada persona yang bisa dibaca" << endl;
                }else{
                for(int i = 0; i < totalPersona ; i++){
                    cout << "\n ======" << dataPersona[i].nama << "======" << endl;
                    cout << "level    : "  << dataPersona[i].level << endl;
                    cout << "arcana   : "  << dataPersona[i].arcana << endl;
                    cout << "skill    : ";
                    for (int j = 0; j < dataPersona[i].panjangSkill ; j++){
                        cout << dataPersona[i].skill[j] << ", ";
                    }
                    cout << endl;
                    cout << "harga   : "  << dataPersona[i].harga << endl;
                }
            }

                break;

                case 2: 

                if (totalPersona < 20){
                    cout << "masukkan nama persona : ";
                    cin.ignore();
                    getline(cin, dataPersona[totalPersona].nama);
                    
                    cout << "masukkan level persona : ";
                    cin >> dataPersona[totalPersona].level;
                    
                    cout << "masukkan arcana persona : ";
                    cin >> dataPersona[totalPersona].arcana;
                    
                    cout << "masukkan skill persona : " << endl;
                    cout << "ketik stop untuk berhenti : " << endl;
                    cin.ignore(1000, '\n'); 
                    int i = 0;
                    while(i <= 7){
                        string inputSkill;
                        cout << "skill " << i + 1 << ": "; getline(cin,inputSkill);
                        
                        if (inputSkill == "stop"){
                            break;
                        }
                        
                        dataPersona[totalPersona].skill[i] = inputSkill;
                        dataPersona[totalPersona].panjangSkill++;
                        i++;
                    }
                    
                    cout << "masukkan harga persona : ";
                    cin >> dataPersona[totalPersona].harga;
                    totalPersona++;
                    cout << "data berhasil dimasukkan" << endl;
                }else{
                    cout << "kapasitas data penuh" << endl;
                }
                break;

                //update
                case 3:
                
                if (totalPersona == 0){
                   cout << "tidak ada persona yang bisa diubah" << endl;
                }else{
                    for(int i = 0; i < totalPersona ; i++){
                        cout << "persona ke " << i + 1 << " : " << dataPersona[i].nama << endl;
                    }
                    cout << "masukkan nomor persona yang ingin diubah" << endl ;
                    cin >> index;

                    if(index >= 1 && index <= totalPersona){
                        do {
                            cout << "1. ubah nama persona" << endl;
                            cout << "2. ubah level persona " << endl;
                            cout << "3. ubah arcana persona" << endl;
                            cout << "4. ubah skill persona" << endl;
                            cout << "5. ubah  harga persona" << endl;
                            cout << "0. batal update" << endl;
                            cout << "Pilihan: ";
                            cin >> pilihan;
                            switch (pilihan)
                            {
                            case 1:
                            cout << "masukkan nama baru : ";
                            cin.ignore();
                            cin >> dataPersona[index - 1].nama;
                            cout << "berhasil diubah" << endl;
                            break;
                            case 2:
                            cout << "masukkan level baru : ";
                            cin.ignore();
                            cin >> dataPersona[index - 1].level;
                            cout << "berhasil diubah" << endl;
                            break;
                            case 3:
                            cout << "masukkan arcana baru : ";
                            cin.ignore();
                            cin >> dataPersona[index - 1].arcana;
                            cout << "berhasil diubah" << endl;
                            break;
                            case 4:
                            for (int j = 0; j < dataPersona[index - 1].panjangSkill ; j++){
                                cout << "skill ke " << j + 1 << " : " << dataPersona[index - 1].skill[j] << endl;
                            }
                            cin.ignore();
                            cout << "masukkan nomor skill yang ingin diubah :"; cin >> indexSkill;
                            indexSkill -= 1;
                            if(indexSkill >= 0 && indexSkill <= dataPersona[index - 1].panjangSkill - 1){
                                cin.ignore();
                                getline(cin,dataPersona[index - 1].skill[indexSkill]);
                                cout << "skill berhasil diubah" << endl;
                            }
                            break;
                            case 5:
                            cout << "masukkan harga baru : ";
                            cin.ignore();
                            cin >> dataPersona[index - 1].harga;
                            cout << "berhasil diubah" << endl;
                            break;

                            case 0:
                            cout << "batal update" << endl;
                            break;
                            
                            default:
                            cout << "nomor tidak valid";
                            break;
                            }
                        } while(pilihan != 0);
                    }else {
                        cout << "tidak ada persona di nomor itu" << endl;
                    }
                }                

                break;
                case 4:
                if (totalPersona == 0){
                   cout << "tidak ada persona yang bisa dihapus" << endl;
                }else{
                    for(int i = 0; i < totalPersona ; i++){
                        cout << "persona ke " << i + 1<< " : " << dataPersona[i].nama << endl;
                    }
                    cout << "masukkan nomor persona yang ingin dihapus" << endl ;
                    cin >> index;

                    if(index >= 1 && index <= totalPersona){
                        for(int i = index - 1 ; i < totalPersona - 1; i++){
                           dataPersona[i] = dataPersona[i + 1];
                        }
                        totalPersona--;
                        cout << "persona berhasil dihapus" << endl;
                    }else {
                        cout << "tidak ada persona di nomor itu" << endl;
                    }
                }                
                break;
                case 0:
                cout << "log out...." << endl;
                status = 0;
                break;
                default:
                cout << "Pilihan tidak valid." << endl;
                }
            } while (pilihan != 0);
            
        }else if(status == 2){
            percobaan = 0;
            string simpanNama = inputNama;
            int simpanIndeks = 0;
            if (totalDataUser == 0){
                dataPersonaUser[0].user = simpanNama;
                dataPersonaUser[0].jumlahPersona = 0;
                simpanIndeks = 0; //mastiin
                totalDataUser++;
                
            }else {
                int i = 0;
                while (i <= totalDataUser - 1)
                {
                    if(dataPersonaUser[i].user == simpanNama){
                        simpanIndeks = i;
                        i = 0;
                        break;
                    }
                    i++;
                }
            }
            int tempJumlah = dataPersonaUser[simpanIndeks].jumlahPersona;
            do {
                cout << "\n = menu velvet room user =" << endl;
                cout << "uang kamu : " << user[indeksUser].uang << " yen"<< endl;
                cout << "1. lihat data persona user" << endl;
                cout << "2. beli persona" << endl;
                cout << "3. fuse/gabung persona" << endl;
                cout << "4. ubah skill persona" << endl;
                cout << "5. hapus persona" << endl; 
                cout << "0. keluar" << endl; 
                cout << "Pilihan: ";
                cin >> pilihan;
                
                switch (pilihan)
                {
                    case 1:
                    if (dataPersonaUser[simpanIndeks].jumlahPersona == 0)
                    {
                        cout << "tidak ada persona yang dilihat" << endl;
                    }else {
                        for(int i = 0; i <= dataPersonaUser[simpanIndeks].jumlahPersona - 1; i++){
                            
                            cout << "\n ======" << dataPersonaUser[simpanIndeks].listPersona[i].nama << "======" << endl;
                            cout << "level    : "  << dataPersonaUser[simpanIndeks].listPersona[i].level << endl;
                            cout << "arcana   : "  << dataPersonaUser[simpanIndeks].listPersona[i].arcana << endl;
                            
                            cout << "skill    : ";
                            for (int j = 0; j < dataPersonaUser[simpanIndeks].listPersona[i].panjangSkill ; j++){
                                cout << dataPersonaUser[simpanIndeks].listPersona[i].skill[j] << ", ";
                            }
                            cout << endl;
                        }
                    }
                    
                    break;
                    case 2:
                    for(int i = 0; i < totalPersona ; i++){
                        cout << "\n ======" << i + 1 << ". " << dataPersona[i].nama << "======" << endl;
                        cout << "level    : "  << dataPersona[i].level << endl;
                        cout << "arcana   : "  << dataPersona[i].arcana << endl;
                        cout << "skill    : ";
                        for (int j = 0; j < dataPersona[i].panjangSkill ; j++){
                            cout << dataPersona[i].skill[j] << ", ";
                        }
                        cout << endl;
                        cout << "harga   : "  << dataPersona[i].harga << endl;
                    }
                    
                    cout << "pilih nomor persona yang ingin dibeli :"; cin >> index;
                    index -= 1;
                    if(index >= 0 && index <= totalPersona){
                        if(dataPersona[index].harga < user[indeksUser].uang){
                            dataPersonaUser[simpanIndeks].listPersona[tempJumlah].nama = dataPersona[index].nama;
                            dataPersonaUser[simpanIndeks].listPersona[tempJumlah].level = dataPersona[index].level;
                            dataPersonaUser[simpanIndeks].listPersona[tempJumlah].arcana = dataPersona[index].arcana;
                            for(int i = 0; i <= dataPersona[index].panjangSkill - 1; i++){
                                dataPersonaUser[simpanIndeks].listPersona[tempJumlah].skill[i] = dataPersona[index].skill[i];
                            }
                            dataPersonaUser[simpanIndeks].listPersona[tempJumlah].panjangSkill = dataPersona[index].panjangSkill;
                            dataPersonaUser[simpanIndeks].jumlahPersona++;
                            tempJumlah++;
                            
                            user[indeksUser].uang -= dataPersona[index].harga; 
                            cout << "persona berhasil dibeli" << endl;
                            
                        }
                    }
                    break;
                    case 3:
                    
                    if (dataPersonaUser[simpanIndeks].jumlahPersona < 2)
                    {
                        cout << "tidak ada persona yang bisa digabung" << endl;
                    }else {
                        for(int i = 0; i <= dataPersonaUser[simpanIndeks].jumlahPersona - 1; i++){
                            
                            cout << "\n ======" << i + 1 << ". "<< dataPersonaUser[simpanIndeks].listPersona[i].nama << "======" << endl;
                            cout << "level    : "  << dataPersonaUser[simpanIndeks].listPersona[i].level << endl;
                            cout << "arcana   : "  << dataPersonaUser[simpanIndeks].listPersona[i].arcana << endl;
                            
                            cout << "skill    : ";
                            for (int j = 0; j <dataPersonaUser[simpanIndeks].listPersona[i].panjangSkill - 1; j++){
                                cout << dataPersonaUser[simpanIndeks].listPersona[i].skill[j] << ", ";
                            }
                    cout << endl;
                }
            }
            
            int persona1, persona2;
            
            cout << "masukkan persona pertama yang ingin digabung "; cin >> persona1;
            cout << "masukkan persona kedua yang ingin digabung "; cin >> persona2;
            persona1 -= 1;
            persona2 -= 1;
            
            if((persona1 >= 0 && persona1 < dataPersonaUser[simpanIndeks].jumlahPersona) && (persona2 >= 0 && persona2 < dataPersonaUser[simpanIndeks].jumlahPersona) && persona1 != persona2 ){
                int target = ((dataPersonaUser[simpanIndeks].listPersona[persona1].level + dataPersonaUser[simpanIndeks].listPersona[persona2].level) / 2 ) + 1;
                
                int terdekat = 0;
                double selisihTerkecil = abs(dataPersona[0].level);
                
                for (int i = 0; i < totalPersona ; i ++){
                    double selisihSekarang = abs(dataPersona[i].level - target);
                    if (selisihSekarang < selisihTerkecil) {
                        selisihTerkecil = selisihSekarang;
                        terdekat = i;
                    }
                }
                
                dataPersonaUser[simpanIndeks].listPersona[tempJumlah].nama = dataPersona[terdekat].nama;
                dataPersonaUser[simpanIndeks].listPersona[tempJumlah].level = dataPersona[terdekat].level;
                dataPersonaUser[simpanIndeks].listPersona[tempJumlah].arcana = dataPersona[terdekat].arcana;
                    for(int i = 0; i <= dataPersona[terdekat].panjangSkill - 1; i++){
                        dataPersonaUser[simpanIndeks].listPersona[tempJumlah].skill[i] = dataPersona[terdekat].skill[i];
                    }
                    dataPersonaUser[simpanIndeks].listPersona[tempJumlah].panjangSkill = dataPersona[terdekat].panjangSkill;
                    dataPersonaUser[simpanIndeks].jumlahPersona++;
                    tempJumlah++;
                    
                    int maxIdx = max(persona1, persona2);
                    int minIdx = min(persona1, persona2);
                    
                    for(int i = maxIdx; i < tempJumlah - 1 ; i++){
                        dataPersonaUser[simpanIndeks].listPersona[i] = dataPersonaUser[simpanIndeks].listPersona[i + 1];
                        dataPersonaUser[simpanIndeks].jumlahPersona--;
                        tempJumlah--;
                    }
                    
                    for(int i = minIdx; i < tempJumlah - 1 ; i++){
                        dataPersonaUser[simpanIndeks].listPersona[i] = dataPersonaUser[simpanIndeks].listPersona[i + 1];
                        dataPersonaUser[simpanIndeks].jumlahPersona--;
                        tempJumlah--;
                    }
                    
                }else {
                    cout << "nomor yang dipilih tidak ada" << endl;
                }
                
                break;
                case 4:
                if(dataPersonaUser[simpanIndeks].jumlahPersona == 0){
                    cout << "kamu belum punya persona apa apa" << endl;
                    break;
                }
                for(int i = 0; i <= tempJumlah - 1; i++){
                    cout << i + 1 << ". " << dataPersonaUser[simpanIndeks].listPersona[i].nama << endl;
                }
                cout << "pilih nomor persona : "; cin >> index;
                index -= 1;
                if (index >= 0 && index <= tempJumlah - 1) {
                    int tempSkill = dataPersonaUser[simpanIndeks].listPersona[index].panjangSkill;
                        for(int j = 0; j < tempSkill ; j ++){
                            cout << j + 1 << ". " << dataPersonaUser[simpanIndeks].listPersona[index].skill[j] << endl;
                        }
                    
                    cout << "pilih skill yang ingin diubah "; cin >> indexSkill;
                    
                    if(indexSkill - 1 >= 0 && indexSkill <= tempSkill){
                        int indexSkillItem;
                        for(int i = 0; i < 5; i++ ){
                            cout << i + 1 << ". "<< skillItem[i] << " " << endl;;
                        }
                        cout << "pilih nomor skill baru : "; cin >> indexSkillItem;
                        
                        if(indexSkillItem - 1 >= 0 && indexSkillItem <= 5){
                                for(int j = 0; j <= tempSkill - 1; j ++){
                                    if(dataPersonaUser[simpanIndeks].listPersona[index].skill[j] == skillItem[indexSkillItem - 1]){
                                        jumlahDataSama = true;
                                    }
                                }
                                if(jumlahDataSama){
                                    cout << "sudah punya skill yang sama, batalkan pembaruan" << endl;
                                }else{
                                    dataPersonaUser[simpanIndeks].listPersona[index].skill[indexSkill -1] = skillItem[indexSkillItem - 1];
                                    cout << "pembaruan berhasil" << endl;
                                }
                        }else {
                    cout << "nomor skill item tidak ada" << endl;
                }
                    }else {
                    cout << "nomor skill Persona tidak ada" << endl;
                }
                }else {
                    cout << "nomor Persona tidak ada" << endl;
                }
                break;
                case 5:
                if(dataPersonaUser[simpanIndeks].jumlahPersona == 0){
                    cout << "kamu belum punya persona apa apa" << endl;
                    break;
                }else{
                    for(int i = 0; i <= dataPersonaUser[simpanIndeks].jumlahPersona - 1; i++){
                        
                        cout << "\n ======" << i + 1 << ". "<< dataPersonaUser[simpanIndeks].listPersona[i].nama << "======" << endl;
                        cout << "level    : "  << dataPersonaUser[simpanIndeks].listPersona[i].level << endl;
                        cout << "arcana   : "  << dataPersonaUser[simpanIndeks].listPersona[i].arcana << endl;
                        
                        cout << "skill    : ";
                        for (int j = 0; j <dataPersonaUser[simpanIndeks].listPersona[i].panjangSkill - 1; j++){
                            cout << dataPersonaUser[simpanIndeks].listPersona[i].skill[j] << ", ";
                        }cout << endl;
                    }
                }
                cout << "pilih persona yang ingin dihapus" ; cin >> index;
                if (index - 1 >= 0 && index - 1 <= tempJumlah - 1 ){
                    for(int i = index - 1; i < tempJumlah ; i++){
                        dataPersonaUser[simpanIndeks].listPersona[i] = dataPersonaUser[simpanIndeks].listPersona[i + 1];
                        tempJumlah--;
                        dataPersonaUser[simpanIndeks].jumlahPersona--;
                    }
                }else{
                    cout << "nomor persona tidak ada" << endl;
                }
                break;
                case 0:
                cout << "log out" << endl;
                status = 0;
                break;
                
                default:
                cout << "Pilihan tidak valid." << endl;
                break;
            }
        }while(pilihan != 0);
        
    }else if(inputNama == "0" || inputPass == "0"){
        cout << "keluar dari program...." << endl;
        break;
    }else{
        cout << "nama atau password salah, coba lagi" << endl;
        percobaan++;
        
    }
}
    cout << "terlalu banyak mecoba";
return 0;
}