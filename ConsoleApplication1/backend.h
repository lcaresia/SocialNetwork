#pragma once

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"

using namespace std;

struct User {
	string email;
	string name;
	string password;

	User(){}

	User(string email, string name, string password) {
		this->email = email;
		this->name = name;
		this->password = password;
	}
};

struct Post {
	User author;
	string content;

	Post() {}

	Post(User author, string content) {
		this->author = author;
		this->content = content;
	}
};

struct SocialNetwork {
	User current_user;
	int usersQuantity = 0;
	int postsQuantity = 0;
	User *users = new User[usersQuantity];
	Post *posts = new Post[postsQuantity];
};

string crypto(string password) {
	return password;
}

User registerUser(SocialNetwork &sn, string email, string name, string password) {
	User user = User(email, name, crypto(password));

	User *tempusers = new User[sn.usersQuantity + 1];

	for(int i = 0; i < sn.usersQuantity; i++)
	{
		tempusers[i] = sn.users[i];
	}

	tempusers[sn.usersQuantity] = user;

	sn.usersQuantity++;
	sn.users = tempusers;

	return user;
}

bool existsEmail(SocialNetwork &sn, string email) {
	for (int i = 0; i < sn.usersQuantity; i++)
	{
		if (sn.users[i].email == email) {
			return true;
		}
	}

	return false;
}

bool validate(SocialNetwork &sn, string email, string name, string password, string confirmpassword, int year, string genre) {
	if(existsEmail(sn, email)) {
		cout << "Esse email já existe.";
		return false;
	}

	if(name.length() < 3) {
		cout << "Seu nome precisa ter pelo menos 3 caracteres.";
		return false;
	}

	if(password.length() < 6) {
		cout << "Sua senha precisa ter pelo menos 6 digitos.";
		return false;
	}

	if (password != confirmpassword) {
		cout << "Você precisa digitar a confirmação de senha igual a senha.";
		return false;
	}

	if (year > 1999) {
		cout << "Você precisa ter 18 anos para de cadastrar";
		return false;
	}

	if (genre != "M" && genre != "m" && genre != "F" && genre != "f") {
		cout << "Você precisa ser do genêro masculino ou feminino (Mm | Ff)";
		return false;
	}

	return true;
}
User findUser(SocialNetwork &sn, string email) {
	for (int i = 0; i < sn.usersQuantity; i++)
	{
		if (sn.users[i].email == email) {
			return sn.users[i];
		}
	}
}

bool login(SocialNetwork &sn, string email, string password) {
	if (!existsEmail(sn, email)) {
		cout << "Esse email não está cadastrado" << endl;
		return false;
	}

	if (findUser(sn, email).password != crypto(password)) {
		cout << "O email ou senha estão incorretos" << endl;
		return false;
	}

	sn.current_user = findUser(sn, email);
	return true;
}

bool writePost(SocialNetwork &sn, User author, string content) {
	Post post = Post(author, content);

	Post *tempposts = new Post[sn.postsQuantity + 1];

	for (int i = 0; i < sn.postsQuantity; i++)
	{
		tempposts[i] = sn.posts[i];
	}

	tempposts[sn.postsQuantity] = post;

	sn.postsQuantity++;
	sn.posts = tempposts;

	return true;
}

void listPosts(SocialNetwork &sn) {
	for (int i = sn.postsQuantity-1; i >= 0; i--)
	{
		cout << endl << "Postado por: " << sn.posts[i].author.name << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl;
		cout << sn.posts[i].content << endl;
		cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;
	}
}

bool loggout(SocialNetwork &sn) {
	sn.current_user = User();

	return true;
}

void load_random_users_posts(SocialNetwork &sn, int usersQuantity, int postsQuantity) {
	srand(time(NULL));

	string text_default = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc pharetra rutrum sem vitae auctor. In malesuada tristique vulputate. Nam semper libero augue, non ultrices eros malesuada et. Maecenas rhoncus dolor lorem, sed suscipit ex tincidunt a. Sed vel eros lacinia, efficitur tellus in, aliquam eros. Suspendisse neque nisi, vestibulum sit amet libero a, viverra tempor ipsum. Duis pharetra quam non pharetra vestibulum. Vivamus bibendum nunc sit amet vulputate euismod. Interdum et malesuada fames ac ante ipsum primis in faucibus. Interdum et malesuada fames ac ante ipsum primis in faucibus. Donec pharetra nibh vitae magna finibus volutpat. Quisque dictum lectus ut pharetra volutpat. Duis eu nulla dui.Maecenas at quam vitae enim aliquam tincidunt ut et ipsum.Sed iaculis quam vitae sapien vehicula, sit amet congue velit efficitur.Integer vehicula efficitur nulla id rhoncus.Integer suscipit facilisis elit, rutrum egestas eros dapibus sed.Sed eget magna nisi.Fusce sed ante at augue feugiat egestas.Donec posuere enim ut lorem suscipit, commodo porta est suscipit.Nulla sit amet lectus neque.Sed viverra maximus dolor, in rhoncus lacus pellentesque non.Praesent non semper mi.In arcu nibh, venenatis sit amet sem at, viverra dictum elit.";

	for (int i = 0; i < usersQuantity; i++)
	{
		string userCode = to_string(rand() % 10000);
		User user = registerUser(sn, "user" + userCode, "user" + userCode, "pass" + userCode);

		for (int j = 0; j < postsQuantity; j++)
		{

			int start = rand() % text_default.length();
			int end = rand() % (text_default.length() - start) + start;

			writePost(sn, user, text_default.substr(start, end));
		}
	}

	sn.current_user = sn.users[rand() % sn.usersQuantity];
}