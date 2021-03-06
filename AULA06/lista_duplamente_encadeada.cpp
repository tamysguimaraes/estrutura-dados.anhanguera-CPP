#include <iostream>
#include <strings.h>
#include <conio.h>
#include <limits>
#include <locale.h>

using namespace std;

struct alunos
{
	char nome[100];
	int idade;
	alunos *proximo;
	alunos *anterior;
} *lista_alunos;

void iniciar_lista();
void inserir_aluno();
void listar_alunos();
void menu();
void limpar_teclado();

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int opcao = -1;
	iniciar_lista();
	while (opcao != 0)
	{
		menu();
		cin >> opcao;
		
		if (opcao == 1)
			inserir_aluno();
		else if (opcao == 2)
			listar_alunos();
	}
	delete lista_alunos;
}

void iniciar_lista()
{
	lista_alunos = NULL;
}

void inserir_aluno()
{
	system("cls");
	cout << "1 - INSERIR ALUNOS" << endl << endl;
	
	limpar_teclado();
	alunos *novo_aluno = new alunos;
	
	cout << "Digite o nome do aluno:" << endl;
	gets(novo_aluno->nome);
	
	cout << "Digite a idade do aluno:" << endl;
	cin >> novo_aluno->idade;
	
	novo_aluno->proximo = NULL;
	novo_aluno->anterior = NULL;
	
	if (lista_alunos == NULL)
		lista_alunos = novo_aluno;
	else 
	{
		alunos *p;
		p = lista_alunos;
		
		while (p->proximo != NULL)
			p = p->proximo;
		
		p->proximo = novo_aluno;
		novo_aluno->anterior = p;
	}
	cout << endl << "Aluno inserido com sucesso." << endl;
	cout << "Pressione uma tecla para continuar..." << endl;
	getch();	
}

void listar_alunos()
{
	system("cls");
	cout << "2 - LISTAR ALUNOS" << endl << endl;
	
	if (lista_alunos == NULL)
	{
		cout << "Nenhum aluno cadastrado." << endl;
		cout << "Pressione uma tecla para continuar..." << endl;
		getch();		
		return;
	}
	
	alunos *p;
	p = lista_alunos;
	
	if (p->proximo == NULL) 
	{
		cout << "------------------------------------" << endl;
		cout << "Nome do Aluno:" << p->nome << endl;
		cout << "Idade do Aluno:" << p->idade << endl;
		cout << "------------------------------------" << endl;
	}
	else
	{
		while (p != NULL)
		{
			cout << "------------------------------------" << endl;
			cout << "Nome do Aluno:" << p->nome << endl;
			cout << "Idade do Aluno:" << p->idade << endl;
			if (p->proximo != NULL)
				cout << "Proximo:" << p->proximo->nome << endl;
			else 
				cout << "Proximo: NULO" << endl;
				
			if (p->anterior != NULL)				
				cout << "Anterior:" << p->anterior->nome << endl;
			else
				cout << "Anterior: NULO" << endl;
			
			cout << "------------------------------------" << endl;
			p = p->proximo;
		}
	}
	cout << endl << "Pressione uma tecla para continuar..." << endl;
	getch();
}

void menu()
{
	system("cls");
	cout << "1 - INSERIR ALUNOS" << endl;
	cout << "2 - LISTAR ALUNOS" << endl;
	cout << "0 - SAIR" << endl;
	cout << "Digite uma op��o: ";
}

void limpar_teclado()
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
