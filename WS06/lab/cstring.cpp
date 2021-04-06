//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-10
#include "cstring.h"
namespace sdds {
  void strCpy(char* des, const char* src)
  {
    int index = 0;
    while(src[index] != '\0')
    {
      des[index] = src[index];
      index++;
    }
    des[index] = '\0';
  }

  int strLen(const char* s)
	{
      		int len = 0;
      		while(s[len] != '\0')
		{
          		len ++;
      		}
      		return len;
   	}

  void strCat(char* des, const char* src)
	{
      		int desSize = strLen(des);
	      	int i = 0;
      		while(src[i] != '\0')
		{
          		des[desSize+i] = src[i];
		        i++;
      		}
      		des[desSize + i] = '\0';
      		return;
   	}
}
