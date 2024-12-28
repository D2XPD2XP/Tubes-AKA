#include <iostream>
#include <chrono>  // Untuk mengukur waktu eksekusi
#include <iomanip> // Untuk mengatur format output
using namespace std;
using namespace chrono;

// Struktur Armada untuk menyimpan jumlah bus
struct Armada {
    int BusVip = 0;
    int Bus = 0;
    int Shuttle = 0;
};

Armada hitungArmada(int nPenumpang, Armada &unit){
    while (nPenumpang > 0) {
        if (nPenumpang >= 50) {
            unit.BusVip += 1;
            nPenumpang -= 50;
        } else if (nPenumpang < 50 && nPenumpang >= 30) {
			unit.Bus += 1;
			nPenumpang -= 30;
		} else {
			unit.Shuttle += 1;
			nPenumpang -= 10;
		}
    }
    return unit;
}

// Fungsi hitungArmada untuk menghitung armada bus yang diperlukan
//Armada hitungArmada(int penumpang, Armada unit) {
//    if (penumpang <= 0) {
//        return unit;
//    }
//
//    if (penumpang >= 50) {
//        unit.BusVip += 1;
//        return hitungArmada(penumpang - 50, unit);
//    } else if (penumpang >= 30) {
//        unit.Bus += 1;
//        return hitungArmada(penumpang - 30, unit);
//    } else {
//        unit.Shuttle += 1;
//        return hitungArmada(penumpang - 10, unit);
//    }
//}

int main() {
    // Melakukan iterasi untuk jumlah penumpang dari 1000 hingga 50000 dengan increment 1000
    for (int penumpang = 1000; penumpang <= 500000; penumpang += 1000) {

        // Mengukur waktu eksekusi
        auto start = high_resolution_clock::now();  // Waktu mulai

        // Menjalankan fungsi hitungArmada beberapa kali untuk menambah durasi eksekusi
        for (int i = 0; i < 1000; ++i) {
            Armada unit;
            unit = hitungArmada(penumpang, unit); // Menghitung armada yang dibutuhkan
        }

        auto stop = high_resolution_clock::now();   // Waktu selesai
        auto duration = duration_cast<milliseconds>(stop - start);  // Menghitung durasi dalam milidetik

        // Menampilkan waktu eksekusi dalam milidetik
        cout << duration.count() << endl;
    }

    return 0;
}
