#include <iostream>
using namespace std;

// prosedur ini menerima nilai dari variable gajiSaya
void cobaUbahGaji(int gajiSaya) {
gajiSaya = 1000000000; // gaji di dalam prosedur
cout << "Gaji pas di dalam fungsi: " << gajiSaya << endl;
}

int main() {
int gajiSaya = 5000000; // gaji di dalam main

cout << "Gaji awal: " << gajiSaya << endl;

cobaUbahGaji(gajiSaya); // kirim ke fungsi

cout << "Gaji setelah fungsi dipanggil: " << gajiSaya << endl;

return 0;
}