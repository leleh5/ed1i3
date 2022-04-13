#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

using namespace std;


#define B 2
#define N 4
#define C 13

int main(){
	int ***m, b, n, c, k=1;
	
	// mapa inicial:
	m = new int**[2];
	
	for(int i=0; i<2; ++i) // Percorre os baralhos
	{
		m[i] = new int*[4]; // Inicialização de cada nipe
	}
	
	for(int i=0; i<2; ++i) // Percorre os baralhos
	{
		for(int j=0; j<4; ++j) // Percorre os nipes
		{
			m[i][j] = new int[13]; // Inicialização de cada carta
		}
	}
	// Fim da declaração do array
	
	for(int i=0; i<2; ++i)
	{
		for(int j = 0; j<4; ++j)
		{
			for(int z = 0; z<13; ++z){
				m[i][j][z] = 0;
			}	
		}
	}
	
	//Mostrar mãos
	srand(time(0));
	
	for(int i=0; i<4; ++i)
	{
		k=1;
		for(int j = 0; j<11; ++j)
		{
			do{
				b = rand() % (1+1-0)+0;
				n = rand() % (3+1-0)+0;
				c = rand() % (12+1-1)+0;
				
				if(m[b][n][c]==0){
					cout << (n+1) <<'-'<<(c+1)<<'-'<<(b+1)<<" | ";
					m[b][n][c]=1;
					
					k=3;
				}	
			}while(k!=3);
		}
		cout << endl;
	}
		
}