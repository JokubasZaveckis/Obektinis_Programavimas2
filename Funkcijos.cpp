#include "Header.h"
#include "Funkcijos.h"


std::ostream& operator<<(std::ostream& os, const Studentas& studentas)
{
	os << std::left << std::setw(13) << studentas.getVardas()
		<< std::left << std::setw(20) << studentas.getPavarde()
		<< std::left << std::setw(20) << studentas.get_vidurkis()
		<< std::left << std::setw(20) << studentas.get_mediana();
	return os;
}


void FailoSukurimas(vector <Studentas>& grupe, int failoDydis, int pazymiuSkaicius)
{
	auto start = std::chrono::high_resolution_clock::now();

	ofstream sugeneruotas("sugeneruotas" + std::to_string(failoDydis) + ".txt");

	auto startGeneravimas = std::chrono::high_resolution_clock::now();

	std::random_device rd;
	std::mt19937 mt(static_cast<long unsigned int> (rd()));
	std::uniform_int_distribution<int> Dist(0, 99);
	std::uniform_int_distribution<int> paz_dist(0, 10);

	sugeneruotas << left << setw(15) << "Vardas" << setw(20) << "Pavarde";
	for (int j = 0; j < pazymiuSkaicius; j++)
	{
		sugeneruotas << left << setw(6) << ("ND" + std::to_string(j + 1));
	}
	sugeneruotas << left << setw(7) << "Egz." << endl;
	for (int i = 0; i < failoDydis; i++)
	{
		sugeneruotas << left << setw(15) << VARDAI[Dist(mt)] << setw(20) << PAVARDES[Dist(mt)];
		for (int j = 0; j <= pazymiuSkaicius; j++)
		{
			sugeneruotas << left << setw(5) << paz_dist(mt) << " ";
		}
		sugeneruotas << endl;
	}
	sugeneruotas.close();

	auto endGeneravimas = std::chrono::high_resolution_clock::now();
	auto generacija = std::chrono::duration_cast<std::chrono::milliseconds>(endGeneravimas - startGeneravimas).count();
	cout << "Failo sugeneruotas" + std::to_string(failoDydis) + ".txt" " generavimas truko: " << fixed << setprecision(2) << static_cast<double>(generacija) / 1000 << "s" << endl;
	string strategija = "2";
	KitiSkaiciavimai(grupe, strategija);
}

void Skaitymas(vector <Studentas>& grupe, float& nuskaitymas)
{

	string failas;
	ifstream duomenys;

	while (true)
	{
		cout << "Iveskite is kurio failo noretumete nuskaityti duomenis:" << endl;
		cin >> failas;

		try {
			duomenys.open(failas);

			if (!duomenys)
			{
				throw std::runtime_error("Failo atverti nepavyko, bandykite dar karta: ");
			}
			else
			{
				cout << "Failas atidarytas sekmingai, nuskaitoma..." << endl;
				break;
			}

		}
		catch (std::exception& e)
		{
			cout << "Error: " << e.what() << endl;
			cout << "Galimi tekstinio failo pavadinimai:" << endl;
			system("dir /b | findstr \\.txt$ | findstr /v protingi.txt | findstr /v neprotingi.txt");
		}
	}
	auto startNuskaitymas = std::chrono::high_resolution_clock::now();

	string line;
	getline(duomenys, line);

	while (duomenys >> grupe) {}
	
	auto endSkaitymas = std::chrono::high_resolution_clock::now();
	auto skaitymas = std::chrono::duration_cast<std::chrono::milliseconds>(endSkaitymas - startNuskaitymas).count();
	nuskaitymas = skaitymas;
	cout << "Failo nuskaitymas truko: " << fixed << setprecision(2) << static_cast<double>(skaitymas) / 1000 << "s" << endl;

	duomenys.close();

}

