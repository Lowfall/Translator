#include "stdafx.h"
#include "IT.h"
#include "Error.h"
namespace IT
{
	IdTable Create(int size)
	{
		IdTable* tabl = new IdTable;
		if (size > TI_MAXSIZE)
		{
			throw ERROR_THROW(203);
		}
		tabl->maxsize = size;
		tabl->size = 0;
		tabl->table = new Entry[size];
		return*tabl;
	}
	void Add(IdTable& idtable, Entry entry)
	{
		if (idtable.size + 1 > idtable.maxsize)
		{
			throw ERROR_THROW(203);
		}

		idtable.table[idtable.size] = entry;
		idtable.size += 1;
	}
	Entry GetEntry(IdTable& idtable, int n)
	{
		return idtable.table[n];
	}
	int IsId(IdTable& idtable, char id[ID_MAXSIZE], char func[ID_MAXSIZE])
	{
		int n = 0;
		bool flag = false;
		while (n < idtable.size)
		{
			if (strcmp(idtable.table[n].id, id) == 0 && (strcmp(idtable.table[n].function, func) == 0 || strcmp(id, func) == 0 ||
				idtable.table[n].idtype == IT::F || idtable.table[n].idtype == IT::N))
			{
				flag = true;
				break;
			}
			n += 1;
		}
		if (flag)
		{
			return n;
		}
		else
		{
			return TI_NULLIDX;
		}
	}

	int IsN(IdTable& idtable, char value[ID_MAXSIZE])
	{
		int n = 0;
		bool flag = false;
		while (n < idtable.size - 1)
		{
			if (idtable.table[n].value.vint == atoi(value))
			{
				flag = true;
				break;
			}
			n += 1;
		}
		if (flag)
		{
			return n;
		}
		else
		{
			return TI_NULLIDX;
		}
	}
	int IsS(IdTable& idtable, char value[ID_MAXSIZE])
	{
		int n = 0;
		bool flag = false;
		while (n < idtable.size - 1)
		{
			if (strcmp(value, idtable.table[n].value.vstr->str) == 0)
			{
				flag = true;
				break;
			}
			n += 1;
		}
		if (flag)
		{
			return n;
		}
		else
		{
			return TI_NULLIDX;
		}
	}

	int IsB(IdTable& idtable, char value[ID_MAXSIZE])
	{
		int n = 0;
		bool flag = false;
		while (n < idtable.size - 1)
		{
			if (idtable.table[n].idtype == IT::L && idtable.table[n].iddatatype == IT::BOOL)
			{
				if ((strcmp(value, "true") == 0 && idtable.table[n].value.vbool == 1)
					|| (strcmp(value, "false") == 0 && idtable.table[n].value.vbool == 0))
				{
					flag = true;
					break;
				}
			}
			n += 1;
		}
		if (flag)
		{
			return n;
		}
		else
		{
			return TI_NULLIDX;
		}
	}



	void Delete(IdTable& idtable)
	{
		delete[] idtable.table;
		delete& idtable;
	}
};