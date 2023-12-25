#pragma once
#include <vector>

template <typename T>
class IDataRepository
{
public:
	virtual std::vector<T> Get() const = 0;
	virtual void add(T item) = 0;
	virtual void remove(T item) = 0;
	virtual void update() = 0;
};