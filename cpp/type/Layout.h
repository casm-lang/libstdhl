//
//  Copyright (c) 2014-2017 Philipp Paulweber
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                Emmanuel Pescosta
//                https://github.com/ppaulweber/libstdhl
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

#ifndef _LIB_STDHL_CPP_TYPE_LAYOUT_H_
#define _LIB_STDHL_CPP_TYPE_LAYOUT_H_

#include "../Type.h"

/**
   @brief    TODO

   TODO
*/

namespace libstdhl
{
    /**
       @extends Stdhl
    */
    namespace Type
    {
        class Layout
        {
          public:
            using Ptr = std::shared_ptr< Layout >;

            /**
               trivial defined value
             */
            Layout( const u64 data, const u1 sign );

            /**
               non-trivial defined value
             */
            Layout( void* data );

            /**
               undefined value
             */
            Layout( void );

            u64 value( void ) const;

            void setValue( const u64 value );

            void* ptr( void ) const;

            void setPtr( void* ptr );

            u1 sign( void ) const;

            u1 trivial( void ) const;

            u1 defined( void ) const;

          protected:
            union layout {
                u64 value;
                void* ptr;
            } m_data;

            u1 m_sign : 1;
            u1 m_trivial : 1;

          public:
            friend Layout operator-( Layout arg )
            {
                arg.m_sign = not arg.m_sign;
                return arg;
            }

            template < const Radix RADIX, const Literal LITERAL = STDHL >
            inline std::string to( void ) const
            {
                return to_string( RADIX, LITERAL );
            }

            std::string to_string( const Radix radix = DECIMAL,
                const Literal literal = NONE ) const;

            static u64 to_digit( const char character,
                const Radix radix = DECIMAL, const Literal literal = NONE );
        };
    }

    namespace Hash
    {
        inline std::size_t value( const Type::Layout& data )
        {
            std::size_t hash = 0;
            std::size_t seed
                = ( ( (std::size_t)data.sign() ) << 1 ) | data.defined();

            if( data.trivial() )
            {
                hash = Hash::value( data.value() );
            }
            else
            {
                assert( 0 );
                // hash = Hash::value( data.value() );
            }

            return Hash::combine( seed, hash );
        }
    }
}

#endif // _LIB_STDHL_CPP_TYPE_LAYOUT_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//