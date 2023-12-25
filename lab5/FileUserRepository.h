#pragma once

#include "IUserRepository.h"

class FileUserRepository : IUserRepository
{
public:
	FileUserRepository();

	virtual User getById(int id) override;
	virtual User getByLogin(const std::string& login) override;

	virtual std::vector<User> Get() const override;
	virtual void add(User item) override;
	virtual void remove(User item) override;
	virtual void update() override;

	virtual User checkLogin();
	virtual int createNewId();

protected:
	std::vector<User> _users;
};