#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
#include <vector>
#include <string>
using namespace std;
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();

   bool read(long& population, char code[]);
   vector<string> split(string str, string token);
}
#endif // !SDDS_FILE_H_
