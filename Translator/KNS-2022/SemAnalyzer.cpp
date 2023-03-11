#include "stdafx.h"

bool expressionCheck(char a)
{
		if (a == '+' || a == '-' || a == '*' || a == '/' ) {
			return true;
		}
		else {
			return false;
		}
}

bool ifCheck(char a, char b, int* pos)
{
	*pos = 0;
	if (b != '~') {
		*pos = 1;
		if (a == '>' || a == '<' || a == '~') {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		*pos = 2;
		if (a == '!' || a == '>' || a == '<')
		{
			return true;
		}
		else {
			return false;
		}
	}
}

namespace Semantic
{
	bool semanticsCheck(LT::LexTable& lextab, IT::IdTable idtab)
	{
		bool parmChek = false;
		int mainCheck = 0;
		int position = 0;
		int parmCount = 0;
		int symbsAmount = 0;

		for (int i = 0; i < lextab.size; i++)
		{
			if (lextab.table[i].lexema[0] == LEX_MAIN) // проверка на мейн
			{
				mainCheck++;
			}

			if ((lextab.table[i - 1].lexema[0] == LEX_ID) &&
				(lextab.table[i - 2].lexema[0] != 't' && lextab.table[i - 2].lexema[0] != LEX_PROC) && lextab.table[i].lexema[0] == LEX_LEFTGESIS)
			{
				parmChek = true;
				position = lextab.table[i - 1].idxTI;

			}
			if (parmChek == true)
			{
				if (lextab.table[i].lexema[0] == LEX_ID || lextab.table[i].lexema[0] == LEX_LITERAL)
				{
				     if(idtab.table[position].value.params.types[parmCount] != idtab.table[lextab.table[i].idxTI].iddatatype)
					{
						throw ERROR_THROW(305);
					}
					parmCount++;
				}
				if (lextab.table[i].lexema[0] == LEX_RIGHTTESIS)
				{
					if (idtab.table[position].value.params.count != parmCount)
					{
						throw ERROR_THROW(304);
					}
					parmChek = false;
					parmCount = 0;

				}
			}

			if (lextab.table[i].lexema[0] == '/' && lextab.table[i + 1].lexema[0] == 'l')
			{
				if (idtab.table[lextab.table[i + 1].idxTI].value.vint == 0)
					throw ERROR_THROW(314);
			}

			if (lextab.table[i].lexema[0] == LEX_EQU) // выражение
			{
				if (i)
				{
					IT::IDDATATYPE lefttype = idtab.table[lextab.table[i - 1].idxTI].iddatatype;
					bool ignore = false;
					if (idtab.table[lextab.table[i+1].idxTI].idtype == IT::F || idtab.table[lextab.table[i + 1].idxTI].idtype == IT::N)
					{
						if (lefttype != idtab.table[lextab.table[i + 1].idxTI].iddatatype)
						{
							throw ERROR_THROW(315);
						}
					}
					for (int k = i + 1; lextab.table[k].lexema[0] != LEX_SEMICOLON; k++)
					{
						if (lextab.table[k].idxTI != TI_NULLIDX && (lextab.table[k + 1].idxTI != TI_NULLIDX || lextab.table[k + 1].lexema[0] == ';'))
						{
							if (!ignore)
							{
								IT::IDDATATYPE righttype;
								if (expressionCheck(lextab.table[k].lexema[0]) != true)
								{
									righttype = idtab.table[lextab.table[k].idxTI].iddatatype;
								}
								else
								{
									righttype = idtab.table[lextab.table[k + 1].idxTI].iddatatype;
								}
								if (lefttype != righttype)
									throw ERROR_THROW(315);
							}
							if (k + 1 < lextab.size && lextab.table[k + 1].lexema[0] == LEX_LEFTGESIS && idtab.table[lextab.table[k].idxTI].idtype == IT::IDTYPE::F)
							{
								ignore = true;
								continue;
							}
							if (ignore && lextab.table[k + 1].lexema[0] == LEX_RIGHTTESIS)
							{
								ignore = false;
								continue;
							}
						}
						if (lefttype == IT::IDDATATYPE::STR)
						{
							char l = lextab.table[k].lexema[0];
							if (expressionCheck(l) == true) 
								throw ERROR_THROW(316);
						}
					}
				}

			}

			if (lextab.table[i].lexema[0] == '/')
			{
				if (idtab.table[lextab.table[i + 1].idxTI].value.vint == 0) {
					throw ERROR_THROW(314);
				}
			}


			if (lextab.table[i].lexema[0] == LEX_IF)
			{
				IT::IDDATATYPE lefttype = idtab.table[lextab.table[i + 1].idxTI].iddatatype;
				if (lefttype == 4 && ifCheck(lextab.table[i + 2].lexema[0], lextab.table[i + 3].lexema[0], &symbsAmount) == false) {
					continue;
				}
				ifCheck(lextab.table[i + 2].lexema[0],lextab.table[i + 3].lexema[0],&symbsAmount);
				if (symbsAmount == 1) {
					if (lefttype != idtab.table[lextab.table[i + 3].idxTI].iddatatype) {
						throw ERROR_THROW(319);
					}
				}
				else if (symbsAmount == 2) {
					if (lefttype != idtab.table[lextab.table[i + 4].idxTI].iddatatype) {
						throw ERROR_THROW(319);
					}
				}
				else {

				}

				if (idtab.table[lextab.table[i + 1].idxTI].iddatatype != 4 && ifCheck(lextab.table[i + 2].lexema[0], lextab.table[i + 3].lexema[0], &symbsAmount) == false)
				{
					throw ERROR_THROW(316);
				}
			}


		}


		for (int i = 0; i < idtab.size; i++)
		{
			if (idtab.table[i].idtype == IT::L && idtab.table[i].iddatatype == IT::INT)  //рабочая проверка на размер численного литерала
			{
				if (idtab.table[i].value.vint >= MAX_NUM || idtab.table[i].value.vint < 0)
				{
					throw ERROR_THROW(309);
				}
			}
		}


		if (mainCheck < 1)
		{
			throw ERROR_THROW(301);
		}
		else if (mainCheck > 1)
		{
			throw ERROR_THROW(302);
		}
	}
};