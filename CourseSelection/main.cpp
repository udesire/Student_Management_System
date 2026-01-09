import std;
import registrar;
int main()
{
        auto&& system = Registrar::getInstance();
        system.exec();
        std::cout << "this is a test ?" << std::endl;
        return 0;
}
