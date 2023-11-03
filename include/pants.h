#ifndef PANTS_H
#define PANTS_H

#include "belt.h"
#include "garment.h"
#include <memory>

namespace clothes {
	using Size = int;

	class Pants : public Garment {
	private:
		Size size;
		std::shared_ptr<Belt> belt;

	public:
		Pants(Size size, Color color, std::shared_ptr<Belt> belt = nullptr);
		Pants(const Pants &source) = default; // Copy constructor
		Pants(Pants &&source); // Move constructor
		virtual ~Pants() = default;
		Size get_size() const;
		std::shared_ptr<Belt> get_belt() const;
		void wear() const override;
	};
} // namespace clothes

#endif // PANTS_H