void KitiSkaiciavimai(vector <Studentas>& grupe, string strategija)
{
	float nuskaitymas;

	for (auto& i : grupe)
	{
		i.get_pazymiai().clear();
	}
	grupe.clear();

	Skaitymas(grupe, nuskaitymas);

	auto start = std::chrono::high_resolution_clock::now();

	auto startRikiavimas = std::chrono::high_resolution_clock::now();
	sort(grupe.begin(), grupe.end(), Palyginimas1);
	auto endRikiavimas = std::chrono::high_resolution_clock::now();
	auto Rikiavimas = std::chrono::duration_cast<std::chrono::milliseconds>(endRikiavimas - startRikiavimas).count();
	cout << "Failo rikiavimas truko " << fixed << setprecision(2) << static_cast<double>(Rikiavimas) / 1000 << "s" << endl;

	float isvedimas = 0.0;
	float rusiavimas = 0.0;

	if (strategija == "1")
	{
		auto startRusiavimas = std::chrono::high_resolution_clock::now();
		vector <Studentas> protingi;
		vector <Studentas> neprotingi;
		for (auto& i : grupe)
		{
			if (i.get_vidurkis() < 5)
			{
				neprotingi.push_back(i);
			}
			else
			{
				protingi.push_back(i);
			}
		}
		auto endRusiavimas = std::chrono::high_resolution_clock::now();
		auto rusiavimas = std::chrono::duration_cast<std::chrono::milliseconds>(endRusiavimas - startRusiavimas).count();
		cout << "Failo rusiavimas truko: " << fixed << setprecision(2) << static_cast<double>(rusiavimas) / 1000 << "s" << endl;

		IsvedimasIFaila(protingi, neprotingi, isvedimas);
	}
	else if (strategija == "2")
	{
		isvedimas = 0;
		auto startRusiavimas = std::chrono::high_resolution_clock::now();
		vector <Studentas> neprotingi;

		auto it = std::remove_if(grupe.begin(), grupe.end(), [](const Studentas& s) { return !(s.get_vidurkis() < 5.0); });
		std::copy(it, grupe.end(), std::back_inserter(neprotingi));
		grupe.erase(it, grupe.end());

		auto endRusiavimas = std::chrono::high_resolution_clock::now();
		auto rusiavimas = std::chrono::duration_cast<std::chrono::milliseconds>(endRusiavimas - startRusiavimas).count();
		cout << "Failo rusiavimas truko: " << fixed << setprecision(2) << static_cast<double>(rusiavimas) / 1000 << "s" << endl;

		IsvedimasIFaila(neprotingi, grupe, isvedimas);
	}

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	std::cout << "Programos trukme: " << fixed << setprecision(2) << static_cast<double>(Rikiavimas + rusiavimas + nuskaitymas + isvedimas) / 1000 << "s" << endl;
}

bool Palyginimas(const Studentas& a, Studentas& b)
{
	return a.getVardas() < b.getPavarde();
}

bool Palyginimas1(const Studentas& a, Studentas& b)
{
	return a.get_vidurkis() < b.get_vidurkis();
}

void Pildymas(Studentas& temp)
{
	cout << "Iveskite studento varda ir pavarde:" << endl;
	string vardas, pavarde;
	cin >> vardas >> pavarde;
	temp.setVardas(vardas);
	temp.setPavarde(pavarde);

	int pasirinkimas = 0;
	while (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3)
	{
		cout << "Iveskite 1 jei norite pazymius ivesti rankiniu budu, 2 jei norite kad pazymiai butu sugeneruoti atsitiktine tvarka, 3 jei nezinote kiek pazymiu ivesite: ";
		cin >> pasirinkimas;
	}

	if (pasirinkimas == 1)
	{
		int n, egz;
		cout << "Iveskite kiek studentas turi pazymiu: ";
		cin >> n;;
		cout << "Iveskite studento pazymius: ";
		int pazymys;
		for (int j = 0; j < n; j++)
		{
			cin >> pazymys;
			if (pazymys > 0 && pazymys < 11)
			{
				temp.get_pazymiai().push_back(pazymys);
			}
			else
			{
				cout << "Neteisingas pazymio formatas" << endl;
				j--;
			}
		}
		cout << "Iveskite egzamino rezultata: ";
		cin >> egz;
		temp.set_egzaminas(egz);
	}
	else if (pasirinkimas == 2)
	{
		std::random_device rd;
		std::mt19937 mt(static_cast<long unsigned int> (rd()));
		std::uniform_int_distribution<int> dist(1, 10);
		int n = dist(mt);
		for (int j = 0; j < n; j++)
		{
			temp.get_pazymiai().push_back(dist(mt));
		}
		int egz = dist(mt);
		temp.set_egzaminas(egz);
	}
	else if (pasirinkimas == 3)
	{
		while (true)
		{
			cout << "Iveskite po viena sveiko tipo pazymi (iveskite bet ka kito noredami sustoti vesti pazymius)" << endl;
			int mark;
			if (cin >> mark)
			{
				temp.get_pazymiai().push_back(mark);
			}
			else
			{
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				break;
			}
		}
		cout << "Iveskite mokinio egzamino rezultata: ";
		int egz;
		cin >> egz;
		temp.set_egzaminas(egz);
	}
	temp.get_pazymiai().shrink_to_fit();
}

void IsvedimasIFaila(vector<Studentas> protingi, vector<Studentas> neprotingi, float& isvestis)
{
	auto startIsvedimas = std::chrono::high_resolution_clock::now();
	ofstream smart("protingi.txt");

	smart << left << setw(13) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.) /" << setw(20) << "Galutinis (Med.)" << endl;
	smart << "-----------------------------------------------------------------------------------" << endl;
	for (auto& i : protingi)
	{
		smart << i << endl;
	}

	smart.close();

	ofstream stupid("neprotingi.txt");

	stupid << left << setw(13) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Galutinis (Vid.) /" << setw(20) << "Galutinis (Med.)" << endl;
	stupid << "-----------------------------------------------------------------------------------" << endl;
	for (auto& i : neprotingi)
	{
		stupid << i << endl;
	}

	auto endIsvedimas = std::chrono::high_resolution_clock::now();
	auto isvedimas = std::chrono::duration_cast<std::chrono::milliseconds>(endIsvedimas - startIsvedimas).count();
	cout << "Failo isvedimas truko: " << fixed << setprecision(2) << static_cast<double>(isvedimas) / 1000 << "s" << endl;
	isvestis = isvedimas;

	stupid.close();
}
