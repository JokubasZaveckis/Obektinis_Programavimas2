#include "Header_list.h"
#include "Funkcijos_v1.0_list.h"

int main()
{
	int pasirinkimas;
	list<Studentas> grupe;
	Studentas laikinas;
	string choice;
	cout << "Iveskite 0 kad studentai butu nuskaitomi is failo" << endl;
	cout << "Iveskite 1 kad studentus ivestumete ranka" << endl;
	cout << "Iveskite 2 kad sugeneruotumete studentu faila" << endl;
	cin >> choice;
	while (true)
	{
		if (choice == "1")
		{
			do {
				cout << "Iveskite studento duomenis" << endl;
				Pildymas(laikinas);
				grupe.push_back(laikinas);
				laikinas.pazymiai.clear();
				cout << "Iveskite 1, kad pratestumete studentu irasyma, arba bet ka kito kad uzbaigtumete" << endl;
				cin >> pasirinkimas;
			} while (pasirinkimas == 1);

			Isvedimas(grupe);
			break;
		}
		else if (choice == "0")
		{
			KitiSkaiciavimai(grupe);
			break;
		}
		else if (choice == "2")
		{
			cout << "Iveskite kokio dydzio faila norite sugeneruoti:" << endl;
			cout << "Galimi failo dydziai: 1 000, 10 000, 100 000, 1 000 000, 10 000 000" << endl;
			string failuDydis;
			while (true)
			{
				cin >> failuDydis;
				if (failuDydis == "1000" || failuDydis == "10000" || failuDydis == "100000" || failuDydis == "1000000" || failuDydis == "10000000")
				{
					int dydis = stoi(failuDydis);
					int pazymiai;
					while (true)
					{
						cout << "Iveskite kiek pazymiu turi kiekvienas studentas (nuo 1 iki 10)" << endl;
						cin >> pazymiai;
						if (pazymiai > 0 && pazymiai <= 10)
						{
							FailoSukurimas(grupe, dydis, pazymiai);
							break;
						}
						else
						{
							cout << "Netinkama ivestis, bandykite dar karta" << endl;
						}
					}
					break;
				}
				else
				{
					cout << "Tokio pasirinkimo nera, bandykite dar karta: " << endl;
				}
			}
			break;
		}
		else
		{
			cout << "Ivestis netinkama, bandykite is naujo" << endl;
			cin >> choice;
		}
	}


	for (auto& i : grupe)
	{
		i.pazymiai.clear();
	}
	grupe.clear();
	return 0;
}