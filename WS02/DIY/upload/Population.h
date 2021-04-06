#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_
#define DATAFILE "PCpopulations.csv"
namespace sdds {
  struct Population {
		long population;
		char* code;
	};

  void sort();
  bool load(const char file[]);
  void display(const Population* population);
  void display();
  void deallocateMemory();
}
#endif // SDDS_POPULATION_H_
