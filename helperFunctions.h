#include "railcar.h"
#include "train.h"

void die(const string msg = "INVALID INPUT") {
  cout << msg << endl;
  exit(EXIT_FAILURE);
}

void new_cargo_menu() {
  cout << "What are you carrying: " << endl;
  cout << "\t" << Railcar::CARGO_CODE_PEOPLE << ": Passengers" << endl;
  cout << "\t" << Railcar::CARGO_CODE_ANIMALS << ": Animals" << endl;
  cout << "\t" << Railcar::CARGO_CODE_CRATES << ": Crates" << endl;
  cout << "\t" << Railcar::CARGO_CODE_BUILDINGS << ": Buildings" << endl;
  cout << "\t" << Railcar::CARGO_CODE_PIPES << ": Pipes" << endl;
  cout << "\tX: Exit" << endl << endl;
}

void pause() {
  cout << "Enter any key to continue..." << endl;
  cin.get();
  system("clear");
}

int get_positive_int() {
  int num = 0;
  cin >> num;
  if (!cin || num < 0) {
    die("NOT A POSITIVE INTEGER");
  }
  return num;
}

void uppercaseify(string &str) {
  for (char &i : str) {
    i = toupper(i);
  }
}
