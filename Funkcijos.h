#pragma once
#include "Header.h"

const string VARDAI[100] = {
	"Adomas", "Aivaras", "Albertas", "Aleksandras", "Algis", "Alvydas", "Andrius", "Antanas", "Arminas", "Arnoldas", //10
	"Arturas", "Aurimas", "Benas", "Dainius", "Dalius", "Danas", "Darius", "Deividas", "Domantas", "Donatas", //10
	"Dovydas", "Edgaras", "Edvinas", "Egidijus", "Evaldas", "Gediminas", "Gintaras", "Gytis", "Ignas", "Ilja", //10
	"Ilona", "Inga", "Ingrida", "Jonas", "Juras", "Juozapas", "Justinas", "Kajus", "Karolis", "Kasparas", //10
	"Kestutis", "Kipras", "Klaudijus", "Konstantinas", "Kristijonas", "Laimonas", "Linas", "Mantas", "Marius", "Martynas", //10
	"Mindaugas", "Meta", "Nerijus", "Nijole", "Olegas", "Osvaldas", "Ovidijus", "Patrikas", "Paulius", "Petras", //10
	"Raimondas", "Ricardas", "Rimantas", "Rolandas", "Rokas", "Romualdas", "Saulius", "Simone", "Simonas", "Stanislovas", //10
	"Svetlana", "Sarunas", "Tadas", "Tauras", "Tautvydas", "Teodoras", "Tomas", "Valdas", "Valentinas", "Vidmantas", //10
	"Vidmante", "Viktoras", "Vilius", "Vytautas", "Zilvinas", "Zygimantas", "Karolis", "Aretas", "Nojus", "Giedrius",//10
	"Dominykas", "Dziugas", "Arnas", "Augustas", "Algimantas", "Maksas", "Orestas", "Tautrimas", "Vladas", "Rytis" //10
};
const string PAVARDES[100] = {
	"Adomaitis", "Alekna", "Aleknavicius", "Andriuskevicius", "Antanaitis", "Arlauskas", "Baksys", "Balciunas", "Baltuska", "Baranauskas", //10
	"Bartkus", "Bendikas", "Bikulcius", "Birzietis", "Bubnys", "Budrys", "Buivydas", "Cepulis", "Cerniauskas", "Cesnulevicius",
	"Dambrauskas", "Dapkus", "Didziokas", "Dilys", "Dobilas", "Dobrovolskis", "Dovydaitis", "Drevinskas", "Dubickas", "Dumbrys",
	"Duda", "Dumbliauskas", "Eidimtas", "Gedvilas", "Gintalas", "Girdauskas", "Girgdys", "Grybauskas", "Grigaitis", "Gudaitis",
	"Gudynas", "Gulbinas", "Gvildys", "Janilionis", "Jankauskas", "Jankunas", "Jonauskas", "Juska", "Juskevicius", "Jusys",
	"Kairys", "Kazlauskas", "Klimasauskas", "Kraujalis", "Kudirka", "Kulvietis", "Lapenas", "Lapinas", "Laukaitis", "Laurinaitis",
	"Laurusaitis", "Liubinas", "Maciulis", "Makaveckas", "Malinauskas", "Markauskas", "Markevicius", "Marozas", "Masalskis", "Maskoliunas",
	"Mazeika", "Mikalauskas", "Miknevicius", "Milaknis", "Miliauskas", "Mockus", "Monstvilas", "Montvilas", "Narkevicius", "Navickas",
	"Norkus", "Pakalniskis", "Pakalniskis", "Palionis", "Petrulis", "Pocius", "Povilaitis", "Rakauskas", "Razmas", "Rimkus", //10
	"Rimsa", "Rupsys", "Rusinas", "Rutkauskas", "Ruzgys", "Sabaliauskas", "Sabonis", "Sakalauskas", "Samsonas", "Savickas" //10
};

class Studentas {
private:
	string vardas_, pavarde_;
	int egzaminas_;
	double vidurkis_, mediana_;
	vector<int> pazymiai_;

	static double Vidurkis(vector<int> pazymiai, int egzaminas);
	static double Mediana(vector<int> pazymiai, int egzaminas);

public:
	Studentas() : vardas_(""), pavarde_(""), egzaminas_(0), vidurkis_(0), mediana_(0), pazymiai_(vector<int>(0, 0)) {}
	Studentas(string vardas, string pavarde, vector<int>& pazymiai, int egzaminas)
	{
		vardas_ = vardas;
		pavarde_ = pavarde;
		pazymiai_ = pazymiai;
		egzaminas_ = egzaminas;
		vidurkis_ = Vidurkis(pazymiai, egzaminas);
		mediana_ = Mediana(pazymiai, egzaminas);
	}

	// Getters
	string get_vardas() const { return vardas_; }
	string get_pavarde() const { return pavarde_; }
	vector<int> get_pazymiai() const { return pazymiai_; }
	int get_egzaminas() const { return egzaminas_; }
	double get_vidurkis() const { return vidurkis_; }
	double get_mediana() const { return mediana_; }
	//Setters
	void set_vardas(string vardas) { vardas_ = vardas; }
	void set_pavarde(string pavarde) { pavarde_ = pavarde; }
	void set_pazymiai(vector<int>& pazymiai) { pazymiai_ = pazymiai; }
	void set_egzaminas(int egzaminas) { egzaminas_ = egzaminas; }
	void set_vidurkis(double vidurkis) { vidurkis_ = vidurkis; }
	void set_mediana(double mediana) { mediana_ = mediana; }

	~Studentas() {
		pazymiai_.clear();
	}
};

void Skaitymas(vector <Studentas>& grupe, float& nuskaitymas);
void Pildymas(Studentas& temp);
bool Palyginimas(const Studentas a, Studentas b);
void IsvedimasIFaila(vector<Studentas> protingi, vector<Studentas> neprotingi, float& isvedimas);
void FailoSukurimas(vector <Studentas>&, int failoDydis, int pazymiuSkaicius);
bool Palyginimas1(const Studentas a, Studentas b);
void KitiSkaiciavimai(vector <Studentas>& grupe, string strategija);
