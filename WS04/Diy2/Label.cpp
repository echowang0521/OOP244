//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-02-14
#include <iostream>
#include <iomanip>
#include <string>
#include "Label.h"
using namespace std;

namespace sdds {
  Label::Label() {
    frame = "+-+|+-+|";
  }
  Label::Label(const char *frameArg) {
    frame = string(frameArg);
  }
  Label::Label(const char* frameArg, const char* content) {
    frame = string(frameArg);
    words = string(content);
  }
  Label::~Label() {}

  void Label::readLabel() {
    char *labelRead = new char[71];
    cin.getline(labelRead, 71, '\n');
    words = labelRead;
    delete [] labelRead;
  }

  ostream& Label::printLabel() const {
    if(frame.empty() || words.empty()) {
      return cout;
    }
    int len = words.size() + 2;
      cout << frame[0];
      cout << setw(len) << setfill(frame[1]) << "";
      cout << frame[2] << endl;
      cout << frame[7];
      cout << setw(len) << setfill(' ') << "";
      cout << frame[3] << endl;
      cout << frame[7] << " " << words << " " << frame[3] << endl;
      cout << frame[7];
      cout << setw(len) << setfill(' ') << "";
      cout << frame[3] << endl;
      cout << frame[2];
      cout << setw(len) << setfill(frame[1]) << "";
      cout << frame[0];
    return cout;
  }
}
