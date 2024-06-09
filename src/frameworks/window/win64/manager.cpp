/** License
*
* Copyright (c) 2015 Adam Œmigielski
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
* @author Adam Œmigielski
* @file Manager.hpp
**/

#include "pch.hpp"

#include "window.hpp"


namespace Window
{
    namespace win64
    {
        Manager::Manager()
            : m_loop_state(loop_state::Halt)
        {
        }

        Manager::~Manager()
        {
            Stop_event_processing();

            m_loop_state = loop_state::Unknown;

            destroy_windows();
        }

        Platform::int32 Manager::Start_event_processing()
        {
            if (loop_state::Halt != m_loop_state)
            {
                ASSERT(0);

                ERRLOG("Event processing already started");
                return Returns::Invalid_object;
            }

            loop();

            return Returns::Window_success;
        }

        Platform::int32 Manager::Stop_event_processing()
        {
            if (loop_state::Run == m_loop_state)
            {
                m_loop_state = loop_state::Stoping;
                return Returns::Window_success;
            }
            else
            {
                ERRLOG("Event processing not started");
                return Returns::Invalid_object;
            }
        }

        Platform::int32 Manager::Process_events()
        {
            for (auto& ptr : m_windows)
            {
                auto* window = dynamic_cast<Window*>(ptr.get());
                window->Process_messages();
            }

            return Returns::Window_success;
        }


        /* Window management */
        Manager::weak_window_ptr Manager::Create_window()
        {
            auto wnd = new Window();

            if (nullptr == wnd)
            {
                ASSERT(0);
                ERRLOG("Failed to allocate memory");
                return weak_window_ptr();
            }
            attach_window(wnd);

            return attach_window(wnd);
        }

        Manager::weak_window_ptr Manager::Take_ownership(Window* window)
        {
            for (auto& ptr : m_windows)
            {
                if (ptr.get() == window)
                {
                    //return weak_window_ptr(ptr);
                    return weak_window_ptr();
                }
            }
            
            return attach_window(window);
        }

        Manager::weak_window_ptr Manager::attach_window(Window* window)
        {
            //auto ptr = std::make_shared<Window>(window);
            shared_window_ptr ptr(window);
            m_windows.push_back(ptr);
            //return weak_window_ptr(m_windows.back());
            return weak_window_ptr(ptr);
        }

        void Manager::destroy_windows()
        {
            m_windows.clear();
        }

        void Manager::loop()
        {
            m_loop_state = loop_state::Starting;

            LOG("Window's Manager's loop start");

            m_loop_state = loop_state::Run;

            while (loop_state::Run == m_loop_state)
            {
                //Update windows
                if (Returns::Window_success != Process_events())
                {
                    break;
                }

                std::this_thread::yield();
            }

            LOG("Window's Manager's loop stop");

            m_loop_state = loop_state::Halt;
        }
    }
}
