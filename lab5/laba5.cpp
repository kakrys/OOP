#include "FileUserManager.h"
#include "FileUserRepository.h"
#include <iostream>

int main()
{
	setlocale(LC_ALL, "Rus");

	FileUserManager manager;
	FileUserRepository repository;
	std::string login, password, name;
	std::string userName = "Vadim";
	int choice = 1;

	User user = repository.checkLogin();

	if (!user.login.empty())
	{
		manager.signIn(user);
		std::cout << "Успешная авторизация в последний аккаунт. 0 - выход, 1 - сменить пользователя, 2 - зарегистрировать нового." << std::endl;
	}

	while (choice != 0)
	{
		if (!manager.isAuthorized())
		{
			std::cout << "1 - вход, 2 - регистриция." << std::endl;
		}

		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "--Вход--" << std::endl;
			std::cout << "Введите ваш логин: " << std::endl;
			std::cin >> login;
			std::cout << "Введите ваш пароль: " << std::endl;
			std::cin >> password;

			user = repository.getByLogin(login);
			if (!user.login.empty() && user.password == password)
			{
				manager.signIn(user);
				std::cout << "Успешная авторизация. 0 - выход, 1 - сменить пользователя, 2 - зарегистрировать нового." << std::endl;
			}
			else
			{
				std::cout << "Вы неправильно ввели логин или пароль." << std::endl;
			}
			break;

		case 2:
			std::cout << "--Регистрация--" << std::endl;
			std::cout << "Введите желаемый логин: " << std::endl;
			std::cin >> login;
			std::cout << "Введите пароль: " << std::endl;
			std::cin >> password;
			std::cout << "Напишите ваше имя: " << std::endl;
			std::cin >> name;

			manager.signUp(name, login, password);
			std::cout << "Успешная регистрация. 1 - сменить пользователя, 2 - зарегистрировать ещё одного." << std::endl;
			break;

		default:
			break;
		}
	}

	return 0;
}