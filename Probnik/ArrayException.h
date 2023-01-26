#pragma once
#include "ArrayException.h"
#include <exception>
#include <string>
using namespace std;

class Bad_Length : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Error: (Bad_Length) length <= 0";
	}

};

class Bad_range : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Error: (Bad_range) newLength > m_length";
	}
};

class Bad_resize : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Error: (Bad_resize) newLength <= 0";
	}
};

class Bad_remove : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Error: (Bad_remove) 0 >= index >= m_length";
	}
};

class Bad_insertBefore : public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "Error: (Bad_insertBefore) there is no index";
	}
};