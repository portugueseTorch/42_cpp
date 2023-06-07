#include "../inc/Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &obj) { (void) obj; }

Serializer &Serializer::operator=(const Serializer &obj) { (void) obj; return *this; }

Serializer::~Serializer() {}
