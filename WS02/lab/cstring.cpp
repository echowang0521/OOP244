//Name: mengjiao Wang
//ID:137144192
//EMAIL:mwang154@myseneca.ca
//date:2021-01-23
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

	void strnCpy(char* des, const char* src, int len)
	{
		int index = 0;
		while(index < len && src[index] != '\0')
		{
			des[index] = src[index];
			index++;
		}
		if (index != len)
		{
			des[index] = '\0';
		}
	}

	int strCmp(const char* s1, const char* s2)
	{
     		int index = 0;
     		while(s1[index]!= '\0' && s2[index] != '\0')
		{
       			if(s1[index] > s2[index])
			{
         			return 1;
       			}
       			if(s1[index] < s2[index])
			{
         			return -1;
       			}
       			index++;
     		}
     		if(s1[index] == '\0' && s2[index] == '\0')
		{
       			return 0;
     		}
     		if(s2[index] != '\0')
		{
       			return -1;
     		}
     		return 1;
   	}

	int strnCmp(const char* s1, const char* s2, int len)
	{
     		int index=0;
     		while(index < len && s1[index] != '\0' && s2[index] != '\0')
		{
       			if(s1[index] > s2[index])
			{
         			return 1;
       			}
       			if(s1[index] < s2[index])
			{
         			return -1;
       			}
       			index++;
     		}
     		if(index == len)
		{
       			return 0;
     		}
      		if(s2[index] != '\0')
		{
       			return -1;
     		}
     		return 1;
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

	const char* strStr(const char* str1, const char* str2)
	{
    		int size1 = strLen(str1);
		int size2 = strLen(str2);
    		int ind1 = 0;
		int ind2 = 0;
    		int equalFlag;

    		while(ind1 < size1-size2+1)
		{
        		ind2 = 0;
        		equalFlag = 1;
        		while(ind2 < size2)
			{
            			if(str1[ind1 + ind2] != str2[ind2])
				{
                			equalFlag = 0;
                			break;
            			}
            		ind2++;
        		}
        		if(equalFlag == 1)
			{
		            return str1 + ind1;
        		}
        	ind1++;
    		}
    		return nullptr;
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
