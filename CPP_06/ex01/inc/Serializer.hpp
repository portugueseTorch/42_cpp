#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <cstdint>

typedef struct Data {
	char *content;
} Data;

class Serializer
{
	public:
		~Serializer();
	private:
		Serializer();
		Serializer(const Serializer &obj);
		Serializer &operator=(const Serializer &obj);

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
