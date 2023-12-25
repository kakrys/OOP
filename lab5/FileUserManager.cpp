#include "FileUserManager.h"

#include <iostream>
#include <fstream>

FileUserManager::FileUserManager() {}

void FileUserManager::signIn(User user)
{
	_curUser = user;
	std::ofstream out("lastAuthorized.txt");
	if (out.is_open())
	{
		out << user.id << " " << user.name << " " << user.login << " " << user.password;
	}
	out.close();
}

void FileUserManager::signOut()
{
	_curUser = User();
	std::ofstream out("lastAuthorized.txt");
	if (out.is_open())
	{
		out << "";
	}
	out.close();
}

bool FileUserManager::isAuthorized()
{
	return !_curUser.login.empty();
}

bool FileUserManager::isRegistered(User user)
{
	User userN;
	std::ifstream in("users.txt");
	std::vector<User> users;
	while (in >> userN.id >> userN.name >> userN.login >> userN.password)
	{
		users.push_back(userN);
	}
	in.close();
	for (User u : users)
	{
		if (u.id == user.id || u.login == user.login)
		{
			return true;
		}

	}
	return false;

}

void FileUserManager::signUp(std::string name, std::string login, std::string password)
{
	User user = _userRepository.getByLogin(login);

	if (user.login.empty())
	{
		User newUser;
		newUser.id = _userRepository.createNewId();
		newUser.name = name;
		newUser.login = login;
		newUser.password = password;

		_userRepository.add(newUser);
		signIn(newUser);
	}
	else
	{
		std::cout << "Этот логин уже занят, выберите другой." << std::endl;
	}
}