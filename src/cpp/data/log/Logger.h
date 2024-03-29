//
//  Copyright (C) 2014-2024 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber et al.
//  <https://github.com/casm-lang/libstdhl/graphs/contributors>
//
//  This file is part of libstdhl.
//
//  libstdhl is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  libstdhl is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with libstdhl. If not, see <http://www.gnu.org/licenses/>.
//
//  Additional permission under GNU GPL version 3 section 7
//
//  libstdhl is distributed under the terms of the GNU General Public License
//  with the following clarification and special exception: Linking libstdhl
//  statically or dynamically with other modules is making a combined work
//  based on libstdhl. Thus, the terms and conditions of the GNU General
//  Public License cover the whole combination. As a special exception,
//  the copyright holders of libstdhl give you permission to link libstdhl
//  with independent modules to produce an executable, regardless of the
//  license terms of these independent modules, and to copy and distribute
//  the resulting executable under terms of your choice, provided that you
//  also meet, for each linked independent module, the terms and conditions
//  of the license of that module. An independent module is a module which
//  is not derived from or based on libstdhl. If you modify libstdhl, you
//  may extend this exception to your version of the library, but you are
//  not obliged to do so. If you do not wish to do so, delete this exception
//  statement from your version.
//

#pragma once
#ifndef _LIBSTDHL_CPP_LOG_LOGGER_H_
#define _LIBSTDHL_CPP_LOG_LOGGER_H_

#include <libstdhl/Type>
#include <libstdhl/data/log/Category>
#include <libstdhl/data/log/Channel>
#include <libstdhl/data/log/Data>
#include <libstdhl/data/log/Filter>
#include <libstdhl/data/log/Formatter>
#include <libstdhl/data/log/Item>
#include <libstdhl/data/log/Level>
#include <libstdhl/data/log/Router>
#include <libstdhl/data/log/Sink>
#include <libstdhl/data/log/Source>
#include <libstdhl/data/log/Stream>
#include <libstdhl/data/log/Switch>
#include <libstdhl/data/log/Timestamp>

/**
   @brief    TODO

   TODO
*/

namespace libstdhl
{
    /**
       @extends Stdhl
    */

    class Logger
    {
      public:
        Logger( Log::Stream& stream );

        void output( const std::string& text );
        void output( const char* format, ... );

        void error( const std::string& text );
        void error( const char* format, ... );
        u64 errors( void ) const;

        void warning( const std::string& text );
        void warning( const char* format, ... );
        u64 warnings( void ) const;

        void info( const std::string& text );
        void info( const char* format, ... );

        void hint( const std::string& text );
        void hint( const char* format, ... );

#ifndef NDEBUG
        void debug( const std::string& text );
        void debug( const char* format, ... );
#else
        inline void debug( const std::string& text )
        {
        }
        inline void debug( const char* format, ... )
        {
        }
#endif

        void c_log( Log::Level::ID level, const char* format, va_list args );

        template < typename... Args >
        void log( Args&&... args )
        {
            m_stream.add( std::forward< Args >( args )... );
            diagnostic( m_stream.data().back() );
        }

        template < const Log::Level::ID LEVEL, typename... Args >
        void log( Args&&... args )
        {
            m_stream.add(
                LEVEL, source(), category(), Log::Items( { std::forward< Args >( args )... } ) );
            diagnostic( m_stream.data().back() );
        }

        Log::Stream& stream( void );

        void setSource( const Log::Source::Ptr& source );

        Log::Source::Ptr source( void ) const;

        void setCategory( const Log::Category::Ptr& category );

        Log::Category::Ptr category( void ) const;

      private:
        void diagnostic( const Log::Data& data );

        Log::Stream& m_stream;
        Log::Source::Ptr m_source;
        Log::Category::Ptr m_category;
        u64 m_errors;
        u64 m_warnings;
    };
}

#endif  // _LIBSTDHL_CPP_LOG_LOGGER_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
