#pragma once
#define ID_MAXSIZE				10
#define TI_MAXSIZE				4096
#define TI_INT_DEFAULT		0x00000000
#define TI_STR_DEFAULT		0x00
#define TI_NULLIDX				0xffffffff
#define TI_STR_MAXSIZE		255
#define TI_CHAR_MAXSIZE	1
#define MAX_PARAMS    5
#define MAX_NUM       4294967294

namespace IT
{
	enum IDDATATYPE { INT = 1, STR = 2, CHAR = 3, BOOL = 4, VOID = 5 };
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, N = 5 };

	struct Entry
	{
		int						idxfirstLE;
		char					id[ID_MAXSIZE];
		char function[ID_MAXSIZE];
		IDDATATYPE	iddatatype;
		IDTYPE				idtype;
		
		union
		{
			char vchar[TI_CHAR_MAXSIZE];
			bool vbool;
			int vint;
			struct {
				char len;
				char str[TI_STR_MAXSIZE - 1];
			} vstr[TI_STR_MAXSIZE];
			struct
			{
				int count;					
				IDDATATYPE* types;			
			} params;
		} value;
	};

	struct IdTable
	{
		int maxsize;
		int size;
		Entry* table;
	};

	IdTable Create(int size);			
	void Add(IdTable& idtable, Entry entry);	
	Entry GetEntry(IdTable& idtable, int n);	
	int IsId(IdTable& idtalbe, char id[ID_MAXSIZE], char func[ID_MAXSIZE]);		
	int IsN(IdTable& idtalbe, char id[ID_MAXSIZE]);		
	int IsS(IdTable& idtalbe, char id[ID_MAXSIZE]);		
	int IsB(IdTable& idtalbe, char id[ID_MAXSIZE]);		
	void Delete(IdTable& idtable);	                    
}
