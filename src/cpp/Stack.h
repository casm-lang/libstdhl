//
//  Copyright (C) 2014-2023 CASM Organization <https://casm-lang.org>
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

#ifndef _LIBSTDHL_STACK_H_
#define _LIBSTDHL_STACK_H_

#include <libstdhl/Exception>

#include <vector>

namespace libstdhl
{
    class StackHasNoElementsException : public Exception
    {
      public:
        using Exception::Exception;
    };

    template < typename T >
    class Stack
    {
      public:
        explicit Stack( void )
        : m_values()
        {
        }

        void push( const T& value )
        {
            m_values.push_back( value );
        }

        T pop( void )
        {
            if( empty() )
            {
                throw StackHasNoElementsException(
                    "unable to get element via pop from empty stack" );
            }
            const auto value = m_values.back();
            m_values.pop_back();
            return value;
        }

        T& top( void )
        {
            if( empty() )
            {
                throw StackHasNoElementsException( "unable to get top element from empty stack" );
            }
            return m_values.back();
        }

        void clear( void )
        {
            m_values.clear();
        }

        std::size_t size( void ) const
        {
            return m_values.size();
        }

        u1 empty( void ) const
        {
            return m_values.empty();
        }

      private:
        std::vector< T > m_values;
    };
}

#endif  // _LIBSTDHL_STACK_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//
