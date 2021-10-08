#include <iostream>
#include <string>

using namespace std;	


int main(){
	char pil = 'o';
	int tempInt, tempIndex;
	string temp;
	string name[100] = {"Reel BC Fugu Taru 17+1 Bearings System Left",
	"Reel BC Lizard Lure Killer 7:2:1 Left",
	"Reel Fugu Aojiro (6000) 10 Ball Bearings",
	"Reel Daido Reno (4000) 6 Ball Bearings",
	"Joran Katana Fiber SDA 180cm",
	"Joran Surf Ruas Pendek Length 240",
	"Joran Surf Ruas Pendek Length 270",
	"Joran Surf Ruas Pendek Length 300",
	"Joran Surf Ruas Pendek Length 360",
	"Joran Surf Ruas Pendek Length 450",
	"Sinori 0.50mm",
	"Hard Jump Frog",
	"Soft Frog",
	"Hard Frog Lure",
	"Top One 100m",
	"Ghostline Leader",
	"Sensor 0.35mm",
	"Box Penyimpan Lure Lure 3 slot",
	"Soft Frog Lure",
	"Soft Frog Lure",
	"Soft Frog Lure",
	"Soft Frog Lure",
	"Soft Frog Lure",
	"Reel BC Fugu Taru 17+1 Bearings System Left",
	"Reel Kaizen Oishi (4000) 3 Ball Bearings 5.1:1",
	"Daido Tsunami (4000) 6 Ball Bearings 4.7:1",
	"Reel Daido Zodias (2000) 6 Ball Bearings 4.7:1",
	"Reel Daido Reno (2000) 6 Ball Bearings 4.7:1",
	"Reel Kaizen Haruki (2000) 3 Ball Bearings 5.1:1",
	"Reel Daido Zodias (4000) 6 Ball Bearings 4.7:1",
	"Reel Kaizen Gin (4000) 3 Ball Bearings 5.1:1",
	"Reel Daido Fino Max (250) 5 Ball Bearings 5.2:1",
	"Reel Kaizen Gin (2000) 3 Ball Bearings 5.1:1",
	"Reel Daido Reno (1000) 3 Ball Bearings 5.1:1",
	"Joran BC Daido Tomman 180cm",
	"Mata Pancing Kaizen Akitakitsune",
	"Mata Pancing Kaizen Chinu",
	"Mata Pancing Carbon Charm 1054 1-13",
	"Mata Pancing Carbon Plus 1130L 1-13",
	"Mata Pancing Owner Unagi  1 - 20",
	"Mata Pancing Carbon Mix 1-17",
	"Reel Daido Zodias (6000) 6 Ball Bearings 4.7:1",
	"Joran Kaizen Fiber Python 150cm",
	"Daido Fastlock Snap + Kili-Kili 12pcs",
	"Joran Iroly Beset Spin 180cm",
	"Pioneer Fastlock Snap HS 12pcs"};
	int price[100] = {310000,
	205000,
	150000,
	140000,
	110000,
	70000,
	80000,
	85000,
	100000,
	130000,
	32000,
	50000,
	32000,
	32000,
	20000,
	28000,
	32000,
	23000,
	35000,
	32000,
	27000,
	27000,
	35000,
	310000,
	150000,
	148000,
	125000,
	125000,
	145000,
	148000,
	180000,
	75000,
	160000,
	120000,
	250000,
	8000,
	8000,
	7000,
	7000,
	28000,
	7000,
	162000,
	100000,
	14000,
	100000,
	10000};
	string itemType[100] = {"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Joran",
	"Joran",
	"Joran",
	"Joran",
	"Joran",
	"Joran",
	"Nylon",
	"Lure",
	"Lure",
	"Lure",
	"Nylon",
	"Nylon",
	"Nylon",
	"Lainnya",
	"Lure",
	"Lure",
	"Lure",
	"Lure",
	"Lure",
	"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Reel",
	"Joran",
	"Hook",
	"Hook",
	"Hook",
	"Hook",
	"Hook",
	"Hook",
	"Reel",
	"Joran",
	"Lainnya",
	"Joran",
	"Lainnya"};
	//data versi json bisa dilihat disini https://github.com/rrisskyy/sdaa/blob/main/items.json
	    
	int arrSize = 46;
	while (pil != 0) {
		cout<<"1. Lihat Barang\n"<<endl<<"2. Tambah Barang\n"<<endl<<"3. Ubah Barang\n"<<endl<<"4. Hapus Barang\n"<<endl<<"0. Keluar\n\n"<<endl;
	    cout << "Masukkan Pilihan >>>  ";
	    
		cin>>pil;
		cin.ignore();
		
		if(pil == '1'){
			for (int i = 0; i < arrSize; i++){
				cout << "_id : " << i << " \nName : " <<name[i]<< " \nPrice : " << price[i]<< " \nItem Type : " <<itemType[i]<<"\n\n\n"<<endl;
	    	}
		} else if (pil == '2'){
			
			cout<<"Masukkan nama barang :  ";
			getline (cin,temp);
			name[arrSize] = temp;
			cout<<"Masukkan harga barang :  ";
			cin>>tempInt;
			price[arrSize] = tempInt;
			cin.ignore();
			cout<<"Masukkan jenis barang :  ";
			getline (cin,temp);
			itemType[arrSize] = temp;
			arrSize+=1;
			
		} else if (pil == '3') {
			for (int i = 0; i < arrSize; i++){
				cout << "_id : " << i << " \nName : " <<name[i]<< " \nPrice : " << price[i]<< " \nItem Type : " <<itemType[i]<<"\n\n\n"<<endl;
	    	};
			cout<<"Masukkan _id yang ingin anda ubah :  ";
			cin>>tempIndex;
			cin.ignore();
			cout << "\nYang ingin anda ubah adalah : \n\n_id : " << tempIndex << " \nName : " <<name[tempIndex]<< " \nPrice : " << price[tempIndex]<< " \nItem Type : " <<itemType[tempIndex]<<"\n\n\n"<<endl;
			
			
			cout<<"\n\nMasukkan nama barang :  ";
			getline (cin,temp);
			name[tempIndex] = temp;
			cout<<"Masukkan harga barang :  ";
			cin>>tempInt;
			price[tempIndex] = tempInt;
			cin.ignore();
			cout<<"Masukkan jenis barang :  ";
			getline (cin,temp);
			itemType[tempIndex] = temp;
			
		} else if (pil == '4') {
	    	int j;
			cout<<"Masukkan _id yang ingin anda hapus :  ";
			cin>>tempIndex;
			cout<<"Berhasil!!\n\n\n";
			for (int i = tempIndex; i < arrSize; i++){
				name[i] = name[i + 1];
				price[i] = price[i + 1];
				itemType[i] = itemType[i + 1];
	    	};
	    	arrSize--;
		}
	}
}



