#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include "File.h"
using namespace std;
namespace sdds {
   FILE* fptr;
   vector<string> v;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }

   bool read(long& population, char code[]) {
       char tmp[128];
       bool res = fscanf(fptr, "%[^\n]\n", tmp) == 1;
       v = split(string(tmp), ",");
       population = stol(v[1]);
       strcpy(code, v[0].c_str());
       return res;
   }

   vector<string> split(string str, string token){
      vector<string>result;
      while(str.size()){
          int index = str.find(token);
          if(index!=string::npos){
              result.push_back(str.substr(0,index));
              str = str.substr(index+token.size());
              if(str.size()==0)result.push_back(str);
          }else{
              result.push_back(str);
              str = "";
          }
      }
      return result;
  }

}
