#include <iostream>
#include <fstream>

using namespace std;


struct Item {
	int _id;
	string name;
	int price;
	string itemType;
	int stok;
};

void printBarang (Item *items, int &arrSize);
void tambahBarang(Item *items, int &arrSize);
void ubahBarang(Item *items, int &arrSize);


int main() {
	Item items[100];
	items[0]._id = 1;
	items[0].name = "Reel BC Fugu Taru 17+1 Bearings System Left";
	items[0].price = 310000;
	items[0].itemType= "Reel";
	items[0].stok= 10;
	
	items[1]._id = 2;
	items[1].name = "Reel BC Lizard Lure Killer 7:2:1 Left";
	items[1].price = 205000,
	items[1].itemType = "Reel";
	items[1].stok = 10;
	
	items[2]._id = 3;
	items[2].name = "Reel Fugu Aojiro (6000) 10 Ball Bearings";
	items[2].price = 150000,
	items[2].itemType = "Reel";
	items[2].stok = 10;
	
	items[3]._id = 4;
	items[3].name = "Reel Daido Reno (4000) 6 Ball Bearings";
	items[3].price = 140000,
	items[3].itemType = "Reel";
	items[3].stok = 10;
	
	items[4]._id = 5;
	items[4].name = "Joran Katana Fiber SDA 180cm";
	items[4].price = 110000,
	items[4].itemType = "Joran";
	items[4].stok = 10;
	
	items[5]._id = 6;
	items[5].name = "Joran Surf Ruas Pendek Length 240";
	items[5].price = 70000,
	items[5].itemType = "Joran";
	items[5].stok = 10;
	//	Default Items
	  
	char pil = 'o';																																																																																																																																																																																																																																																																																																																																																																																					
	int tempInt, tempIndex, jumlah;
	string temp;
	int arrSize = 6;
	
	
	
	while (pil != 0) {
		cout << "1. Lihat Barang\n" << "2. Tambah Barang\n" << "3. Ubah Barang\n" << "4. Hapus Barang\n" << "5. Simpan Barang Kedalam CSV\n" << "0. Keluar\n\n" << endl;
		cout << "Masukkan Pilihan >>>  ";
		cin >> pil;

		if (pil == '1') {
			printBarang(&items[0], arrSize);
		}
		else if (pil == '2') {
			tambahBarang(&items[arrSize], arrSize);
		}
		else if (pil == '3') {
			printBarang(&items[0], arrSize);
			cout<<"Masukkan ID yang ingin anda ubah :  ";
			cin>>tempIndex;	
			tempIndex--;
			cout << "\nYang ingin anda ubah adalah : \n\nID : " << ++tempIndex << " \nNama : " <<items[tempIndex].name<< " \nHarga : " << items[tempIndex].price<< " \nTipe : " <<items[tempIndex].itemType<<" \nStok : "<<items[tempIndex].stok<<"\n\n\n"<<endl;
			
			ubahBarang(&items[tempIndex-1], arrSize);
		}
		else if (pil == '4') {
			printBarang(&items[0], arrSize);
			cout<<"\n\nMasukkan ID yang ingin anda hapus :  ";
			cin>>tempIndex;
			--tempIndex;
			for (int i = tempIndex; i < arrSize; i++){
				items[i] = items[i+1];
			};	
			arrSize--;
			cout<<"Berhasil!!\n\n\n";
		}
		else if (pil == '5') {
		  	ofstream MyFile("item.csv");
		  	MyFile << "_id, name, price, itemType, stok\n";
		    for(int i = 0; i < arrSize; i++) {
		    	MyFile <<items[i]._id<<","<<items[i].name<<","<<items[i].price<<","<<items[i].itemType<<","<<items[i].stok<<"\n";
			}
		  	// Close the file
		  	MyFile.close();
		  	cout<<"Berhasil!!\n\n\n";
		}
	}
}

void printBarang(Item *items, int &arrSize) {
	for(int i = 0; i < arrSize; i++) {
		cout<< "ID \t\t: " <<items[i]._id << "\n";
		cout<< "Nama Barang \t: " <<items[i].name << "\n";
		cout<< "Harga Barang \t: "<<items[i].price<<"\n";
		cout<< "Tipe Barang \t: "<<items[i].itemType<< "\n";
		cout<< "Stok Barang \t: "<<items[i].stok<<"\n\n"<<endl;
	}
}

void tambahBarang(Item *items, int &arrSize) {
	items->_id = arrSize+1;
	cout<<"Masukkan nama barang :  " ;	fflush(stdin);getline(cin,items->name);
	cout<<"Masukkan harga barang :  "; 	cin>>items->price;
	cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,items->itemType);
	cout<<"Masukkan stok barang :  " ;	cin>> items->stok;
	arrSize++;
	cout<<"\n\nBerhasil!!!\nBerhasil Menambahkan : \n";
	cout<< "ID \t\t: " <<items[0]._id << "\n";
	cout<< "Nama Barang \t: " <<items[0].name << "\n";
	cout<< "Harga Barang \t: "<<items[0].price<<"\n";
	cout<< "Tipe Barang \t: "<<items[0].itemType<< "\n";
	cout<< "Stok Barang \t: "<<items[0].stok<<"\n\n"<<endl;
	cin.get();
}
void ubahBarang(Item *items, int &arrSize) {
	cout<<"Masukkan nama barang :  " ;	fflush(stdin);getline(cin,items->name);
	cout<<"Masukkan harga barang :  "; 	cin>>items->price;
	cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,items->itemType);
	cout<<"Masukkan stok barang :  " ;	cin>> items->stok;
	cout<<"\n\nBerhasil!!!\n\n";
}
