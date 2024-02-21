#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <cstdint>
#include <string>

struct Data
{
	std::string data;
};

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const &source);
		~Serializer();

		Serializer &operator=(Serializer const &source);
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
