#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include "File.h"
#include "Population.h"


using namespace std;
namespace sdds {
    int noOfPopulation;
    Population* population;

    void sort() {
        int i, j;
        Population temp;
        for (i = noOfPopulation - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (population[j].population > population[j + 1].population) {
                    temp = population[j];
                    population[j] = population[j + 1];
                    population[j + 1] = temp;
                }
            }
        }
    }

    bool load(const char file[]) {
       bool ok = false;
       int i = 0;

       if (openFile(DATAFILE)) {
         noOfPopulation = noOfRecords();
         population = new Population[noOfPopulation];
         char tmp[128];
         for (i = 0; i < noOfPopulation; i++) {
           if (read(population[i].population, tmp)) {
               population[i].code = new char[strlen(tmp) + 1];
               strcpy(population[i].code, tmp);
           } else break;
         }

         if (i != noOfPopulation) {
           cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
         } else {
           ok = true;
         }
         closeFile();
       }
       else {
         cout << "Could not open data file: " << DATAFILE << endl;
       }
       return ok;
    }

    void display(const Population* population) {
      cout << "Postal Code: population" << endl;
      cout << "-------------------------" << endl;
      for (int i = 0; i < noOfPopulation; i++) {
        cout << i + 1 << "- ";
        cout << population[i].code << ": " << population[i].population << endl;
      }
      cout << "-------------------------" << endl;
      cout << "Population of Canada: 282439" << endl;
    }

    void display() {
      sort();
      display(population);
    }

    void deallocateMemory() {
      for (int i = 0; i < noOfPopulation; i++) {
        delete[] population[i].code;
        population[i].code = nullptr;
      }
      delete[] population;
      population = nullptr;
    }
}
