#include <iostream>
using namespace std;


extern "C"
{
	
	char* __stdcall copystr(char* str1, char* str2)
	{
		int size = 0;
		

		for (int j = 0; str2[j] != '\0'; j++)
		{
			str1[j] = str2[j];
			size++;
		}
		str1[size] = '\0';
		return str1;
	}

	char* __stdcall concat(char* buffer, char* str1, char* str2)
	{
		int j = 0;
		for (j; str1[j] != '\0'; j++)
		{
			buffer[j] = str1[j];
		}
		int i = j;
		for (int j = 0; str2[j] != '\0'; j++)
		{
			buffer[i] = str2[j];
			i++;
		}
		buffer[i] = '\0';
		return buffer;
	}
}
