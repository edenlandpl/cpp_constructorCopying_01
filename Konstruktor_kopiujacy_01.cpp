#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Tablica
{
	public:
		Tablica(int rozmiar);	// konstruktor z argumentem - tworzenie tablicy dynamicznej o nieznanej ilosci argumentow
		~Tablica();				// destruktor
		Tablica(Tablica &t);	// konstruktor kopiujacy
		void wczytaj();			// wczytuje liczby z klawiatury
		void pokaz ();			// wyswietla tablice na ekranie
		float get (int i);		// zwraca i-ty element tablicy
		void set(int i, float x);// ustala i-ny element, zamienic i-ny element tablicy liczba x, elementy podane na sztywno
		void set();				// wywolanie funkcji, argumenty beda podane z klawiatury
	//	float srednia();		// zwraca srednia na ekranie
	//	float minimum():		// zwraca najmniejsza liczbe
	//	float maksimum();		// zwraca najwiekszy element
	//	void sortuj();			// sortowanie np babelkowe
	//	float mediana();		// wyznaczenie mediany, srodkowej liczby posortowanej tablicy
	//	void losuj(); 			// wypelnia tablice losowymi liczbami
	private:
		int n;					// liczba elementow
		float *wsk;				// adres tablicy w pamieci
};

Tablica::Tablica(int rozmiar)	// zaprogramowany konstruktor
{
	n = rozmiar;
	wsk = new float[n];			// n nazwa zmiennej, new przydzielenie pamieci dla tablicy
	if(wsk==0)					// sprawdzenie czy pamiec zostala przydzielona
			{
				cout << "Brak pamieci" << endl;
				exit(-1);
			}
}

Tablica::~Tablica()			//zaprogramowany destruktor aby wlasciwie usunal dane z pamieci
{
	if (wsk != 0)			// nie zwalniaj jesli nie zostala przydzielona
	{
		delete [] wsk;		// zwolnienie pamieci
		wsk=0; 	
	}
}

Tablica::Tablica(Tablica &t)	// zaprogramowany konstruktor kopiujacy
{
	n = t.n;
	wsk = new float[n];			// przydzielamy nowa pamiec
	if(wsk==0)					// sprawdzenie czy pamiec zostala przydzielona
			{
				cout << "Brak pamieci" << endl;
				exit(-1);
			}	
	for (int i = 0; i < n; i++)	// kopiujemy do nowego adresu pamieci
	wsk[i] = t.wsk[i];			// tworzona jest kopia, aby podczas kasowania kopii oryginal zostal nienaruszony
}

void Tablica::wczytaj()
{
	cout << "Podaj zawartosc tablicy" << endl;
	for ( int i=0; i<n;i++)
	{
		cout << "Podaj " << i+1 << " liczbe:" << endl;
		cin >> wsk[i];			// *wsk+1
	}
}
	
float Tablica::get (int i)
{
	return wsk[i]; 			// 
}

void Tablica::pokaz ()
{
	for(int i=0; i<n; i++)
	{
		cout << "Liczba " << i+1 << " - "<< wsk[i] << endl;
	}

}

void Tablica::set()
{
	cout << "Podaj liczbe do zamiany:" << endl;
	cin >> x ;
	cout << "Ktory element tablicy zamienic:" << endl;
	cin >> i ;
	wsk[i-1]=x;
}

void Tablica::set(int i, float x)
{
	wsk[i-1]=x;
}


int main(int argc, char** argv) 
{
	system ("cls");
	Tablica t1(3);				// tworzenie obiektu t1
	t1.wczytaj();
	cout <<"Pierwsza liczba to "<< t1.get(0) << endl;
	t1.set(2,2);
	t1.set();
	t1.pokaz();
//Tablica t2 = t1;			// kopiowanie obiektu przy pomocy konstruktora kopiujacego
	
	system ("pause");
	return 0;
}
