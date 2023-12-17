//
// Created by vadya on 17.12.2023.
//

#ifndef LAB5_USERMANAGER_H
#define LAB5_USERMANAGER_H


#include "IUserManager.h"
#include "IUserRepository.h"
#include "iostream"
class UserManager : public IUserManager
{
private:
    User* currentUser;
    IUserRepository* userRepository;
public:

    UserManager(IUserRepository* userRepository) : userRepository(userRepository), currentUser(nullptr)
    {
    }

    void signIn(User& user)
    {
        currentUser = &user;
    }

    void signOut(User& user)
    {

        currentUser = nullptr;
        std::cout << user.getLogin() << " has been signed out" << std::endl;

    }

    bool isAuthorized()
    {
        return currentUser != nullptr;
    }
};

#endif //LAB5_USERMANAGER_H
