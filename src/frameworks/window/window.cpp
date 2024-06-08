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
* @file Window.cpp
**/

#include "pch.hpp"

#include "window.hpp"

namespace Window
{
    ///////////////////////////////////////////////////////////////
    Window::Window()
        : m_user_data(nullptr)
	{
		/* Nothing to be done here */
	}

	Window::~Window()
	{
        m_user_data = nullptr;
    }

    void * Window::Get_user_data()
    {
        return m_user_data;
    }

    void Window::Set_user_data(void * info)
    {
        m_user_data = info;
    }


    ///////////////////////////////////////////////////////////////
    Manager::Manager()
    {
        /* Nothing to be done */
    }

    Manager::~Manager()
    {
        /* Nothing to be done */
    }


    ///////////////////////////////////////////////////////////////
    Event_handler::Event_handler()
    {
    }

    Event_handler::~Event_handler()
    {
    }

    void Event_handler::On_init(
        Window* window)
    {

    }

    void Event_handler::On_release(
        Window* window)
    {

    }

    Platform::int32 Event_handler::On_deactivation(
        Window* window)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_activation_click(
        Window* window)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_activation(
        Window* window)
    {
        return Returns::Window_success;
    }


    Platform::int32 Event_handler::On_close(
        Window* window,
        bool& should_window_close)
    {
        should_window_close = true;

        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_quit(
        Window* window)
    {
        return Returns::Window_success;
    }


    Platform::int32 Event_handler::On_power_suspend(
        Window* window)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_power_resume(
        Window* window)
    {
        return Returns::Window_success;
    }


    Platform::int32 Event_handler::On_moving(
        Window* window,
        Platform::int32& left,
        Platform::int32& top,
        Platform::int32& right,
        Platform::int32& bottom)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_move(
        Window* window,
        Platform::int32 x,
        Platform::int32 y)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_sizing(
        Window* window,
        Sizing_direction direction,
        Platform::int32& left,
        Platform::int32& top,
        Platform::int32& right,
        Platform::int32& bottom)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_size(
        Window* window,
        Platform::int32 width,
        Platform::int32 height)

    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_maximization(
        Window* window,
        Platform::int32 width,
        Platform::int32 height)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_minimization(
        Window* window,
        Platform::int32 width,
        Platform::int32 height)

    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_other_window_maximized_or_restored(
        Window* window,
        Platform::int32 width,
        Platform::int32 height)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_paint(
        Window* window)
    {
        return Returns::Window_success;
    }

    Platform::int32 Event_handler::On_menu(
        Window* window,
        Platform::uint16 id)

    {
        return Returns::Window_success;
    }

    ////Keyboard
    //bool WindowEventHandler::OnKeyPressed(Ozone::Window::WindowClass * window, const OIS::KeyEvent &arg)
    //{
    //	return true;
    //}
    //
    //bool WindowEventHandler::OnKeyReleased(Ozone::Window::WindowClass * window, const OIS::KeyEvent &arg)
    //{
    //	return true;
    //}
    //
    //
    ////Mouse
    //bool WindowEventHandler::OnMouseMoved(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg)
    //{
    //	return true;
    //}
    //
    //bool WindowEventHandler::OnMousePressed(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg, int id)
    //{
    //	return true;
    //}
    //
    //bool WindowEventHandler::OnMouseReleased(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg, int id)
    //{
    //	return true;
    //}
    //
    //
    ////Joy
    //bool WindowEventHandler::OnButtonPressed(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int button)
    //{
    //	return true;
    //}
    //
    //bool WindowEventHandler::OnButtonReleased(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int button)
    //{
    //	return true;
    //}
    //
    //bool WindowEventHandler::OnAxisMoved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int axis)
    //{
    //	return true;
    //}
    //
    //bool WindowEventHandler::OnPovMoved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int pov)
    //{
    //	return true;
    //}
    //
    //bool WindowEventHandler::OnVector3Moved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int index)
    //{
    //	return true;
    //}
}
