#include <iostream>
#include <string.h>
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

	/*string getData()
	{
		return to_string(this->dia) + "/" +
			   to_string(this->mes) + "/" +
			   to_string(this->ano);
	}
	*/

};

class Contato
{
	private:
		string email;
		string nome;
		string telefone;
		string dtnasc;

	public:
		Contato()
		{
			this->email = "";
			this->nome = "";
			this->telefone = "";
		}

		Contato(string email, string nome, string telefone, string dtnasc_p)
		{
			this->dtnasc =  dtnasc_p;
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

		void setDtnasc(string dtnasc)
		{
			this->dtnasc = dtnasc;
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
		
		string getDtnasc()
		{
			return this->dtnasc;
		}
		
		int Idade(string dtnasc_p, Data *hoje)
		{
			Data *nasc = new Data(stol(dtnasc_p.substr(0,2)),stol(dtnasc_p.substr(3,2)),stol(dtnasc_p.substr(6,4)));
	
			return hoje->getAno()-nasc->getAno();	
		}
};

int main(int argc, char** argv)
{
	Data *hoje = new Data(3, 5, 2022);

	string email;
	string nome;
	string telefone, dtnasc;
	int i=0;
	
	while(i<5){	

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

		Contato *contato = new Contato(email, nome, telefone, dtnasc);
	
		cout << contato->getNome() << endl;
	
		cout << contato->getEmail() << endl;
	
		cout << contato->getTelefone() << endl;

		cout << contato->Idade(contato->getDtnasc(),hoje) << endl;
	}
	
		return 0;
}