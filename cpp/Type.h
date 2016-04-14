//  
//  Copyright (c) 2014-2016 Philipp Paulweber
//  All rights reserved.
//  
//  Developed by: Philipp Paulweber
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
//  along with this program. If not, see <http://www.gnu.org/licenses/>.
//  

#ifndef _LIB_STDHL_CPP_TYPE_H_
#define _LIB_STDHL_CPP_TYPE_H_

#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <type_traits>

using namespace std;

#include "stdhl/c/type.h"
#include "Default.h"

/**
   @brief    TODO
   
   TODO
*/

namespace libstdhl 
{

	class Hash
	{
	public:
		size_t operator()( const char *val ) const
		{
			return std::hash< std::string >()( val );
		}
	};

	class Equal
	{
	public:
		size_t operator()( const char *val1, const char *val2 ) const
		{
			return std::string( val1 ) == std::string( val2 );
		}
	};
}

#endif /* _LIB_STDHL_CPP_TYPE_H_ */


//  
//  Local variables:
//  mode: c++
//  indent-tabs-mode: t
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//  