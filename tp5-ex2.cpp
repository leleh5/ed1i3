#include <iostream>
using namespace std;

#define MAX 5

struct No {
	float dado;
	No *prox;
};

struct Pilha
{
	No *topo;
};

Pilha* init() {
	Pilha *p = new Pilha;
	p->topo = NULL;
	return p;
}

int count(Pilha *p) {
	int i=0;
	No *no;
	no = p->topo;
	while (no != NULL) {
		i++;
		no = no->prox;
	}
	return i;
}

int push(Pilha *p, float v) {
	if((count(p)+1)<=MAX){
		No *no = new No;
		no->dado = v;
		no->prox = p->topo;
		p->topo = no;
		return 1;
	}
	else{return 0;}

}

int isEmpty(Pilha *p) {
	return (p->topo == NULL);
}

void print(Pilha *p) {
	No *no;
	no = p->topo;
	cout << "Qtde: " << count(p) << endl;
	cout << "------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "------" << endl;
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
	} while((count(pilhaFloat)+1)<MAX);
	
	cout << "Qtde: " << count(pilhaFloat) << endl;

	print(pilhaFloat);
	
	return 0;
}