#include <iostream>
#include "Arr3d.h"

int main()
{
    Array3d<int> arr(3, 3, 3);

    arr(0, 0, 0) = 1;
    arr(1, 1, 1) = 22;
    arr(2, 2, 2) = 333;

    std::vector<int> slice0 = arr.GetValues0(2);
    for (int i = 0; i < slice0.size(); i++)
    {
        std::cout << slice0[i] << " ";
    }
    std::cout << '\n' << '\n';

    Array3d<int> ones_arr = Array3d<int>::ones(2, 2, 2);
    Array3d<int> zeros_arr = Array3d<int>::zeros(2, 2, 2);
    Array3d<int> fill_arr = Array3d<int>::fill(2,2,2,45);

    std::vector mas1 = ones_arr.GetValues01(0,0);
    for (int i = 0; i < mas1.size(); i++)
    {
        std::cout << mas1[i] << " ";
    }

    std::cout << std::endl;

    std::vector mas2 = zeros_arr.GetValues02(0, 0);
    for (int i = 0; i < mas2.size(); i++)
    {
        std::cout << mas2[i] << " ";
    }

    std::cout << std::endl;

    std::vector mas3 = fill_arr.GetValues1(0);
    for (int i = 0; i < mas3.size(); i++)
    {
        std::cout << mas3[i] << " ";
    }


    return 0;
}
