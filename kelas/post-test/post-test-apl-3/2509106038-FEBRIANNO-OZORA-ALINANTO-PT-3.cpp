#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct LevelUser {
    string nama;
    string password;
    int uang;
    int status; 
};

struct persona {
    string nama;
    int level;
    string arcana;
    vector<string> skills; 
    int harga;
    
};

struct personaUser {
    string user;
    vector<persona> listPersona; 
};


vector<LevelUser> users = {
    {"ozora", "038", 10000, 2},
    {"igor", "444", 999999, 1}
};

vector<persona> personaUtama = {
    {"orpheus", 10, "fool", {"agi", "dia", "bash", "tarunda"}, 500},
    {"jack o lantern", 15, "magician", {"bufu", "pulinpa", "mabufu", "shock punch", "freeze boost", "magic boost"}, 750},
    {"archangel", 20, "justice", {"kouha", "single shot", "baisudi", "sukukaja", "holy arrow", "apt pupil"}, 1000}
};

vector<personaUser> profilUser;

const vector<string> skillItems = {"masukunda", "dekaja", "debilitate", "charge", "concentrate"};


void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool cekNamaPersona(const string& name, int excludeIndex = -1) {
    for (size_t i = 0; i < personaUtama.size(); ++i) {
        if (i == excludeIndex) continue;
        if (personaUtama[i].nama == name) {
            return true;
        }
    }
    return false;
}

bool cekSkillPersona(const vector<string>& skills, const string& skillName, int excludeIndex = -1) {
    for (size_t i = 0; i < skills.size(); ++i) {
        if (i == excludeIndex) continue;
        if (skills[i] == skillName) {
            return true;
        }
    }
    return false;
}

bool cekUser(const string& name) {
    for (const auto& u : users) {
        if (u.nama == name) {
            return true;
        }
    }
    return false;
}

int cariIndexUser(const string& name) {
    for (size_t i = 0; i < users.size(); ++i) {
        if (users[i].nama == name) {
            return i;
        }
    }
    return -1;
}

int cariAtauBuatProfil(const string& username) {
    for (size_t i = 0; i < profilUser.size(); ++i) {
        if (profilUser[i].user == username) {
            return i;
        }
    }

    personaUser newProfile;
    newProfile.user = username;
    profilUser.push_back(newProfile);
    return profilUser.size() - 1;
}


void registerUser() {
    string namaBaru, passBaru;
    cout << "\n=== Registrasi user baru ===" << endl;
    cout << "masukkan nama user : ";
    cin >> namaBaru;
    
    if (cekUser(namaBaru)) {
        cout << "nama user sudah terdaftar!" << endl;
        return;
    }

    cout << "masukkan password : ";
    cin >> passBaru;

    LevelUser newUser;
    newUser.nama = namaBaru;
    newUser.password = passBaru;
    newUser.uang = 10000; 
    newUser.status = 2;   

    users.push_back(newUser);
    cout << "registrasi berhasil " << endl;
}

bool login(int& userIndex) {
    string inputNama, inputPass;
    int percobaan = 1;
    
    while (percobaan <= 3) {
        cout << "\n--- Menu Login ---" << endl;
        cout << "masukkan nama (atau 0 untuk keluar): ";
        cin >> inputNama;

        if (inputNama == "0") {
            return false;
        }

        cout << "masukkan Password : ";
        cin >> inputPass;

        userIndex = cariIndexUser(inputNama);

        if (userIndex != -1 && users[userIndex].password == inputPass) {
            cout << "selamat datang " << users[userIndex].nama << endl;
            return true;
        } else {
            cout << "nama atau password salah, coba lagi " << endl;
            percobaan++;
        }
    }
    cout << "Terlalu banyak mencoba login." << endl;
    return false;
}

void lihatPersonaUtama() {
    if (personaUtama.empty()) {
        cout << "Tidak ada persona yang bisa dibaca" << endl;
        return;
    }
    for (size_t i = 0; i < personaUtama.size(); ++i) {
        cout << "\n====== " << i + 1 << personaUtama[i].nama << " ======" << endl;
        cout << "Level    : " << personaUtama[i].level << endl;
        cout << "Arcana   : " << personaUtama[i].arcana << endl;
        cout << "Skill    : ";
        for (const auto& skill : personaUtama[i].skills) {
            cout << skill << ", ";
        }
        cout << endl;
        cout << "Harga    : " << personaUtama[i].harga << endl;
    }
}

