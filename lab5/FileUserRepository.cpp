#include "FileUserRepository.h"
#include <iostream>
#include <fstream>

FileUserRepository::FileUserRepository()
{
	_users.clear();
	std::ifstream in("users.txt");
	if (in.is_open())
	{
		User user;
		while (in >> user.id >> user.name >> user.login >> user.password)
		{
			_users.push_back(user);
		}
	}
	in.close();
}

User FileUserRepository::getById(int id)
{
	User user;
	for (const User& userF : _users)
	{
		if (userF.id == id)
		{
			user = userF;
			break;
		}
	}
	return user;
}

User FileUserRepository::getByLogin(const std::string& login)
{
	User user;
	for (const User& userF : _users)
	{
		if (userF.login == login)
		{
			user = userF;
			return user;
		}
	}
	return user;
}

std::vector<User> FileUserRepository::Get() const { return _users; }

void FileUserRepository::add(User item)
{
	_users.push_back(item);
	update();
}

void FileUserRepository::remove(User item)
{
	auto it = _users.begin();
	while (it != _users.end())
	{
		if (it->id == item.id)
		{
			_users.erase(it);
			break;
		}
		else
		{
			++it;
		}
	}
	update();
}

void FileUserRepository::update()
{
	std::ofstream out("users.txt");
	if (out.is_open())
	{
		for (auto const& user : _users)
		{
			out << user.id << " " << user.name << " " << user.login << " " << user.password;
		}
	}
	out.close();
}

User FileUserRepository::checkLogin()
{
	std::ifstream in("lastAuthorized.txt");
	User user;
	if (in.is_open())
	{
		in >> user.id >> user.name >> user.login >> user.password;
		in.close();
	}
	return user;
}

int FileUserRepository::createNewId()
{
	return _users.size() + 1;
}