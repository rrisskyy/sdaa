
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>


using namespace std;


struct Keranjang {
	string selectedGame;
};

struct Account {
	string _id, userName, nama, pass, email;
	string isiKeranjang[100];
	int jumlahKeranjang;
};
struct Node_1 {
	struct Account data;
	struct Node_1 *next;	
	struct Node_1 *prev;	
};

Node_1 *head = NULL, *tail = NULL, *del;

struct Game{
	string ID, namaGame, tanggalRilis;
	int rating, stok, harga;
};


//ini array sementara untuk nyimpan data gamenya, jadi ini nanti di convert dari array ke linked list
Game games[100];


struct Node_2 {
	struct Game data;
	struct Node_2 *next;
	struct Node_2 *prev;
};

Node_2 *TOP = NULL, *END = NULL, *del_2;

struct History {
	string ID, nama, tanggalBeli;
	int totalHarga;
};

struct Node_3 {
	struct History data;
	struct Node_2 *next;
	struct Node_2 *prev;
};

Node_3 *FRONT = NULL, *del_3;

int accountCount = 0;
int gameCount = 0;




void hubungiAdmin();
void csvToList(Node_2 **TOP, Node_2 **END, int &gameCount);
void convertArrToList(Node_2 **TOP, Game games);

void auth(struct Node_1 *head, string userName, string pass);
void menuLogin();
void menuUser(string userName, string pass);
void menuAdmin();

void dataGame();
void dataUser();
void dataHistory();

void lihatDataUser(Node_1 *head);
void *hapusDataUser(Node_1 *head, Node_1 *tail, string selectedID);
void ubahDataUser( Node_1 *head, string selectedID );

void lihatDataGame(Node_2 *TOP);
void lihatDataSatuGame( Node_2 *TOP, string SelectedID );
void addDataGamefirst(Node_2 **TOP, Node_2 **END, int &gameCount);
void ubahDataGame(Node_2 *TOP, string SelectedID);
Node_2 *hapusDataGame(Node_2 *TOP, Node_2 *END, string SelectedID);

//user
void lihatKeranjang(struct Node_1 *head, Node_2 *TOP, string userName);
void tambahKeranjang(Node_1 *head, Node_2 *TOP, string userName);


int main() {
	//masukkan data csv ke linked list
	csvToList(&TOP, &END, gameCount);

	//login 
	menuLogin();
}

