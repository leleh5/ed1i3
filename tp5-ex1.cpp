#include <iostream>
using namespace std;

#define MAX 30

struct Pilha {
	int qtde;
	float elementos[MAX];
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->qtde = 0;
	return p;
};

int push(Pilha *p, float v) {
	int podeEmpilhar = (p->qtde < MAX);
	float ret;
	ret = p->elementos[p->qtde-1];
	if (podeEmpilhar && ret<v) {
		p->elementos[p->qtde++] = v;
	}
	else{podeEmpilhar=0;}
	return podeEmpilhar;
}

int count(Pilha *p) {
	return (p->qtde);
}

int isEmpty(Pilha *p) {
	return (p->qtde == 0);
}

void print(Pilha *p) {
	for(int i = p->qtde-1; i>=0; --i) {
		cout << p->elementos[i] << endl;
	}
	cout << "----------" << endl;
}

int main(int argc, char** argv)
{
	Pilha *pilhaFloat;
	pilhaFloat = init();
	float valor;
	int cond;
	cout << "Pilha vazia: " << (isEmpty(pilhaFloat)?"SIM":"NAO") << endl;
	do{
		cout << "Digite o número: " << endl;
		cin >> valor;
		cond = push(pilhaFloat, valor);
		cout << "Empilhado: " << (cond?"SIM":"NAO") << endl;
	} while(count(pilhaFloat)<MAX);
	
	cout << "Qtde: " << count(pilhaFloat) << endl;
	print(pilhaFloat);
	
	return 0;
}