//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-02-14
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <vector>
using namespace std;
namespace sdds {
    class LabelMaker {
        vector<Label> labels;
        int size;
    public:
        LabelMaker(int noOfLabels);
        void readLabels();
        void printLabels();
        ~LabelMaker();
    };
}
#endif //SDDS_LABELMAKER_H
