#ifndef JWSFILE_H
#define JWSFILE_H

#include <iostream>
#include <fstream>

class jwsFile
{
    public:
        jwsFile();
        virtual ~jwsFile();

        int Open(std::string name);
        int Close();

        // getters / setters
        void GetLine(char lineChar){ getline(m_in, m_buffer, lineChar); }
        std::string GetBuffer(){ return m_buffer; }

    protected:

    private:
        std::ifstream m_in;
        std::string m_buffer;
};

#endif // JWSFILE_H
