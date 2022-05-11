#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Data
{
	private:
		int dia;
		int mes;
		int ano;

	public:
		Data(int dia, int mes, int ano)
		{
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}

		Data()
		{
			this->dia = 28;
			this->mes = 9;
			this->ano = 1962;
		}

		void setDia(int dia)
		{
			this->dia = dia;
		}

		void setMes(int mes)
		{
			this->mes = mes;
		}

		void setAno(int ano)
		{
			this->ano = ano;
		}

		int getDia()
		{
			return this->dia;
		}

		int getMes()
		{
			return this->mes;
		}
		
		int getAno()
		{
			return this->ano;
		}

		string getData()
		{
			return to_string(this->dia) + "/" +
			   to_string(this->mes) + "/" +
			   to_string(this->ano);
		}
		

};

class Contato
{
	private:
		string email;
		string nome;
		string telefone;
		Data *dtnasc_c;

	public:
		Contato()
		{
			this->email = "";
			this->nome = "";
			this->telefone = "";
		}

		Contato(string email, string nome, string telefone, Data *dtnasc_p)
		{
			this->dtnasc_c =  dtnasc_p;
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
		}

		void setEmail(string email)
		{
			this->email = email;
		}

		void setNome(string nome)
		{
			this->nome = nome;
		}

		void setTelefone(string telefone)
		{
			this->telefone = telefone;
		}

		void setDtnasc(Data *dtnasc)
		{
			this->dtnasc_c = dtnasc;
		}
						
		string getEmail()
		{
			return this->email;
		}

		string getNome()
		{
			return this->nome;
		}

		string getTelefone()
		{
			return this->telefone;
		}
		
		Data *getDtnasc()
		{
			return this->dtnasc_c;
		}
		
		int Idade(Data *hoje)
		{
			return hoje->getAno()-dtnasc_c->getAno();
		}
};

int main(int argc, char** argv)
{
	Data *hoje = new Data(10, 5, 2022);

	string email;
	string nome;
	string telefone, dtnasc;
	int i=0, media=0, qt_m_idad=0, maior_idade=0;
	
	Contato *pessoa[10];
	
	while(i<10){	

		cout << "Escreva seu email:";
		cin >> email;
		cout << endl;

		cout << "Escreva seu nome:";
		cin >> nome;
		cout << endl;

		cout << "Escreva seu telefone:";
		cin >> telefone;
		cout << endl;

		cout << "Escreva seu dtnasc:";
		cin >> dtnasc;
		cout << endl;
		
		Data *nasc = new Data(stol(dtnasc.substr(0,2)),stol(dtnasc.substr(3,2)),stol(dtnasc.substr(6,4)));

		Contato *contato = new Contato(email, nome, telefone, nasc);
		
		pessoa[i] = contato; 
		
		i++;
	}
	
	for(int j=0; j<10; j++){
		media += pessoa[j]->Idade(hoje);
		if(pessoa[j]->Idade(hoje)>18){
			qt_m_idad+pessoa[j]+;
		}
		
		if(pessoa[j]->Idade(hoje)>maior_idade){
			maior_idade = pessoa[j]->Idade(hoje);
		}
	}
	
	media = media/10;
	
	cout << "Media: " << media << endl;
	
	for(int j=0; j<10; j++){
		if(pessoa[j]->Idade(hoje)>media){
			cout << pessoa[j]->getNome() << endl;
		}
	}
	
	cout << "Contatos maiores de idade: " << qt_m_idad << endl;	
	
	cout << "Contato de maior idade: " << endl;
	
	for(int j=0; j<10; j++){
		if(pessoa[j]->Idade(hoje) == maior_idade){
			cout << "Nome: " << pessoa[j]->getNome() << endl;
			cout << "Email: " << pessoa[j]->getEmail() << endl;
			cout << "Telefone: " << pessoa[j]->getTelefone() << endl;
		}
	}
	
	return 0;
}