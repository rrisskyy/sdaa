#include <iostream>

using namespace std;


struct Item {
	int _id;
	string itemType;
	string name;
	int price;
	int stok;
};

void tambahBarang(Item *items, int &jumlah, int &arrSize) {
	
	for (int i = 0; i < jumlah; i ++) {
		items->_id = arrSize;
		cout<<"Masukkan nama barang :  ";	fflush(stdin);getline(cin,items->name);
		cout<<"Masukkan harga barang :  "; 	cin>>items->price;
		cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,items->itemType);
		cout<<"Masukkan stok barang :  ";	cin>> items->stok;
		arrSize++;
	}
	
}



int main() {
	char pil = 'o';
	int tempInt, tempIndex, jumlah;
	string temp;
	int arrSize = 0;
	
	
	
	while (pil != 0) {
		cout << "1. Lihat Barang\n" << "2. Tambah Barang\n" << "3. Ubah Barang\n" << "4. Hapus Barang\n" << "5. Simpan Barang Kedalam Database\n" << "0. Keluar\n\n" << endl;
		cout << "Masukkan Pilihan >>>  ";
		cin >> pil;

		if (pil == '1') {
			
		}
		else if (pil == '2') {
			cout<< "Masukkan Jumlah Barang :  ";
			cin >> jumlah;
			Item items[jumlah];
			tambahBarang(&items[0], jumlah, arrSize);
		}
		else if (pil == '3') {
		}
		else if (pil == '4') {
		}
	}
}
