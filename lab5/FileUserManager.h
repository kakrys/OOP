#pragma once

#include "IUserManager.h"
#include "FileUserRepository.h"

class FileUserManager : IUserManager
{
public:
	FileUserManager();

	virtual void signIn(User user) override;
	virtual void signOut() override;
	virtual bool isAuthorized() override;
	virtual bool isRegistered(User user) override;
	virtual void signUp(std::string name, std::string login, std::string password) override;

private:
	User _curUser;
	FileUserRepository _userRepository;
};
