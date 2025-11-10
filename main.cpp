#include "helperFunctions.h"
#include "railcar.h"
#include "train.h"

using namespace std;

int main() {
  // Get the name of a train
  string name = "";
  cout << "Enter the name of your train: ";
  getline(cin, name);

  // TODO: Create a train

  // Add cars
  while (true) {
    // Create a new car
    // (need to dynamically allocate it so it can persist)
    // (we will delete it later)
    Railcar *new_car = new Railcar();
    new_cargo_menu();
    char type = ' ';

    cin >> type;
    type = toupper(type);

    // TODO: Set the id of the car
    // (hint: use the Railcar class methods)

    cout << "How many " << type << " do you need to carry? ";
    int num_items = get_positive_int();
    // TODO: Set the number of items

    // TODO: Add the car
  }

  // TODO: Print out the train

  return 0;
}
