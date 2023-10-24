#include "garment.h"

namespace clothes {
	Garment::Garment(Color color) {
		this->color = color;
	}

	Color Garment::get_color() const {
		return this->color;
	}
} // namespace clothes
