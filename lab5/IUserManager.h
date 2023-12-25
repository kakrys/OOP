#pragma once
#include "User.h"
#include<string>

class IUserManager
{
public:
	virtual void signIn(User user) = 0;
	virtual void signOut() = 0;
	virtual bool isAuthorized() = 0;
	virtual bool isRegistered(User user) = 0;
	virtual void signUp(std::string name, std::string login, std::string password) = 0;
};