#include <iostream>
#include <string>
#include <vector>	// Vektorien luonti
#include <cstdlib>	// rand()-funktien käyttö
#include <random>	// Mersenne Twister - satunnaislukugeneraattori varausnumerolle
#include <windows.h>	// Värien käyttöönotto


using namespace std;


// Funktio luo satunnaisen 0%, 10% tai 20% alennuksen loppusummaan
double luoAlennus()
{
	// Luodaan satunnaislukugeneraattori
	srand(time(0));
	int alennusVaihtoehto = rand() % 3;
	if (alennusVaihtoehto == 0)
	{
		cout << "\nValitettavasti tällä varauksella aleprosentti on 0.\n";
		return 1;
	}
	else if (alennusVaihtoehto == 1)
	{
		cout << "\nOnneksi olkoon! Voititte arvassa ja saitte loppusummaan 10 % alennuksen.\n";
		return 0.9;
	}
	else
	{
		cout << "\nOnneksi olkoon! Voititte arvassa ja saitte loppusummaan 20 % alennuksen.\n";

		return 0.8;
	}
}


// LuoVaraus-luokka mahdollistaa muuttujien yhdistämisen yhdeksi kokonaisuudeksi.
// Tässä tiedot joita kysytään käyttäjältä ja struct tallentaa ne vektoriin.

struct LuoVaraus
{
	int varausnumero;
	string nimi, osoite, puhelinnumero;
	int yöt = 0;
	int summa = 0;
	int huone_nro = 0;
	bool huone_vapaa = false;
};



// Funktio luo satunnaisen varausnumeron väliltä 10000-99999.

vector<LuoVaraus> luoSatunnainenVarausnumero(vector<LuoVaraus> varausNumerot, int varausnumero)
{
	LuoVaraus v;
	// Luodaan satunnaislukugeneraattori
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(10000, 99999);

	v.varausnumero = dis(gen);

	varausNumerot.push_back(v);

	return varausNumerot;
}




// Funktio luo satunnaisen varausnumeron väliltä 10000-99999.
// Toinen samanlainen funktio, jotta varausnumerot eivät toistu.

vector<LuoVaraus> luoSatunnainenVarausnumero2(vector<LuoVaraus> varausNumerot2, int varausnumero)
{
	LuoVaraus v;
	// Luodaan satunnaislukugeneraattori
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(10000, 99999);

	v.varausnumero = dis(gen);

	varausNumerot2.push_back(v);

	return varausNumerot2;
}

const int MAX_HUONEITA = 300;

vector<LuoVaraus> Varaus1(vector<LuoVaraus> Vector1, string nimi, string osoite, string puhelinnumero,
											int yöt, int summa, int huone_nro);
vector<LuoVaraus> Varaus2(vector<LuoVaraus> Vector2, string nimi, string osoite, string puhelinnumero,
											int yöt, int summa, int* huone_nro);




// Pääohjelma alkaa:

