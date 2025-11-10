#pragma once
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

class Railcar {
private:
  string id = "";
  int num_items = 0;
  Railcar *next_car = NULL;

  // This function returns the max items for the given cargo type
  int get_max_cargo() const;
  // This function returns a random 3 digit numeric string
  string rand_3digit() const;

public:
  // Static member variables
  // Cargo codes
  static const char CARGO_CODE_PEOPLE = 'P';
  static const char CARGO_CODE_ANIMALS = 'A';
  static const char CARGO_CODE_CRATES = 'C';
  static const char CARGO_CODE_BUILDINGS = 'B';
  static const char CARGO_CODE_PIPES = 'S';

  // Maximum number of items for each cargo type
  static const int MAX_PEOPLE = 12;
  static const int MAX_ANIMALS = 6;
  static const int MAX_CRATES = 8;
  static const int MAX_BUILDINGS = 1;
  static const int MAX_PIPES = 3;

  // Constructors
  Railcar();
  Railcar(const char type); // the numeric part of the id is set automatically

  // Set methods
  void set_id(const char type); // we only need to set the type
  void set_num_items(const int num);
  void set_next_car(Railcar *const next);

  // Get methods
  string get_id() const {
    if (!id.empty()) {
      return id;
    }

    return "~~~~";
  }

  char get_type() const {
    if (!id.empty()) {
      return id.front();
    }

    return '~';
  }

  int get_num_items() const { return num_items; }

  Railcar *get_next_car() const { return next_car; }

  // Other methods
  void print_id() const;
};
