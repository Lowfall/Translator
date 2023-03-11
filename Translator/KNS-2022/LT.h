#pragma once
#define LEXEMA_FIXSIZE  1			
#define LT_MAXSIZE		4096		
#define LT_TI_NULLIDX	0xffffffff	
#define LEX_INTEGER		't'			
#define LEX_STRING		't'			
#define LEX_CHAR		't'
#define LEX_BOOL		't'
#define LEX_ID			'i'			
#define LEX_LITERAL		'l'			
#define LEX_FUNCTION	'f'			
#define LEX_DEFINE		'd'			
#define LEX_RETURN		'r'			
#define	LEX_SHOW		's'			
#define LEX_MAIN		'm'
#define LEX_EQU			'='
#define LEX_SEMICOLON	';'
#define LEX_COMMA		','
#define LEX_LEFTBRACE	'{'
#define	LEX_BRACELET	'}'
#define LEX_LEFTGESIS	'('
#define	LEX_RIGHTTESIS	')'
#define LEX_NOT '!'
#define LEX_LESS '<'
#define LEX_MORE '>'
#define LEX_EQUALS '~'
#define LEX_ELSE 'e'
#define LEX_IF 'n'
#define LEX_PROC 'p'

namespace LT			
{
	struct Entry			
	{
		char lexema[LEXEMA_FIXSIZE];	
		int sn;							
		int idxTI;	
		int priority;
	};

	struct LexTable						
	{
		int maxsize;				
		int size;					
		Entry* table;				
	};

	LexTable Create(int size);			
	void Add(LexTable& lextable, Entry entry);		
	Entry GerEntry(LexTable& lextable, int n);		
	void Delete(LexTable* lextable);				
}