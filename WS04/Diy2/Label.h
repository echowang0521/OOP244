//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-02-10
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <string>
using namespace std;
namespace sdds {
   class Label {
     string frame;
     string words;
   public:
     Label();
     Label(const char* frameArg);
     Label(const char* frameArg, const char* content);
     ~Label();
     void readLabel();
     std::ostream& printLabel() const;
   };
}

#endif // !SDDS_LABEL_H
