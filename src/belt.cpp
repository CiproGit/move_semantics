#include "belt.h"
#include <iostream>

using namespace std;

namespace clothes {
	Belt::Belt(Length length, Color color) : Garment(color) {
		this->length = length;
	}

	Length Belt::get_length() const {
		return this->length;
	}

	void Belt::wear() const {
		cout << this->get_color() << " belt worn" << endl;
	}
} // namespace clothes
