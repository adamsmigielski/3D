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
* @file Window.hpp
**/

#pragma once

namespace Window
{
	///////////////////////////////////////////////////////////////
	// Types
	enum Returns
	{
        Window_success       = 0,
		Window_error_generic = -1024,
	};


	///////////////////////////////////////////////////////////////
	// Classes
	class Manager;
	class Event_handler;
	class Window;


	///////////////////////////////////////////////////////////////
	// Definitions
	///////////////////////////////////////////////////////////////
	class Window
	{
	public:
		/* Creation and initialization */
		typedef void * Native;

		Window();
		virtual ~Window();

		virtual Platform::int32 Init(
			Event_handler * handler,
			Platform::int32 x,
			Platform::int32 y,
			Platform::int32 width,
			Platform::int32 height,
			const char * title) = 0;
		virtual Platform::int32 Init(
			Native native,
			Event_handler * handler) = 0;
        virtual void Close() = 0;
		virtual void Release() = 0;

		/* Native */
		virtual Native Get_native() = 0;

		/* Event handling */
		virtual Event_handler * Get_event_handler() = 0;
        void * Get_user_data();
        void Set_user_data(void * info);

		/* Size and position */
		virtual void X(Platform::int32 val) = 0;
		virtual void Y(Platform::int32 val) = 0;

		virtual Platform::int32 X() const = 0;
		virtual Platform::int32 Y() const = 0;

		virtual void Width(Platform::int32 val) = 0;
		virtual void Height(Platform::int32 val) = 0;

		virtual Platform::int32 Width() const = 0;
		virtual Platform::int32 Height() const = 0;

		virtual void Client_width(Platform::int32 width) = 0;
		virtual void Client_height(Platform::int32 height) = 0;

		virtual Platform::int32 Client_width() const = 0;
		virtual Platform::int32 Client_height() const = 0;

        virtual Platform::int32 Show() = 0;

		/* Title */
		virtual void Get_title(std::string & title) const = 0;
		virtual void Set_title(const std::string & title) = 0;

    private:
        void * m_user_data;
	};


	///////////////////////////////////////////////////////////////
	class Manager
	{
	public:
		virtual ~Manager();

		/* Event processing */
		virtual Platform::int32 Start_event_processing() = 0;
		virtual Platform::int32 Stop_event_processing() = 0;
		virtual Platform::int32 Process_events() = 0;

		/* Window management */
		virtual Window* Create_window() = 0;

	protected:
		Manager();
	};


	/////////////////////////////////////////////////////////////// 
    class Event_handler
    {
    public:
        enum class Sizing_direction {
            Bottom,
            Bottom_left,
            Left,
            Top_left,
            Top,
            Top_right,
            Right,
            Bottom_right,
        };

        Event_handler& operator = (const Event_handler&) = delete;
        virtual ~Event_handler();

        /* Internal callbacks */
        virtual void On_init(
            Window * window);

        virtual void On_release(
            Window * window);

        /* OS */
        virtual Platform::int32 On_deactivation(
            Window * window);
        virtual Platform::int32 On_activation_click(
            Window * window);
        virtual Platform::int32 On_activation(
            Window * window);

        virtual Platform::int32 On_close(
            Window * window,
            bool& should_window_close);
        virtual Platform::int32 On_quit(
            Window * window);

        virtual Platform::int32 On_power_suspend(
            Window * window);
        virtual Platform::int32 On_power_resume(
            Window * window);

        virtual Platform::int32 On_moving(
            Window * window,
            Platform::int32 & left,
            Platform::int32 & top,
            Platform::int32 & right,
            Platform::int32 & bottom);
        virtual Platform::int32 On_move(
            Window * window,
            Platform::int32 x,
            Platform::int32 y);

        virtual Platform::int32 On_sizing(
            Window * window,
            Sizing_direction direction,
            Platform::int32 & left,
            Platform::int32 & top,
            Platform::int32 & right,
            Platform::int32 & bottom);
        virtual Platform::int32 On_size(
            Window * window,
            Platform::int32 width,
            Platform::int32 height);
        virtual Platform::int32 On_maximization(
            Window * window,
            Platform::int32 width,
            Platform::int32 height);
        virtual Platform::int32 On_minimization(
            Window * window,
            Platform::int32 width,
            Platform::int32 height);
        virtual Platform::int32 On_other_window_maximized_or_restored(
            Window * window,
            Platform::int32 width,
            Platform::int32 height);

        virtual Platform::int32 On_paint(
            Window * window);

        virtual Platform::int32 On_menu(
            Window * window,
            Platform::uint16 id);

        ////OIS
        ////Keyboard
        //virtual bool OnKeyPressed(Ozone::Window::WindowClass * window, const OIS::KeyEvent &arg );
        //virtual bool OnKeyReleased(Ozone::Window::WindowClass * window, const OIS::KeyEvent &arg );
        //
        ////Mouse
        //virtual bool OnMouseMoved(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg );
        //virtual bool OnMousePressed(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg, int id );
        //virtual bool OnMouseReleased(Ozone::Window::WindowClass * window, const OIS::MouseEvent &arg, int id );
        //
        ////Joy
        //virtual bool OnButtonPressed(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int button );
        //virtual bool OnButtonReleased(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int button );
        //virtual bool OnAxisMoved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int axis );
        //virtual bool OnPovMoved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int pov );
        //virtual bool OnVector3Moved(Ozone::Window::WindowClass * window, const OIS::JoyStickEvent &arg, int index);



    protected:
        Event_handler();
    };
}
