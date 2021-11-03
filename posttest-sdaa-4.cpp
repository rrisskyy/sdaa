//github.com/rrisskyy/sdaa
#include <iostream>
#include <fstream>
#include <math.h> 

using namespace std;


struct Item {
	int _id;
	string name;
	int price;
	string itemType;
	int stok;
};
Item items[100];
int arrSize = 6;


void printBarang ( Item *items, int &arrSize );
void printOneBarang ( Item *items );
void tambahBarang( Item *items, int &arrSize );
void ubahBarang( Item *items, int &arrSize );

//Sort
void shellSort( Item *items, int &arrSize, int orderItem, int orderMethod );
void quickSort( Item *arr, int low, int high );
//void mergeSort(Item *arr, int l, int m, int r)


//Search
int fibMonaccianSearch( Item *arr, int x, int n );
int jumpSearch( Item *arr, int x, int n );

int main() {
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
	int tempInt, tempIndex, jumlah, orderItem, orderMethod, searchItem, searchMethod, res, x;
	string temp;
	
	
	
	
	while (pil != 0) {
		cout << "1. Lihat Barang\n" 
			 << "2. Tambah Barang\n"
			 << "3. Ubah Barang\n" 
			 << "4. Hapus Barang\n" 
			 << "5. Simpan Barang Kedalam CSV\n" 
			 << "6. Sorting Barang\n"  
			 << "7. Searching Barang\n\n"  
			 << "0. Keluar\n\n" <<endl;
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
		  	MyFile.close();
		  	cout<<"Berhasil!!\n\n\n";
		}
		else if (pil == '6') {
			//Shell Sort
			sort:
				cout<<"1. Sort Berdasarkan Nama"<<endl;
				cout<<"2. Sort Berdasarkan Harga"<<endl;
				cout<<"Silahkan Pilih Menu : ";cin>>orderItem;
				if(orderItem == 1 or orderItem == 2) {
					cout<<"1. Ascending"<<endl;
					cout<<"2. Descending"<<endl;
					cout<<"Silahkan Pilih Menu : ";cin>>orderMethod;	
					shellSort( &items[0], arrSize, orderItem, orderMethod );		
				} else {
					goto sort;
				}
			cout<<"Berhasil!!\n\n\n";
		}
		else if (pil == '7') {
			//Karena tidak ada ketentuan minimum, jadi hanya search berdasarkan 1 Kateogri saja
			search:
				cout<<"1. Fibonacci Search"<<endl;
				cout<<"2. Jump Search"<<endl;
				cout<<"Silahkan Pilih Menu : ";cin>>searchMethod;
				if(searchMethod == 1) {
					cout<<" == Search Berdasarkan ID Barang  == "<<endl;
					int high = arrSize-1;
					//Wajib disorting dahulu
 					quickSort(&items[0], 0, high);
					cout<<"Silahkan Masukkan ID yang ingin anda cari : "; cin>>x;
					res = fibMonaccianSearch(&items[0], x, arrSize);
					tempIndex = res+1;
					printOneBarang(&items[res]);
				} else if(searchMethod == 2) {
					cout<<" == Search Berdasarkan ID == "<<endl;
					int high = arrSize-1;
					//Wajib disorting dahulu
 					quickSort(&items[0], 0, high);
					cout<<"Silahkan Masukkan ID yang ingin anda cari : "; cin>>x;
					res = jumpSearch(&items[0], x, arrSize);
					printOneBarang(&items[res]);
				} else {
					goto search;
				}
		}
	}
}



void printBarang( Item *items, int &arrSize ) {
	for(int i = 0; i < arrSize; i++) {
		cout<< "ID \t\t: " <<items->_id << "\n";
		cout<< "Nama Barang \t: " <<items->name << "\n";
		cout<< "Harga Barang \t: "<<items->price<<"\n";
		cout<< "Tipe Barang \t: "<<items->itemType<< "\n";
		cout<< "Stok Barang \t: "<<items->stok<<"\n\n"<<endl;
		items++;
	}
}
void printOneBarang( Item *items ) {
		cout<< "\n\n\nIni adalah Barang yang anda cari : \n";
		cout<< "\nID \t\t: " <<items->_id << "\n";
		cout<< "Nama Barang \t: " <<items->name << "\n";
		cout<< "Harga Barang \t: "<<items->price<<"\n";
		cout<< "Tipe Barang \t: "<<items->itemType<< "\n";
		cout<< "Stok Barang \t: "<<items->stok<<"\n\n"<<endl;
}
void tambahBarang( Item *items, int &arrSize ) {
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
void ubahBarang( Item *items, int &arrSize ) {
	cout<<"Masukkan nama barang :  " ;	fflush(stdin);getline(cin,items->name);
	cout<<"Masukkan harga barang :  "; 	cin>>items->price;
	cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,items->itemType);
	cout<<"Masukkan stok barang :  " ;	cin>> items->stok;
	cout<<"\n\nBerhasil!!!\n\n";
}


