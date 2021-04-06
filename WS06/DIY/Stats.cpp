//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-14
#include "Stats.h"
#include <vector>
#include <algorithm>
namespace sdds {
   Stats::Stats(const char* filename,
    unsigned int columnWidth,
    unsigned int noOfColumns,
    unsigned int precision) {
      this->column = noOfColumns;
      this->width = columnWidth;
      this->precision = precision;
      this->fileName = nullptr;
      this->grid = nullptr;
      this->row = 0;
      this->records = 0;
      if (filename != nullptr) {
        set_name(filename);
        loadContent();
      }
   }

   Stats::Stats(unsigned columnWidth,
    unsigned noOfColumns,
    unsigned precision) {
      this->column = noOfColumns;
      this->width = columnWidth;
      this->precision = precision;
      this->fileName = nullptr;
      this->grid = nullptr;
      this->row = 0;
      this->records = 0;
    }

    void Stats::set_name(const char *name) {
      if (name != nullptr) {
        delete this->fileName;
        this->fileName = new char[strlen(name) + 1];
        strcpy(fileName, name);
      }
    }

    Stats::~Stats() {
      delete[] fileName;
      fileName = nullptr;
      for (int i = 0; i < (int)row; i++) {
          delete[] grid[i];
          grid[i] = nullptr;
      }
      delete[] grid;
      grid = nullptr;
    }

    void Stats::write() const {
      int count = 0;
      ofstream out;
      out.open(fileName);
      if (out.is_open()) {
        for (int i = 0; i < (int)row && count < records; i++) {
          for(int j = 0; j < (int)column && count < records; j++, count++) {
            out << grid[i][j];
            if (count < records - 1) {
              out << ",";
            }
          }
        }
        out.close();
      }
    }

    unsigned Stats::size() const {
      return this->records;
    }

    const char *Stats::name() const {
      return this->fileName;
    }

    void Stats::sort(bool ascending) {
      vector<double> nums;
      int count = 0;
      for (int i = 0; i < (int)row && count < records; i++) {
        for (int j = 0; j < (int)column && count < records; j++) {
          nums.push_back(grid[i][j]);
          count++;
        }
      }

      if (ascending) {
        std::sort(nums.begin(), nums.end());
      } else {
        std::sort(nums.begin(), nums.end(), greater<int>());
      }
      loadGrid(nums);
    }

    void Stats::occurrence(double min, double max, ostream &ostr) const {
      if (fileName == nullptr || row == 0) return;
      int count = 0;
      vector<double> nums;
      for (int i = 0; i < (int)row && count < records; i++) {
        for (int j = 0; j < (int)column && count < records; j++, count++) {
          if (grid[i][j] > min && grid[i][j] < max) {
            nums.push_back(grid[i][j]);
          }
        }
      }

      int tmpRow = ceil((double) records / column);
      double **newGrid = new double *[tmpRow];
      for (int i = 0; i < (int) row; i++) {
        newGrid[i] = new double[column];
      }

      int current = 0;
      ostr << '\n';
      for (int i = 0; i < (int)row && current < nums.size(); i++) {
        for (int j = 0; j < (int)column && current < nums.size(); j++) {
          newGrid[i][j] = nums[current];
          ostr.width(width);
          ostr.setf(ios::fixed);
          ostr.precision(precision);
          ostr << newGrid[i][j];
        }
        ostr << '\n';
      }

      for (int i = 0; i < (int)row; i++) {
        delete[] newGrid[i];
        newGrid[i] = nullptr;
      }
      delete[] newGrid;
      newGrid = nullptr;
      ostr << "Total of " << nums.size() << " numbers are between " << min << " and " << max << '\n';
    }

    ostream &operator<<(ostream &out, const Stats &stat) {
      if (stat.fileName == nullptr || (int)stat.row == 0) return out;
      out << stat.fileName << endl;
      out.width(strlen(stat.fileName));
      out.fill('=');
      out << "" << endl << endl;
      stat.display(out);
      out << "Total of " << stat.records << " listed!" << endl;
      return out;
    }

    istream &operator>>(istream &in, Stats &stat) {
      string newFile;
      in >> newFile;
      stat.set_name(newFile.c_str());
      stat.loadContent();
      return in;
    }

