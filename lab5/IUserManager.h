//
// Created by vadya on 17.12.2023.
//

#ifndef LAB5_IUSERMANAGER_H
#define LAB5_IUSERMANAGER_H

#pragma once

#include <combaseapi.h>
#include "User.h"

interface IUserManager
        {
                public:
                void signIn(User& user);
                void signOut(User& user);
                bool isAuthorized();
        };

#endif //LAB5_IUSERMANAGER_H
