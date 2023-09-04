#ifndef JWSSTRING_H
#define JWSSTRING_H

#include <iostream>
#include <string>

using namespace std;

class jwsString
{
    public:
        jwsString();
        jwsString(const char* s){ m_str = s; }
        virtual ~jwsString();

        operator char*(){ return (char*)m_str.c_str(); }
        void operator=(const char* str){ m_str = str; }

        char* GetData(){ return (char*)m_str.data(); }

    protected:

    private:
        string m_str;
};

#endif // JWSSTRING_H
