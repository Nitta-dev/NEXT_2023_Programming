#pragma once

/// <summary>
/// Singleton pattern template class
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
class Singleton
{
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}

	Singleton(const Singleton&) = delete;
	void operator= (Singleton const&) = delete;

protected:
	Singleton() {}
};