int main()
{

	// Lisää ääkköset koodiin
	setlocale(LC_ALL, "fi_FI"); 


	vector<LuoVaraus> varausnumerot;		// Varausnumeron tallentaminen
	vector<LuoVaraus> varausnumerot2;

	vector<LuoVaraus> Vector1, Vector2, U_Vector1, U_Vector2;		// Varausten tiedot tallennetaan näihin vektoreihin

	LuoVaraus varaus[MAX_HUONEITA];
	LuoVaraus v;

	int aloita, vaihtoehto, vaihtoehto2;
	char vaihtoehto3;
	bool tarkista_huone = true;

	system("Color 0D");		//Värikoodin käyttöönotto

	cout << "\n\n\t\t----Hotelli Carita----\n\n\n";		//Aloitusmenu
	cout << "\t\tMENU\n\n";
	cout << "\t\t1. Aloita hotellivaraus\n\n";

	cin >> aloita;

	while (aloita != 1)
	{
		cout << "Syötä luku 1 aloittaaksesi varaamisen, kiitos!\n";

		while (!(cin >> aloita))
		{
			//Virhesyöte
			cout << " ";
			cin.clear();
			cin.ignore(80, '\n');
		}
	}

	cout << "\n\t\tTervetuloa ajanvarausjärjestelmäämme!\n\n";		//Toinen menu alkaa


	do
	{

		cout << "\t\t1. Varaa huone\n";		//Siirtyy varaamaan huonetta
		cout << "\t\t2. Hae varauksesi\n";			//Varauksen tarkastelu
		cout << "\t\t3. Päätä varaus\n\n";				//Varauksen päättäminen

		cin >> vaihtoehto;
		while (vaihtoehto < 1 || vaihtoehto > 3)
		{
			cout << "Syötä valinta lukuna 1-3, kiitos!\n";
			while (!(cin >> vaihtoehto))
			{
				//Virhesyöte
				cout << " ";
				cin.clear();
				cin.ignore(80, '\n');
			}
		}

		switch (vaihtoehto)
		{
			case 1:		

				do
				{
					cout << "\t\t1. 1 Hengen huone\n";
					cout << "\t\t2. 2 Hengen huone\n\n";
					cin >> vaihtoehto2;

					while (vaihtoehto2 < 1 || vaihtoehto2 > 2)
					{
						cout << "Syötä valinta lukuna 1-2, kiitos!\n";
							while (!(cin >> vaihtoehto2))
							{
								// Virhesyöte
								cout << " ";
								cin.clear();
								cin.ignore(80, '\n');
								cout << endl;
							}
					}
					do
					{
						// Käyttäjä päättää valitseeko hän onman huonenumeronsa vai arvotaanko 1 hengen huone
						cout << "\t\t1. Valitse huonenumero\n";
						cout << "\t\t2. Arvo huonenumero\n\n";
						cin >> vaihtoehto3;

						// Tarkistaa onko syöte merkki vai luku
						tarkista_huone = isdigit(vaihtoehto3);
						while (tarkista_huone == 0)
						{
							// Virhesyöte
							cout << "\nSyötä valinta lukuna 1-2, kiitos!\n";
							cin.clear();
							cin.ignore(80, '\n');
							cin >> vaihtoehto3;
							tarkista_huone = isdigit(vaihtoehto3);
						}

						if (vaihtoehto3 == '1')

						{

							// Käyttäjä valitsee huonenumeron
							cout << "Voit valita huoneen 1-150 väliltä. Syötä huonenumero: ";

							while (!(cin >> v.huone_nro))
							{
								// Virhesyöte
								cout << "Syötä valinta lukuna 1-150, kiitos!\n";
								cin.clear();
								cin.ignore(80, '\n');
								cout << endl;
							}

							// Huonenumeroista puolet eli 1-150 ovat 1 hengen huoeita ja hän voi valita vain niiden numeroiden välillä

							while (v.huone_nro > 150 || v.huone_nro < 1)
							{
								//Virhesyöte
								cout << "Syötä valinta lukuna 1-150, kiitos!\n";
								while (!(cin >> v.huone_nro))
								{
									cout << "Syötä valinta lukuna 1-150, kiitos!\n";
									cin.clear();
									cin.ignore(80, '\n');
									cout << endl;
								}
							}

							// Ohjelma tarkistaa onko huone jo varattu vai onko se varattavissa.
							while (varaus[v.huone_nro].huone_vapaa == true)
							{
								// Huoneen ollessa varattu, tulee seuraava syöte
								cout << "Huone varattu. Kokeile toista huonenumeroa, kiitos!\n";

								while (!(cin >> v.huone_nro))
								{
									//Virhesyöte
									cout << "Syötä valinta lukuna 1-150, kiitos!\n";
									cin.clear();
									cin.ignore(80, '\n');
									cout << endl;
								}

								while (v.huone_nro > 150 || v.huone_nro < 1)
								{
									//Virhesyöte
									cout << "Syötä valinta lukuna 1-150, kiitos!\n";
									while (!(cin >> v.huone_nro))
									{
										cout << "Syötä valinta lukuna 1-150, kiitos!\n";
										cin.clear();
										cin.ignore(80, '\n');
										cout << endl;
									}
								}
							}


							break;
						}

						else if (vaihtoehto3 == '2')

						{
							do
							{
								//Satunnaislukugeneraattori, joka arpoo varaajalle huoneen
								srand(time(0));
								v.huone_nro = 1 + (rand() % 149);

							} while (varaus[v.huone_nro].huone_vapaa == true);

							cout << "\nSait huoneen " << v.huone_nro << endl;

							break;
						}



					} while (true);




					//Tarkistaa, onko huone vapaa
					varaus[v.huone_nro].huone_vapaa = true;

					// push_back-funktio tuo vektorin tiedot VARAUSTIEDOT-osioon
					U_Vector1.push_back(v);

					//Varausnumeron luoja
					varausnumerot = luoSatunnainenVarausnumero(varausnumerot, 0);

					Vector1 = Varaus1(Vector1, "", "", "", 0, 0, 0);

					break;

				
					do
					{
						//Käyttäjä päättää valitseeko hän huonenumeron vain arvotaanko huone
						cout << "\t\t1. Valitse huonenumero\n";
						cout << "\t\t2. Arvo huonenumero\n\n";
						cin >> vaihtoehto3;


						// Tarkistaa onko syöte luku vai merkki
						tarkista_huone = isdigit(vaihtoehto3);
						while (tarkista_huone == 0)
						{
							cout << "Syötä valinta lukuna 1-2, kiitos!\n";
							cin.clear();
							cin.ignore(80, '\n');
							cin >> vaihtoehto3;
							tarkista_huone = isdigit(vaihtoehto3);
						}



						if (vaihtoehto3 == '1')
			
						{
							cout << "\nVoit valita huoneen 151-300 väliltä. Syötä huonenumero: ";
							while (!(cin >> v.huone_nro))
							{
								cout << "Syötä valinta lukuna 151-300, kiitos!\n";
								cin.clear();
								cin.ignore(80, '\n');
								cout << endl;
							}

							// Huonenumeroista puolet eli 151-300 ovat 2 hengen huoeita ja hän voi valita vain niiden numeroiden välillä
							while (v.huone_nro > 300 || v.huone_nro < 151)
							{
								cout << "Syötä valinta lukuna 151-300, kiitos!\n";

								while (!(cin >> v.huone_nro))
								{
									cout << "Syötä valinta lukuna 151-300, kiitos!\n";
									cin.clear();
									cin.ignore(80, '\n');
									cout << endl;
								}
							}

							// Tarkistetaan onko huonenumero jo varattu vai varattavissa
							while (varaus[v.huone_nro].huone_vapaa == true)
							{
								cout << "Huone varattu. Kokeile toista huonenumeroa, kiitos!\n";

								while (!(cin >> v.huone_nro))
								{
									cout << "Syötä valinta lukuna 151-300, kiitos!\n";
									cin.clear();
									cin.ignore(80, '\n');
									cout << endl;
								}

								while (v.huone_nro > 300 || v.huone_nro < 151)
								{
									cout << "Syötä valinta lukuna 151-300, kiitos!\n";

									while (!(cin >> v.huone_nro))
									{
										cout << "Syötä valinta lukuna 151-300, kiitos!\n";
										cin.clear();
										cin.ignore(80, '\n');
										cout << endl;
									}
								}
							}

							break;

						}

						else if (vaihtoehto3 == '2')

						{
							do
							{
								srand(time(0));
								v.huone_nro = 151 + (rand() % 149);

							} while (varaus[v.huone_nro].huone_vapaa == true);

							cout << "\nSait huoneen " << v.huone_nro << endl;

							break;

						}

						break;

					} while (true);
				
					// Tarkistaa, onko huone vapaa
					varaus[v.huone_nro].huone_vapaa = true;

					// push_back-funktio tuo vektorin tiedot VARAUSTIEDOT-osiooN
					U_Vector2.push_back(v);

					// Luo satunnaisen varausnumeron
					varausnumerot = luoSatunnainenVarausnumero2(varausnumerot, 0);

					// Tallentaa 2 hengen huoneen tietoja
					Vector2 = Varaus2(Vector2, "", "", "", 0, 0, 0);

					break;

				} while (true);

				break;

				case 2:	
					
					// Siirtyy varaustietoihin
					// Tässä valinnassa tulostetaan kaikki vektoreihin tallennetut tiedot

					cout << "\n\nVARAUSTIEDOT:\n";

					//Näyttää varaajan tiedot 1 hengen huoneista
					for (int i = 0; i < Vector1.size(); i++)
					{
						cout << "\nVarausnumero #" << varausnumerot[i].varausnumero << endl;
						cout << "Huoneluokka: 1 Hengen huone" << endl << endl;
					
						cout << "Nimi: " << Vector1[i].nimi << endl;		
						cout << "Osoite: " << Vector1[i].osoite << endl;
						cout << "Puhelinnumero: " << Vector1[i].puhelinnumero << endl;
						cout << "Huone: " << U_Vector1[i].huone_nro << endl;
						cout << "Yöt: " << Vector1[i].yöt << endl;
						cout << "Summa: " << Vector1[i].summa << endl << endl;
					}


					//Näyttää varaajan tiedot 2 hengen huoneista
					for (int i = 0; i < Vector2.size(); i++)
					{

						cout << "\nVarausnumero #" << varausnumerot2[i].varausnumero << endl;
						cout << "Huoneluokka: 2 Hengen huone" << endl << endl;

					
						cout << "Nimi: " << Vector2[i].nimi << endl;			
						cout << "Osoite: " << Vector2[i].osoite << endl;
						cout << "Puhelinnumero: " << Vector2[i].puhelinnumero << endl;
						cout << "Huone: " << U_Vector2[i].huone_nro << endl;
						cout << "Yöt: " << Vector2[i].yöt << endl;
						cout << "Summa: " << Vector2[i].summa << endl << endl;
					}

					break;

			case 3:	// Lopettaa ajanvarauksen ja hyvästelee varaajan

			cout << "\n\n" << "\t\tTervetuloa uudestaan ajanvarausjärjestelmäämme!\n\n";

		}



	} while (vaihtoehto != 3);

	

	return 0;

}
// Vektorit tallentavat varaajan tiedot hotellivarauksistaan ja alla ne erikseen 1 ja 2 hengen huoneille.



