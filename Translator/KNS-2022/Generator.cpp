#include "stdafx.h"

namespace Generator {
	void generateCode(Lexical::Lexic& tables, char* outfile) {
		std::ofstream out(outfile);
		char concat[] = "concat";
		char copystr[] = "copystr";
		int funcType = 0;
		bool showFlag = false;
		bool ifFlag = false;
		bool parmFlag = false;
		int stringCounters = 1;

		if (!out.is_open()) {											//проверка на открытие файла иначе ошибка
			throw ERROR_THROW(113);
		}
		for (int i = 0; i < tables.Lex.size; i++)
		{
			switch (tables.Lex.table[i].lexema[0])
			{
			case LEX_FUNCTION: {
				out << "function ";
				i++;
				while (tables.Lex.table[i].lexema[0] != 'f' && tables.Lex.table[i].lexema[0] != 'p' && tables.Lex.table[i].lexema[0] != 'm') {
					i++;
					if (tables.Lex.table[i].lexema[0] == 'i' && strcmp(tables.Id.table[tables.Lex.table[i].idxTI].id, concat) == 0) {
						if (tables.Lex.table[i + 4].lexema[0] == 'i' && tables.Lex.table[i + 2].lexema[0] == 'i') {
							if (tables.Lex.table[i - 1].lexema[0] == '=') {
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << ".concat(' '," << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ")";
								i += 5;
							}
							else
							{
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << " = " << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << ".concat(' '," << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ")";
								stringCounters++;
								i += 5;
							}
						}
						else
						{
							throw ERROR_THROW(321);
						}
					}
					else if (tables.Lex.table[i].lexema[0] == 'i' && strcmp(tables.Id.table[tables.Lex.table[i].idxTI].id, copystr) == 0) {
						if (tables.Lex.table[i + 4].lexema[0] == 'i' && tables.Lex.table[i + 2].lexema[0] == 'i') {
							if (tables.Lex.table[i - 1].lexema[0] == '=') {
								throw ERROR_THROW(322);
							}
							else
							{
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << " = " << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ".slice( 0 )";
								i += 5;
							}
						}
						else
						{
							throw ERROR_THROW(321);
						}
					}
					else if (tables.Lex.table[i].lexema[0] == 'i') {
						if (tables.Lex.table[i + 1].lexema[0] == ')') {
							out << tables.Id.table[tables.Lex.table[i].idxTI].id << "";
						}
						else {
							out << tables.Id.table[tables.Lex.table[i].idxTI].id << " ";
						}
						if (showFlag == true) {
							out << ")";
							showFlag = false;
						}
					}

					else if (tables.Lex.table[i].lexema[0] == 'd') {
						out << "let ";
					}
					else if (tables.Lex.table[i].lexema[0] == ',') {
						out << ",";
					}
					else if (tables.Lex.table[i].lexema[0] == '(') {
						out << "(";
					}
					else if (tables.Lex.table[i].lexema[0] == ')') {
						out << ")";

					}
					else if (tables.Lex.table[i].lexema[0] == '{') {
						if (ifFlag == true) {
							out << ")";
							ifFlag = false;
						}
						out << "{\n";
					}
					else if (tables.Lex.table[i].lexema[0] == '}') {
						out << "}\n\n";
					}
					else if (tables.Lex.table[i].lexema[0] == ';') {
						out << ";\n";
					}
					else if (tables.Lex.table[i].lexema[0] == 'r') {
						out << "return ";
					}
					else if (tables.Lex.table[i].lexema[0] == '=') {
						out << "= ";
					}
					else if (tables.Lex.table[i].lexema[0] == 'n') {
						out << "if (";
						ifFlag = true;
					}
					else if (tables.Lex.table[i].lexema[0] == 'e') {
						out << "else ";
					}
					else if (tables.Lex.table[i].lexema[0] == '!') {
						out << "!";
					}
					else if (tables.Lex.table[i].lexema[0] == '-') {
						out << "-";
					}
					else if (tables.Lex.table[i].lexema[0] == '+') {
						out << "+ ";
					}
					else if (tables.Lex.table[i].lexema[0] == '>') {
						out << ">";
					}
					else if (tables.Lex.table[i].lexema[0] == '<') {
						out << "<";
					}
					else if (tables.Lex.table[i].lexema[0] == '~') {
						if (tables.Lex.table[i - 1].lexema[0] != 'i' && tables.Lex.table[i - 1].lexema[0] != 'l') {
							out << "=";
						}
						else {
							out << "==";
						}
					}
					else if (tables.Lex.table[i].lexema[0] == '*') {
						out << "* ";
					}
					else if (tables.Lex.table[i].lexema[0] == '/') {
						out << "/ ";
					}
					else if (tables.Lex.table[i].lexema[0] == 's') {
						out << "alert(";
						showFlag = true;
					}
					else if (tables.Lex.table[i].lexema[0] == 'l') {
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::CHAR) {
							out << "'" << tables.Id.table[tables.Lex.table[i].idxTI].value.vchar[0] << "'";
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::STR) {
							out << "'" << (char*)tables.Id.table[tables.Lex.table[i].idxTI].value.vstr->str << "'";
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::INT) {
							out << tables.Id.table[tables.Lex.table[i].idxTI].value.vint;
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::BOOL) {
							if (tables.Id.table[tables.Lex.table[i].idxTI].value.vbool == 1) {
								out << "true";
							}
							else {
								out << "false";
							}
						}
						if (showFlag == true) {
							out << ")";
							showFlag = false;
						}
					}
				}
				i--;
				break;
			}
			case LEX_PROC: {
				out << "function " << tables.Id.table[tables.Lex.table[i + 1].idxTI].id;
				i++;
				while (tables.Lex.table[i].lexema[0] != 'f' && tables.Lex.table[i].lexema[0] != 'p' && tables.Lex.table[i].lexema[0] != 'm') {
					i++;
					if (tables.Lex.table[i].lexema[0] == 'i' && strcmp(tables.Id.table[tables.Lex.table[i].idxTI].id, concat) == 0) {
						if (tables.Lex.table[i + 4].lexema[0] == 'i' && tables.Lex.table[i + 2].lexema[0] == 'i') {
							if (tables.Lex.table[i - 1].lexema[0] == '=') {
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << ".concat(' '," << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ")";

							}
							else
							{
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << " = " << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << ".concat(' '," << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ")";
								stringCounters++;

							}
						}
						else
						{
							throw ERROR_THROW(321);
						}
					}
					else if (tables.Lex.table[i].lexema[0] == 'i' && strcmp(tables.Id.table[tables.Lex.table[i].idxTI].id, copystr) == 0) {
						if (tables.Lex.table[i + 4].lexema[0] == 'i' && tables.Lex.table[i + 2].lexema[0] == 'i') {
							if (tables.Lex.table[i - 1].lexema[0] == '=') {
								throw ERROR_THROW(322);
							}
							else
							{
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << " = " << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ".slice( 0 )";

							}
						}
						else
						{
							throw ERROR_THROW(321);
						}
					}
					else if (tables.Lex.table[i].lexema[0] == 'i') {
						if (tables.Lex.table[i + 1].lexema[0] == ')') {
							out << tables.Id.table[tables.Lex.table[i].idxTI].id << "";
						}
						else {
							out << tables.Id.table[tables.Lex.table[i].idxTI].id << " ";
						}
						if (showFlag == true) {
							out << ")";
							showFlag = false;
						}
					}

					else if (tables.Lex.table[i].lexema[0] == 'd') {
						out << "let ";
					}
					else if (tables.Lex.table[i].lexema[0] == ',') {
						out << ",";
					}
					else if (tables.Lex.table[i].lexema[0] == '(') {
						out << "(";
					}
					else if (tables.Lex.table[i].lexema[0] == ')') {
						out << ")";

					}
					else if (tables.Lex.table[i].lexema[0] == '{') {
						if (ifFlag == true) {
							out << ")";
							ifFlag = false;
						}
						out << "{\n";
					}
					else if (tables.Lex.table[i].lexema[0] == '}') {
						out << "}\n\n";
					}
					else if (tables.Lex.table[i].lexema[0] == ';') {
						out << ";\n";
					}
					else if (tables.Lex.table[i].lexema[0] == 'r') {
						out << "return ";
					}
					else if (tables.Lex.table[i].lexema[0] == '=') {
						out << "= ";
					}
					else if (tables.Lex.table[i].lexema[0] == 'n') {
						out << "if (";
						ifFlag = true;
					}
					else if (tables.Lex.table[i].lexema[0] == 'e') {
						out << "else ";
					}
					else if (tables.Lex.table[i].lexema[0] == '!') {
						out << "!";
					}
					else if (tables.Lex.table[i].lexema[0] == '-') {
						out << "-";
					}
					else if (tables.Lex.table[i].lexema[0] == '+') {
						out << "+ ";
					}
					else if (tables.Lex.table[i].lexema[0] == '>') {
						out << ">";
					}
					else if (tables.Lex.table[i].lexema[0] == '<') {
						out << "<";
					}
					else if (tables.Lex.table[i].lexema[0] == '~') {
						if (tables.Lex.table[i - 1].lexema[0] != 'i' && tables.Lex.table[i - 1].lexema[0] != 'l') {
							out << "=";
						}
						else {
							out << "==";
						}
					}
					else if (tables.Lex.table[i].lexema[0] == '*') {
						out << "* ";
					}
					else if (tables.Lex.table[i].lexema[0] == '/') {
						out << "/ ";
					}
					else if (tables.Lex.table[i].lexema[0] == 's') {
						out << "alert(";
						showFlag = true;
					}
					else if (tables.Lex.table[i].lexema[0] == 'l') {
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::CHAR) {
							out << "'" << tables.Id.table[tables.Lex.table[i].idxTI].value.vchar[0] << "'";
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::STR) {
							out << "'" << (char*)tables.Id.table[tables.Lex.table[i].idxTI].value.vstr->str << "'";
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::INT) {
							out << tables.Id.table[tables.Lex.table[i].idxTI].value.vint;
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::BOOL) {
							if (tables.Id.table[tables.Lex.table[i].idxTI].value.vbool == 1) {
								out << "true";
							}
							else {
								out << "false";
							}
						}
						if (showFlag == true) {
							out << ")";
							showFlag = false;
						}
					}
				}
				i--;
				break;
			}
			case LEX_MAIN: {
				i++;
				while (i <= tables.Lex.size) {
					i++;
					if (tables.Lex.table[i].lexema[0] == 'i' && strcmp(tables.Id.table[tables.Lex.table[i].idxTI].id, concat) == 0) {
						if (tables.Lex.table[i + 4].lexema[0] == 'i' && tables.Lex.table[i + 2].lexema[0] == 'i') {
							if (tables.Lex.table[i - 1].lexema[0] == '=') {
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << ".concat(' '," << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ")";
							}
							else
							{
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << " = " << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << ".concat(' '," << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ")";
								stringCounters++;
							}
						}
						else
						{
							throw ERROR_THROW(321);
						}
					}
					else if (tables.Lex.table[i].lexema[0] == 'i' && strcmp(tables.Id.table[tables.Lex.table[i].idxTI].id, copystr) == 0) {
						if (tables.Lex.table[i + 4].lexema[0] == 'i' && tables.Lex.table[i + 2].lexema[0] == 'i') {
							if (tables.Lex.table[i - 1].lexema[0] == '=') {
								throw ERROR_THROW(322);
							}
							else
							{
								out << tables.Id.table[tables.Lex.table[i + 2].idxTI].id << " = " << tables.Id.table[tables.Lex.table[i + 4].idxTI].id << ".slice( 0 )";
							}
						}
						else
						{
							throw ERROR_THROW(321);
						}
					}
					else if (tables.Lex.table[i].lexema[0] == 'i') {
						if (tables.Lex.table[i + 1].lexema[0] == ')') {
							out << tables.Id.table[tables.Lex.table[i].idxTI].id << "";
						}
						else {
							out << tables.Id.table[tables.Lex.table[i].idxTI].id << " ";
						}
						if (showFlag == true) {
							out << ")";
							showFlag = false;
						}
					}

					else if (tables.Lex.table[i].lexema[0] == 'd') {
						out << "let ";
					}
					else if (tables.Lex.table[i].lexema[0] == ',') {
						out << ",";
					}
					else if (tables.Lex.table[i].lexema[0] == '(') {
						out << "(";
					}
					else if (tables.Lex.table[i].lexema[0] == ')') {
						out << ")";

					}
					else if (tables.Lex.table[i].lexema[0] == '{') {
						if (ifFlag == true) {
							out << ")";
							ifFlag = false;
						}
						out << "{\n";
					}
					else if (tables.Lex.table[i].lexema[0] == '}') {
						if (ifFlag == true) {
							out << "}\n\n";
							ifFlag = false;
						}
					}
					else if (tables.Lex.table[i].lexema[0] == ';') {
						out << ";\n";
					}
					else if (tables.Lex.table[i].lexema[0] == 'r') {
						out << "return ";
					}
					else if (tables.Lex.table[i].lexema[0] == '=') {
						out << "= ";
					}
					else if (tables.Lex.table[i].lexema[0] == 'n') {
						out << "if (";
						ifFlag = true;
					}
					else if (tables.Lex.table[i].lexema[0] == 'e') {
						out << "}\nelse {\n";
						i++;
						ifFlag = true;
					}
					else if (tables.Lex.table[i].lexema[0] == '!') {
						out << "!";
					}
					else if (tables.Lex.table[i].lexema[0] == '-') {
						out << "-";
					}
					else if (tables.Lex.table[i].lexema[0] == '+') {
						out << "+ ";
					}
					else if (tables.Lex.table[i].lexema[0] == '>') {
						out << ">";
					}
					else if (tables.Lex.table[i].lexema[0] == '<') {
						out << "<";
					}
					else if (tables.Lex.table[i].lexema[0] == '~') {
						if (tables.Lex.table[i - 1].lexema[0] != 'i' && tables.Lex.table[i - 1].lexema[0] != 'l') {
							out << "=";
						}
						else {
							out << "==";
						}
					}
					else if (tables.Lex.table[i].lexema[0] == '*') {
						out << "* ";
					}
					else if (tables.Lex.table[i].lexema[0] == '/') {
						out << "/ ";
					}
					else if (tables.Lex.table[i].lexema[0] == 's') {
						out << "alert(";
						showFlag = true;
					}
					else if (tables.Lex.table[i].lexema[0] == 'l') {
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::CHAR) {
							out << "'" << (char)tables.Id.table[tables.Lex.table[i].idxTI].value.vchar[0] << "'";
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::STR) {
							out << "'" << (char*)tables.Id.table[tables.Lex.table[i].idxTI].value.vstr->str << "'";
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::INT) {
							out << tables.Id.table[tables.Lex.table[i].idxTI].value.vint;
						}
						if (tables.Id.table[tables.Lex.table[i].idxTI].iddatatype == IT::BOOL) {
							if (tables.Id.table[tables.Lex.table[i].idxTI].value.vbool == 1) {
								out << "true";
							}
							else {
								out << "false";
							}
						}
						if (showFlag == true) {
							out << ")";
							showFlag = false;
						}
					}
				}
				break;
			}
			default:
				break;
			}
		}
	}
}