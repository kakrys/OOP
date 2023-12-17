#include "FileUserRepository.h"
#include "UserManager.h"
#include <windows.h>
#include <memory>

int main()
{
    std::string filePath = "users.txt";

    std::unique_ptr<IUserRepository> userRepository(new FileUserRepository(filePath));

    std::unique_ptr<UserManager> userManager(new UserManager(userRepository.get()));

    User user(1, "Vadim", "123456", "name");

    userManager->signIn(user);

    bool isAuthorized = userManager->isAuthorized();
    if (isAuthorized)
    {
        std::cout << "User is authorized" << std::endl;
    }
    else {
        std::cout << "User is not authorized" << std::endl;
    }

    userManager->signOut(user);

    return 0;

}