// Vektori 1 hengen huoneille
vector<LuoVaraus> Varaus1(vector<LuoVaraus> Vector1, string nimi, string osoite, string puhelinnumero,
											int yöt, int summa, int huone_nro)
{
	LuoVaraus v;

	// Varaaja syöttää omat tietonsa ja kuinka monta yötä tahtoo viettää hotellissa
	cout << "\nSyötä koko nimesi: ";
	cin.ignore();
	getline(cin, v.nimi);
	cout << "Syota katuosoite: ";
	getline(cin, v.osoite);
	cout << "Syötä puhelinnumero: ";
	getline(cin, v.puhelinnumero);


	cout << "Syötä öiden määrä: ";
	cin >> v.yöt;
	while (v.yöt < 1)
	{
		cout << "Syötä öiden määrä lukuna, kiitos!\n";

		while (!(cin >> v.yöt))
		{
			cout << "Syötä öiden määrä lukuna, kiitos!\n";
			cin.clear();
			cin.ignore(80, '\n');
		}

	}
	// Lasketaan joko 0%, 10% tai 20% alennus loppusummaan

	double alennus = luoAlennus();
	v.summa = alennus * 100 * v.yöt;
	cout << "\nHuoneesi yhteissummaksi tulee " << v.summa << " euroa.\n";

	// Palauttaa vektoriin tallennetut tiedot VARAUSTIEDOT-osioon

	Vector1.push_back(v);

	return Vector1;

}


