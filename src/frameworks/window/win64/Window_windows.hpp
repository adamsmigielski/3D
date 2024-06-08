/** License
*
* Copyright (c) 2015 Adam �migielski
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
* @author Adam �migielski
* @file Window_windows.hpp
**/

#pragma once

#include <frameworks\window\window.hpp>

namespace Window
{
	namespace win64
	{
		class Window : public ::Window::Window
		{
		public:
			/* Creation and initialization */
			Window();
			virtual ~Window();

			virtual Platform::int32 Init(
				Event_handler * handler,
				Platform::int32 x,
				Platform::int32 y,
				Platform::int32 width,
				Platform::int32 height,
				const char * title);
			virtual Platform::int32 Init(
				Native native,
				Event_handler * handler);
            virtual void Close();
			virtual void Release();

			/* Native */
			virtual Native Get_native();
            static Window* Get_from_native(HWND wnd);

			/* Event handling */
			virtual Event_handler * Get_event_handler();

			/* Size and position */
			virtual void X(Platform::int32 val);
			virtual void Y(Platform::int32 val);

			virtual Platform::int32 X() const;
			virtual Platform::int32 Y() const;

			virtual void Width(Platform::int32 val);
			virtual void Height(Platform::int32 val);

			virtual Platform::int32 Width() const;
			virtual Platform::int32 Height() const;

			virtual void Client_width(Platform::int32 width);
			virtual void Client_height(Platform::int32 height);

			virtual Platform::int32 Client_width() const;
			virtual Platform::int32 Client_height() const;

			/* Title */
			virtual void Get_title(std::string & title) const;
			virtual void Set_title(const std::string & title);

            virtual Platform::int32 Show();

            /* Message processing */
            enum Message_processing_status {
                Msg_prc_Successfull,
                Msg_prc_error,
                Msg_prc_quit,
            };

            struct OS_message
            {
                HWND hwnd;
                UINT uMsg;
                WPARAM wParam;
                LPARAM lParam;
            };

            LRESULT Handle_event(OS_message & msg);
            Platform::int32 Process_messages();

		private:
            void capture_input();
            void disable_input_system();
            void enable_input_system();
            LRESULT on_wm_activate(OS_message & msg);
            LRESULT on_wm_close(OS_message & msg);
            LRESULT on_wm_command(OS_message & msg);
            LRESULT on_wm_destroy(OS_message & msg);
            LRESULT on_wm_move(OS_message & msg);
            LRESULT on_wm_moving(OS_message & msg);
            LRESULT on_wm_paint(OS_message & msg);
            LRESULT on_wm_power_broadcast(OS_message & msg);
            LRESULT on_wm_quit(OS_message & msg);
            LRESULT on_wm_sizing(OS_message & msg);
            LRESULT on_wm_size(OS_message & msg);
            void release();
            void update_input_system(
                Platform::int32 w,
                Platform::int32 h);
            static LRESULT CALLBACK window_procedure(
                HWND hwnd,
                UINT msg,
                WPARAM wParam,
                LPARAM lParam);

            HWND m_native;
			Event_handler * m_handler;
		};
	}
}
