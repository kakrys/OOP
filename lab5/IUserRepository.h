#pragma once

#include "User.h"
#include "IDataRepository.h"

class IUserRepository : IDataRepository<User>
{
public:
	virtual User getById(int id) = 0;
	virtual User getByLogin(const std::string& name) = 0;
};