/*
- implement a n-ton.
  	Given a class, implement such that the client can create at most n objects
*/

#include <iostream>

template <unsigned n = 1>
class n_ton
{
    n_ton() = default;
public:
    n_ton & operator=(n_ton const &) = delete;

    template <unsigned i = 0>
    static n_ton const get_instance()
    {
        static_assert(i < n, "Index out of bounds.");
        static n_ton const instance;
        std::cout << "n_ton<" << n << ">::get_instance<" << i << ">(): " << &instance << '\n';
        return instance;
    }
};

int main()
{
    n_ton<2>::get_instance<>();
    n_ton<2>::get_instance<0>();
    n_ton<2>::get_instance<1>();
    return 0;
}
