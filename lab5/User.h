//
// Created by vadya on 17.12.2023.
//

#ifndef LAB5_USER_H
#define LAB5_USER_H

#pragma once
#include <string>

class User
{
public:
    int id;
    std::string login;
    std::string password;
    std::string name;

    User(const int& id, const std::string& login, const std::string& password, const std::string& name)
            : id(id), login(login), password(password), name(name) {}

    int getId() const
    {
        return id;
    }

    void setId(int newId)
    {
        id = newId;
    }

    const std::string& getLogin() const
    {
        return login;
    }

    void setLogin(const std::string& newLogin)
    {
        login = newLogin;
    }

    const std::string& getPassword() const
    {
        return password;
    }
    void setPassword(const std::string& newPassword)
    {
        password = newPassword;
    }

    const std::string& getName() const
    {
        return name;
    }
    void setName(const std::string& newName)
    {
        name = newName;
    }
};

#endif //LAB5_USER_H
