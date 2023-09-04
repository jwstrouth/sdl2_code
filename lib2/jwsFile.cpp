#include "jwsFile.h"

jwsFile::jwsFile()
{
    //ctor
}

jwsFile::~jwsFile()
{
    //dtor
}

int jwsFile::Open(std::string name)
{
    m_in.open(name);

    if(!m_in.good())
    {
        std::cout << "jwsFile::Open: failed to open: " << name << std::endl;
        return -1;
    }

    std::cout << "jwsFile::Open: opened file: " << name << std::endl;

    return 0;
}

int jwsFile::Close()
{
    m_in.close();

    return 0;
}
