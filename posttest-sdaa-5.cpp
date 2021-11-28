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

struct Node {
	struct Item data;
	struct Node *next;	
};

Item items[100];
int arrSize = 0;

//konversi array & linked list
void convertArr( Node* head, Item *items, int &arrSize );
void insertArr(Node **head, Item items);


void printBarang ( struct Node *head );
void printOneBarang ( Item *items );
void tambahBarang( Node **head, int &arrSize );
void ubahBarang( struct Node *head, int tempIndex );

//Sort
void shellSort( Item *items, int &arrSize, int orderItem, int orderMethod );
void quickSort( Item *arr, int low, int high );
//void mergeSort(Item *arr, int l, int m, int r)


//Search
int fibMonaccianSearch( Item *arr, int x, int n );
int jumpSearch( Item *arr, int x, int n );

int main() {
	Node *head = NULL;

	char pil = 'o';																																																																																																																																																																																																																																																																																																																																																																																					
	int tempInt, tempIndex, jumlah, orderItem, orderMethod, searchItem, searchMethod, res, x;
	string temp, pos;




	while (pil != '0') {
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

		switch(pil) {


		case '1': {
			printBarang(head);
			break;
		}
		case '2': {
			tambahBarang(&head, arrSize);
			break;
		}
		case '3': {
			printBarang(head);
			cout<<"Masukkan ID yang ingin anda ubah :  ";
			cin>>tempIndex;	
			ubahBarang(head, tempIndex);
			break;
		}
		case '4': {
			printBarang(head);
			if(head != NULL) {
				cout<<"\n\n1. Hapus Data di Awal"<<endl;
				cout<<"2. Hapus Data di Akhir"<<endl;
				cout<<"Pilih Menu : ";
				cin>>pos;
				if(pos == "1") {
					head = head->next;
					arrSize--;
				} else if(pos == "2") {
					Node *temp = head;
					while(temp->next->next != NULL){
						temp = temp->next;
					}
					temp->next = NULL;
					arrSize--;
				}
			}
			break;
		}
		case '5': {
		  	ofstream MyFile("item.csv");
		  	MyFile << "_id, name, price, itemType, stok\n";
		  	convertArr(head, &items[0], arrSize);
		    for(int i = 0; i < arrSize; i++) {
		    	MyFile <<items[i]._id<<","<<items[i].name<<","<<items[i].price<<","<<items[i].itemType<<","<<items[i].stok<<"\n";
			}
		  	MyFile.close();
		  	cout<<"Berhasil!!\n\n\n";
		  	break;
		}
		case '6': {
			//Shell Sort
			sort:
				cout<<"1. Sort Berdasarkan Nama"<<endl;
				cout<<"2. Sort Berdasarkan Harga"<<endl;
				cout<<"Silahkan Pilih Menu : ";cin>>orderItem;
				if(orderItem == 1 or orderItem == 2) {
					convertArr(head, &items[0], arrSize);
					cout<<"1. Ascending"<<endl;
					cout<<"2. Descending"<<endl;
					cout<<"Silahkan Pilih Menu : ";cin>>orderMethod;	
					shellSort( &items[0], arrSize, orderItem, orderMethod );	

					head = NULL;		
					for (int i = 0; i < arrSize; i++)
						insertArr(&head, items[i]);
				} else {
					goto sort;
				}
			cout<<"Berhasil!!\n\n\n";
			break;
		}
		case '7': {
			//Karena tidak ada ketentuan minimum, jadi hanya search berdasarkan 1 Kateogri saja
			search:
				cout<<"1. Fibonacci Search"<<endl;
				cout<<"2. Jump Search"<<endl;
				cout<<"Silahkan Pilih Menu : ";cin>>searchMethod;
				if(searchMethod == 1) {
					convertArr(head, &items[0], arrSize);
					cout<<" == Search Berdasarkan ID Barang == "<<endl;
					int high = arrSize-1;
					//Wajib disorting dahulu
 					quickSort(&items[0], 0, high);
					cout<<"Silahkan Masukkan ID yang ingin anda cari : "; cin>>x;
					res = fibMonaccianSearch(&items[0], x, arrSize);
					tempIndex = res+1;
					printOneBarang(&items[res]);

					head = NULL;		
					for (int i = 0; i < arrSize; i++)
						insertArr(&head, items[i]);
				} else if(searchMethod == 2) {
					convertArr(head, &items[0], arrSize);
					cout<<" == Search Berdasarkan ID Barang == "<<endl;
					int high = arrSize-1;
					//Wajib disorting dahulu
 					quickSort(&items[0], 0, high);
					cout<<"Silahkan Masukkan ID yang ingin anda cari : "; cin>>x;
					res = jumpSearch(&items[0], x, arrSize);
					printOneBarang(&items[res]);

					head = NULL;		
					for (int i = 0; i < arrSize; i++)
						insertArr(&head, items[i]);
				} else {
					goto search;
				}
				break;
		}
		}
	}
}

void convertArr( Node* head, Item *items, int &arrSize ) {
	int index = 0;
	Node* curr = head;
	while (curr != NULL) {
		items[index]._id = curr->data._id;
		items[index].name = curr->data.name;
		items[index].price = curr->data.price;
		items[index].itemType = curr->data.itemType;
		items[index].stok = curr->data.stok;
		index++;
		curr = curr->next;
	}
}


