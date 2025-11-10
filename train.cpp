#include "train.h"

#include <iomanip>

// Constructors
Train::Train() { name = "n/a"; }

Train::Train(const string &str) { name = str; }

Train::Train(const string &str, Railcar *const first) {
  name = str;
  first_car = first;
}

// Destructor
Train::~Train() {}

// Set methods
void Train::set_name(const string &str) { name = str; }

void Train::set_first_car(Railcar *const first) { first_car = first; }

// Other methods
void Train::add_car(Railcar *const new_car) {
  // If the train is empty, set the first car
  if (first_car == nullptr) {
    cerr << "Adding the first car" << endl;
    first_car = new_car;
    return;
  }

  Railcar *old_first = first_car; // Grab the first car so that we don't lose it

  first_car = new_car;                // Set the new first car
  first_car->set_next_car(old_first); // Set the old first car as the next
}

// TODO: Implement this function
Railcar *Train::find_car(const string &id) const { return nullptr; }

void Train::remove_car(const string &id) {
  // If the first car is the one we want to remove, remove it
  // (set the first car to the next car)
  // (this is the easiest case)
  if (first_car->get_id() == id) {
    Railcar *temp = first_car; // Grab the first car

    // Set the first car to the next car
    first_car = first_car->get_next_car();

    delete temp; // Delete the old first car
                 // (every new needs to be deleted)

    return;
  }

  // We will need to keep track of the previous car in order to remove properly
  Railcar *prev_car = first_car;

  // Start at the second car since the first car has already been checked
  Railcar *current_car = first_car->get_next_car();

  // Go through the whole Train
  // (if nullptr, we have reached the end of the train)
  while (current_car != nullptr) {
    // If we find the car, remove it
    if (current_car->get_id() == id) {
      // prev_car = Car1
      // current_car = Car2
      // Car1 -> Car2 -> Car3
      // Car1 -> Car3
      prev_car->set_next_car(current_car->get_next_car());
      return;
    }

    // Go to the next car and keep track of the previous
    prev_car = current_car;
    current_car = current_car->get_next_car();
  }

  // If we get here, the car was not found
  return;
}

// TODO: Implement this function
void Train::edit_car(const string &id, const int new_item_count) {}

// TODO: Implement this function
void Train::print_all_contents() const {}
