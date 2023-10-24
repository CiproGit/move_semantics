#ifndef BELT_H
#define BELT_H

#include "garment.h"

namespace clothes {
	using Length = int;

	class Belt : public Garment {
	private:
		Length length;

	public:
		Belt(Length length, Color color);
		virtual ~Belt() = default;
		Length get_length() const;
		void wear() const override;
	};
} // namespace clothes

#endif // BELT_H