void insertArr(Node **head, Item items) {
	Node *temp = new Node;
	Node *ptr;
	temp->data._id = items._id;
	temp->data.name = items.name;
	temp->data.price = items.price;
	temp->data.itemType = items.itemType;
	temp->data.stok = items.stok;
	temp->next = NULL;

	if (*head == NULL) *head = temp;
	else {
		ptr = *head;
		while (ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}


void printBarang( struct Node *head ) {
	if(head == NULL) {
		cout<<"\n\n\nLinked List masih kosong!\n\n\n"; 	
	}
	while (head != NULL) {
		cout<< "ID \t\t: " <<head->data._id<< "\n";
		cout<< "Nama Barang \t: " <<head->data.name << "\n";
		cout<< "Harga Barang \t: "<<head->data.price<<"\n";
		cout<< "Tipe Barang \t: "<<head->data.itemType<< "\n";
		cout<< "Stok Barang \t: "<<head->data.stok<<"\n\n"<<endl;
		head = head->next;
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

void tambahBarang( Node **head, int &arrSize ) {
	string pos;
	if(*head != NULL) {
		cout<<"\n\n1. Tambahkan Data di Awal"<<endl;
		cout<<"2. Tambahkan Data di Akhir"<<endl;
		cout<<"Pilih Menu : ";
		cin>>pos;
	}

	Node *nodeBaru = new Node();

	nodeBaru->data._id = arrSize+=1;
	cout<<"Masukkan nama barang  :  " ;	fflush(stdin);getline(cin,nodeBaru->data.name);
	cout<<"Masukkan harga barang :  "; 	cin>>nodeBaru->data.price;
	cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,nodeBaru->data.itemType);
	cout<<"Masukkan stok barang  :  " ;	cin>> nodeBaru->data.stok;

	cout<<"\n\nBerhasil!!!\nBerhasil Menambahkan : \n";
	cout<< "ID \t\t: " <<nodeBaru->data._id << "\n";
	cout<< "Nama Barang \t: " <<nodeBaru->data.name << "\n";
	cout<< "Harga Barang \t: "<<nodeBaru->data.price<<"\n";
	cout<< "Tipe Barang \t: "<<nodeBaru->data.itemType<< "\n";
	cout<< "Stok Barang \t: "<<nodeBaru->data.stok<<"\n\n"<<endl;
	nodeBaru->next = NULL;
	cin.get();


	if(*head == NULL) {
		*head = nodeBaru;
	} else {
		if (pos == "1"){
			nodeBaru->next = *head;
			*head = nodeBaru;
		} else if (pos == "2"){
			Node *temp = *head;
			while (temp->next != NULL) {
				temp = temp->next;
			}	
			temp->next = nodeBaru;
		} else if (pos != "1" && pos != "2") arrSize--; //karena dari awal sudah ditambah 1, karena gagal menambahkan maka size dikurangi 1.
	}

}

void ubahBarang(struct Node *head, int tempIndex) {
    Node *nodeBaru = new Node();

	nodeBaru = head;
	while (nodeBaru != NULL) {
        if (nodeBaru->data._id == tempIndex) {
            cout<<"\n\nMasukkan nama barang  :  " ;	fflush(stdin);getline(cin,nodeBaru->data.name);
			cout<<"Masukkan harga barang :  "; 	cin>>nodeBaru->data.price;
			cout<<"Masukkan jenis barang :  "; 	fflush(stdin);getline(cin,nodeBaru->data.itemType);
			cout<<"Masukkan stok barang  :  " ;	cin>> nodeBaru->data.stok;         
        }        
		nodeBaru = nodeBaru -> next;
	}
	cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
}

////====================== S o r t ======================


///////////////////////////////////////////////////////
//////////////////////Shell Sort//////////////////////
/////////////////////////////////////////////////////
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

////Free Posttest, Jadi yang dimasukkan cuma 2.
///////////////////////////////////////////////////////
///////////////////////Quick Sort/////////////////////
/////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////
///////////////////////Merge Sort/////////////////////
/////////////////////////////////////////////////////
////void mergeSort(Item *arr, int l, int m, int r) {
////	int i, j, k;
////	int n1 = m - l + 1;
////	int n2 = r - m;
////	
////	Hewan L[n1], R[n2];
////		
////	for (i = 0; i < n1; i++) L[i] = arr[l + i];
////	for (j = 0; j < n2; j++) R[j] = arr[m + 1+ j];
////	
////	
////	i = 0; 
////	j = 0; 
////	k = l; 
////	while (i < n1 && j < n2) {
////		if (L[i].price <= R[j].price) {
////			arr[k] = L[i];
////			i++;
////		}
////		else {
////			arr[k] = R[j];
////			j++;
////		}
////		k++;
////	}
////	
////	while (i < n1) {
////		arr[k] = L[i];
////		i++;
////		k++;
////	}
////	while (j < n2) {
////		arr[k] = R[j];
////		j++;
////		k++;
////	}
////}
////
////void mergeSortDesc(Hewan *arr, int l, int r) {
////	if (l < r) {
////		int m = l+(r-l)/2;
////		mergeSortDesc(arr, l, m);
////		mergeSortDesc(arr, m+1, r);
////		mergeDesc(arr, l, m, r);
////	}
////}
///////////////////////////////////////////////////////




////==================== S e a r c h ====================

///////////////////////////////////////////////////////
///////////////////Fibonacci Search///////////////////
/////////////////////////////////////////////////////


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

///////////////////////////////////////////////////////
/////////////////////Jump Search//////////////////////
/////////////////////////////////////////////////////

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
