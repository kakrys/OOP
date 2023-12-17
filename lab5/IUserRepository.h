//
// Created by vadya on 17.12.2023.
//

#ifndef LAB5_IUSERREPOSITORY_H
#define LAB5_IUSERREPOSITORY_H

#pragma once

#include "IRepository.h"
#include "User.h"

class IUserRepository : public IRepository<User>
{
public:
    virtual User* getById(int id) = 0;
    virtual User* getByLogin(const std::string& login) = 0;
};

#endif //LAB5_IUSERREPOSITORY_H
