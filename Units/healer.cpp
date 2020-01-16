#include "unit.h"


Healer::Healer(int HP, int AP, int initiative, int row, int col)
    : Unit(HP, AP, initiative, row, col)
{
    //std::cerr<< "Healer constructor called"<< std::endl;
}


Healer::~Healer()
{
    //std::cerr<< "Healer destructor called"<< std::endl;
}


std::string Healer::info() const
{
    return "Healer\n"
            "Id: " + std::to_string(getId()) + "; "
            "Health: " + std::to_string(health().first) + '/' + std::to_string(health().second) + ";\n";
}


std::ostream& operator<<(std::ostream& out, const Healer& h)
{
    return out<< "Healer (id=" << h.getId() <<") says hello!"<< std::endl;
}
