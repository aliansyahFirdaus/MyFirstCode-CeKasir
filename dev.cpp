#include <iostream>
#include <ctime>
#include <sstream>
#include <string>


using namespace std;


//Edit
int diskon = 20; //%
int syaratDiskon = 700000;
float totalPpn = 0.005;


//Prototype
int hitungDiskon(int belanja);
int hitungPpn(int potongan);
int hitungDpp(int potongan, int ppn);
void infoPajak(int ppn, int dpp);
int hitungBayar(int potongan, int ppn);
int hitungKembalian(int bayar);
string formatAngka(int value);
void header();
void batas();
void footer();


//Program Kasir Main
int main(){


	int totalBelanja, totalPotongan, totalBayar, totalTunai, totalKembalian, totalPpn, totalDpp;

	header();
	cout << "RINCIAN BELANJA: " << endl << endl;
	cout << "Total Belanja: Rp. ";
	cin >> totalBelanja;

	totalPotongan = hitungDiskon(totalBelanja);
 	totalPpn = hitungPpn(totalPotongan);
 	totalDpp = hitungDpp(totalPotongan, totalPpn);
 	totalBayar = hitungBayar(totalPotongan, totalPpn);

	cout << "Harga Jual: Rp. " << formatAngka(totalPotongan) << endl;
	infoPajak(totalPpn, totalDpp); 

	batas();

	cout << "RINCIAN PEMBAYARAN: " << endl << endl;
	cout << "Total Pembayaran: Rp. " << formatAngka(totalBayar) << " (Termasuk PPN)" << endl;

	totalKembalian = hitungKembalian(totalBayar);

	footer();

	cin.get();
	return 0;


 }


//Fungsi
int hitungDiskon(int belanja){


	int totalDiskon, totalPotongan;
	

	// menghitung diskon
	if (belanja >= syaratDiskon){
		totalDiskon = belanja * diskon / 100;
		cout << "*Disc 10%: -Rp. " << formatAngka(totalDiskon) << endl;
	} else {
		totalDiskon = 0;
	}

	// menghitung potongan
 	totalPotongan = belanja - totalDiskon;

	return totalPotongan;


 }	
int hitungPpn(int potongan){


	int ppn, dpp;

	// menghitung ppn
 	ppn = totalPpn * potongan;

	return ppn;


  } 
int hitungDpp(int potongan, int ppn){


	int dpp;

	// menghitung dpp
	dpp = potongan - ppn;

	return dpp;


 }
void infoPajak(int ppn, int dpp){


	cout << "PPN: +Rp. " << formatAngka(ppn) << "   ||" << "   DPP: Rp. " << formatAngka(dpp);


 }
int hitungBayar (int potongan, int ppn){


	int totalBayar;

	//  menghitung total bayar
	totalBayar =  potongan + ppn;

	return totalBayar;


 }
int hitungKembalian(int bayar){


	int uangKembali, totalTunai;


	while(true) {

	    cout << "Tunai: Rp.";
		cin >> totalTunai;
		cout << endl;

		if (totalTunai >= bayar){

			break;

		} else {
			cout << "Uang tidak cukup/Salah Input" << endl;
		}

	}

	// menghitung kembalian
	uangKembali = totalTunai - bayar;

	if (uangKembali != 0){

		cout << "Total Kembalian: Rp. " << formatAngka(uangKembali);

	} 

	return uangKembali;


 }
string formatAngka(int value) {


 string perantara = ".";
 stringstream ss; ss << value; 
 string output = ss.str();

 int inspost = output.length() - 3;
 	while (inspost > 0) {
  		output.insert(inspost, perantara);
  		inspost -= 3; }

	return output;


 }


//Properti
void header(){


	// menampilkan waktu
	time_t now = time(0);
   	char* dt = ctime(&now);

   	// menampilkan alamat
   	cout << endl << endl;
   	cout << "Jl. Pangkalan Jati VI, RT.5/RW.5, Cipinang Melayu," << endl;
   	cout << "Kec. Makasar, Kota Jakarta Timur, DKI Jakarta, 13620, Indonesia";
  	batas();
   	cout << endl << "Waktu Pembelanjaan : " << dt;
  	batas();


 }
void batas(){


	cout << endl << endl;
	cout << "======================================";
	cout << endl << endl;


 }
void footer(){


	batas();
	// footer
	cout << "Layanan Konsumen SMS 0856 8227 596" << endl;
	cout << "CALL 1500 270 - KONTAK@ALIANSYAH.CO.ID";

	cout << endl << endl;
	cout << "Terima kasih telah mengunjungi toko kami! See you on the next order!" << endl << endl << endl;


 }


/*


update notice!

* Manajemen kode dengan menggunakan reference dan pointer
* Perapihan code karna menggunakan reference
* Sudah mengimplementasikan GIT untuk meyimpan perubahan
* Dan masih akan banyak lagi


*/