void csvToList(Node_2 **TOP, Node_2 **END, int &gameCount) {
	
	Node_2 *newNode;
	
	ifstream input("game.csv");
	string line, text;
	int i;
	string arr[60];
	while(getline(input, line)){
		std::stringstream ss(line);
		while(getline(ss, text, ',')){
			arr[i] = text;
			i++;
		}
		gameCount++;
	}
	for ( i = 0; i<gameCount; i++ ) {
		//karena ini ada 6 kolom, maka dikali 6, jadi ketemu lagi di kolom yg sama di kelipatan 6
		games[i].ID = arr[0+i*6];
		games[i].namaGame = arr[1+i*6];
		games[i].tanggalRilis = arr[2+i*6];
		games[i].rating = stoi(arr[3+i*6]);
		games[i].stok = stoi(arr[4+i*6]);
		games[i].harga = stoll(arr[5+i*6]);
	} 
	for (int i = 0; i <gameCount; i++){
		convertArrToList(TOP, games[i]);
	}
		
	
}

	
//fungsi ini untuk ngubah array awal jadi list.	
void convertArrToList(Node_2 **TOP, Game games) {
	Node_2 *temp = new Node_2;
	Node_2 *ptr;
	temp->data.ID = games.ID;
	temp->data.namaGame = games.namaGame;
	temp->data.tanggalRilis = games.tanggalRilis;
	temp->data.rating = games.rating;
	temp->data.stok = games.stok;
	temp->data.harga = games.harga;
	
	temp->data.stok = games.stok;
	temp->next = NULL;

	if (*TOP == NULL) *TOP = temp;
	else {
		ptr = *TOP;
		while (ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
}



//verifikasi username akun user baru untuk bagian pendaftaran
string verifikasi(Node_1 *head, string userName) {
	if(head == NULL && userName == "admin") {
		userName = "";
		cout<<"Mohon maaf, \nUsername sudah terdaftar, Silahkan menggunakan Username yang lain!.\n";
	} 
	while ( head != NULL ) {
		if(userName == head->data.userName || userName == "admin") {
			userName = "";
			cout<<"Mohon maaf, \nUsername sudah terdaftar, Silahkan menggunakan Username yang lain!.\n";
			break;
		}
		head = head->next;
	}
	
	return userName;
}

// fungsi untuk mendaftarkan user baru
void addUser(Node_1 **head, Node_1 **tail, int &accountCount) {
	string userName, pass, nama, email;
	Node_1 *newNode = new Node_1();
	newNode->data._id = "USER"+to_string(accountCount+1);
	while (userName == "") {//tidak boleh kosong
		cout<<"\n\nMasukkan Username	:  ";fflush(stdin);getline(cin, userName);	
		//mengecek ketersediaan username
		userName = verifikasi(*head, userName);
		newNode->data.userName = userName;
	}
	while (pass == "") {//tidak boleh kosong
		cout<<"Masukkan Password	:  ";fflush(stdin);getline(cin, pass);		
		newNode->data.pass = pass;
	}
	while (nama == "") {//tidak boleh kosong
		cout<<"Masukkan Nama		:  ";fflush(stdin);getline(cin, nama);		
		newNode->data.nama = nama;
	}
	
	while (email == "") {//tidak boleh kosong
		cout<<"Masukkan Email		:  ";fflush(stdin);getline(cin, email);		
		newNode->data.email = email;
	}
	newNode->next = NULL;
	accountCount++;
	if(*head == NULL) {//kalau linked list kosong
		*head = newNode;
		*tail = newNode;
	} else {//kalau linked list sudah terisi
		newNode->prev = *tail;
		newNode->next = NULL;
		(*tail)->next = newNode;
		*tail = newNode;
	}
}


void menuLogin() {
	string userName, pass;
	string pil;
	do {
		system("cls");
		
		cout<<"\n\n\n=========================================================\n";
		cout<<"=========================TOKO GAME=======================";
		cout<<"\n=========================================================\n\n\n\n\n";
		cout<<"1. Login\n";
		cout<<"2. Daftar\n";
		cout<<"\n\n\n0. Keluar\n";
		
		cout<<"\nPilih Menu >> ";pil = getch();
		if(pil == "1"){
			cout<<"\n\nMasukkan Username 	:  ";cin>>userName;	
			cout<<"Masukkan Password	:  ";cin>>pass;
			auth(head, userName, pass);
			//kalau salah!
//			cout<<"\n\n\nPassword anda salah!!!\n\n\n"; 	
			continue;
		} else if (pil == "2") {
			addUser(&head, &tail, accountCount);
			continue;
		} else {
			continue;
		}
	} while (pil != "0");
		
}
//menggunakan parameter username untuk mengetahui siapa yg login
void menuUser(string userName) {
	string pil;
	system("cls");
	do{
		string pil;
		cout<<"\n\n==================== HAI " << userName << " ==================\n\n";
		cout<<"1. Lihat Daftar Game"<<endl;
		cout<<"2. Cari Daftar Game"<<endl;
		cout<<"3. Lihat Keranjang"<<endl;
		cout<<"4. Tambah Barang Ke Keranjang"<<endl;
		cout<<"5. Hapus Barang Di Keranjang"<<endl;
		cout<<"6. Checkout"<<endl;
		cout<<"7. Hubungi Admin"<<endl;
		cout<<"8. Log Out"<<endl;
		cout<<"\nPilih Menu >> ";pil = getch();
		if (pil == "1") {
			lihatDataGame(TOP);
		} else if (pil == "2") {
			
		} else if (pil == "3") {
			lihatKeranjang(head, TOP, userName);
		} else if (pil == "4") {
			tambahKeranjang(head, TOP, userName);
		} else if (pil == "5") {
			
		} else if (pil == "6") {
				
		} else if (pil == "7") {
			hubungiAdmin();
		} else if (pil == "8") {
			menuLogin();
		} else {
			continue;
		}
	} while(pil != "8");
		
}
void menuAdmin() {
	string pil;
	do{
		system("cls");
		cout<<"\n\n==================== HAI ADMIN ==================\n\n";
		cout<<"1. Pembayaran"<<endl;
		cout<<"2. Data Game"<<endl;
		cout<<"3. Data User"<<endl;
		cout<<"4. Data History"<<endl;
		cout<<"5. Log Out"<<endl;
		cout<<"\nPilih Menu >> ";pil = getch();
		
		if (pil ==  "1") {
			//pembayaran();
		} else if (pil ==  "2") {
			dataGame();
		} else if (pil ==  "3") {
			dataUser();
		} else if (pil ==  "4") {
			dataHistory();
		} else if (pil ==  "5") {
			menuLogin();
		} else {
			continue;
		}
	} while (pil != "5");
		
		
		
}
void dataGame() {
	string pil, SelectedID;
	do{
		cout<<"\n\n==================== DATA GAME ==================\n\n";
		cout<<"1. Lihat Data Game"<<endl;
		cout<<"2. Tambah Data Game"<<endl;
		cout<<"3. Ubah Data Game"<<endl;
		cout<<"4. Hapus Data Game"<<endl;
		cout<<"5. Sortir Data Game"<<endl;
		cout<<"6. Cari Data Game"<<endl;
		cout<<"7. Kembali"<<endl;
		cout<<"\nPilih Menu >> ";pil = getch();
		if (pil ==  "1") {
			lihatDataGame(TOP);
		} else if (pil ==  "2") {
			addDataGamefirst(&TOP, &END, gameCount);
		} else if (pil ==  "3") {
			lihatDataGame(TOP);
			cout<<"\n\n Masukkan ID game yang ingin anda ubah:   ";
			cin>>SelectedID;
			ubahDataGame(TOP, SelectedID);	
		} else if (pil ==  "4") {
			lihatDataGame(TOP);
			cout<<"\n\n Masukkan ID game yang ingin anda hapus:   ";
			cin>>SelectedID;
			TOP = hapusDataGame(TOP, END, SelectedID);
		} else if (pil ==  "5") {
			
		} else if (pil ==  "6") {
		
		} else if (pil ==  "7") {
			
		} else {
			continue;
		}
	} while(pil != "7");
		
}
void dataUser() {
	string pil, selectedID;
	do{
		cout<<"\n\n==================== DATA USER ==================\n\n";
		cout<<"1. Lihat Data User"<<endl;
		cout<<"2. Ubah Data User"<<endl;
		cout<<"3. Hapus Data User"<<endl;
		cout<<"4. Kembali"<<endl;
		cout<<"\nPilih Menu >> ";pil = getch();
		if (pil ==  "1") {
			lihatDataUser(head);
		} else if (pil ==  "2") {
			lihatDataUser(head);
			cout<<"Masukkan ID yang ingin anda ubah :  ";
			cin>>selectedID;
			ubahDataUser(head, selectedID);		
		} else if (pil ==  "3") {
			lihatDataUser(head);
			cout<<"\n\n Masukkan ID yang ingin anda hapus:   ";
			cin>>selectedID;
			hapusDataUser(head, tail, selectedID);
		} else if (pil ==  "4") {
			
		} else {
			continue;
		}
	} while(pil != "4");		
}
void dataHistory() {
	string pil;
	do{
		cout<<"\n\n==================== DATA HISTORY ==================\n\n";
		cout<<"1. Lihat History Penjualan"<<endl;
		cout<<"2. Hapus History Penjualan"<<endl;
		cout<<"3. Kembali";
		cout<<"\nPilih Menu >> ";pil = getch();
		if (pil ==  "1") {
			
		} else if (pil ==  "2") {
			
		} else if (pil ==  "3") {
			
		} else {
			continue;
		}
	} while(pil != "3");
		
}

void auth(struct Node_1 *head, string userName, string pass) {
	if(userName == "admin" and pass == "admin")	{
		menuAdmin();
	} else {
		if(head == NULL) {
			cout<<"\n\n\nUser Tidak Ada!\n\n\n"; 	
		}
		while (head != NULL) {	
			if (head->data.userName == userName && head->data.pass == pass) {
				menuUser(userName);
			}
			head = head->next;
		}
	}
	
}

void lihatDataUser(struct Node_1 *head){
	if (head == NULL) {
		cout << "\nData Masih Kosong !!\n\n ";
		return;
	} else {
		cout << "\nData: " << "\n\n";
		while ( head != NULL ) {
			cout << "ID		: " << head->data._id << endl;
			cout << "Nama		: " << head->data.nama << endl;
			cout << "Username	: " << head->data.userName << endl;
			cout << "Passowrd	: " << head->data.pass << endl;
			cout << "Email		: " << head->data.email << "\n\n";
			head = head->next;
		}
	}
}

void lihatDataSatuUser( Node_1 *head, string selectedID ) {
	if (head == NULL) {
		cout << "\nData Masih Kosong !!\n\n ";
		return;
	} else {
		while ( head != NULL ) {
			if (head->data._id == selectedID) {
				cout<< "\n\n\nBerikut Adalah Data User yang ingin anda ubah: \n";
				cout<< "\nID		: "<<head->data._id << "\n";
				cout<< "Nama		: "<<head->data.nama << "\n";
				cout<< "Username	: "<<head->data.userName<<"\n";
				cout<< "Password	: "<<head->data.pass<< "\n";
			}
			head = head->next;
		}
	}
}

void ubahDataUser( Node_1 *head, string selectedID ) {
    Node_1 *nodeBaru = new Node_1();
    
	nodeBaru = head;
	while (nodeBaru != NULL) {
		char pil;
		bool repeat = true;
        if (nodeBaru->data._id == selectedID) {
        	do {
        		system("cls");
        		lihatDataSatuUser(head, selectedID);
        		cout << "\n\n+==============================+" << endl;
	        	cout << "1. Ubah Nama"<<endl;
	        	cout << "2. Ubah Password"<<endl;
	        	cout << "3. Ubah Email"<<endl;
	        	cout << "\nPilih Menu: ";pil = getch();
	        	if(pil == '1') {
	        		cout<<"\n\nMasukkan Nama Baru  :  " ;	fflush(stdin);getline(cin,nodeBaru->data.nama);	
	        		repeat = false;
	        		cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
				} else if (pil == '2') {
					cout<<"\n\nMasukkan Password Baru :  "; 	cin>>nodeBaru->data.pass;	
					repeat = false;
					cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
				} else if (pil == '3') {
					cout<<"\n\nMasukkan Email Baru :  "; 	cin>>nodeBaru->data.email;
					repeat = false;	
					cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
				} else {
					continue;
				}
			} while(repeat);
        }        
		nodeBaru = nodeBaru -> next;
	}
	
}




void *hapusDataUser(Node_1 *head, Node_1 *tail, string selectedID) {
	
	Node_1 *temp;
	if (head == NULL) {
		cout << "List Kosong" << endl;
	}
	
	//	di logika didalam while itu kita tidak bisa menghapus elemen pertama, karena 
	//	dari awal itu sudah mengecek data ke 2, jadi bisa diakali dengan menambah 1 kondisi
	//	dimana headnya itu sama dengan pil, kalau sama langsung hapus
	if (head->data._id == selectedID) {
		del = head;
		head = head->next;
		head->prev = NULL;
		delete del;
    }
	
	temp = head; 
    while (temp -> next != NULL) {
        if (temp->next->data._id == selectedID) {
            del = temp -> next;
            temp->next = del->next;
            free(del);
        }
        temp = temp->next;
    }
    return head;
}



void lihatDataGame(Node_2 *TOP){
	if (TOP == NULL) {
		cout << "\nData Masih Kosong !! " << endl << endl;
		return;
	} else {
		cout << "\nData Game : " << endl;
		while ( TOP != NULL ) {
			cout << "\n\nID		: " << TOP->data.ID << endl;
			cout << "Nama Game  	: " << TOP->data.namaGame << endl;
			cout << "Tanggal Rilis	: " << TOP->data.tanggalRilis << endl;
			cout << "Rating		: " << TOP->data.rating << endl;
			cout << "Stok		: " << TOP->data.stok << endl;
			cout << "Harga		: " << TOP->data.harga << endl;
			TOP = TOP->next;
		}
	}
}

void lihatDataSatuGame( Node_2 *TOP, string selectedID ) {
	if (TOP == NULL) {
		cout << "\nData Masih Kosong !!\n\n ";
		return;
	} else {
		while ( TOP != NULL ) {
			if (TOP->data.ID == selectedID) {
				cout << "\n\nID		: " << TOP->data.ID << endl;
				cout << "Nama Game  	: " << TOP->data.namaGame << endl;
				cout << "Tanggal Rilis	: " << TOP->data.tanggalRilis << endl;
				cout << "Rating		: " << TOP->data.rating << endl;
				cout << "Stok		: " << TOP->data.stok << endl;
				cout << "Harga		: " << TOP->data.harga << endl;
			}
			TOP = TOP->next;
		}
	}
}

// fungsi untuk mendaftarkan game baru
void addDataGamefirst(Node_2 **TOP, Node_2 **END, int &gameCount) {
	string ID, namaGame, tanggalRilis;
	int rating = 0;
	int stok = 0;
	int harga = 0;
	Node_2 *newGame= new Node_2();
	
	while (ID == "") {//tidak boleh kosong
		cout<<"\n\nMasukkan ID Game	:  ";fflush(stdin);getline(cin, ID);	
		newGame->data.ID = ID;
	}
	while (namaGame == "") {//tidak boleh kosong
		cout<<"\nMasukkan Nama Game	:  ";fflush(stdin);getline(cin, namaGame);	
		newGame->data.namaGame = namaGame;
	}
	while ( tanggalRilis== "") {//tidak boleh kosong
		cout<<"Masukkan Tanggal Rilis	:  ";fflush(stdin);getline(cin, tanggalRilis);		
		newGame->data.tanggalRilis= tanggalRilis;
	}
	while (rating == 0) {//tidak boleh kosong
		cout << "Masukan Rating  : "; cin >> rating;
		newGame->data.rating = rating;	
		
	}
	while (stok == 0) {//tidak boleh kosong
		cout << "Masukan Stok  : "; cin >> stok;
		newGame->data.stok = stok;		
		
	}
	while (harga == 0) {//tidak boleh kosong
		cout << "Masukan Harga : "; cin >> harga;
		newGame->data.harga = harga;	
		
	}

	newGame->next = *TOP;
	accountCount++;
	if(*TOP == NULL) {//kalau linked list kosong
		*TOP = newGame;
		*END = newGame;
	} else {//kalau linked list sudah terisi
		newGame->prev = NULL;
		newGame->next = *TOP;
		(*TOP)->prev = newGame;
		*TOP = newGame;
	}
	
}

void ubahDataGame(Node_2 *TOP, string selectedID) {
	Node_2 *nodeBaru = new Node_2();
    
	nodeBaru = TOP;
	while (nodeBaru != NULL) {
		char pil;
		bool repeat = true;
        if (nodeBaru->data.ID == selectedID) {
        	do {
        		system("cls");
        		lihatDataSatuGame(TOP, selectedID);
        		cout << "\n\n+==============================+" << endl;
	        	cout << "1. Ubah Nama"<<endl;
	        	cout << "2. Ubah Tanggal Rilis"<<endl;
	        	cout << "3. Ubah Rating"<<endl;
	        	cout << "4. Ubah Stok"<<endl;
	        	cout << "5. Ubah Harga"<<endl;
	        	cout << "\nPilih Menu: ";pil = getch();
	        	if(pil == '1') { 
	        		cout<<"\n\nMasukkan Nama Game Baru  :  " ;	fflush(stdin);getline(cin,nodeBaru->data.namaGame);	
	        		repeat = false;
	        		cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
				} else if (pil == '2') {
					cout<<"\n\nMasukkan Tanggal Rilis Baru :  "; fflush(stdin);getline(cin,nodeBaru->data.tanggalRilis);	
					repeat = false;
					cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
				} else if (pil == '3') {
					cout<<"\n\nMasukkan Rating Baru :  "; 	cin>>nodeBaru->data.rating;
					repeat = false;
					cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
				} else if (pil == '4') {
					cout<<"\n\nMasukkan Stok Baru :  "; 	cin>>nodeBaru->data.stok;
					repeat = false;
					cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
				} else if (pil == '5') {
					cout<<"\n\nMasukkan Harga Baru :  "; 	cin>>nodeBaru->data.harga;
					repeat = false;
					cout << "\n\nBerhasil!!!\n\n\n\n" << endl;
				} else {
					continue;
				}
			} while(repeat);
        }        
		nodeBaru = nodeBaru -> next;
	}
}

//Fungsi Hapus game bertipe data struct jadi ini kembaliannya nanti berupa Struct.
Node_2 *hapusDataGame(Node_2 *TOP, Node_2 *END, string SelectedID){
	//Buat Struct temp untuk perulangan nanti
	Node_2 *temp;
	if (TOP == NULL) {
		cout << "Game Tidak ada!!" << endl;
 	}
	
	//	di logika didalam while itu kita tidak bisa menghapus elemen pertama, karena 
	//	dari awal itu sudah mengecek data ke 2, jadi bisa diakali dengan menambah 1 kondisi
	//	dimana headnya itu sama dengan pil, kalau sama langsung hapus
	//  trus setelah dihapus, di kembalikan structnya. (yang sudah dihapus elemennya)
	if (TOP->data.ID == SelectedID) {		
		//karena ini Posisi TOP nya adalah elemen yang mau dihapus, jadi langsung arahkan saja TOPnya ke alamat selanjutnya
        TOP = TOP->next;
        TOP->prev = NULL;
        //free kita menghemat memory karena del_2 sudah tidak terpakai, fungsinya sama seperti delete
        free(del_2);  
        return TOP;
    }
    //masukkan nilai dari TOP ke temp
    temp = TOP;
    //Ulangi sampai next dari temp itu NULL
    while (temp -> next != NULL) {
    	// kalau dalam perulangan itu alamat selanjutnya memiliki data.ID yang mau kita hapus
        if (temp->next->data.ID == SelectedID) {
        	//del_2 nya itu menyimpan dari alamat next variable temp
        	//misalnya saat ini berada di alamat pertama, maka del_2 menyimpan alamat kedua:
            del_2 = temp -> next;
            //setelah itu alamat next dari temp itu menyimpan alamat next dari variable del
            //misalnya saat ini berada di alamat pertama, maka yang seharusnya temp->next itu menyimpan alamat kedua, jadi menyimpan alamat ketiga
            temp->next = del_2->next;
            //free kita menghemat memory karena del_2 sudah tidak terpakai, fungsinya sama seperti delete
            free(del_2);
            return TOP;
        }
        temp = temp->next;
    }
    return TOP;
}

//void sortirDataGame

//void cariDataGame


void lihatKeranjang( Node_1 *head,  Node_2 *TOP, string userName) {
	cout<<"\n";
	//buat variabel temp yang nilainya sampa dengan TOP karena kita akan menggunakan variabel TOP
	//ketika variabel TOP digunakan, nilainya akan berubah ubah sesuai alur dari linked list
	//jadi yang tercetak itu elemen list yang berada di alamat selanjutnya, 
	//karena elemen list yang terletak sebelum TOP tidak akan terbaca,
	//jadi triknya, buat variabel temp, trus kalau elemen sudah ketemu, kita kembalikan TOP tadi ke semula (nilai semulanya disimpan di temp)
	//jadi karena TOP tadi kembali ke alamat awal, jadi tidak masalah dimanapun alamat yang mau dicetak
	Node_2 *temp;
	temp = TOP;
	while (head != NULL) {	
		//kita memilih ini user mana yang punya keranjangnya
		if (head->data.userName == userName) {
			//kita ngecek keranjangnya satu per satu pakai perulangan
			for(int i = 0; i < head->data.jumlahKeranjang; i++){
				//kita lakukan perulangan selama TOP nya itu tidak NULL alias sampai data masih ada
				while(TOP != NULL) {
					//disini kita ngecek, apakah data yang ada di isi keranjang index ke-i itu sama dengan data game yang berada di top
					//kalau sama, kita print data tersebut, trus karna kita menggunakan TOP untuk looping, kita kembalikan alamatnya ke semula
					if(head->data.isiKeranjang[i] == TOP->data.ID) {
						lihatDataSatuGame(TOP, TOP->data.ID);
						TOP = temp;
						//ini kita break untuk menghemat memory, karena kalau sudah ketemu, data selanjutnya itu ga mungkin ada yg sama
						break;
					} else {
						//kalau masih belum ketemu kita next
						TOP = TOP->next;		
					}
				}
			}
		//ini kita break untuk menghemat memory, karena kalau sudah ketemu, data selanjutnya itu ga mungkin ada yg sama			
		break;
		} else {
			head = head->next;	
		}
		
	}
}

void tambahKeranjang( Node_1 *head, Node_2 *TOP, string userName ) {
	
	while (head != NULL) {
		//kita memilih ini user mana yang punya keranjangnya	
		if (head->data.userName == userName) {
			string selectedID;
			//print dulu data gamenya baru suruh user masukkan ke keranjang
			lihatDataGame(TOP);
			cout<<"\n\nMasukkan ID Game >>>  ";
			cin>>selectedID;	
			//nah kita masukkan data inputan tadi kedalam array keranjang
			head->data.isiKeranjang[head->data.jumlahKeranjang] = selectedID;
			//karna isi keranjangnya bertambah, kita tambah juga ini
			head->data.jumlahKeranjang++;			
			break;
		} else {
			head = head->next;	
		}
		
	}
}



void checkout() {
	//cout << "\n\n Apakah Anda Yakin Membeli Game Ini?"
		//while (head != NULL) {
		//kita memilih ini user mana yang punya keranjangnya	
		//if (head->data.userName == userName) {
			//string selectedID;
			//print dulu data gamenya baru suruh user masukkan ke keranjang
			//lihatKeranjang(head, TOP, userName);
			//cout<<"\n\nYa/Tidak >>>  ";	
			//kita masukkan data dari array keranjang ke data history
			//FRONT->data->data.isiKeranjang[head->data.jumlahKeranjang] = selectedID;
			//karna isi keranjangnya bertambah, kita tambah juga ini
			//head->data.jumlahKeranjang++;			
			//break;
		//} else {
			//kalau masih belum ketemu kita next
			//head = head->next;	
		}
		



void lihatHistory(){
	//aku gapaham ubah data array ke struct
}

//taroh paling bawah aja ga penting	
void hubungiAdmin() {
	system("cls");
	cout<<"\n\n\n\n\n\n";
	cout<<"Admin 1: 2009106xxx   ||   +62 8xx xxxx xxxx   ||   Riska Nurliyanti\n";
	cout<<"Admin 2: 2009106xxx   ||   +62 8xx xxxx xxxx   ||   Muhammad Daffa Putra Mahardika\n";
	cout<<"Admin 3: 2009106050   ||   +62 821 5831 7722   ||   Risky Kurniawan\n\n\n";
}


