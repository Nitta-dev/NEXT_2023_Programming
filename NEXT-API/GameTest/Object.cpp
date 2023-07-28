#include "stdafx.h"
#include "Object.h"

bool Object::operator!= (Object obj)
{
	return name != obj.name;
}

bool Object::operator== (Object obj)
{
	return name == obj.name;
}