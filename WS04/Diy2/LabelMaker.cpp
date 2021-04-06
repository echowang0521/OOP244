//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-02-14
#include <iostream>
#include "Label.h"
#include "LabelMaker.h"
using namespace std;
namespace sdds {
    LabelMaker::LabelMaker(int noOfLabels) {
      size = noOfLabels;
    }
    void LabelMaker::readLabels() {
        cout << "Enter " << size << " labels: " << endl;
        for (int i = 0; i < size; i++) {
            cout << "Enter label number " << i + 1 << endl << "> ";
            Label label;
            label.readLabel();
            labels.push_back(label);
        }
    }

    void LabelMaker::printLabels() {
        for (size_t i = 0; i < labels.size(); i++)
            labels[i].printLabel(),
            cout << endl;
    }

    LabelMaker::~LabelMaker() {}
}
