#include "stdafx.h"
#include <fstream>
using namespace std;

namespace In
{
	IN getin(wchar_t infile[])
	{
		IN stuct;
		int pos = 0;
		ifstream fin(infile);
		unsigned char* text = new unsigned char[IN_MAX_LEN_TEXT];
		unsigned char buf;

		if (fin.fail())
		{
			cout << "Файл с таким именем не может быть открыт\n";
			throw ERROR_THROW(110);
		}
		else
		{
			buf = fin.get();
			while (stuct.size < IN_MAX_LEN_TEXT)
			{
				if (fin.eof())
				{
					text[stuct.size] = '\0';
					break;
				}
				if (buf == IN_CODE_ENDL)
				{
					stuct.lines++; pos++;
					text[stuct.size] = '\n';
					stuct.size++;
					pos = 0;
				}
				else if (stuct.code[(int)buf] == IN::T)
				{
					text[stuct.size] = buf;
					stuct.size++;
					pos++;
				}
				else if (stuct.code[(int)buf] == IN::F)
				{
					throw ERROR_THROW_IN(111, pos, stuct.lines)
				}
				else if (stuct.code[(int)buf] == IN::I)
				{
					stuct.ignor++;
				}
				else
				{
					text[stuct.size] = stuct.code[(int)buf];
					stuct.size++;
				}

				buf = fin.get();
			}
		}
		fin.close();

		SpaceClear((char*)text);
		text = (unsigned char*)MoreReadable((char*)text);
		Clear((char*)text);



		//Separator((char*)text);

		stuct.text = text;
		return stuct;
	}

	void SpaceClear(char* text)
	{
		for (int i = 0; i < strlen(text); i++)
		{
			if (text[i] == ' ' && text[i - 1] == '\n')
			{
				DeleteSymb(text, i);
			}
			if (text[i] == ' ' && text[i - 1] == ' ')
			{
				DeleteSymb(text, i);
			}
			if (text[i] == '\n' && text[i - 1] == ' ' && text[i - 2] == ',')
			{
				DeleteSymb(text, i);
			}
			if (text[i] == '\n' && text[i - 1] == '\n')
			{
				DeleteSymb(text, i);
			}
		}
	}

	void DeleteSymb(char* text, int& pos)
	{
		for (int i = pos; i < strlen(text); i++)
		{
			text[i] = text[i + 1];
		}
		pos--;
	}

	char* MoreReadable(char* text)
	{
		char* buferText = new char[strlen(text) * 2];
		for (int i = 0, j = 0; i < strlen(buferText); i++, j++)
		{
			if (text[i] != ' ' && (text[i + 1] == ';' || text[i + 1] == ',' || text[i + 1] == '(' || text[i + 1] == ')' || text[i + 1] == '{'
				|| text[i + 1] == '}' || text[i + 1] == '+' || text[i + 1] == '-' || text[i + 1] == '=' || text[i + 1] == '/' || text[i + 1] == '*' || text[i + 1] == '\'' || text[i+1] == '`' || text[i + 1] == '\"'))
			{
				buferText[j] = text[i];
				buferText[j + 1] = ' ';
				j++;
			}
			else
			{
				buferText[j] = text[i];
			}
			if (text[i + 1] != ' ' && (text[i] == ';' || text[i] == ',' || text[i] == '(' || text[i] == ')' || text[i] == '{'
				|| text[i] == '}' || text[i] == '+' || text[i] == '-' || text[i] == '=' || text[i] == '/' || text[i] == '*' || text[i] == '\'' || text[i] == '`' || text[i] == '\"'))
			{
				buferText[j] = text[i];
				buferText[j + 1] = ' ';
				j++;
			}
		}
		return buferText;

	}

	void Clear(char* text)
	{
		for (int i = 0; i < strlen(text); i++)
		{
			if ((text[i + 1] == ';' || text[i + 1] == ',' || text[i + 1] == '(' || text[i + 1] == ')' || text[i + 1] == '{'
				|| text[i + 1] == '}' || text[i + 1] == '+' || text[i + 1] == '-' || text[i + 1] == '=' || text[i + 1] == '/' || text[i + 1] == '*' || text[i + 1] == '\'' || text[i+1] == '`' || text[i + 1] == '\"') && text[i] == text[i + 1] )
			{
				DeleteSymb(text, i);
			}
			/*if (text[i - 1] == '\n' && text[i] == ' ')
			{
				DeleteSymb(text, i);
			}*/
		}
		text[strlen(text)] = '\0';
	}
}
