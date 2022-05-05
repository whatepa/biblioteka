#include <iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<limits>


class Ksiazka
{
	struct dane
	{
		unsigned int idKsiazki;
		char sygnaturaKsiazki[5];
		char autorKsiazki[51];
		char tytulKsiazki[61];
		unsigned long long int ISBN;
		char wydawnictwoKsiazki[41];
		unsigned short rokWydaniaKsiazki;

	};

public:

	std::fstream plik;
	dane ksiazka1 = {};

	void dodajKsiazke();
	void wyswietlKsiazki();
	void usunKsiazke();
	void wyszukajKsiazke();
	void wyswietlSzukane();



};
void menuWyboru()
{
	Ksiazka k;
	int wybor = 0;
	std::string s;
	bool OK;

	

		
		do
		{
			OK = false;
			std::cout << "///////MENU\\\\\\\\\\\\\\" << std::endl;
			std::cout << "1.Wyswietl ksiazki." << std::endl;
			std::cout << "2.Wyszukaj ksiazke." << std::endl;
			std::cout << "3.Dodaj ksiazke." << std::endl;
			std::cout << "4.Usun ksiazke." << std::endl;
			std::cout << "0.Wyjdz" << std::endl;
			std::cout << "Wybierz opcje: ";
			std::getline(std::cin, s);
			
			for (char c : s)
			{
				if (c >= '0' && c <= '9')
				{
					wybor = wybor * 10 + (c - '0');
				}
				else
				{
					std::cout << "Niepoprawna wartosc. Opcje nalezy wybrac wpisujac odpowiadajaca jej cyfre.\n";
					OK = true;
					wybor = 0;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}
			}

		} while (OK || s == "");

		std::system("CLS");
		switch (wybor)
		{
		case 0:
		{
			exit(1);
			break;
		}
		case 1:
		{
			k.wyswietlKsiazki();
			menuWyboru();
			break;
		}
		case 2:
		{
			k.wyszukajKsiazke();
			menuWyboru();
			break;
		}
		case 3:
		{
			k.dodajKsiazke();
			menuWyboru();
			break;
		}
		case 4:
		{
			k.usunKsiazke();
			menuWyboru();
			break;
		}
		default: std::cout << "Nie ma takiej opcji." << std::endl;
			menuWyboru();
			break;
		}
	
}

