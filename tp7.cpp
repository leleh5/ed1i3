#include <iostream>
using namespace std;

void insertion_sort(int t, int *a)
{
	int aux;
	for(int i=0; i<t-1; ++i)
	{	 
		int j=i;
		
		cout << "a[" << j+1 << "]: " << a[j+1] << ", "
		     << "a[" << j << "]: " << a[j] << endl;
		     
		while(a[j+1] < a[j])
		{		     
			aux = a[j+1];
			a[j+1] = a[j];
			a[j] = aux;
			cout << " -- Trocou --" << endl;
			if(j!=0){
				j--;
				cout << "a[" << j+1 << "]: " << a[j+1] << ", "
		     << "a[" << j << "]: " << a[j] << endl;
			}
		}
		cout << endl;
	}
	cout << "-------" << endl;
}

void print(int t, int *a)
{
	for(int i=0; i<t; ++i)
	{
		cout << "a[" << i << "]: " << a[i] << endl;
	}
	cout << "-------" << endl;
}

int main(int argc, char** argv)
{
	int v[8] = {49, 38, 58, 87, 34, 93, 26, 13};
	print(8, v);
	insertion_sort(8, v);
	print(8, v);
	
	return 0;
}