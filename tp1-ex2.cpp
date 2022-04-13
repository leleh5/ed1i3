#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;


#define LIN 4
#define COL 11

void mostra_maos(char **maos)
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