void Ksiazka::dodajKsiazke()
{

	bool OK;
	char tmp[70];
	std::string s;
	ksiazka1.idKsiazki = 0; ksiazka1.ISBN = 0; ksiazka1.rokWydaniaKsiazki = 0;

	do
	{
		OK = false;
		std::cout << "Podaj ID Ksiazki lub wpisz \"0\" by wrocic do menu: ";
		std::getline(std::cin,s);
		if (s == "0")
		{
			std::system("CLS");
			menuWyboru();
		}
		for (char c : s)
		{
			if (c >= '0' && c <= '9')
			{
				ksiazka1.idKsiazki = ksiazka1.idKsiazki * 10 + (c - '0');
				
			}
			else
			{
				OK = true;
				std::cout << "Niepoprawna wartosc. ID ksiazki musi byc liczba dodatnia.\n";
				ksiazka1.idKsiazki = 0;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			
		}

	} while(OK || s=="");

	
	do
	{
		int i;
		OK = false;
		std::cout << "Podaj sygnature Ksiazki: ";
		std::cin.getline(tmp, 70);

		for (i = 0; i < strlen(tmp); i++);
		if (i > 4)
		{
			OK = true;
			std::cout << "Rozmiar wprowadzonej sygnatury jest za duzy!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
			else
				strncpy_s(ksiazka1.sygnaturaKsiazki, tmp,_TRUNCATE);
	} while (OK);
	
	do
	{
		
		int i;
		OK = false;
		std::cout << "Podaj autora Ksiazki: ";
		std::cin.getline(tmp, 70);
		for (i = 0; i < strlen(tmp); i++);
		if (i > 50)
		{
			OK = true;
			std::cout << "Rozmiar wprowadzonego autora jest za duzy!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			strncpy_s(ksiazka1.autorKsiazki, tmp, _TRUNCATE);
	} while (OK);

	do
	{

		int i;
		OK = false;
		std::cout << "Podaj tytul Ksiazki: ";
		std::cin.getline(tmp, 70);

		for (i = 0; i < strlen(tmp); i++);
		if (i > 60)
		{
			OK = true;
			std::cout << "Rozmiar wprowadzonego tytulu jest za duzy!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			strncpy_s(ksiazka1.tytulKsiazki, tmp, _TRUNCATE);
	} while (OK);
	
	do
	{
		OK = false;
		std::cout << "Podaj ISBN Ksiazki: ";
		std::getline(std::cin, s);

		int i = 0;
		for (char c : s)
		{
			i++;
		}
		for (char c : s)
		{
			if (i == 13 && (c >= '0' && c <= '9'))
			{
				ksiazka1.ISBN = ksiazka1.ISBN * 10 + ((long long int)c - '0');
			}
			else
			{
				std::cout << "Niepoprawna wartosc. ISBN ksiazki musi byc 13 cyfrowa liczba.\n";
				OK = true;
				ksiazka1.ISBN = 0;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
		}

	} while (OK || s == "");
	
	do
	{
		int i;
		OK = false;
		std::cout << "Podaj wydawnictwo Ksiazki: ";
		std::cin.getline(tmp, 70);
		for (i = 0; i < strlen(tmp); i++);
		if (i > 40)
		{
			
			OK = true;
			std::cout << "Rozmiar wprowadzonego wydawnictwa jest za duzy!" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
			strncpy_s(ksiazka1.wydawnictwoKsiazki, tmp, _TRUNCATE);
	} while (OK);
	
	do
	{
		OK = false;
		std::cout << "Podaj rok wydania Ksiazki: ";
		std::getline(std::cin, s);
		for (char c : s)
		{
			if (c >= '0' && c <= '9')
			{
				ksiazka1.rokWydaniaKsiazki = ksiazka1.rokWydaniaKsiazki * 10 + (c - '0');
			}
			else
			{
				std::cout << "Niepoprawna wartosc. Rok wydania ksiazki musi byc liczba dodatnia.\n";
				OK = true;
				ksiazka1.rokWydaniaKsiazki = 0;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
		}

	} while (OK || s == "");
	

	plik.open("Ksiazki.bin", std::ios::app | std::ios::binary);

	if (plik.is_open() && !plik.eof())
	{

		sizeof(dane);
		plik.write((const char*)&ksiazka1, sizeof(ksiazka1));


		plik.close();
	}
	else
		std::cout << "Nie udalo sie otworzyc pliku. \n";

}

void Ksiazka::wyswietlKsiazki()
{
	

	plik.open("Ksiazki.bin", std::ios::in | std::ios::binary);
	if (plik.is_open())
	{
		std::cout << std::left << std::setw(10)  << "ID" << '|' << std::setw(10)  << "SYGNATURA" << '|' << std::setw(52) << "AUTOR" << '|' <<
			std::setw(62) << "TYTUL" << '|' << std::setw(15) << "ISBN" << '|' << std::setw(42) << "WYDAWNICTWO" << '|' <<
			std::setw(12) << "ROK WYDANIA" << '|' << std::endl;
		
	
		while (plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
		{
			std::cout << std::left << std::setw(10) << ksiazka1.idKsiazki << '|' << std::setw(10) << ksiazka1.sygnaturaKsiazki << '|'
				<< std::setw(52) << ksiazka1.autorKsiazki << '|' << std::setw(62)
				<< ksiazka1.tytulKsiazki << '|' << std::setw(15) << ksiazka1.ISBN << '|' << std::setw(42) << ksiazka1.wydawnictwoKsiazki << '|'
				<< std::setw(12) << ksiazka1.rokWydaniaKsiazki << '|' << std::endl;
		}
	plik.close();
	}
	else
		std::cout << "Nie udalo sie otworzyc pliku. \n";

	
}
void Ksiazka::wyswietlSzukane()
{
	
	std::cout << std::left << std::setw(10) << "ID" << '|' << std::setw(10) << "SYGNATURA" << '|' << std::setw(52) << "AUTOR" << '|' <<
		std::setw(62) << "TYTUL" << '|' << std::setw(15) << "ISBN" << '|' << std::setw(42) << "WYDAWNICTWO" << '|' <<
		std::setw(12) << "ROK WYDANIA" << '|' << std::endl;
	
	std::cout << std::left << std::setw(10) << ksiazka1.idKsiazki << '|' << std::setw(10) << ksiazka1.sygnaturaKsiazki << '|'
		<< std::setw(52) << ksiazka1.autorKsiazki << '|' << std::setw(62)
		<< ksiazka1.tytulKsiazki << '|' << std::setw(15) << ksiazka1.ISBN << '|' << std::setw(42) << ksiazka1.wydawnictwoKsiazki << '|'
		<< std::setw(12) << ksiazka1.rokWydaniaKsiazki << '|' << std::endl;
	
}
void Ksiazka::wyszukajKsiazke()
{
	long long int lint = 0;
	int atrybut = 0;
	int id = 0;
	char chr[60];
	short sht = 0;
	bool OK;
	std::string s;

	std::cout <<" 1 - ID\n 2 - SYGNATURA\n 3 - AUTOR\n 4 - TYTUL\n 5 - ISBN\n 6 - WYDAWNICTWO\n 7 - ROK WYDANIA\n 0 - POWROT DO MENU\n";
	do
	{
		OK = false;
		std::cout << "Wybierz atrybut ksiazki po ktorym chcesz szukac lub wpisz \"0\" by wrocic do menu: ";
		std::getline(std::cin, s);
		for (char c : s)
		{
			if (c >= '0' && c <= '9')
			{
				atrybut = atrybut * 10 + (c - '0');
			}
			else
			{
				std::cout << "Niepoprawna wartosc. Atrybut ksiazki nalezy wybrac wpisujac odpowiadajaca mu cyfre.\n";
				OK = true;
				atrybut = 0;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
		}

	} while (OK || s == "");
	std::system("CLS");

	plik.open("Ksiazki.bin", std::ios::in | std::ios::binary);
	switch (atrybut)
	{

		case 0:
		{
			std::system("CLS");
			menuWyboru();
		}
		case 1:
			do
			{
				OK = false;
				std::cout << "Podaj ID szukanej ksiazki:";
				std::getline(std::cin, s);
				for (char c : s)
				{
					if (c >= '0' && c <= '9')
					{
						id = id * 10 + (c - '0');
					}
					else
					{
						std::cout << "Niepoprawna wartosc. ID ksiazki musi byc liczba dodatnia.\n";
						OK = true;
						id = 0;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						break;
					}
				}

			} while (OK || s == "");

			while(plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
			{
				if (id == ksiazka1.idKsiazki)
				{
					wyswietlSzukane();
				}	
				
			}
			plik.close();
			break;
		case 2:
			std::cout << "Podaj sygnature szukanej ksiazki:";
			std::cin.getline(chr,60);
			while (plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
			{
				if (strstr(ksiazka1.sygnaturaKsiazki, chr))
					wyswietlSzukane();
			}
			plik.close();
			break;
		case 3:
			std::cout << "Podaj autora szukanej ksiazki:";
			std::cin.getline(chr, 60);
			while (plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
			{
				if (strstr(ksiazka1.autorKsiazki,chr))
					wyswietlSzukane();
			}
			plik.close();
			break;
		case 4:
			std::cout << "Podaj tytul szukanej ksiazki:";
			std::cin.getline(chr, 60);
			while (plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
			{
				if (strstr(ksiazka1.tytulKsiazki,chr))
					wyswietlSzukane();
			}
			plik.close();
			break;
		case 5:
			std::cout << "Podaj ISBN szukanej ksiazki:";
			do
			{
				OK = false;
				std::cout << "Podaj ISBN Ksiazki: ";
				std::getline(std::cin, s);

				int i = 0;
				for (char c : s)
				{
					i++;
				}
				for (char c : s)
				{
					if (i == 13 && (c >= '0' && c <= '9'))
					{
						lint = lint* 10 + ((long long int)c - '0');
					}
					else
					{
						std::cout << "Niepoprawna wartosc. ISBN ksiazki musi byc 13 cyfrowa liczba dodatnia.\n";
						OK = true;
						lint = 0;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						break;
					}
				}

			} while (OK || s == "");

			while (plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
			{
				if (lint == ksiazka1.ISBN)
					wyswietlSzukane();
			}
			plik.close();
			break;
		case 6:
			std::cout << "Podaj wydawnictwo szukanej ksiazki:";
			std::cin.getline(chr, 60);
			while (plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
			{
				if (strstr(ksiazka1.wydawnictwoKsiazki, chr))
					
					wyswietlSzukane();
					
			}
			plik.close();
			break;
		case 7:
			do
			{
				OK = false;
				std::cout << "Podaj rok wydania szukanej ksiazki:";
				std::getline(std::cin, s);
				for (char c : s)
				{
					if (c >= '0' && c <= '9')
					{
						sht = sht * 10 + (c - '0');
					}
					else
					{
						std::cout << "Niepoprawna wartosc. Rok wydania ksiazki musi byc liczba dodatnia.\n";
						OK = true;
						sht = 0;
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						break;
					}
				}

			} while (OK || s == "");

			while (plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
			{
				if (sht == ksiazka1.rokWydaniaKsiazki)
				{
					wyswietlSzukane();
				}
			}
			plik.close();
			break;

		default: std::cout << "Nie ma takiego atrybutu." << std::endl;
			break;
			
	}
	
};

void Ksiazka::usunKsiazke()
{
	wyswietlKsiazki();
	int id = 0;
	std::string s;
	bool OK;
	std::fstream plikTmp;

	do
	{
		OK = false;
		std::cout << "Wpisz ID ksiazki ktora chcesz usunac lub wpisz \"0\" by wrocic do menu:";
		std::getline(std::cin, s);
		for (char c : s)
		{
			if (c >= '0' && c <= '9')
			{
				id = id * 10 + (c - '0');

			}
			else
			{
				OK = true;
				std::cout << "Niepoprawna wartosc. ID ksiazki musi byc liczba dodatnia.\n";
				id = 0;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}

		}

	} while (OK || s == "");

	if (id == 0)
	{
		std::system("CLS");
		menuWyboru();
	}
	else
	{
	plik.open("Ksiazki.bin", std::ios::in | std::ios::binary);
	plikTmp.open("temp.bin", std::ios::out | std::ios::binary);
	}
	{
		if (plik.is_open())
		{

			while (plik.read((char*)&ksiazka1, sizeof(ksiazka1)))
			{
				if (id != ksiazka1.idKsiazki)
				{
					plikTmp.write((const char*)&ksiazka1, sizeof(ksiazka1));
				}
			}
				plik.close();
				plikTmp.close();
				remove("Ksiazki.bin");
				rename("temp.bin", "Ksiazki.bin");
				std::cout << "Usunieto ksiazke." << std::endl;

		}else
			std::cout << "Nie udalo sie otworzyc pliku. \n";
	}

};



int main()
{
	menuWyboru();
	
	
}
	
