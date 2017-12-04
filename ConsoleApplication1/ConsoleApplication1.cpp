// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "backend.h"
#include <conio.h>
#include <windows.h>
#include "string.h"

using namespace std;

void interfaceRegister(SocialNetwork &sn) {
	int option = 0;

	system("cls");
	string email = "";
	string name;
	string password;
	string confirmpassword;
	int year;
	string genre;

	do {
		if (email != "")
		{
			Sleep(2500);
		}

		system("cls");
		cout << "Email: ";
		cin >> email;
		cout << endl;
		cout << "Nome: ";
		cin >> name;
		cout << endl;
		cout << "Senha: ";
		cin >> password;
		cout << endl;
		cout << "Confirmar senha: ";
		cin >> confirmpassword;
		cout << endl;
		cout << "Ano de nascimento: ";
		cin >> year;
		cout << endl;
		cout << "Genêro(Mm | Ff): ";
		cin >> genre;
		cout << endl;

	} while (!validate(sn, email, name, password, confirmpassword, year, genre));

	User user = registerUser(sn, email, name, password);

	cout << "Suas informações: " << endl;
	cout << "Email: " << user.email << endl;
	cout << "Nome: " << user.name << endl;
	cout << "Senha: " << user.password << endl;

	Sleep(2000);
}

void interfacePost(SocialNetwork &sn);
void interfaceMain(SocialNetwork &sn);

void interfaceTimeline(SocialNetwork &sn) {
	int option = NULL;

	do {
		system("cls");
		listPosts(sn);

		cout << "1 - Escrever um post" << endl;
		cout << "2 - Sair da conta" << endl;

		cin >> option;
	} while (option < 1 || option > 2);

	if (option == 1) {
		interfacePost(sn);
	}
	else if (option == 2) {
		loggout(sn);
		interfaceMain(sn);
	}
}

void interfacePost(SocialNetwork &sn) {
	system("cls");
	string content;

	do {
		system("cls");
		cout << "Conteudo do post: " << endl;
		getline(cin, content);
		cout << endl;
	} while (!writePost(sn, sn.current_user, replace(content, " ", "_")));

	cout << endl << "Todos já podem ver seu post, sua timeline está sendo carregada..." << endl;

	Sleep(2000);

	interfaceTimeline(sn);
}

void interfaceLogged(SocialNetwork &sn) {
	int option = NULL;

	do {
		system("cls");
		cout << "Bem vindo ao CaraLivro " << sn.current_user.name << endl << endl;
		cout << "1 - Ver Timeline" << endl;
		cout << "2 - Escrever um post" << endl;
		cout << "3 - Sair da conta" << endl;

		cin >> option;
	} while (option < 1 || option > 3);

	if (option == 1) {
		interfaceTimeline(sn);
	}
	else if (option == 2) {
		interfacePost(sn);
	}
	else if (option == 3) {
		loggout(sn);
		interfaceMain(sn);
	}
}

void interfaceLogin(SocialNetwork &sn) {
	int option = NULL;

	system("cls");
	string email = "";
	string password;

	do {
		if (email != "")
		{
			Sleep(3000);
		}

		system("cls");
		cout << "Email: ";
		cin >> email;
		cout << endl;
		cout << "Senha: ";
		cin >> password;
		cout << endl;
	} while (!login(sn, email, password));
	
	interfaceLogged(sn);
}

void interfaceMain(SocialNetwork &sn) {
	int option = NULL;

	if(sn.current_user.email != "") {
		interfaceLogged(sn);
	}

	do {
		system("cls");
		cout << "Bem vindo ao CaraLivro " << endl << endl;
		cout << "1 - Entrar" << endl;
		cout << "2 - Cadastrar" << endl;
		cout << "3 - Fechar o programa" << endl;

		cin >> option;
	} while (option < 1 || option > 3);

	if (option == 1) {
		interfaceLogin(sn);
	}
	else if (option == 2) {
		interfaceRegister(sn);
	}
	else if (option == 3) {
		system("cls");
		exit(0);
	}
}

int main()
{
	string *words = getWordAfter("camila@camila e fulano@fulano em tal lugar, tambem junto com o matheus@matheus", "@");

	for (int i = 0; i < 3; i++)
	{
		cout << words[i] << endl;
	}

	system("pause");

	setlocale(LC_ALL, "PORTUGUESE");

	bool pre_load_users_posts = true;

	SocialNetwork sn;
	bool running = true;

	if (pre_load_users_posts) {
		load_random_users_posts(sn, 3, 5);
	}

	do {
		interfaceMain(sn);
	} while(running);

	system("pause");

    return 0;
}



