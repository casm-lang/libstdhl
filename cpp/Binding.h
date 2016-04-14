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

#ifndef _LIB_STDHL_CPP_BINDING_H_
#define _LIB_STDHL_CPP_BINDING_H_

#include "Type.h"

/**
   @brief    TODO
   
   TODO
*/

namespace libstdhl 
{
    template< class C >
	class Binding
	{
	private:
		C* reference = 0;
		
	public:
		void bind( C* object )
		{
			assert( !reference && "already bounded to a reference" );
			assert( object && "invalid object reference to bind" );
			
			reference = object;
		}
		
		C* unbind( void )
		{
			assert( reference && "object reference was never bound" );
			
			C* tmp = reference;
			reference = 0;
			return tmp;
		}
		
	    C* getBound( void ) const
		{
			assert( reference && "object reference was never bound" );
			return reference;
		}

		const u1 isBound( void ) const
		{
			return reference != 0;
		}
	};
}

#endif /* _LIB_STDHL_CPP_BINDING_H_ */


//  
//  Local variables:
//  mode: c++
//  indent-tabs-mode: t
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//  