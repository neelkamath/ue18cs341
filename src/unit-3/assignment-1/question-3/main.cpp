/* implement a singleton which can die and can be re_created. */

#include <iostream>

class singleton
{
    singleton() = default;

    static singleton const * instance;
public:
    singleton(singleton const &) = delete;

    singleton & operator=(singleton const &) = delete;

    static singleton const * get_instance()
    {
        std::cout << "singleton::get_instance()\n";
        if (instance == nullptr)
        {
            instance = new singleton;
            std::cout << "new singleton: " << instance << '\n';
        }
        return instance;
    }

    static void destroy()
    {
        std::cout << "singleton::destroy()\n";
        if (instance != nullptr)
        {
            std::cout << "delete instance\n";
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
    return 0;
}
