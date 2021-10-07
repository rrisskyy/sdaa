
#include <iostream>
#include <tuple>
#include <variant>

using namespace std;

int main() {
    string dataMyItems[]{
        "1, Daido Fastlock Snap + Kili-Kili 12pcs, 14000, Lainnya, 1",
        "2, Joran Iroly Beset Spin 180cm, 100000, Joran, 1",
        "3, Reel BC Fugu Taru 17+1 Bearings System Left, 310000, Reel, 1",
        "4, Reel BC Lizard Lure Killer 7:2:1 Left, 205000, Reel, 1",
        "5, Reel Fugu Aojiro (6000) 10 Ball Bearings, 150000, Reel, 1",
        "6, Reel Daido Reno (4000) 6 Ball Bearings, 140000, Reel, 1",
        "7, Joran Katana Fiber SDA 180cm, 110000, Joran, 1",
        "8, Joran Surf Ruas Pendek Length 240, 70000, Joran, 1",
        "9, Joran Surf Ruas Pendek Length 270, 80000, Joran, 1",
        "10,  Joran Surf Ruas Pendek Length 300, 85000, Joran, 1",
        "11,  Joran Surf Ruas Pendek Length 360, 100000, Joran, 1",
        "12,  Joran Surf Ruas Pendek Length 450, 130000, Joran, 1",
        "13,  Sinori 0.50mm, 32000, Nylon, 1",
        "14,  Hard Jump Frog, 50000, Lure, 1",
        "15,  Soft Frog, 32000, Lure, 1",
        "16,  Hard Frog Lure, 32000, Lure, 1",
        "17,  Top One 100m, 20000, Nylon, 1",
        "18,  Ghostline Leader, 28000, Nylon, 1",
        "19,  Sensor 0.35mm, 32000, Nylon, 1",
        "20,  Box Penyimpan Lure Lure 3 slot, 23000, Lainnya, 1",
        "21,  Soft Frog Lure, 32000, Lure, 1",
        "22,  Soft Frog Lure, 27000, Lure, 1",
        "23,  Soft Frog Lure, 27000, Lure, 1",
        "24,  Soft Frog Lure, 35000, Lure, 1",
        "25,  Reel BC Fugu Taru 17+1 Bearings System Left, 310000, Reel, 1",
        "26,  Reel Kaizen Oishi (4000) 3 Ball Bearings 5.1:1, 150000, Reel, 1",
        "27,  Daido Tsunami (4000) 6 Ball Bearings 4.7:1, 148000, Reel, 1",
        "28,  Reel Daido Zodias (2000) 6 Ball Bearings 4.7:1, 125000, Reel, 1",
        "29,  Reel Daido Reno (2000) 6 Ball Bearings 4.7:1, 125000, Reel, 1",
        "30,  Reel Kaizen Haruki (2000) 3 Ball Bearings 5.1:1, 145000, Reel, 1",
        "31,  Reel Daido Zodias (4000) 6 Ball Bearings 4.7:1, 148000, Reel, 1",
        "32,  Reel Kaizen Gin (4000) 3 Ball Bearings 5.1:1, 180000, Reel, 1",
        "33,  Reel Daido Fino Max (250) 5 Ball Bearings 5.2:1, 75000, Reel, 1",
        "34,  Reel Kaizen Gin (2000) 3 Ball Bearings 5.1:1, 160000, Reel, 1",
        "35,  Reel Daido Reno (1000) 3 Ball Bearings 5.1:1, 120000, Reel, 1",
        "36,  Joran BC Daido Tomman 180cm, 250000, Joran, 1",
        "37,  Mata Pancing Kaizen Akitakitsune, 8000, Hook, 1",
        "38,  Mata Pancing Kaizen Chinu, 8000, Hook, 1",
        "39,  Mata Pancing Carbon Charm 1054 1-13, 7000, Hook, 1",
        "40,  Mata Pancing Carbon Plus 1130L 1-13, 7000, Hook, 1",
        "41,  Mata Pancing Owner Unagi  1 - 20, 28000, Hook, 1",
        "42,  Mata Pancing Carbon Mix 1-17, 7000, Hook, 1",
        "43,  Reel Daido Zodias (6000) 6 Ball Bearings 4.7:1, 162000, Reel, 1",
        "44,  Joran Kaizen Fiber Python 150cm, 100000, Joran, 1",
        "45,  Daido Fastlock Snap + Kili-Kili 12pcs, 14000, Lainnya, 1",
        "46,  Joran Iroly Beset Spin 180cm, 100000, Joran, 1",
        "47,  Pioneer Fastlock Snap HS 12pcs, 10000, Lainnya, "
    }; //file versi json bisa dilihat disini https://github.com/rrisskyy/sdaa/blob/main/items.json

    int arrSize = sizeof(dataMyItems) / sizeof(dataMyItems[0]);
    char pil = 's';
    while (pil != '0') {
        cout << "1. Lihat Barang\n" << "2. Tambah Barang\n" << "3. Ubah Barang\n" << "4. Hapus Barang\n" << "0. Exit\n\n";
        cout << "Masukkan Input >>>   ";
        cin >> pil;
        switch (pil) {
        case '1':
            for (int i = 0; i < arrSize; i++) {
                cout << dataMyItems[i] << "\n";
            }
            cout << "\n\n\n\n";
            break;
        case '2':
            /**/
            break;
        case '3':
            /**/
            break;
        case '4':
            /**/
            break;
        case '0':
            /**/
            break;
        default:
            cout << "Input anda Salah!!";
            break;
        }
    }
}
