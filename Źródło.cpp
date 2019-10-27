#include <iostream>
#include <cctype>
#include <fstream>		//zliczanie znakow z pliku

struct zliczanie_dane
{
	int spolgloski;
	int samogloski;
	int inne;
	int blad = 0;
};

zliczanie_dane zliczanie(void);
void wyswietlanie(zliczanie_dane);

int main()
{
	std::cout << "Podaj teks, program zlicza tak dlugo jak nie natknie sie na pojedynczy znak \"q\"."
		<< "Wprowadz swoj tekst:\n";
	wyswietlanie(zliczanie());
	
	while (std::cin.get() != '\n')
		continue;

	std::cin.get();
	return 0;
}


void wyswietlanie(zliczanie_dane wynik)
{
	std::cout << "\n\nW podanym tekscie znajduje sie: " << wynik.samogloski << " wyrazow zaczynajacych sie na samogloske, "
		<< wynik.spolgloski << " wyrazow zaczynajacych sie na spolgolske, " << wynik.inne << " wyrazow zaczynajacych sie na inny znak.";
}
zliczanie_dane zliczanie(void)
{
	char ch;
	int znacznik_q=0,znacznik_przerwa=1,koniec=0;
	zliczanie_dane wynik{0};
	while (!koniec)
	{
		std::cin.get(ch);
		std::cout << ch;
		if ((ch == '\n' || ch == ' ' && znacznik_przerwa) || !znacznik_przerwa)
		{
			if (ch == '\n' || ch == ' ')
			{
				znacznik_przerwa = 1;
				if (znacznik_q)
				{
					koniec = 1;
					wynik.spolgloski -= 1;
						
				}
			}

			znacznik_q = 0;
		}
		else
		{
			if (std::isalpha(ch))
			{
				switch (ch)
				{
				case 'a':
				case 'A':
				case 'e':
				case 'E':
				case 'i':
				case 'I':
				case 'o':
				case 'O':
				case 'u':
				case 'U':
				case 'y':
				case 'Y':
					wynik.samogloski += 1;
					break;
				case 'q':
				case 'Q':
					wynik.spolgloski += 1;
					znacznik_q = 1;
					break;
				default:
					wynik.spolgloski += 1;


				}
				znacznik_przerwa = 0;
			}
			else
			{
				wynik.inne += 1;
				znacznik_przerwa = 0;			
			}
		}
	}

	return wynik;
		
}