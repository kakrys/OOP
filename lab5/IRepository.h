//
// Created by vadya on 17.12.2023.
//

#pragma once
#include <string>
#include <vector>

#pragma once
#include <string>
#include <vector>
#include <combaseapi.h>


template <typename T>
interface IRepository
        {
                public:
                std::vector<T> getAll() const;
                void add(const T& user) ;
                void Remove(const T& user);
                void update(const T& user);
        };

