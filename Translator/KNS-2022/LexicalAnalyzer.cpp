#include "stdafx.h"

bool intCheck(char* str) {
	FST::FST typeint(str, 4,
		FST::NODE(1, FST::RELATION('i', 1)),
		FST::NODE(1, FST::RELATION('n', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE()
	);
	return FST::execute(typeint);
}

bool strCheck(char* str)
{
	FST::FST typestring(str, 4,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('t', 2)),
		FST::NODE(1, FST::RELATION('r', 3)),
		FST::NODE()
	);
	return FST::execute(typestring);
}

bool charCheck(char* str)
{
	FST::FST typechar(str, 5,
		FST::NODE(1, FST::RELATION('c', 1)),
		FST::NODE(1, FST::RELATION('h', 2)),
		FST::NODE(1, FST::RELATION('a', 3)),
		FST::NODE(1, FST::RELATION('r', 4)),
		FST::NODE()
	);
	return FST::execute(typechar);
}

bool funcCheck(char* str)
{
	FST::FST typefunction(str, 9,
		FST::NODE(1, FST::RELATION('f', 1)),
		FST::NODE(1, FST::RELATION('u', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('t', 5)),
		FST::NODE(1, FST::RELATION('i', 6)),
		FST::NODE(1, FST::RELATION('o', 7)),
		FST::NODE(1, FST::RELATION('n', 8)),
		FST::NODE()
	);
	return FST::execute(typefunction);
}

bool defineCheck(char* str)
{
	FST::FST strdefine(str, 7,
		FST::NODE(1, FST::RELATION('d', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('f', 3)),
		FST::NODE(1, FST::RELATION('i', 4)),
		FST::NODE(1, FST::RELATION('n', 5)),
		FST::NODE(1, FST::RELATION('e', 6)),
		FST::NODE()
	);
	return FST::execute(strdefine);
}

bool returnCheck(char* str)
{
	FST::FST streturn(str, 7,
		FST::NODE(1, FST::RELATION('r', 1)),
		FST::NODE(1, FST::RELATION('e', 2)),
		FST::NODE(1, FST::RELATION('t', 3)),
		FST::NODE(1, FST::RELATION('u', 4)),
		FST::NODE(1, FST::RELATION('r', 5)),
		FST::NODE(1, FST::RELATION('n', 6)),
		FST::NODE()
	);
	return FST::execute(streturn);
}

bool mainCheck(char* str)
{
	FST::FST strmain(str, 5,
		FST::NODE(1, FST::RELATION('m', 1)),
		FST::NODE(1, FST::RELATION('a', 2)),
		FST::NODE(1, FST::RELATION('i', 3)),
		FST::NODE(1, FST::RELATION('n', 4)),
		FST::NODE()
	);
	return FST::execute(strmain);
}

bool showCheck(char* str)
{
	FST::FST strshow(str, 5,
		FST::NODE(1, FST::RELATION('s', 1)),
		FST::NODE(1, FST::RELATION('h', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('w', 4)),
		FST::NODE()
	);
	return FST::execute(strshow);
}

bool ifCheck(char* str) {
	FST::FST ifcheck(str, 3,
		FST::NODE(1, FST::RELATION('i', 1)),
		FST::NODE(1, FST::RELATION('f', 2)),
		FST::NODE()
	);
	return FST::execute(ifcheck);
}

bool elseCheck(char* str) {
	FST::FST elsecheck(str, 5,
		FST::NODE(1, FST::RELATION('e', 1)),
		FST::NODE(1, FST::RELATION('l', 2)),
		FST::NODE(1, FST::RELATION('s', 3)),
		FST::NODE(1, FST::RELATION('e', 4)),
		FST::NODE()
	);
	return FST::execute(elsecheck);
}


bool spaceCheck(char* str)
{
	FST::FST space(str, 2,
		FST::NODE(1, FST::RELATION(' ', 1)),
		FST::NODE()
	);
	return FST::execute(space);
}

bool lbraceCheck(char* str)
{
	FST::FST leftbrace(str, 2,
		FST::NODE(1, FST::RELATION('{', 1)),
		FST::NODE()
	);
	return FST::execute(leftbrace);
}

bool rbraceCheck(char* str)
{
	FST::FST rightbrace(str, 2,
		FST::NODE(1, FST::RELATION('}', 1)),
		FST::NODE()
	);
	return FST::execute(rightbrace);
}

bool lhesCheck(char* str)
{
	FST::FST leftthesis(str, 2,
		FST::NODE(1, FST::RELATION('(', 1)),
		FST::NODE()
	);
	return FST::execute(leftthesis);
}

bool rhesCheck(char* str)
{
	FST::FST rightthesis(str, 2,
		FST::NODE(1, FST::RELATION(')', 1)),
		FST::NODE()
	);
	return FST::execute(rightthesis);
}

bool semCheck(char* str)
{
	FST::FST semicolon(str, 2,
		FST::NODE(1, FST::RELATION(';', 1)),
		FST::NODE()
	);
	return FST::execute(semicolon);
}

bool comCheck(char* str)
{
	FST::FST comma(str, 2,
		FST::NODE(1, FST::RELATION(',', 1)),
		FST::NODE()
	);
	return FST::execute(comma);
}

bool equCheck(char* str)
{
	FST::FST equals(str, 2,
		FST::NODE(1, FST::RELATION('=', 1)),
		FST::NODE());
	return FST::execute(equals);
}



bool litIntCheck(char* str)
{
	FST::FST Literal(str, 2,
		FST::NODE(20,
			FST::RELATION('0', 0), FST::RELATION('1', 0), FST::RELATION('2', 0),
			FST::RELATION('3', 0), FST::RELATION('4', 0), FST::RELATION('5', 0),
			FST::RELATION('6', 0), FST::RELATION('7', 0), FST::RELATION('8', 0),
			FST::RELATION('9', 0), FST::RELATION('0', 1), FST::RELATION('1', 1),
			FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
			FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
			FST::RELATION('8', 1), FST::RELATION('9', 1)),
		FST::NODE()
	);
	return FST::execute(Literal);
}

bool litStrCheck(char* str)
{
	FST::FST fstidenf(str, 2,
		FST::NODE(142,
			FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0), FST::RELATION('c', 1), FST::RELATION('c', 0),
			FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0), FST::RELATION('f', 1), FST::RELATION('f', 0),
			FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
			FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
			FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
			FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
			FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
			FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
			FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1), FST::RELATION('1', 0), FST::RELATION('1', 1),
			FST::RELATION('2', 0), FST::RELATION('2', 1), FST::RELATION('3', 0), FST::RELATION('3', 1), FST::RELATION('4', 0), FST::RELATION('4', 1),
			FST::RELATION('5', 0), FST::RELATION('5', 1), FST::RELATION('6', 0), FST::RELATION('6', 1), FST::RELATION('7', 0), FST::RELATION('7', 1),
			FST::RELATION('8', 0), FST::RELATION('8', 1), FST::RELATION('9', 0), FST::RELATION('9', 1), FST::RELATION('0', 0), FST::RELATION('0', 1),
			FST::RELATION('й', 1), FST::RELATION('й', 0), FST::RELATION('ц', 1), FST::RELATION('ц', 0), FST::RELATION('ё', 1), FST::RELATION('ё', 0),
			FST::RELATION('у', 1), FST::RELATION('у', 0), FST::RELATION('к', 1), FST::RELATION('к', 0), FST::RELATION('е', 1), FST::RELATION('е', 0),
			FST::RELATION('н', 1), FST::RELATION('н', 0), FST::RELATION('г', 1), FST::RELATION('г', 0), FST::RELATION('ш', 1), FST::RELATION('ш', 0),
			FST::RELATION('щ', 1), FST::RELATION('щ', 0), FST::RELATION('з', 1), FST::RELATION('з', 0), FST::RELATION('х', 1), FST::RELATION('х', 0),
			FST::RELATION('ъ', 1), FST::RELATION('ъ', 0), FST::RELATION('ф', 1), FST::RELATION('ф', 0), FST::RELATION('ы', 1), FST::RELATION('ы', 0),
			FST::RELATION('в', 1), FST::RELATION('в', 0), FST::RELATION('а', 1), FST::RELATION('а', 0), FST::RELATION('п', 1), FST::RELATION('п', 0),
			FST::RELATION('р', 1), FST::RELATION('р', 0), FST::RELATION('о', 1), FST::RELATION('о', 0), FST::RELATION('л', 1), FST::RELATION('л', 0),
			FST::RELATION('д', 1), FST::RELATION('д', 0), FST::RELATION('ж', 1), FST::RELATION('ж', 0), FST::RELATION('э', 1), FST::RELATION('э', 0),
			FST::RELATION('я', 1), FST::RELATION('я', 0), FST::RELATION('ч', 1), FST::RELATION('ч', 0), FST::RELATION('с', 1), FST::RELATION('с', 0),
			FST::RELATION('м', 1), FST::RELATION('м', 0), FST::RELATION('и', 1), FST::RELATION('и', 0), FST::RELATION('т', 1), FST::RELATION('т', 0),
			FST::RELATION('ь', 1), FST::RELATION('ь', 0), FST::RELATION('б', 1), FST::RELATION('б', 0), FST::RELATION('ю', 1), FST::RELATION('ю', 0),
			FST::RELATION(' ', 0), FST::RELATION(' ', 1), FST::RELATION('/', 0), FST::RELATION('/', 1)),
		FST::NODE()
	);
	return FST::execute(fstidenf);
}

bool identCheck(char* str)
{
	FST::FST fstidenf(str, 2,
		FST::NODE(54,
			FST::RELATION('a', 1), FST::RELATION('a', 0), FST::RELATION('b', 1), FST::RELATION('b', 0),
			FST::RELATION('c', 1), FST::RELATION('c', 0), FST::RELATION('d', 1), FST::RELATION('d', 0), FST::RELATION('e', 1), FST::RELATION('e', 0),
			FST::RELATION('f', 1), FST::RELATION('f', 0), FST::RELATION('g', 1), FST::RELATION('g', 0), FST::RELATION('h', 0), FST::RELATION('h', 1), FST::RELATION('i', 0), FST::RELATION('i', 1),
			FST::RELATION('j', 0), FST::RELATION('j', 1), FST::RELATION('k', 0), FST::RELATION('k', 1), FST::RELATION('l', 0), FST::RELATION('l', 1),
			FST::RELATION('m', 0), FST::RELATION('m', 1), FST::RELATION('n', 0), FST::RELATION('n', 1), FST::RELATION('o', 0), FST::RELATION('o', 1),
			FST::RELATION('p', 0), FST::RELATION('p', 1), FST::RELATION('q', 0), FST::RELATION('q', 1), FST::RELATION('r', 0), FST::RELATION('r', 1),
			FST::RELATION('s', 0), FST::RELATION('s', 1), FST::RELATION('t', 0), FST::RELATION('t', 1), FST::RELATION('u', 0), FST::RELATION('u', 1),
			FST::RELATION('v', 0), FST::RELATION('v', 1), FST::RELATION('w', 0), FST::RELATION('w', 1), FST::RELATION('x', 0), FST::RELATION('x', 1),
			FST::RELATION('y', 0), FST::RELATION('y', 1), FST::RELATION('z', 0), FST::RELATION('z', 1)),
		FST::NODE()
	);
	return FST::execute(fstidenf);
}

bool litBoolCheck(char* str)
{
	FST::FST typebool(str, 6,
		FST::NODE(2, FST::RELATION('t', 1), FST::RELATION('f', 1)),
		FST::NODE(2, FST::RELATION('r', 2), FST::RELATION('a', 2)),
		FST::NODE(2, FST::RELATION('u', 3), FST::RELATION('l', 3)),
		FST::NODE(2, FST::RELATION('e', 5), FST::RELATION('s', 4)),
		FST::NODE(2, FST::RELATION('e', 5)),
		FST::NODE()
	);
	return FST::execute(typebool);
}

bool copystrCheck(char* str)
{
	FST::FST copystr(str, 8,
		FST::NODE(1, FST::RELATION('c', 1)),
		FST::NODE(1, FST::RELATION('o', 2)),
		FST::NODE(1, FST::RELATION('p', 3)),
		FST::NODE(1, FST::RELATION('y', 4)),
		FST::NODE(1, FST::RELATION('s', 5)),
		FST::NODE(1, FST::RELATION('t', 6)),
		FST::NODE(1, FST::RELATION('r', 7)),
		FST::NODE()
	);
	return FST::execute(copystr);
}

bool concatCheck(char* str)
{
	FST::FST concat(str, 7,
		FST::NODE(1, FST::RELATION('c', 1)),
		FST::NODE(1, FST::RELATION('o', 2)),
		FST::NODE(1, FST::RELATION('n', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE(1, FST::RELATION('a', 5)),
		FST::NODE(1, FST::RELATION('t', 6)),
		FST::NODE()
	);
	return FST::execute(concat);
}

bool procCheck(char* str)
{
	FST::FST typeprocedure(str, 5,
		FST::NODE(1, FST::RELATION('p', 1)),
		FST::NODE(1, FST::RELATION('r', 2)),
		FST::NODE(1, FST::RELATION('o', 3)),
		FST::NODE(1, FST::RELATION('c', 4)),
		FST::NODE()
	);
	return FST::execute(typeprocedure);
}

bool exprCheck(char* str)
{
	FST::FST expression(str, 2,
		FST::NODE(7,
			FST::RELATION('+', 1),
			FST::RELATION('-', 1),
			FST::RELATION('*', 1),
			FST::RELATION('/', 1),
			FST::RELATION('<', 1),
			FST::RELATION('>', 1),
			FST::RELATION('~', 1)
		),
		FST::NODE()
	);
	return FST::execute(expression);
}

bool lessOrEqCheck(char* str)
{
	FST::FST lessOrEq(str, 3,
		FST::NODE(1,
			FST::RELATION('<', 1)
		),
		FST::NODE(1,
			FST::RELATION('~', 2)
		),
		FST::NODE()
	);
	return FST::execute(lessOrEq);
}
bool moreOrEqCheck(char* str)
{
	FST::FST moreOrEq(str, 3,
		FST::NODE(1,
			FST::RELATION('>', 1)
		),
		FST::NODE(1,
			FST::RELATION('~', 2)
		),
		FST::NODE()
	);
	return FST::execute(moreOrEq);
}
bool notEqCheck(char* str)
{
	FST::FST notEq(str, 3,
		FST::NODE(1,
			FST::RELATION('!', 1)
		),
		FST::NODE(1,
			FST::RELATION('~', 2)
		),
		FST::NODE()
	);
	return FST::execute(notEq);
}

bool litCharCheck(char* str)
{
	FST::FST fstidenf(str, 2,
		FST::NODE(71,
			FST::RELATION('a', 1), FST::RELATION('b', 1), FST::RELATION('c', 1),
			FST::RELATION('d', 1), FST::RELATION('e', 1), FST::RELATION('f', 1),
			FST::RELATION('g', 1), FST::RELATION('h', 1), FST::RELATION('i', 1),
			FST::RELATION('j', 1), FST::RELATION('k', 1), FST::RELATION('l', 1),
			FST::RELATION('m', 1), FST::RELATION('n', 1), FST::RELATION('o', 1),
			FST::RELATION('p', 1), FST::RELATION('q', 1), FST::RELATION('r', 1),
			FST::RELATION('s', 1), FST::RELATION('t', 1), FST::RELATION('u', 1),
			FST::RELATION('v', 1), FST::RELATION('w', 1), FST::RELATION('x', 1),
			FST::RELATION('y', 1), FST::RELATION('z', 1), FST::RELATION('1', 1),
			FST::RELATION('2', 1), FST::RELATION('3', 1), FST::RELATION('4', 1),
			FST::RELATION('5', 1), FST::RELATION('6', 1), FST::RELATION('7', 1),
			FST::RELATION('8', 1), FST::RELATION('9', 1), FST::RELATION('0', 1),
			FST::RELATION('й', 1), FST::RELATION('ц', 1), FST::RELATION('ё', 1),
			FST::RELATION('у', 1), FST::RELATION('к', 1), FST::RELATION('е', 1),
			FST::RELATION('н', 1), FST::RELATION('г', 1), FST::RELATION('ш', 1),
			FST::RELATION('щ', 1), FST::RELATION('з', 1), FST::RELATION('х', 1),
			FST::RELATION('ъ', 1), FST::RELATION('ф', 1), FST::RELATION('ы', 1),
			FST::RELATION('в', 1), FST::RELATION('а', 1), FST::RELATION('п', 1),
			FST::RELATION('р', 1), FST::RELATION('о', 1), FST::RELATION('л', 1),
			FST::RELATION('д', 1), FST::RELATION('ж', 1), FST::RELATION('э', 1),
			FST::RELATION('я', 1), FST::RELATION('ч', 1), FST::RELATION('с', 1),
			FST::RELATION('м', 1), FST::RELATION('и', 1), FST::RELATION('т', 1),
			FST::RELATION('ь', 1), FST::RELATION('б', 1), FST::RELATION('ю', 1),
			FST::RELATION(' ', 1),
			FST::NODE()
		));
	return FST::execute(fstidenf);
}



LT::LexTable lextab = LT::Create(LT_MAXSIZE - 1);
IT::IdTable idtab = IT::Create(TI_MAXSIZE - 1);
Lexical::Lexic tables;
std::fstream file;

void StaticLib()
{
	IT::Entry idTable;
	strcpy_s(idTable.id, "concat");
	idTable.iddatatype = IT::STR;
	idTable.value.vstr->len = 0;
	strcpy_s(idTable.value.vstr->str, "");
	idTable.idtype = IT::F;
	idTable.idxfirstLE = lextab.size;
	idTable.value.params.types = new IT::IDDATATYPE[2];
	idTable.value.params.types[0] = IT::STR;
	idTable.value.params.types[1] = IT::STR;
	idTable.value.params.count = 2;
	IT::Add(idtab, idTable);

	strcpy_s(idTable.id, "parma");
	strcpy_s(idTable.function, "concat");
	idTable.iddatatype = IT::STR;
	idTable.value.vstr->len = 0;
	strcpy_s(idTable.value.vstr->str, "");
	idTable.idtype = IT::P;
	idTable.idxfirstLE = lextab.size;
	IT::Add(idtab, idTable);

	strcpy_s(idTable.id, "parmb");
	strcpy_s(idTable.function, "concat");
	idTable.iddatatype = IT::STR;
	idTable.value.vstr->len = 0;
	strcpy_s(idTable.value.vstr->str, "");
	idTable.idtype = IT::P;
	idTable.idxfirstLE = lextab.size;
	IT::Add(idtab, idTable);

	strcpy_s(idTable.id, "copystr");
	idTable.iddatatype = IT::STR;
	idTable.value.vstr->len = 0;
	strcpy_s(idTable.value.vstr->str, "");
	idTable.idtype = IT::F;
	idTable.idxfirstLE = lextab.size;
	idTable.value.params.types = new IT::IDDATATYPE[2];
	idTable.value.params.types[0] = IT::STR;
	idTable.value.params.types[1] = IT::STR;
	idTable.value.params.count = 2;
	IT::Add(idtab, idTable);

	strcpy_s(idTable.id, "parma");
	strcpy_s(idTable.function, "copystr");
	idTable.iddatatype = IT::STR;
	idTable.value.vstr->len = 0;
	strcpy_s(idTable.value.vstr->str, "");
	idTable.idtype = IT::P;
	idTable.idxfirstLE = lextab.size;
	IT::Add(idtab, idTable);

	strcpy_s(idTable.id, "parmb");
	strcpy_s(idTable.function, "copystr");
	idTable.iddatatype = IT::STR;
	idTable.value.vstr->len = 0;
	strcpy_s(idTable.value.vstr->str, "");
	idTable.idtype = IT::P;
	idTable.idxfirstLE = lextab.size;
	IT::Add(idtab, idTable);
}


namespace Lexical
{
	int getIndexInLT(LT::LexTable& lextable, int itTableIndex)					// индекс первой встречи в таблице лексем
	{
		if (itTableIndex == -1)		// если идентификатор встречается впервые
			return lextable.size;
		for (int i = 0; i < lextable.size; i++)
			if (itTableIndex == lextable.table[i].idxTI)
				return i;
		return -1;
	}

	void LexTableInput(int line, char symbol)
	{
		LT::Entry entry;
		entry.sn = line;
		if (symbol != 'i' && symbol != 'l')
		{
			entry.idxTI = LT_TI_NULLIDX;
		}
		else
		{
			entry.idxTI = idtab.size;
		}
		memset(entry.lexema, '\0', strlen(entry.lexema) - 1);
		entry.lexema[0] = symbol;
		LT::Add(lextab, entry);
	}

	Lexical::Lexic LexicalAnalize(In::IN infile)
	{
		setlocale(LC_ALL, "rus");

		int paramCount = 0;
		char symbol;
		char buferWord1[255];
		char buferFunc1[255];
		bool funcFlag1 = false;
		bool procFlag = false;
		bool mainFlag = false;
		bool numFlag = false;
		bool strFlag = false;
		bool charFlag = false;
		bool boolFlag = false;
		bool idFlag = false;
		bool keyWordFlag = false;
		bool parmFlag = false;
		bool parmFlag1 = false;  // флаг, чтобы на скобки в теле функции не реагировало.
		bool parmStatFlag = false;
		bool returnFlag = false;
		bool newFlag = false;
		bool strLexFlag = false;
		bool charLexFlag = false;
		bool intLexFlag = false;
		bool boolLexFlag = false;
		bool symbFlag = false;
		bool staticFlag = false;
		bool strLex = 0;
		bool charLex = 0;
		int line = 0;
		int LexCount = 0;
		int k = 0;

		int symbolPos = 1;

		StaticLib();

		for (int i = 0; i < infile.size * 1.4; i++)
		{
			keyWordFlag = false;
			symbolPos++;
			symbol = infile.text[i];
			if (symbol == '\0')
			{
				break;
			}
			if (symbol == '\n')
			{
				line++;
				symbolPos = 0;
				continue;

			}
			if (symbol != ' ' || (symbol == ' ' && strLex == true && infile.text[i - 1] != '\'' && infile.text[i + 1] != '\''))
			{
				buferWord1[k] = symbol;
				k++;
				if (strLex == true && k >= TI_STR_MAXSIZE)
				{
					throw ERROR_THROW_IN(307, symbolPos, line + 1);
				}
				if (charLex == true && k > TI_CHAR_MAXSIZE)
				{
					throw ERROR_THROW_IN(317, symbolPos, line + 1);
				}

				continue;
			}
			else if (i != 0)
			{
				buferWord1[k] = '\0';
				k = 0;

				if (intCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_INTEGER);
					numFlag = true;
					keyWordFlag = true;
				}
				else if (strCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_STRING);
					strFlag = true;
					keyWordFlag = true;
				}
				else if (charCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_CHAR);
					charFlag = true;
					keyWordFlag = true;
				}

				else if (funcCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_FUNCTION);
					funcFlag1 = true;
					keyWordFlag = true;
				}
				else if (procCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_PROC);
					procFlag = true;
					keyWordFlag = true;
					//checkFlag = true;
				}

				else if (defineCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_DEFINE);
					newFlag = true;
					keyWordFlag = true;
				}
				else if (returnCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_RETURN);
					keyWordFlag = true;
					returnFlag = true;
				}
				else if (mainCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_MAIN);
					strcpy_s(buferFunc1, buferWord1);
					keyWordFlag = true;
					mainFlag = true;
				}
				else if (exprCheck(buferWord1))
				{
					LexTableInput(line, *buferWord1);
					symbFlag = true;
					keyWordFlag = true;
				}
				else if (moreOrEqCheck(buferWord1))
				{
					LexTableInput(line, LEX_MORE);
					LexTableInput(line, LEX_EQUALS);
					symbFlag = true;
					keyWordFlag = true;
				}
				else if (lessOrEqCheck(buferWord1))
				{
					LexTableInput(line, LEX_LESS);
					LexTableInput(line, LEX_EQUALS);
					symbFlag = true;
					keyWordFlag = true;
				}
				else if (notEqCheck(buferWord1))
				{
					LexTableInput(line, LEX_NOT);
					LexTableInput(line, LEX_EQUALS);
					symbFlag = true;
					keyWordFlag = true;
				}
				else if (concatCheck(buferWord1) == true || copystrCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_ID);
					lextab.table[lextab.size - 1].idxTI = IT::IsId(idtab, buferWord1, buferWord1);
					staticFlag = true;
					keyWordFlag = true;
				}
				else if (semCheck(buferWord1))
				{
					LexTableInput(line, LEX_SEMICOLON);
					idFlag = false;
					if (mainFlag == true && lextab.table[lextab.size - 1].lexema[0] == LEX_BRACELET)
					{
						mainFlag = false;
						memset(buferFunc1, '\0', 255);
					}
				}

				else if (rbraceCheck(buferWord1))
				{
					LexTableInput(line, LEX_BRACELET);
					continue;
				}
				else if (lbraceCheck(buferWord1))
				{
					LexTableInput(line, LEX_LEFTBRACE);
					continue;

				}
				else if (rhesCheck(buferWord1))
				{
					LexTableInput(line, LEX_RIGHTTESIS);
					if (parmFlag == true)
					{
						parmFlag = false;
						parmFlag1 = true;
					}
					if (parmStatFlag == true)
					{
						parmStatFlag = false;
						staticFlag = false;
					}
					continue;
				}
				else if (lhesCheck(buferWord1))
				{
					LexTableInput(line, LEX_LEFTGESIS);
					if (funcFlag1 == true)
					{
						parmFlag = true;
					}
					if (procFlag == true)
					{
						parmFlag = true;
					}
					continue;
				}
				else if (comCheck(buferWord1))
				{
					LexTableInput(line, LEX_COMMA);

				}
				else if (equCheck(buferWord1))
				{
					LexTableInput(line, LEX_EQU);
					if (newFlag == true)
					{
						newFlag = false;
						if (numFlag == false && boolFlag == false && strFlag == false)
						{
							throw ERROR_THROW_IN(310, symbolPos, line + 1);
						}
					}
				}
				else if (ifCheck(buferWord1) == true)
				{
					LexTableInput(line, '#');
					LexTableInput(line, LEX_IF);
					keyWordFlag = true;
				}
				else if (elseCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_ELSE);
					keyWordFlag = true;
				}

				else if (litIntCheck(buferWord1) && strLex == false)
				{
					LexTableInput(line, LEX_LITERAL);
					intLexFlag = true;
				}
				else if (strLex == true || charLex == true)
				{
					if (buferWord1[0] == '\'')
					{
						strLex = false;
					}
					if (buferWord1[0] == '`')
					{
						charLex = false;
					}
					if (litStrCheck(buferWord1))
					{
						LexTableInput(line, LEX_LITERAL);
						if (strLex == true)
						{
							strLexFlag = true;
						}
						if (charLex == true)
						{
							charLexFlag = true;
						}
					}
					else                         // семантическая проверка, если текстовая лексема имеет некорректный формат.
					{

					}
				}
				else if (litBoolCheck(buferWord1) == true && strLex == false)
				{
					LexTableInput(line, LEX_LITERAL);
					boolLexFlag = true;
				}

				else if (showCheck(buferWord1))
				{
					LexTableInput(line, LEX_SHOW);
					keyWordFlag = true;
				}

				else if (buferWord1[0] == '\'')
				{
					if (strLex == false)
					{
						strLex = true;
						int j = i;
						int cov = 1;
						while (infile.text[j] != ';')
						{
							if (infile.text[j] == '\'' || infile.text[j] == '\`')
								cov++;
							j++;
						}
						if (cov % 2 != 0)
						{
							throw ERROR_THROW_IN(318, symbolPos, line + 1);
						}
					}
					if (infile.text[i + 1] == '\'')
					{
						throw ERROR_THROW_IN(308, symbolPos, line + 1);
					}
				}
				else if (buferWord1[0] == '`')
				{
					if (charLex == false)
					{
						charLex = true;
						int j = i;
						int cov = 1;
						while (infile.text[j] != ';')
						{
							if (infile.text[j] == '\'' || infile.text[j] == '\`')
								cov++;
							j++;
						}
						if (cov % 2 != 0)
						{
							throw ERROR_THROW_IN(318, symbolPos, line + 1);
						}
					}
					if (infile.text[i + 1] == '`')
					{
						throw ERROR_THROW_IN(308, symbolPos, line + 1);
					}
				}

				else if (ifCheck(buferWord1) == true)
				{
					LexTableInput(line, LEX_IF);
				}
				else if (elseCheck(buferWord1))
				{
					LexTableInput(line, LEX_ELSE);
				}

				else if (keyWordFlag == false && strLex == false && equCheck(buferWord1) == false && symbFlag == false)
				{
					if (identCheck(buferWord1) == true)
					{
						if (strlen(buferWord1) < ID_MAXSIZE) {

							LexTableInput(line, LEX_ID);
							idFlag = true;
							//checkFlag = false;
						}
						else
						{
						throw ERROR_THROW_IN(311, symbolPos, line + 1);
						}
					}
					
				}
				else // лексема не разобрана.
				{
					throw ERROR_THROW_IN(200, symbolPos, line + 1);
				}
			}

			

			if ((funcFlag1 == true || procFlag == true || mainFlag) && idFlag == true && newFlag == false)    // функции и их параметры.
			{
				IT::Entry idTable;
				if (parmFlag == false && newFlag == false)
				{
					if (numFlag == true)
					{
						strcpy_s(buferFunc1, buferWord1);
						strcpy_s(idTable.id, buferFunc1);
						strcpy_s(idTable.function, buferFunc1);
						if (IT::IsId(idtab, buferWord1, buferFunc1) != -1)
						{
							throw ERROR_THROW_IN(300, symbolPos, line + 1);
						}
						if (strlen(idTable.id) > ID_MAXSIZE)    // семантическая ошибка идентефикатор больше макс длины
						{
							break;
						}
						idTable.iddatatype = IT::INT;
						idTable.value.vint = 0;
						idTable.idtype = IT::F;
						idTable.idxfirstLE = lextab.size;
						idTable.value.params.count = 0;
						idTable.value.params.types = new IT::IDDATATYPE[MAX_PARAMS];
						IT::Add(idtab, idTable);
						numFlag = false;
						idFlag = false;
					}
					else if (strFlag == true)
					{
						strcpy_s(buferFunc1, buferWord1);
						strcpy_s(idTable.id, buferFunc1);
						strcpy_s(idTable.function, buferFunc1);
						if (IT::IsId(idtab, buferWord1, buferFunc1) != -1)
						{
							throw ERROR_THROW_IN(300, symbolPos, line + 1);
						}
						idTable.iddatatype = IT::STR;
						strcpy_s(idTable.value.vstr->str, "");
						idTable.idtype = IT::F;
						idTable.idxfirstLE = lextab.size;
						idTable.value.params.count = 0;
						idTable.value.params.types = new IT::IDDATATYPE[MAX_PARAMS];
						IT::Add(idtab, idTable);
						strFlag = false;
						idFlag = false;
					}
					else if (boolFlag == true)
					{
						strcpy_s(buferFunc1, buferWord1);
						strcpy_s(idTable.id, buferFunc1);
						strcpy_s(idTable.function, buferFunc1);
						if (IT::IsId(idtab, buferWord1, buferFunc1) != -1)
						{
							throw ERROR_THROW_IN(300, symbolPos, line + 1);
						}
						idTable.value.vbool = 0;
						idTable.iddatatype = IT::BOOL;
						idTable.idtype = IT::F;
						idTable.idxfirstLE = lextab.size;
						idTable.value.params.count = 0;
						idTable.value.params.types = new IT::IDDATATYPE[MAX_PARAMS];
						IT::Add(idtab, idTable);
						boolFlag = false;
						idFlag = false;
					}
					else if (charFlag == true)
					{
						strcpy_s(buferFunc1, buferWord1);
						strcpy_s(idTable.id, buferFunc1);
						strcpy_s(idTable.function, buferFunc1);
						if (IT::IsId(idtab, buferWord1, buferFunc1) != -1)
						{
							throw ERROR_THROW_IN(300, symbolPos, line + 1);
						}
						idTable.value.vbool = 0;
						idTable.iddatatype = IT::CHAR;
						idTable.idtype = IT::F;
						idTable.idxfirstLE = lextab.size;
						idTable.value.params.count = 0;
						idTable.value.params.types = new IT::IDDATATYPE[MAX_PARAMS];
						IT::Add(idtab, idTable);
						charFlag = false;
						idFlag = false;
					}
					else if (procFlag == true && lextab.table[lextab.size - 2].lexema[0] == 'p')
					{
						IT::Entry idTable;
						strcpy_s(buferFunc1, buferWord1);
						strcpy_s(idTable.id, buferFunc1);
						strcpy_s(idTable.function, buferFunc1);
						if (IT::IsId(idtab, buferWord1, buferFunc1) != -1)
						{
							throw ERROR_THROW_IN(300, symbolPos, line + 1);
						}
						if (strlen(idTable.id) > ID_MAXSIZE)    // семантическая ошибка идентефикатор больше макс длины
						{
							break;
						}
						idTable.iddatatype = IT::VOID;
						idTable.idtype = IT::N;
						idTable.idxfirstLE = lextab.size;
						idTable.value.params.count = 0;
						idTable.value.params.types = new IT::IDDATATYPE[MAX_PARAMS];
						IT::Add(idtab, idTable);
						idFlag = false;
					}
				}
				if (parmFlag == true && (numFlag || strFlag || charFlag) && idFlag == true)
				{
					int position = 0;
					
					idTable.idtype = IT::P;
					idTable.idxfirstLE = lextab.size;
					strcpy_s(idTable.function, buferFunc1);
					strcpy_s(idTable.id, buferWord1);
					if (IT::IsId(idtab, buferWord1, buferFunc1) != -1)
					{
						throw ERROR_THROW_IN(300, symbolPos, line + 1);
					}

					for (int j = idtab.size; j >= 0; j--)
					{
						if (idtab.table[j].idtype == IT::F || idtab.table[j].idtype == IT::N)
						{
							position = j;
							break;
						}
					}

					if (numFlag == true)
					{
						idTable.iddatatype = IT::INT;
						idtab.table[position].value.params.types[idtab.table[position].value.params.count] = IT::INT;
						paramCount++;
						idTable.value.vint = 0;
						numFlag = false;
						idFlag = false;
					}
					else if (strFlag == true)
					{
						idTable.iddatatype = IT::STR;
						paramCount++;
						strcpy_s(idTable.value.vstr->str, "");
						idtab.table[position].value.params.types[idtab.table[position].value.params.count] = IT::STR;
						idTable.value.vstr->len = 0;
						strFlag = false;
						idFlag = false;
			
					}
					else if (charFlag == true)
					{
						idTable.iddatatype = IT::CHAR;
						idtab.table[position].value.params.types[idtab.table[position].value.params.count] = IT::CHAR;
						strcpy_s(idTable.value.vstr->str, "");
						paramCount++;
						idTable.value.vstr->len = 0;
						charFlag = false;
						idFlag = false;
						
					}
					else if (boolFlag == true)
					{
						paramCount++;
						idtab.table[position].value.params.types[idtab.table[position].value.params.count] = IT::BOOL;
						idTable.iddatatype = IT::BOOL;
						idTable.value.vbool = 0;
						boolFlag = false;
						idFlag = false;
						
					}
					if  (paramCount >= MAX_PARAMS)
					{
						throw ERROR_THROW_IN(306, symbolPos, line + 1);
					}
					idtab.table[position].value.params.count++;
					IT::Add(idtab, idTable);
				}
			}

			if (newFlag == true && idFlag == true)
			{
				IT::Entry idTable;
				if (funcFlag1 == true || mainFlag == true || procFlag == true)
				{
					strcpy_s(idTable.id, buferWord1);
					if (IT::IsId(idtab, buferWord1, buferFunc1) != -1)
					{
						throw ERROR_THROW_IN(300, symbolPos, line + 1);
					}
					if (strlen(idTable.id) > ID_MAXSIZE)    // семантическая ошибка идентефикатор больше макс длины
					{
						
					}
					if (mainFlag == true)
					{
						strcpy_s(idTable.function, "main");
					}
					else
					{
						strcpy_s(idTable.function, buferFunc1);
					}
					if (numFlag)
					{
						idTable.iddatatype = IT::INT;
						idTable.value.vint = 0;
						numFlag = false;
						idFlag = false;
						idTable.idtype = IT::V;
						idTable.idxfirstLE = lextab.size;
						lextab.table[lextab.size - 1].idxTI = idtab.size;
						IT::Add(idtab, idTable);
						newFlag = false;
					}
					else if (strFlag)
					{
						idTable.iddatatype = IT::STR;
						strcpy_s(idTable.value.vstr->str, "");
						idTable.value.vstr->len = 0;
						strFlag = false;
						idFlag = false;
						idTable.idtype = IT::V;
						idTable.idxfirstLE = lextab.size;
						lextab.table[lextab.size - 1].idxTI = idtab.size;
						IT::Add(idtab, idTable);
						newFlag = false;
					}
					else if (charFlag)
					{
						idTable.iddatatype = IT::CHAR;
						strcpy_s(idTable.value.vstr->str, "");
						
						idTable.value.vstr->len = 0;
						charFlag = false;
						idFlag = false;
						idTable.idtype = IT::V;
						idTable.idxfirstLE = lextab.size;
						lextab.table[lextab.size - 1].idxTI = idtab.size;
						IT::Add(idtab, idTable);
						newFlag = false;
					}

				}
				else                                  // семантическая ошибка, переменная вне функции
				{
					throw ERROR_THROW_IN(313, symbolPos, line + 1);
				}
			}


			if (intLexFlag == true || strLexFlag == true || boolLexFlag == true || charLexFlag)    // занесение лексем в таблицу идентефикаторов
			{
				IT::Entry idTable;
				char buferName[ID_MAXSIZE] = "L";
				char buf[5];
				_itoa_s(LexCount, buf, 10);
				strcat_s(buferName, buf);
				strcpy_s(idTable.id, buferName);
				idTable.idxfirstLE = lextab.size;
				idTable.idtype = IT::L;

				if (intLexFlag == true)
				{
					if (IT::IsN(idtab, buferWord1) != -1)
					{
						lextab.table[lextab.size - 1].idxTI = IT::IsN(idtab, buferWord1);
						intLexFlag = false;
						continue;
					}
					LexCount++;
					idTable.iddatatype = IT::INT;
					idTable.value.vint = atoll(buferWord1);
					

				}
				if (strLexFlag == true)
				{
					if (IT::IsS(idtab, buferWord1) != -1)
					{
						lextab.table[lextab.size - 1].idxTI = IT::IsS(idtab, buferWord1);
						strLexFlag = false;
						continue;
					}
					LexCount++;
					idTable.iddatatype = IT::STR;
					strcpy_s(idTable.value.vstr->str, buferWord1);
					idTable.value.vstr->len = strlen(buferWord1);
				}
				if (charLexFlag == true)
				{
					if (IT::IsS(idtab, buferWord1) != -1)
					{
						lextab.table[lextab.size - 1].idxTI = IT::IsS(idtab, buferWord1);
						charLexFlag = false;
						continue;
					}
					LexCount++;
					idTable.iddatatype = IT::CHAR;
					idTable.value.vchar[0] = buferWord1[0];
				}
				if (boolLexFlag == true)
				{
					if (IT::IsB(idtab, buferWord1) != -1)
					{
						lextab.table[lextab.size - 1].idxTI = IT::IsB(idtab, buferWord1);
						boolLexFlag = false;
						continue;
					}
					LexCount++;
					idTable.iddatatype = IT::BOOL;
					if (strcmp(buferWord1, "true") == 0)
					{
						idTable.value.vbool = true;
					}
					else
					{
						idTable.value.vbool = false;
					}

				}
				IT::Add(idtab, idTable);

				intLexFlag = false;
				strLexFlag = false;
				boolLexFlag = false;
				charLexFlag = false;

			}

			if (returnFlag == true && semCheck(buferWord1) == true)  // возвращаемое значение для фукнции
			{
				paramCount = 0;
				returnFlag = false;
				parmFlag1 = false;
				funcFlag1 = false;
				procFlag = false;
				for (int j = 0; j < idtab.size; j++)			// семантическая проверка соответствия возращаемого значения функции и фактического
				{
					if (strcmp(idtab.table[j].id, buferFunc1) == 0 && idtab.table[j].idtype == IT::F)
					{
						if (idtab.table[j].iddatatype != idtab.table[lextab.table[lextab.size - 2].idxTI].iddatatype)
						{
							throw ERROR_THROW_IN(303, symbolPos, line + 1);
						}
					}
				}

				if (idFlag == true)
				{
					idFlag = false;
				}
				memset(buferFunc1, '\0', 255);
			}

			if (symbFlag == true)    // занесение символов
			{
				IT::Entry idTable;
				strcpy_s(idTable.id, buferWord1);
				idTable.idtype = IT::L;
				idTable.idxfirstLE = lextab.size;
				lextab.table[lextab.size - 1].idxTI = idtab.size;
				IT::Add(idtab, idTable);
				numFlag = false;
				symbFlag = false;
				keyWordFlag = false;
			}

			if (idFlag == true && lextab.table[lextab.size - 2].lexema[0] != 'p' && lextab.table[lextab.size - 2].lexema[0] != 'd'
				&& lextab.table[lextab.size - 2].lexema[0] != 'f' && lextab.table[lextab.size - 1].lexema[0] != 't')
			{ // запись позиции в таблице идентефикаторв при вызове
				if (IT::IsId(idtab, buferWord1, buferFunc1) >= 0)  // проверка, был ли вообще идентефикатор объявлен
				{
					lextab.table[lextab.size - 1].idxTI = IT::IsId(idtab, buferWord1, buferFunc1);
					idFlag = false;
				}
				else
				{
					throw ERROR_THROW_IN(312, symbolPos, line + 1);
				}
			}
			memset(buferWord1, '\0', 255);
		}
		tables.Lex = lextab;
		tables.Id = idtab;
		return tables;
	}

	void Logger(std::ostream& stream)
	{
		stream << "\n\n";
		stream << std::setw(10) << "|Лексема" << std::setw(2) << '|';
		stream << std::setw(20) << "|Строка" << std::setw(2) << '|';
		stream << std::setw(20) << "|ID в ТИ" << std::setw(2) << '|';
		stream << "\n";

		for (int i = 0; i < lextab.size; i++)
		{
			stream << i;
			stream << std::setw(7) << lextab.table[i].lexema[0] << std::setw(22);
			if (i != (lextab.size))
			{
				stream << lextab.table[i].sn + 1 << ' ';
			}
			if (lextab.table[i].idxTI != -1)
			{
				stream << std::setw(20) << lextab.table[i].idxTI;
			}
			else
			{
				stream << std::setw(22) << "не ID";
			}

			stream << "\n";


		}

		stream << "\n\n";
		stream << std::setw(15) << "- ID" << std::setw(2) << '-';
		stream << std::setw(15) << "- Тип" << std::setw(2) << '-';
		stream << std::setw(15) << "- ID Тип" << std::setw(2) << '-';
		stream << std::setw(15) << "- позиция" << std::setw(2) << '-';
		stream << std::setw(15) << "- область" << std::setw(2) << '-';
		stream << std::setw(15) << "- значение" << std::setw(2) << '-';
		stream << std::setw(15) << "- длина" << std::setw(2) << '-';
		stream << std::setw(15) << "- парам. кол." << std::setw(2) << '-';
		stream << std::setw(15) << "- параметры" << std::setw(2) << '-' << '\n';
		stream << "\n";
		for (int i = 0; i < idtab.size; i++)
		{
			stream << std::setw(17) << idtab.table[i].id << std::setw(2);


			if (idtab.table[i].iddatatype == IT::INT)
				stream << std::setw(15) << "integer" << std::setw(2);
			if (idtab.table[i].iddatatype == IT::STR)
				stream << std::setw(15) << "string" << std::setw(2);
			if (idtab.table[i].iddatatype == IT::BOOL)
				stream << std::setw(15) << "bool" << std::setw(2);
			if (idtab.table[i].iddatatype == IT::VOID)
				stream << std::setw(15) << "proc" << std::setw(2);
			if (idtab.table[i].iddatatype == IT::CHAR)
				stream << std::setw(15) << "char" << std::setw(2);



			if (idtab.table[i].idtype == IT::F)
				stream << std::setw(16) << "Функция" << std::setw(2);
			else if (idtab.table[i].idtype == IT::P)
				stream << std::setw(16) << "Параметр" << std::setw(2);
			else if (idtab.table[i].idtype == IT::L)
				stream << std::setw(16) << "Литерал" << std::setw(2);
			else if (idtab.table[i].idtype == IT::V)
				stream << std::setw(16) << "Переменная" << std::setw(2);
			else if (idtab.table[i].idtype == IT::N)
				stream << std::setw(16) << "Процедура" << std::setw(2);
			else
				stream << std::setw(30);

			stream << std::setw(15) << idtab.table[i].idxfirstLE << std::setw(2);
			if (idtab.table[i].idtype == IT::P || idtab.table[i].idtype == IT::V)
			{
				stream << std::setw(13) << "\"" << idtab.table[i].function << "\"" << std::setw(2);
			}
			if (idtab.table[i].idtype == IT::L)
			{
				if (idtab.table[i].iddatatype == IT::STR)
				{
					stream << std::setw(30) << "\"" << idtab.table[i].value.vstr->str << "\"" << std::setw(2);
					stream << std::setw(16) << idtab.table[i].value.vstr->len << std::setw(2);
				}
				else if (idtab.table[i].iddatatype == IT::CHAR)
				{
					stream << std::setw(32) << "\"" << idtab.table[i].value.vstr->str << "\"" << std::setw(2);
				}
				else if (idtab.table[i].iddatatype == IT::INT)
				{
					stream << std::setw(32) << "\"" << idtab.table[i].value.vint << "\"" << std::setw(2);
				}
				else if (idtab.table[i].iddatatype == IT::BOOL)
				{
					stream << std::setw(32) << "\"" << idtab.table[i].value.vbool << "\"" << std::setw(2);
				}

			}

			if (idtab.table[i].idtype == IT::F || idtab.table[i].idtype == IT::N)
			{
				stream << std::setw(60) << idtab.table[i].value.params.count << "\t\t";
				for (int j = 0; j < idtab.table[i].value.params.count; j++)
				{
					switch (idtab.table[i].value.params.types[j])
					{
					case 1: {stream << std::setw(10) << "Численный" << std::setw(2); break; }
					case 2: {stream << std::setw(10) << "Строковый" << std::setw(2); break; }
					case 3: {stream << std::setw(10) << "Cимвольный" << std::setw(2); break; }
					}

				}
			}

			stream << "\n\n";
		}
	}
}
