#include "pants.h"
#include <iostream>

using namespace std;

using Wardrobe = vector<shared_ptr<clothes::Garment>>;

void print_belt(const clothes::Belt &belt) {
	cout << "\tColor: " << belt.get_color() << "\n";
	cout << "\tLength: " << belt.get_length() << endl;
}

void print_pants(const clothes::Pants &pants) {
	cout << "\tColor: " << pants.get_color() << "\n";
	cout << "\tSize: " << pants.get_size() << "\n";
	if (pants.get_belt() == nullptr) cout << "\tWithout belt" << endl;
	else cout << "\tWith belt" << endl;
}

int main(void) {	
	cout << "**************************\n";
	cout << "*     MOVE SEMANTICS     *\n";
	cout << "**************************\n" << endl;

	constexpr clothes::Length BELT_LENGTH = 100;
	constexpr clothes::Size PANTS_SIZE = 48;

	// Lambda function
	auto buy_clothes = [](Wardrobe &wardrobe) {
		shared_ptr<clothes::Belt> brown_belt(new clothes::Belt(BELT_LENGTH, "Brown")); // Create belt
		wardrobe.push_back(brown_belt);

		shared_ptr<clothes::Pants> red_pants(new clothes::Pants(PANTS_SIZE, "Red", brown_belt)); // Create red pants
		wardrobe.push_back(red_pants);
	};

	Wardrobe wardrobe;

	cout << "Buy clothes!" << endl;
	buy_clothes(wardrobe); // Pass by reference

	cout << "Belt" << endl;
	shared_ptr<clothes::Belt> brown_belt = dynamic_pointer_cast<clothes::Belt>(wardrobe.at(0));
	print_belt(*brown_belt); // Pass by reference

	cout << "Red pants" << endl;
	shared_ptr<clothes::Pants> red_pants = dynamic_pointer_cast<clothes::Pants>(wardrobe.at(1));
	print_pants(*red_pants); // Pass by reference

	cout << "\nGet dressed with another red pants, moving the belt from the previous one..." << endl;
	clothes::Pants red_pants_2(std::move(*red_pants)); // Get an rvalue reference and use move constructor

	cout << "Previous red pants" << endl;
	print_pants(*red_pants); // Pass by reference

	cout << "Second red pants" << endl;
	print_pants(red_pants_2); // Pass by reference

	red_pants_2.wear();

	cout << "\nEnd" << endl;
	return EXIT_SUCCESS;
}
