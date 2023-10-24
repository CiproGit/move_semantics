#include "pants.h"
#include <iostream>

using namespace std;

namespace clothes {
	Pants::Pants(Size size, Color color, shared_ptr<Belt> belt) : Garment(color) {
		this->size = size;
		this->belt = belt;
	}

	Pants::Pants(Pants &&source) : Garment(source.get_color()) {
		this->size = source.size;
		this->belt = source.belt;

		source.belt = nullptr;
	}

	Size Pants::get_size() const {
		return this->size;
	}

	shared_ptr<Belt> Pants::get_belt() const {
		return this->belt;
	}

	void Pants::wear() const {
		cout << this->get_color() << " pants worn" << endl;
	}
} // namespace clothes
