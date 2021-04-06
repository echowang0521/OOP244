//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-14
#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;

namespace sdds {
   class Stats {
      unsigned column { 0 };
      unsigned row { 0 };
      unsigned width { 0 };
      unsigned precision { 0 };
      char* fileName {nullptr};
      double **grid {nullptr};
      int records { 0 };
      double falseCase { 0.0 };
   public:
      void setFilename(string name);
      void loadContent();
      void loadGrid(const vector<double> &nums);
      Stats(unsigned columnWidth = 15,
       unsigned noOfColumns = 4,
       unsigned precision = 2);
      Stats(const char* filename,
       unsigned columnWidth = 15,
       unsigned noOfColumns = 4,
       unsigned precision = 2);
       void display(ostream &out)const;
      ~Stats();
      void set_name(const char *name);
      Stats(const Stats &stat);
      Stats &operator=(const Stats &stat);
      void write() const;
      double& operator[](int idx);
      double operator[](int idx)const;
      void showGrid()const;
      operator bool() const;
      void sort(bool ascending);
      unsigned size()const;
      const char* name()const;
      void occurrence(double min, double max, ostream& ostr = cout)const;
      friend ostream &operator<<(ostream &out, const Stats &stat);
      friend std::istream &operator>>(std::istream &in, Stats &stat);
   };
}
