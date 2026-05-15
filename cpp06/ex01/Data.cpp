#include "Data.hpp"

Data::Data() : id(0), name(""), value(0.0)
{
}

Data::Data(int id, const std::string& name, double value) : id(id), name(name), value(value)
{
}

Data::Data(const Data& that) : id(that.id), name(that.name), value(that.value)
{
}

Data& Data::operator=(const Data& that)
{
	if (this != &that)
	{
		id = that.id;
		name = that.name;
		value = that.value;
	}
	return *this;
}

Data::~Data()
{
}