//================ S o r t ================


/////////////////////////////////////////////////////
////////////////////Shell Sort//////////////////////
///////////////////////////////////////////////////
void shellSort( Item *items, int &arrSize, int orderItem, int orderMethod ) {
	Item temp;
	for ( int gap = arrSize/2; gap > 0; gap /= 2 ) {
		for ( int i = gap; i < arrSize; i += 1 ) {
			temp = items[i];
			int j;
			//ASC			
			if( orderItem == 1 && orderMethod == 1 ){
				for ( j = i; j >= gap &&  items[j-gap].name > temp.name; j -= gap ) {
					items[j] = items[j - gap];
				}
			} else if( orderItem == 2 && orderMethod == 1 ){
				for ( j = i; j >= gap &&  items[j-gap].price > temp.price; j -= gap ) {
					items[j] = items[j - gap];
				}
			} 
			//DESC
			else if( orderItem == 1 && orderMethod == 2 ) {  
				for ( j = i; j >= gap &&  items[j-gap].name < temp.name; j -= gap ) {
					items[j] = items[j - gap];
				}
			} else if( orderItem == 2 && orderMethod == 2 ) {
				for ( j = i; j >= gap &&  items[j-gap].price < temp.price; j -= gap ) {
					items[j] = items[j - gap];
				}
			} 
			items[j] = temp;
		}
	}
} 

/////////////////////////////////////////////////////
/////////////////////Quick Sort/////////////////////
///////////////////////////////////////////////////
void swap(Item *a, Item *b) {
	Item t = *a;
	*a = *b; *b = t;
}

int partition (Item *arr, int low, int high) {
	Item pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++) {
		if (arr[j]._id < pivot._id)	{	
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
	
void quickSort(Item *arr, int low, int high) {
	if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
//Free Posttest, Jadi yang dimasukkan cuma 2.
/////////////////////////////////////////////////////
/////////////////////Merge Sort/////////////////////
///////////////////////////////////////////////////
//void mergeSort(Item *arr, int l, int m, int r) {
//	int i, j, k;
//	int n1 = m - l + 1;
//	int n2 = r - m;
//	
//	Hewan L[n1], R[n2];
//		
//	for (i = 0; i < n1; i++) L[i] = arr[l + i];
//	for (j = 0; j < n2; j++) R[j] = arr[m + 1+ j];
//	
//	
//	i = 0; 
//	j = 0; 
//	k = l; 
//	while (i < n1 && j < n2) {
//		if (L[i].price <= R[j].price) {
//			arr[k] = L[i];
//			i++;
//		}
//		else {
//			arr[k] = R[j];
//			j++;
//		}
//		k++;
//	}
//	
//	while (i < n1) {
//		arr[k] = L[i];
//		i++;
//		k++;
//	}
//	while (j < n2) {
//		arr[k] = R[j];
//		j++;
//		k++;
//	}
//}
//
//void mergeSortDesc(Hewan *arr, int l, int r) {
//	if (l < r) {
//		int m = l+(r-l)/2;
//		mergeSortDesc(arr, l, m);
//		mergeSortDesc(arr, m+1, r);
//		mergeDesc(arr, l, m, r);
//	}
//}
/////////////////////////////////////////////////////




//================ S e a r c h ================

/////////////////////////////////////////////////////
/////////////////Fibonacci Search///////////////////
///////////////////////////////////////////////////


int fibMonaccianSearch(Item *arr, int x, int n) {
	int fibMMm2 = 0;
	int fibMMm1 = 1;
	int fibM = fibMMm2 + fibMMm1;
	while (fibM < n) {
		fibMMm2 = fibMMm1;
		fibMMm1 = fibM;
		fibM = fibMMm2 + fibMMm1;
	}
	
	int offset = -1;
	
	while (fibM > 1) {
		int i = min(offset+fibMMm2, n-1);
		if (arr[i]._id < x) {
			fibM = fibMMm1;
			fibMMm1 = fibMMm2;
			fibMMm2 = fibM - fibMMm1;
			offset = i;
		} else if (arr[i]._id > x) {
			fibM = fibMMm2;
			fibMMm1 = fibMMm1 - fibMMm2;
			fibMMm2 = fibM - fibMMm1;
		} else return i;
	
	}
	if ( fibMMm1 && arr[offset+1]._id==x ) return offset+1;
	
	return -1;
}

/////////////////////////////////////////////////////
///////////////////Jump Search//////////////////////
///////////////////////////////////////////////////

int jumpSearch(Item *arr, int x, int n) {
	int step = sqrt(n);
	int prev = 0;
	while (arr[min(step, n)-1]._id < x) {
		prev = step;
		step += sqrt(n);
	if (prev >= n) return -1;
	}
	while (arr[prev]._id < x) {
		prev++;
		if (prev == min(step, n))
		return -1;
	}
	if (arr[prev]._id == x) return prev;
	return -1;
}
