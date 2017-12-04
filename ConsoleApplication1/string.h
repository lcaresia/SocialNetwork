#pragma once

#include <iostream>
#include <string>
#include "string.h"

using namespace std;

/*template<typename T>
T insertInArray(*T currentArray, int currentQuantity, *T value) {
	T *tempArray = new T[currentQuantity + 1];

	for (int i = 0; i < currentQuantity; i++)
	{
		tempArray[i] = currentArray[i];
	}

	tempArray[currentQuantity] = value;

	return tempArray;
}*/

string replace(string txt, string target, string to) {
	for (int i = 0; i < (txt.length() - target.length()); i++)
	{
		if(txt.substr(i, target.length()) == target) {
			txt.replace(i, target.length(), to);
		}
	}

	cout << endl << endl << txt << endl << endl;
	return txt;
}

string *getWordAfter(string txt, string target) {
	int found = 0;
	string *found_words = new string[found];

	for (int i = 0; i < (txt.length() - target.length()); i++)
	{
		if (txt.substr(i, target.length()) == target) {
			string txt_found = "";

			for (int j = i+1; txt.substr(j, 1) != " " && j < txt.length() && j > 0; j++)
			{
				txt_found += txt.substr(j, 1);
			}

			//insertInArray[string](found_words, found, txt_found);
			string *tempArray = new string[found + 1];

			for (int k = 0; k < found; k++)
			{
				tempArray[k] = found_words[k];
			}

			tempArray[found] = txt_found;

			found_words = tempArray;
			found++;
		}
	}

	return found_words;
}

string *getWordBefore(string txt, string target) {
	int found = 0;
	string *found_words = new string[found];

	txt = " " + txt;

	for (int i = 0; i < (txt.length() - target.length()); i++)
	{
		if (txt.substr(i, target.length()) == target) {
			int j = i - 1;
			string txt_found = "";

			for (int j = i - 1; txt.substr(j, 1) != " " && j < txt.length() && j >= 0; j--)
			{
				txt_found = txt.substr(j, 1) + txt_found;
			}

			//insertInArray[string](found_words, found, txt_found);
			string *tempArray = new string[found + 1];

			for (int k = 0; k < found; k++)
			{
				tempArray[k] = found_words[k];
			}

			tempArray[found] = txt_found;

			found_words = tempArray;
			found++;
		}
	}

	return found_words;
}