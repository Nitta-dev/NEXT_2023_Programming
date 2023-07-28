#pragma once
#include <string>

/// <summary>
/// Base class for game objects
/// </summary>
class Object
{
public:
	std::string name;

	bool operator!= (Object obj);
	bool operator== (Object obj);
};

