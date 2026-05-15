#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include "Data.hpp"
# include <stdint.h>

// "serialization" means converting an object's data/content into a format 
// that can be stored or transmitted (JSON, binary, etc.)

// this exercise is using the term in a simplified way, 
// it's really demonstrating:
//
// - reinterpret_cast: converting a pointer to a sufficiently large 
//   integer type (uintptr_t) and back
//
// - Guarantee that uintptr_t can hold a pointer value without loss
//
// - Proof that the round-trip (pointer → integer → pointer) 
//   yields the exact same address

// - It does NOT serialize the id, name, or value members of Data
//
// - It does NOT create a portable representation of the data
//
// - It does NOT convert the struct contents to bytes

class Serializer
{
	private:

		Serializer();
		Serializer(const Serializer& that);
		Serializer& operator=(const Serializer& that);
		~Serializer();

	public:

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
