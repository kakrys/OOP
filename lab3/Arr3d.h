//
// Created by vadya on 11.12.2023.
//

#ifndef LAB3_ARR3D_H
#define LAB3_ARR3D_H

#include <iostream>
#include <vector>

template<class T>
class Array3d
{
private:
    std::vector<T> data;
    int dim0, dim1, dim2;

public:
    Array3d(int dim0, int dim1, int dim2) : dim0(dim0), dim1(dim1), dim2(dim2), data(dim0* dim1* dim2) {}

    T& operator()(int i, int j, int k)
    {
        return data[i * dim1 * dim2 + j * dim2 + k];
    }

    std::vector<T> GetValues0(int i) const;

    std::vector<T> GetValues1(int j) const;

    std::vector<T> GetValues2(int k) const;

    std::vector<T> GetValues01(int i, int j) const;

    std::vector<T> GetValues02(int i, int k) const;

    std::vector<T> GetValues12(int j, int k) const;

    void SetValues0(int i, const std::vector<std::vector<T>>& arr);

    void SetValues1(int j, const std::vector<std::vector<T>>& arr);

    void SetValues2(int k, const std::vector<std::vector<T>>& arr);

    void SetValues01(int i, int j, const std::vector<std::vector<T>>& arr);

    void SetValues02(int i, int k, const std::vector<std::vector<T>>& arr);

    void SetValues12(int j, int k, const std::vector<std::vector<T>>& arr);
};

template<typename T>
std::vector<T> Array3d<T>::GetValues0(int i)  const
{
    std::vector<T> slice(dim1 * dim2);
    for (int j = 0; j < dim1; j++)
    {
        for (int k = 0; k < dim2; k++)
        {
            slice[j * dim2 + k] = data[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return slice;
}


template<typename T>
std::vector<T> Array3d<T>::GetValues1(int j) const
{
    std::vector<T> slice(dim0 * dim2);
    for (int i = 0; i < dim0; i++)
    {
        for (int k = 0; k < dim2; k++)
        {
            slice[i * dim2 + k] = data[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return slice;
}

template<typename T>
std::vector<T> Array3d<T>::GetValues2(int k) const
{
    std::vector<T> slice(dim0 * dim1);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            slice[i * dim1 + j] = data[i * dim1 * dim2 + j * dim2 + k];
        }
    }
    return slice;
}

template<typename T>
std::vector<T> Array3d<T>::GetValues01(int i, int j) const
{
    std::vector<T> slice(dim2);
    for (int k = 0; k < dim2; k++)
    {
        slice[k] = data[i * dim1 * dim2 + j * dim2 + k];
    }
    return slice;
}

template<typename T>
std::vector<T> Array3d<T>::GetValues02(int i, int k) const
{
    std::vector<T> slice(dim1);
    for (int j = 0; j < dim1; j++)
    {
        slice[j] = data[i * dim1 * dim2 + j * dim2 + k];
    }
    return slice;
}

template<typename T>
std::vector<T> Array3d<T>::GetValues12(int j, int k) const
{
    std::vector<T> slice(dim0);
    for (int i = 0; i < dim0; i++)
    {
        slice[i] = data[i * dim1 * dim2 + j * dim2 + k];
    }
    return slice;
}

template<typename T>
void Array3d<T>::SetValues0(int i, const std::vector<std::vector<T>>& arr)
{
    for (int j = 0; j < dim1; j++)
    {
        for (int k = 0; k < dim2; k++)
        {
            data[i * dim1 * dim2 + j * dim2 + k] = arr[j][k];
        }
    }
}

template<typename T>
void Array3d<T>::SetValues1(int j, const std::vector<std::vector<T>>& arr)
{
    for (int i = 0; i < dim0; i++)
    {
        for (int k = 0; k < dim2; k++)
        {
            data[i * dim1 * dim2 + j * dim2 + k] = arr[i][k];
        }
    }
}

template<typename T>
void Array3d<T>::SetValues2(int k, const std::vector<std::vector<T>>& arr)
{
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            data[i * dim1 * dim2 + j * dim2 + k] = arr[i][j];
        }
    }
}

template<typename T>
void Array3d<T>::SetValues01(int i, int j, const std::vector<std::vector<T>>& arr)
{
    for (int k = 0; k < dim2; k++)
    {
        data[i * dim1 * dim2 + j * dim2 + k] = arr[k];
    }
}

template<typename T>
void Array3d<T>::SetValues02(int i, int k, const std::vector<std::vector<T>>& arr)
{
    for (int j = 0; j < dim1; j++)
    {
        data[i * dim1 * dim2 + j * dim2 + k] = arr[j];
    }
}

template<typename T>
void Array3d<T>::SetValues12(int j, int k, const std::vector<std::vector<T>>& arr)
{
    for (int i = 0; i < dim0; i++)
    {
        data[i * dim1 * dim2 + j * dim2 + k] = arr[i];
    }
}


template<typename T>
Array3d<T> ones(int dim0, int dim1, int dim2)
{
    Array3d<T> arr(dim0, dim1, dim2);
    T one = static_cast<T>(1);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                arr(i, j, k) = one;
            }
        }
    }
    return arr;
}


template<typename T>
Array3d<T> zeros(int dim0, int dim1, int dim2)
{
    Array3d<T> arr(dim0, dim1, dim2);
    T zero = static_cast<T>(0);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                arr(i, j, k) = zero;
            }
        }
    }
    return arr;
}

template<typename T>
Array3d<T> fill(int dim0, int dim1, int dim2, T value)
{
    Array3d<T> arr(dim0, dim1, dim2);
    for (int i = 0; i < dim0; i++)
    {
        for (int j = 0; j < dim1; j++)
        {
            for (int k = 0; k < dim2; k++)
            {
                arr(i, j, k) = value;
            }
        }
    }
    return arr;
}


#endif //LAB3_ARR3D_H