void tambahPersona() {

    persona newP;
    cout << "masukkan nama persona : ";
    clearInputBuffer();
    getline(cin, newP.nama);

    if (cekNamaPersona(newP.nama)) {
        cout << "Gagal: Nama persona sudah ada!" << endl;
        return;
    }

    cout << "masukkan level persona : ";
    cin >> newP.level;
    cout << "masukkan arcana persona : ";
    cin >> newP.arcana;

    cout << "masukkan skill persona (ketik 'stop' untuk berhenti):" << endl;
    clearInputBuffer();
    while (newP.skills.size() < 8) {
        string inputSkill;
        cout << "Skill " << (newP.skills.size() + 1) << ": ";
        getline(cin, inputSkill);
        if (inputSkill == "stop") break;

        if (cekSkillPersona(newP.skills, inputSkill)) {
            cout << "Skill tersebut sudah ada di persona ini, abaikan." << endl;
        } else {
            newP.skills.push_back(inputSkill);
        }
    }

    cout << "masukkan harga persona : ";
    cin >> newP.harga;

    personaUtama.push_back(newP);
    cout << "Data persona berhasil dimasukkan" << endl;
}

void updatePersona() {
    if (personaUtama.empty()) {
        cout << "Tidak ada persona yang bisa diubah" << endl;
        return;
    }

    lihatPersonaUtama();

    int index;
    cout << "masukkan nomor persona yang ingin diubah: ";
    cin >> index;

    if (index - 1 >= 0 && index - 1 < (int)personaUtama.size()) {
        int idx = index - 1;
        int pilihan;
        do {
            cout << "\n--- Update persona: " << personaUtama[idx].nama << " ---" << endl;
            cout << "1. Ubah nama persona" << endl;
            cout << "2. Ubah level persona" << endl;
            cout << "3. Ubah arcana persona" << endl;
            cout << "4. Ubah skill persona" << endl;
            cout << "5. Ubah harga persona" << endl;
            cout << "0. Batal update" << endl;
            cout << "pilihan: ";
            cin >> pilihan;
    
            switch (pilihan) {
            case 1: {
                string namaBaru;
                cout << "masukkan nama baru : ";
                clearInputBuffer();
                getline(cin, namaBaru);
                if (cekNamaPersona(namaBaru, idx)) {
                    cout << "Gagal: Nama persona sudah ada!" << endl;
                } else {
                    personaUtama[idx].nama = namaBaru;
                    cout << "Berhasil diubah" << endl;
                }
                break;
            }
            case 2:
                cout << "masukkan level baru : ";
                cin >> personaUtama[idx].level;
                cout << "Berhasil diubah" << endl;
                break;
            case 3:
                cout << "masukkan arcana baru : ";
                cin >> personaUtama[idx].arcana;
                cout << "Berhasil diubah" << endl;
                break;
            case 4: {
                if (personaUtama[idx].skills.empty()) {
                    cout << "Tidak ada skill untuk diubah" << endl;
                    break;
                }
                for (size_t j = 0; j < personaUtama[idx].skills.size(); ++j) {
                    cout << "Skill ke " << (j + 1) << " : " << personaUtama[idx].skills[j] << endl;
                }
                int idxSkill;
                cout << "masukkan nomor skill yang ingin diubah : ";
                cin >> idxSkill;
                if (idxSkill >= 1 && idxSkill <= (int)personaUtama[idx].skills.size()) {
                    clearInputBuffer();
                    string skillBaru;
                    cout << "masukkan skill baru : ";
                    getline(cin, skillBaru);
                    
                    if (cekSkillPersona(personaUtama[idx].skills, skillBaru, idxSkill - 1)) {
                        cout << "Gagal: Skill sudah ada di persona ini!" << endl;
                    } else {
                        personaUtama[idx].skills[idxSkill - 1] = skillBaru;
                        cout << "Skill berhasil diubah" << endl;
                    }
                } else {
                    cout << "Nomor skill tidak valid" << endl;
                }
                break;
            }
            case 5:
                cout << "masukkan harga baru : ";
                cin >> personaUtama[idx].harga;
                cout << "Berhasil diubah" << endl;
                break;
            case 0:
                cout << "Batal update" << endl;
                break;
            default:
                cout << "pilihan tidak valid" << endl;
            }
        } while (pilihan != 0);

    }else{
        cout << "Nomor tidak valid" << endl;
        return; 
    }

}

