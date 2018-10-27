#ifndef RANDOMIZER_H
#define RANDOMIZER_H
#include <cstdlib>
#include <random>
#include <vector>

namespace ADS101
{
template <class T>
class randomizer
{
private:
    std::mt19937 m_mt;
    // Checks if T is an integer, required to let it decide which uniform
    // distribution to use
    T generateRandomNumber(int endRange)
    {
        if (std::numeric_limits<T>::is_integer)
        {
            std::uniform_int_distribution<int> distribution(0, endRange);
            return static_cast<T>(distribution(m_mt));
        }
        else
        {
            std::uniform_real_distribution<double> distribution(0, endRange + 1);
            return static_cast<T>(distribution(m_mt));
        }
    }

public:
    randomizer() : m_mt((std::random_device())()) {}

    std::vector<T> generateVector(const int vectorSize)
    {
        std::vector<T> tempVector;
        for (int i = 0; i < vectorSize; i++)
        {
            tempVector.push_back(generateRandomNumber(100));
        }
        return tempVector;
    }
};
} // namespace ADS101
#endif // RANDOMIZER_H
