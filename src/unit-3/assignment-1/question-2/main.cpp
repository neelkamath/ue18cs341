/* implement a singleton in a class hierarchy */

#include <iostream>

class db_connection
{
    db_connection() = default;

    static db_connection const * instance;
public:
    db_connection(db_connection const &) = delete;

    db_connection & operator=(db_connection const &) = delete;

    static db_connection const * get_instance()
    {
        std::cout << "get_instance(): ";
        if (instance == nullptr)
        {
            instance = new db_connection;
            std::cout << "created instance " << &instance << '\n';
        }
        else
            std::cout << "nothing to create\n";
        return instance;
    }

    static void destroy()
    {
        std::cout << "destroy(): ";
        if (instance == nullptr)
            std::cout << "nothing to delete\n";
        else
        {
            std::cout << "deleting instance " << &instance << '\n';
            delete instance;
            instance = nullptr;
        }
    }
};

db_connection const * db_connection::instance = nullptr;

class postgres_connection : public db_connection
{
};

void demo_db_connection();

void demo_postgres_connection();

int main()
{
    demo_db_connection();
    demo_postgres_connection();
    return 0;
}

void demo_db_connection()
{
    std::cout << "***DEMO_DB_CONNECTION***\n";
    db_connection::destroy();
    db_connection::get_instance();
    db_connection::get_instance();
    db_connection::destroy();
    db_connection::destroy();
    db_connection::get_instance();
    db_connection::destroy();
}

void demo_postgres_connection()
{
    std::cout << "***DEMO_POSTGRES_CONNECTION***\n";
    postgres_connection::destroy();
    postgres_connection::get_instance();
    postgres_connection::get_instance();
    postgres_connection::destroy();
    postgres_connection::destroy();
    postgres_connection::get_instance();
    postgres_connection::destroy();
}