void hapusPersona() {
    if (personaUtama.empty()) {
        cout << "Tidak ada persona yang bisa dihapus" << endl;
        return;
    }

    lihatPersonaUtama();

    int index;
    cout << "masukkan nomor persona yang ingin dihapus : ";
    cin >> index;

    if (index >= 1 && index <= (int)personaUtama.size()) {
        personaUtama.erase(personaUtama.begin() + (index - 1));
        cout << "persona berhasil dihapus" << endl;
    } else {
        cout << "Tidak ada persona di nomor itu" << endl;
    }
}

void menuAdmin(int userIndex) {
    int pilihan;
    do {
        cout << "\n= Menu Velvet Room Admin =" << endl;
        cout << "1. Tampilkan data persona" << endl;
        cout << "2. Tambah persona" << endl;
        cout << "3. Update persona" << endl;
        cout << "4. Hapus persona" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: lihatPersonaUtama(); break;
        case 2: tambahPersona(); break;
        case 3: updatePersona(); break;
        case 4: hapusPersona(); break;
        case 0: cout << "Log out...." << endl; break;
        default: cout << "pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);
}

void lihatPersonaUser(int profilIndex) {
    if (profilUser[profilIndex].listPersona.empty()) {
        cout << "Tidak ada persona yang dilihat" << endl;
        return;
    }
    for (size_t i = 0; i < profilUser[profilIndex].listPersona.size(); ++i) {
        const auto& p = profilUser[profilIndex].listPersona[i];
        cout << "\n====== "<< i + 1 << p.nama << " ======" << endl;
        cout << "Level    : " << p.level << endl;
        cout << "Arcana   : " << p.arcana << endl;
        cout << "Skill    : ";
        for (const auto& skill : p.skills) {
            cout << skill << ", ";
        }
        cout << endl;
    }
}

void beliPersona(int userIndex, int profilIndex) {
    lihatPersonaUtama();
    int index;
    cout << "Pilih nomor persona yang ingin dibeli (0 untuk batal) : ";
    cin >> index;
    index -= 1;

    if (index == -1 ){
        cout << "batal membeli" << endl;
    }

    if (index >= 0 && index < (int)personaUtama.size()) {
            if (users[userIndex].uang >= personaUtama[index].harga) {
            persona terbeli = personaUtama[index];
            profilUser[profilIndex].listPersona.push_back(terbeli);
            users[userIndex].uang -= personaUtama[index].harga;
            cout << "persona berhasil dibeli! Sisa uang: " << users[userIndex].uang << endl;
            }else{
            cout << "Uang tidak cukup!" << endl;
            }
    } else {
        cout << "Nomor persona tidak valid" << endl;
    }
}

void fusePersona(int profilIndex) {
    if (profilUser[profilIndex].listPersona.size() < 2) {
        cout << "Tidak ada persona yang bisa digabung (Minimal 2)" << endl;
        return;
    }

    lihatPersonaUser(profilIndex);

    int p1, p2;
    cout << "masukkan nomor persona pertama : "; cin >> p1;
    cout << "masukkan nomor persona kedua : "; cin >> p2;
    p1--; p2--;

    if (p1 >= 0 && p1 < (int)profilUser[profilIndex].listPersona.size() && p2 >= 0 && p2 < (int)profilUser[profilIndex].listPersona.size() && p1 != p2) {
        
        int lvl1 = profilUser[profilIndex].listPersona[p1].level;
        int lvl2 = profilUser[profilIndex].listPersona[p2].level;
        int targetLevel = (lvl1 + lvl2) / 2 + 1;

        int terdekat = 0;
        int minDiff = abs(personaUtama[0].level - targetLevel);

        for (size_t i = 1; i < personaUtama.size(); ++i) {
            int diff = abs(personaUtama[i].level - targetLevel);
            if (diff < minDiff) {
                minDiff = diff;
                terdekat = i;
            }
        }

        profilUser[profilIndex].listPersona.push_back(personaUtama[terdekat]);
        cout << "Fusion berhasil! Mendapatkan: " << personaUtama[terdekat].nama << endl;


        int maxIdx = max(p1, p2);
        int minIdx = min(p1, p2);
        
        profilUser[profilIndex].listPersona.erase(profilUser[profilIndex].listPersona.begin() + maxIdx);
        profilUser[profilIndex].listPersona.erase(profilUser[profilIndex].listPersona.begin() + minIdx);

    } else {
        cout << "Nomor yang dipilih tidak valid" << endl;
    }
}

void updateSkillUser(int profilIndex) {
    if (profilUser[profilIndex].listPersona.empty()) {
        cout << "Kamu belum punya persona apa-apa" << endl;
        return;
    }

    for (size_t i = 0; i < profilUser[profilIndex].listPersona.size(); ++i) {
        cout << (i + 1) << ". " << profilUser[profilIndex].listPersona[i].nama << endl;
    }

    int index;
    cout << "Pilih nomor persona : "; cin >> index;
    index -= 1;

    if (index >= 0 && index < (int)profilUser[profilIndex].listPersona.size()) {
        auto& p = profilUser[profilIndex].listPersona[index];
        if (p.skills.empty()) {
            cout << "persona ini tidak memiliki skill" << endl;
            return;
        }

        for (size_t j = 0; j < p.skills.size(); ++j) {
            cout << (j + 1) << ". " << p.skills[j] << endl;
        }

        int idxSkill;
        cout << "Pilih skill yang ingin diubah : "; cin >> idxSkill;
        idxSkill -= 1;

        if (idxSkill >= 0 && idxSkill < (int)p.skills.size()) {
            cout << "Daftar Skill Item:" << endl;
            for (size_t i = 0; i < skillItems.size(); ++i) {
                cout << (i + 1) << ". " << skillItems[i] << endl;
            }
            int idxItem;
            cout << "Pilih nomor skill baru : "; cin >> idxItem;
            idxItem -= 1;

            if (idxItem >= 0 && idxItem < (int)skillItems.size()) {
                string skillBaru = skillItems[idxItem];
                if (cekSkillPersona(p.skills, skillBaru, idxSkill)) {
                    cout << "Sudah punya skill yang sama, batalkan pembaruan" << endl;
                } else {
                    p.skills[idxSkill] = skillBaru;
                    cout << "Pembaruan berhasil" << endl;
                }
            } else {
                cout << "Nomor skill item tidak ada" << endl;
            }
        } else {
            cout << "Nomor skill persona tidak ada" << endl;
        }
    } else {
        cout << "Nomor persona tidak ada" << endl;
    }
}

void hapusPersonaUser(int profilIndex) {
    if (profilUser[profilIndex].listPersona.empty()) {
        cout << "Kamu belum punya persona apa-apa" << endl;
        return;
    }

    lihatPersonaUser(profilIndex);

    int index;
    cout << "Pilih persona yang ingin dihapus : "; cin >> index;
    if (index >= 1 && index <= (int)profilUser[profilIndex].listPersona.size()) {
        profilUser[profilIndex].listPersona.erase(profilUser[profilIndex].listPersona.begin() + (index - 1));
        cout << "persona berhasil dihapus" << endl;
    } else {
        cout << "Nomor persona tidak ada" << endl;
    }
}

void userMenu(int userIndex) {
    int profilIndex = cariAtauBuatProfil(users[userIndex].nama);
    int pilihan;
    do {
        cout << "\n= Menu Velvet Room User =" << endl;
        cout << "User: " << users[userIndex].nama << " | Uang: " << users[userIndex].uang << " yen" << endl;
        cout << "1. Lihat data persona user" << endl;
        cout << "2. Beli persona" << endl;
        cout << "3. Fuse/Gabung persona" << endl;
        cout << "4. Ubah skill persona" << endl;
        cout << "5. Hapus persona" << endl;
        cout << "0. Keluar" << endl;
        cout << "pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
        case 1: lihatPersonaUser(profilIndex); break;
        case 2: beliPersona(userIndex, profilIndex); break;
        case 3: fusePersona(profilIndex); break;
        case 4: updateSkillUser(profilIndex); break;
        case 5: hapusPersonaUser(profilIndex); break;
        case 0: cout << "Log out" << endl; break;
        default: cout << "pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);
}

int main() {
    int currentUserIndex = -1;
    

    while (true) {
        cout << "\n=== SELAMAT DATANG DI VELVET ROOM ===" << endl;
        cout << "1. login" << endl;
        cout << "2. register" << endl;
        cout << "0. keluar" << endl;
        cout << "pilihan : ";
        
        int pilihanUtama;
        cin >> pilihanUtama;

        if (pilihanUtama == 0) {
            cout << "keluar dari program...." << endl;
            break;
        } else if (pilihanUtama == 1) {
            if (login(currentUserIndex)) {
                if (users[currentUserIndex].status == 1) {
                    menuAdmin(currentUserIndex);
                } else if (users[currentUserIndex].status == 2) {
                    userMenu(currentUserIndex);
                } else {
                    cout << "status user tidak dikenali." << endl;
                }
            }
        } else if (pilihanUtama == 2) {
            registerUser();
        } else {
            cout << "pilihan tidak valid." << endl;
        }
    }

    return 0;
}