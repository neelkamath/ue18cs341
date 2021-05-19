/*
- implement a singleton where resources can be released - flag an error if the
	object is dead
*/

#include <iostream>

class singleton
{
    static singleton const * instance;

    singleton() = default;
public:
    singleton(singleton const &) = delete;

    singleton & operator=(singleton const &) = delete;

    static singleton const * get_instance()
    {
        std::cout << "get_instance(): getting ";
        if (instance == nullptr)
        {
            instance = new singleton;
            std::cout << "new ";
        }
        else
            std::cout << "existing ";
        std::cout << "instance " << &instance << '\n';
        return instance;
    }

    static void destroy()
    {
        std::cout << "destroy(): ";
        if (instance == nullptr)
            std::cerr << "nothing to destroy\n";
        else
        {
            std::cout << "destroying instance " << &instance << '\n';
            delete instance;
            instance = nullptr;
        }
    }
};

singleton const * singleton::instance = nullptr;

int main()
{
    singleton::destroy();
    singleton::get_instance();
    singleton::get_instance();
    singleton::destroy();
    singleton::destroy();
    singleton::get_instance();
    singleton::destroy();
    return 0;
}
