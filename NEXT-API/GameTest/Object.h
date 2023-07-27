//-----------------------------------------------------------------------------
// Object.h
// Base object class
//-----------------------------------------------------------------------------
#pragma once
#include <string>

class Object
{
public:
	std::string name;

	bool operator!= (Object obj);
	bool operator== (Object obj);
};

