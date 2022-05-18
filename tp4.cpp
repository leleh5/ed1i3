#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class Funcionario
{
	private:
		int prontuario;
		string nome;
		double salario;

	public:
		Funcionario(int prontuario, string nome, double salario)
		{
			this->prontuario = prontuario;
			this->nome = nome;
			this->salario = salario;
		}

		Funcionario()
		{
			this->prontuario = 0;
			this->nome ="";
			this->salario = 0.0;
		}
		
		void setProntuario(int prontuario)
		{
			this->prontuario = prontuario;
		}

		int getProntuario()
		{
			return this->prontuario;
		}
		
		void setNome(string nome)
		{
			this->nome = nome;
		}

		string getNome()
		{
			return this->nome;
		}
		
		void setSalario(double salario)
		{
			this->salario = salario;
		}

		int getSalario()
		{
			return this->salario;
		}
		
		string getFuncionario()
		{
			return to_string(this->prontuario) + nome + to_string(this->salario);
		}
		

		
		/*set()
		{
			
		}
		
		Pesquisar()
		{
			
		}*/
	 };	

		int main(int argc, char** argv)
		{
			
			int opcao;
			int prontuario;
			string nome;
			double salario;	
			
			int k=0;		
						
		
			do{
	  	          cout << "0. Sair:" << endl;
				  cout << "1. Incluir" << endl;
  			      cout << "2. Excluir:" << endl;
 	  	  	  	  cout << "3. Pesquisar:" << endl;
				  cout << "4. Listar:" << endl;
				  cin >> opcao;
				  
				  switch(opcao)
				  {
					case 1:
						
						{
							
						Funcionario *func[1];
								
						cout << "Digite o prontuario do funcionario:" << endl;
						cin >> prontuario;
						cout << "Digite o nome do funcionario:" << endl;
						cin >> nome;
						cout << "Digite o Salario:" << endl;
						cin >> salario;
						Funcionario *funcionario = new Funcionario(prontuario,nome,salario);
						
						func[prontuario] = funcionario; 
						
						k++;
						
						//cout << func.size() << endl;
					
						}
				
						break;
					
						
				/*	case 2: 
						{
						

					
						}
					
						break;

				*/	
							
					case 4: 
					{
						for(int i=0;i<=1;i++){
							
							
							
						}
					
					}	
					
					 break;						
					
					   
					   default:{
					   	
						   	cout << "Opção Invalida." << endl;
					   }
					   
					   
					   
				  }
				return 0;
				
			}while(opcao !=0);
			
			
	}



	
		
		
		
		