//
//  Copyright (c) 2014-2017 CASM Organization https://casm-lang.org
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                Emmanuel Pescosta
//                https://github.com/casm-lang/libstdhl
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

#include "String.h"

using namespace libstdhl;
using namespace Type;

//
// Type::create*
//

String Type::createString( const std::string& value )
{
    return String( new StringLayout( value ) );
}

//
// String
//

std::string String::toString( void ) const
{
    const auto data = static_cast< StringLayout* >( m_data.ptr );
    return data->str();
}

u1 String::operator==( const String& rhs ) const
{
    auto lval = static_cast< StringLayout* >( m_data.ptr );
    const auto rval = static_cast< StringLayout* >( rhs.m_data.ptr );

    if( lval and rval )
    {
        return lval->str() == rval->str();
    }
    else
    {
        return not( lval or rval );
    }
}

String& String::operator+=( const String& rhs )
{
    auto lval = static_cast< StringLayout* >( m_data.ptr );
    const auto rval = static_cast< StringLayout* >( rhs.m_data.ptr );

    lval->operator+=( *rval );

    return *this;
}

//
// StringLayout
//

StringLayout::StringLayout( const std::string& value )
: m_str( value )
{
}

Layout* StringLayout::clone( void ) const
{
    return new StringLayout( m_str );
}

const std::string& StringLayout::str( void ) const
{
    return m_str;
}

StringLayout& StringLayout::operator+=( const StringLayout& rhs )
{
    m_str += rhs.m_str;
    return *this;
}

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//