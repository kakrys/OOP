//
// Created by vadya on 17.12.2023.
//

#ifndef LAB5_FILEUSERREPOSITORY_H
#define LAB5_FILEUSERREPOSITORY_H

#pragma once
#include "IUserRepository.h"
#include <vector>
#include <fstream>

class FileUserRepository : public IUserRepository
{
public:
    FileUserRepository(const std::string& filePath) : filePath(filePath)
    {
        loadUsersFromFile();
    }

    ~FileUserRepository() {
        saveUsersToFile();
    }

    std::vector<User> getAll() const
    {
        return users;
    }

    void add(const User& user)
    {
        users.push_back(user);
        saveUsersToFile();
    }

    void Remove(const User& user)
    {
        users.erase(std::remove_if(users.begin(), users.end(), [&user](const User& u) {return u.getId() == user.getId();}), users.end());
        saveUsersToFile();
    }

    void update(const User& user)
    {
        int userId = user.getId();
        User* userToUpdate = getById(userId);
        if (!userToUpdate)
        {
            return;
        }
        userToUpdate->setLogin(user.getLogin());
        userToUpdate->setPassword(user.getPassword());
        userToUpdate->setName(user.getName());
        saveUsersToFile();
    }

    User* getById(int id) override {
        for (User& user : users) {
            if (user.getId() == id) {
                return &user;
            }
        }

        return nullptr;
    }

    User* getByLogin(const std::string& login) override
    {
        for (User& user : users) {
            if (user.getLogin() == login) {
                return &user;
            }
        }

        return nullptr;
    }

private:
    void loadUsersFromFile()
    {
        users.clear();

        std::ifstream file(filePath);
        if (!file.is_open())
        {
            return;
        }

        std::string line;
        while (getline(file, line)) {
            std::vector<std::string> parts = split(line, ',');
            int id = std::stoi(parts[0]);
            std::string login = parts[1];
            std::string password = parts[2];
            std::string name = parts[3];

            User user(id, login, password, name);
            users.push_back(user);
        }

        file.close();
    }

    void saveUsersToFile() const
    {
        std::ofstream file(filePath, std::ios::out | std::ios::trunc);
        if (!file.is_open())
        {
            return;
        }

        for (const User& user : users)
        {
            file << user.getId() << "," << user.getLogin() << "," << user.getPassword() << "," << user.getName() << std::endl;
        }

        file.close();
    }

    std::vector<std::string> split(const std::string& str, char delimiter) const
    {
        std::vector<std::string> parts;
        std::string part;

        for (char c : str)
        {
            if (c == delimiter)
            {
                if (!part.empty())
                {
                    parts.push_back(part);
                    part.clear();
                }
            }
            else
            {
                part += c;
            }
        }
        if (!part.empty())
        {
            parts.push_back(part);
        }
        return parts;
    }

private:
    std::vector<User> users;
    std::string filePath;
};

#endif //LAB5_FILEUSERREPOSITORY_H
