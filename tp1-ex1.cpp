#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;


#define LIN 15
#define COL 40

void mapa_ocup(char **pol)
{
    for(int i=0; i<LIN; ++i)
	{
		for(int j = 0; j<COL; ++j)
		{
			cout << setw(1) << pol[i][j] << "|";
		}
		cout << endl;
	}
}

int main()
{
	int op = 4, f, p, qt_l_o, v_f=0;
	int res;
	float bil=0;
	
	char **pol;
	
	stringstream ss;
	
	// mapa inicial:
	pol = new char*[15];
	
	for(int i=0; i<LIN; ++i) // Percorre as linhas
	{
		pol[i] = new char[40]; // Inicialização de cada coluna
	}
	// Fim da declaração do array
	
	for(int i=0; i<LIN; ++i)
	{
		for(int j = 0; j<COL; ++j)
		{
			pol[i][j] = '.';
		}
	}

	do
	{
		cout << "Escolha uma das opcoes: \n 0. Finalizar \n 1. Reservar poltrona \n 2. Mapa de ocupacao \n 3. Faturamento \n";
		
		cin >> op;
		
		cout << endl;
		
		switch(op)
		{
			case 1:
				cout << "Escolha uma poltrona da seguinte forma: numero da fileira, com 2 digitos e numero da poltrona, com 2 digitos. Ex: 0101 \n";
				cin >> res;
				cout << endl;
				p=res%100;
				p=p-1;
				f=(res-p)/100;
				f=f-1;
					
				if(pol[f][p]=='.'){
					pol[(f)][p]= '#';
				}
					
				else{cout << "Poltrona ja reservada." << endl;}
					
				break;
			
			case 2:
				mapa_ocup(pol);
				break;
			
			case 3:
				for(int i=0; i<LIN; ++i)
				{
					if(i<6){
						v_f=5;
					}
					else if(i<11){
						v_f=30;
					}
					else{
						v_f=15;
					}
					for(int j = 0; j<COL; ++j)
					{
						if(pol[i][j] == '#'){
							bil+=v_f;
						}
					}
				}
				cout << "Quantidade de lugares ocupados: " << qt_l_o << endl;
				cout << "Bilheteria: "<< bil << endl;
				break;
		}
		
		
	}while(op!=0);

	return 0;
}