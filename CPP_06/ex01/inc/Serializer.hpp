#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>

typedef struct Data {
	std::string content;
} Data;

class Serializer
{
	public:
		~Serializer();

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	private:
		Serializer();
		Serializer(const Serializer &obj);
		Serializer &operator=(const Serializer &obj);
};

#endif
