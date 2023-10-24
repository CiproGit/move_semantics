#ifndef GARMENT_H
#define GARMENT_H

#include <string>

namespace clothes {
	using Color = std::string;

	class Garment { // Abstract class
	private:
		Color color;

	public:
		Garment(Color color);
		virtual ~Garment() = default;
		Color get_color() const;
		virtual void wear() const = 0; // Pure virtual method
	};
} // namespace clothes

#endif // GARMENT_H
