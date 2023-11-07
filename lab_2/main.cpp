#include <iostream>
#include <vector>

template<typename T>
class Arry3d {
private:
    std::vector<T> data;
    int size0, size1, size2;

public:
    Arry3d(int size0, int size1, int size2) : size0(size0), size1(size1), size2(size2) {
        data.resize(size0 * size1 * size2);
    }

    friend std::ostream &operator<<(std::ostream &os, const Arry3d<T> &arr) {
        for (int i = 0; i < arr.size0; i++) {
            for (int j = 0; j < arr.size1; j++) {
                for (int k = 0; k < arr.size2; k++)
                    os << arr.data[i * arr.size1 * arr.size2 + j * arr.size2 + k] << " ";
                os << std::endl;
            }
            os << std::endl;
        }
        return os;
    }

    T &GetValue0(int i) {
        return data[i * size1 * size2];
    }

    T &GetValue1(int j) {
        return data[j * size2];
    }

    T &GetValue2(int k) {
        return data[k];
    }

    std::vector<T> GetValues01(int i, int j) {
        std::vector<T> values01;
        for (int k = 0; k < size2; k++)
            values01.push_back(data[i * size1 * size2 + j * size2 + k]);
        return values01;
    }

    std::vector<T> GetValues02(int i, int k) {
        std::vector<T> values02;
        for (int j = 0; j < size1; j++)
            values02.push_back(data[i * size1 * size2 + j * size2 + k]);
        return values02;
    }

    std::vector<T> GetValues12(int j, int k) {
        std::vector<T> values12;
        for (int i = 0; i < size0; i++)
            values12.push_back(data[i * size1 * size2 + j * size2 + k]);
        return values12;
    }

    void SetValues0(int i, const std::vector<std::vector<T>> &values0) {
        for (int j = 0; j < size1; j++)
            for (int k = 0; k < size2; k++)
                data[i * size1 * size2 + j + k] = values0[j][k];
    }

    void SetValues1(int j) {
        return data[j * size2];
    }

    void SetValues2(int k) {
        return data[k];
    }

    void SetValues01(int i, int j, const std::vector<T> &values01) {
        for (int k = 0; k < size2; k++)
            data[i * size1 * size2 + j * size2 + k] = values01[k];
    }

    void SetValues02(int i, int k, const std::vector<T> &values02) {
        for (int j = 0; j < size1; j++)
            data[i * size1 * size2 + j * size2 + k] = values02[j];
    }

    void SetValues12(int j, int k, const std::vector<T> &values12) {
        for (int i = 0; i < size0; i++)
            data[i * size1 * size2 + j * size2 + k] = values12[i];
    }

    static Arry3d<T> CreateFill(int size0, int size1, int size2, const T &value) {
        Arry3d<T> arr(size0, size1, size2);
        for (int i = 0; i < size0; i++)
            for (int j = 0; j < size1; j++)
                for (int k = 0; k < size2; k++)
                    arr.data[i * size1 * size2 + j * size2 + k] = value;
        return arr;
    }
};

int main() {
    Arry3d<int> arr = Arry3d<int>::CreateFill(2, 3, 4, 0);

    std::cout << arr << "\tarr" << std::endl;

    arr.SetValues0(0, {{1,  2,  3,  4},
                       {5,  6,  7,  8},
                       {11, 22, 33, 44},
                       {55, 66, 77, 88}});

    std::cout << arr << std::endl;
//    std::vector<int> values01 = arr.GetValues01(0, 1);
//    for (int value : values01)
//        std::cout << value << " ";
//    std::cout << "\tGetValues01(i:0, j:1)" << std::endl;
//
//    std::vector<int> values02 = arr.GetValues02(0, 2);
//    for (int value : values02)
//        std::cout << value << " ";
//    std::cout << "\tGetValues02(i:0, k:2)" << std::endl;
//
//    std::vector<int> values12 = arr.GetValues12(1, 2);
//    for (int value : values12)
//        std::cout << value << " ";
//    std::cout << "\tGetValues12(j:1, k:2)" << std::endl;

    return 0;
}
