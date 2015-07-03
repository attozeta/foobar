#include <iostream>
#include <vector>
#include <cstdlib>

static void sieve(std::vector<bool> &a)
{
    a[0] = a[1] = 0;
    for (size_t i=2; i*i<a.size(); i++)
        for (size_t j=2*i; a[i] && j<a.size(); j+=i)
            a[j] = 0;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "usage: " << *argv << " N" << std::endl;
        return 0;
    }

    size_t n = std::atoi(argv[1]);
    std::vector<bool> a(n, true);

    sieve(a);

    for (size_t i=0; i<n; i++)
        if (a[i])
            std::cout << i << std::endl;

    return 0;
}

