#include <iostream>
using namespace std;

struct No {
	float dado;
	No *prox;
};

struct Fila {
	No *ini;
	No *fim; 
};

Fila* init() {
	Fila *f = new Fila;
	f->ini = NULL;
	f->fim = NULL;
	return f;
}

int isEmpty(Fila *f) {
	return (f->ini == NULL);
}

int count(Fila *f) {
	int qtde = 0;
	No *no;
	no = f->ini;
	while (no != NULL) {
		qtde++;
		no = no->prox;
	}
	return qtde;
}

void print(Fila *f) {
	No *no;
	no = f->ini;
	cout << "-------------" << endl;
	while (no != NULL) {
		cout << no->dado << endl;
		no = no->prox;
	}
	cout << "-------------" << endl;
}

void enqueue(Fila *f, float v) {
	No *no = new No;
	no->dado = v;
	no->prox = NULL;
	if (isEmpty(f)) {
		f->ini = no;
	}
	else {
		f->fim->prox = no;
	}
	f->fim = no;
}

float dequeue(Fila *f) {
	float ret;
	if (isEmpty(f)) {
		ret = -1;
	}
	else {
		No *no = f->ini;
		ret = no->dado;
		f->ini = no->prox;
		if (f->ini == NULL) {
			f->fim = NULL;
		}
		free(no);
	}
	return ret;
}

void freeFila(Fila *f) {
	No *no = f->ini;
	while (no != NULL) {
		No *temp = no->prox;
		free(no);
		no = temp;
	}
	free(f);
}

int main(int argc, char** argv)
{
	Fila *senhasGeradas;
	senhasGeradas = init();
	Fila *senhasAtendidas;
	senhasAtendidas = init();
	int c, valor;
	float aux;
	
	do{
		aux = 0.0;
		cout << "Escolha uma opcao: " << endl;
		cout << "0. Sair" << endl;
		cout << "1. Gerar senha" << endl;
		cout << "2. Realizar atendimento"<< endl;
		cin >> valor;
		
		if(valor==1){
			enqueue(senhasGeradas, 1.0);
			c++;
			cout << "Enfileirou +1" << endl;
		}
		else if(valor==2){
			if(isEmpty(senhasGeradas)){
				cout << "Fila vazia, digite outra opcao." << endl;
			}
			else{
				aux = dequeue(senhasGeradas);
				cout << "Atendeu: " << aux << endl;
				enqueue(senhasAtendidas, aux);
			}	
		}
		cout << "Quantidade de senhas ainda aguardando atendimento: " << count(senhasGeradas) << endl;
	} while((count(senhasGeradas)>0) || (valor=0));
	
	cout << "Senhas atendidas:" << count(senhasAtendidas) <<endl;
			
	return 0;
}