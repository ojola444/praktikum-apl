#include <iostream>
using namespace std;

int main() {
    int matriks[3][3] = {

{1, 2, 3}, // Baris ke-0
{4, 5, 6},// Baris ke-1
{7, 8, 9} // Baris ke-2

};

for (auto &baris : matriks) { // Iterasi setiap baris (array 1D)
for (auto &elemen : baris) { // Iterasi setiap elemen dalam baris
cout << elemen << " ";
}
cout << endl;
}

    return 0;
}
