#include <iostream>
#include <vector>
using namespace std;

class pengarang;
class penerbit {
public:
	string nama;
	vector <pengarang*> daftar_pengarang;
	penerbit(string pNama) : nama(pNama) {
		cout << "penerbit \"" << nama << "\" ada \n";
	}
	~penerbit() {
		cout << "penerbit \"" << nama << "\" tidak ada\n";
	}
	void tambahpengarang(pengarang*);
	void cetakpengarang();
};

class pengarang {
public:
	string nama;
	vector <penerbit*> daftar_penerbit;

	pengarang(string pNama) :nama(pNama) {};
	~pengarang() {};

	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
};

void penerbit::tambahpengarang(pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}

void penerbit::cetakpengarang() {
	cout << "Daftar Pengarang pada penerbit \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

void pengarang::tambahpenerbit(penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
	pPenerbit->tambahpengarang(this);
}
void pengarang::cetakpenerbit() {
	cout << "Daftar penerbit yang diikuti \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

class buku {
public:
	string nama;
	vector <buku*> daftar_buku;
	buku(string pNama) : nama(pNama) {
		cout << "buku \"" << nama << "\" ada \n";
	}
	~buku() {
		cout << "pasien \"" << nama << "\" tidak ada\n";
	}
	void tambahbuku(buku*);
	void cetakbuku();
};

void buku::tambahbuku(buku* pBuku) {
	daftar_buku.push_back(pBuku);
}

void buku::cetakbuku() {
	cout << "Daftar buku yang dikarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_buku) {
		cout << a->nama << "\n";
	}
	cout << endl;
}

int main() {
	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Giga");
	pengarang* varPengarang4 = new pengarang("Asroni");
	penerbit* varPenerbit1 = new penerbit("Game Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");
	buku* varBuku1 = new buku("Fisika");
	buku* varBuku2 = new buku("Matematika");
	buku* varBuku3 = new buku("Algoritma");
	buku* varBuku4 = new buku("BasisData");
	buku* varBuku5 = new buku("Dasar Pemrograman");

	varPenerbit1->tambahpengarang(varPengarang1);
	varPenerbit1->tambahpengarang(varPengarang2);
	varPenerbit1->tambahpengarang(varPengarang3);
	varPenerbit2->tambahpengarang(varPengarang4);
	varPenerbit2->tambahpengarang(varPengarang3);
	varPengarang3->tambahpenerbit(varPenerbit1);
	varPengarang3->tambahpenerbit(varPenerbit2);

	varPengarang1->cetakpenerbit();
	varPengarang2->cetakpenerbit();
	varPengarang3->cetakpenerbit();
	varPengarang4->cetakpenerbit();
	varPenerbit1->cetakpengarang();
	varPenerbit2->cetakpengarang();

	return 0;
}
