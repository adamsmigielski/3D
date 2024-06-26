/** License
*
* Copyright (c) 2015 Adam Śmigielski
*
*
*  Permission is hereby granted, free of charge, to any person obtaining a
*      copy of this software and associated documentation files (the
*      "Software"), to deal in the Software without restriction, including
*      without limitation the rights to use, copy, modify, merge, publish,
*      distribute, sublicense, and/or sell copies of the Software, and to
*      permit persons to whom the Software is furnished to do so, subject to
*      the following conditions: The above copyright notice and this permission
*      notice shall be included in all copies or substantial portions of the
*      Software.
*
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
*      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
*      MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*      IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
*      CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
*      TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
*      SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
**/

/**
* @author Adam Śmigielski
* @file Singleton.hpp
**/

#pragma once

namespace Containers
{
    template <class T>
    class Singleton
    {
    public:
        using value_type = T;
        using pointer = T *;

        virtual ~Singleton();

        static pointer Get_singleton();
        static void Release();

    protected:
        Singleton();

    private:
        static pointer s_singleton;
    };

    template <class T>
    Singleton<T>::Singleton()
    {
        s_singleton = (pointer) this;
    }

    template <class T>
    Singleton<T>::~Singleton()
    {
        s_singleton = nullptr;
    }

    template <class T>
    typename Singleton<T>::pointer Singleton<T>::Get_singleton()
    {
        if (nullptr == s_singleton)
        {
            new T;
        }

        return s_singleton;
    }

    template <typename T>
    void Singleton<T>::Release()
    {
        if (nullptr != s_singleton)
        {
            auto singleton = s_singleton;
            delete singleton;
        }
    }

    template <class T>
    typename Singleton<T>::pointer Singleton<T>::s_singleton = nullptr;
}
