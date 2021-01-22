#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class obslugaPliku{
	public:
		obslugaPliku();
		~obslugaPliku();
		ifstream wejscie;
		ofstream wyjscie;
	bool sprawdzPlik();
};
class obslugaCiagu:public obslugaPliku{
	public:
		int ilosc=0;
		int dlugosc;
		int liczba;
		vector <int> ciag;
	void zapisCiagu();
	void sprawdzCiag(int dlugosc);
};
obslugaPliku::obslugaPliku(){
	wejscie.open("ciagi.txt");
	wyjscie.open("wyjscie.txt");
}
obslugaPliku::~obslugaPliku(){
	wejscie.close();
	wyjscie.close();
}
bool obslugaPliku::sprawdzPlik(){
	if(wejscie.good()&&wyjscie.good()) return true;
	else return false;
}
void obslugaCiagu::zapisCiagu(){
	obslugaPliku p1;
	while(!p1.wejscie.eof()){
		p1.wejscie>>dlugosc;
		for(int i=0;i<=dlugosc-1;i++){
			p1.wejscie>>liczba;
			ciag.push_back(liczba);
		}
		sprawdzCiag(dlugosc);
		ciag.clear();
		system("cls");
		cout<<ilosc<<endl;
		
	}
}
void obslugaCiagu::sprawdzCiag(int dlugosc){
	int roznica = ciag[0] - ciag[1];
	if(roznica == ciag[3] - ciag[2]) ilosc++;
}

int main() {
	obslugaPliku p1;
	obslugaCiagu c1;
	p1.sprawdzPlik();
	if(p1.sprawdzPlik()==false) exit(0);
	else c1.zapisCiagu();
	system("pause");
	return 0;
}
