#include "railcar.h"

int Railcar::get_max_cargo() const {
  if (id.front() == '~') {
    return 0;
  }

  if (id.front() == Railcar::CARGO_CODE_PEOPLE) {
    return Railcar::MAX_PEOPLE;
  } else if (id.front() == Railcar::CARGO_CODE_ANIMALS) {
    return Railcar::MAX_ANIMALS;
  } else if (id.front() == Railcar::CARGO_CODE_CRATES) {
    return Railcar::MAX_CRATES;
  } else if (id.front() == Railcar::CARGO_CODE_BUILDINGS) {
    return Railcar::MAX_BUILDINGS;
  } else if (id.front() == Railcar::CARGO_CODE_PIPES) {
    return Railcar::MAX_PIPES;
  }

  invalid_argument("INVALID RAILCAR CARGO CODE");
  return -1;
}

// This function returns a random 3 digit numeric string
string Railcar::rand_3digit() const { return to_string(rand() % 999 + 100); }

// Constructors
Railcar::Railcar() { id = '~' + rand_3digit(); }

Railcar::Railcar(const char type) {
  int num = get_max_cargo();
  id = type + rand_3digit();
}

// Set methods
void Railcar::set_id(const char type) {
  int num = get_max_cargo();
  id = type + rand_3digit();
  cerr << "ID: " << id << endl;
}

void Railcar::set_num_items(const int num) {
  if (num < 0) {
    invalid_argument("ERROR, number of items cannot be negative");
  } else if (num > get_max_cargo()) {
    return;
  } else {
    num_items = num;
  }
}

void Railcar::set_next_car(Railcar *const next) { next_car = next; }

// Other methods

// TODO: Implement this function
void Railcar::print_id() const {}