    void Stats::display(ostream &out) const {
      if (!row) return;
      int count = 0;
      for (int i = 0; i < (int)row && count < records; i++) {
        for (int j = 0; j < (int)column && count < records; j++, count++) {
          out.fill(' ');
          out.width(width);
          out.setf(ios::fixed);
          out.precision(precision);
          out << grid[i][j];
        }
        out << '\n';
      }
    }

    Stats::operator bool() const {
      if (row == 0 || fileName == nullptr || grid == nullptr) return true;
      return false;
    }

    double Stats::operator[](int index)const {
      int count = 0;
      vector<double> nums;
      for (int i = 0; i < (int)row && count < records; i++) {
        for (int j = 0; j < (int)column && count < records; j++, count++) {
          nums.push_back(grid[i][j]);
        }
      }
      if (nums.size() == 0) return 0;
      return nums[index % nums.size()];
    }

    double &Stats::operator[](int index) {
      if (fileName == nullptr) return this->falseCase;
      index = index % records;
      int tmpRow = index / column;
      return grid[tmpRow][index - tmpRow * column];
    }

    void Stats::showGrid()const {
      int count = 0;
      for (int i = 0; i < (int)row && count < records; i++) {
        for (int j = 0; j < (int)column && count < records; j++, count++) {
          cout << grid[i][j] << ", ";
        }
        cout << '\n';
      }
    }

    void Stats::loadContent() {
      vector<double> nums;
      ifstream f;
      f.open(fileName);
      if (f.is_open()) {
        while(f) {
          char comma;
          double num;
          f >> num >> comma;
          nums.push_back(num);
        }
      }
      records = nums.size();
      f.close();
      loadGrid(nums);
    }

    void replace(const char *destination, const char *source) {
      ifstream f;
      vector<char> nums;
      string s;
      f.open(source);
      if (f.is_open()) {
        while(f) {
          getline(f, s);
        }
      }
      f.close();

      ofstream o;
      o.open(destination);
      if (o.is_open()) {
        o << s;
      }
      o.close();
    }

    Stats &Stats::operator=(const Stats &s) {
      if (this == &s) return *this;
      if (this->fileName != nullptr && s.fileName != nullptr) {
        replace(this->fileName, s.fileName);
      }
      vector<double> tmp;
      column = s.column;
      width = s.width;
      precision = s.precision;
      records = s.records;
      if (s.fileName == nullptr) {
        row = 0;
        for (int i = 0; i < (int)row; i++) {
            delete[] grid[i];
            grid[i] = nullptr;
        }
        delete[] grid;
        grid = nullptr;
        return *this;
      }

      int count = 0;
      for (int i = 0; i < (int)s.row && count < records; i++) {
        for (int j = 0; j < (int)s.column && count < records; j++, count++) {
          tmp.push_back(s.grid[i][j]);
        }
      }

      loadGrid(tmp);
      return *this;
    }

    Stats::Stats(const Stats &s) {
      if (this == &s) return;
      this->fileName = nullptr;
      this->grid = nullptr;
      this->row = 0;
      string prefix = "C_";
      prefix += s.fileName;
      set_name(prefix.c_str());
      vector<double> tmp;
      this->column = s.column;
      this->width = s.width;
      this->precision = s.precision;
      this->records = s.records;
      if (s.fileName == nullptr) {
        this->row = 0;
        for (int i = 0; i < (int)row; i++) {
            delete[] this->grid[i];
            this->grid[i] = nullptr;
        }
        delete[] this->grid;
        this->grid = nullptr;
        return;
      }

      int count = 0;
      for (int i = 0; i < (int)s.row && count < records; i++) {
        for (int j = 0; j < (int)s.column && count < records; j++, count++) {
          tmp.push_back(s.grid[i][j]);
        }
      }
      loadGrid(tmp);
      replace(prefix.c_str(), s.fileName);
    }

    void Stats::loadGrid(const vector<double> &nums) {
      for (int i = 0; i < (int)row; i++) {
          delete[] grid[i];
          grid[i] = nullptr;
      }
      delete[] grid;
      grid = nullptr;
      records = nums.size();
      row = ceil((double) records / column);
      grid = new double*[(int)row];
      for (int i = 0; i < (int)row; i++) {
        grid[i] = new double[column];
      }
      for (int k = 0, i = 0; i < (int)row && k < nums.size(); i++) {
        for (int j = 0; j < (int)column && k < nums.size(); j++, k++) {
          grid[i][j] = nums[k];
        }
      }
    }
}
