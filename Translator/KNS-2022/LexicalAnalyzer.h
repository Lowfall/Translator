#pragma once
#include "stdafx.h"


namespace Lexical
{
	struct Lexic
	{
		LT::LexTable Lex;
		IT::IdTable Id;
	};
	Lexic LexicalAnalize(In::IN);
	void Logger(std::ostream& stream);
	void LexTableInp(int, char);
	int getIndexInLT(LT::LexTable& lextable, int itTableIndex);
}