// Vektori 2 hengen huoneille
vector<LuoVaraus> Varaus2(vector<LuoVaraus> Vector2, string nimi, string osoite, string puhelinnumero,
											int yöt, int summa, int* huone_nro)

{
	LuoVaraus v;

	// Varaaja syöttää omat tietonsa ja kuinka monta yötä tahtoo viettää hotellissa
	cout << "\nSyötä koko nimesi: ";
	cin.ignore();
	getline(cin, v.nimi);
	cout << "Syota katuosoite: ";
	getline(cin, v.osoite);
	cout << "Syötä puhelinnumero: ";
	getline(cin, v.puhelinnumero);


	cout << "Syötä öiden määrä: ";
	cin >> v.yöt;
	while (v.yöt < 1)
	{
		// Virhesyöte
		cout << "Syötä öiden määrä lukuna, kiitos!\n";
		while (!(cin >> v.yöt))
		{
			cout << "Syötä öiden määrä lukuna, kiitos!\n";
			cin.clear();
			cin.ignore(80, '\n');
		}

	}

	// Lasketaan joko 0%, 10% tai 20% alennus loppusummaan
	double alennus = luoAlennus();
	v.summa = alennus * 150 * v.yöt;

	cout << "\nHuoneesi yhteissummaksi tulee " <<  v.summa << " euroa.\n";

	// Palauttaa vektoriin tallennetut tiedot VARAUSTIEDOT-osioon
	Vector2.push_back(v);

	return Vector2;
}