#pragma once
#include "railcar.h"

#include <iostream>
#include <string>

using namespace std;

class Train {
private:
  string name = "";
  Railcar *first_car = nullptr;

public:
  // Constructors
  Train();
  Train(const string &str);
  Train(const string &str, Railcar *const first);

  // Destructor
  ~Train();

  // Set methods
  void set_name(const string &str);
  void set_first_car(Railcar *const first);

  // Get methods
  string get_name() const { return name; }
  Railcar *get_first_car() const { return first_car; }

  // Other methods
  void add_car(Railcar *const new_car);
  Railcar *find_car(const string &id) const;
  void remove_car(const string &id);
  void edit_car(const string &id, const int new_item_count);
  void print_all_contents() const;
};
