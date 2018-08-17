//
//  Copyright (C) 2014-2018 CASM Organization <https://casm-lang.org>
//  All rights reserved.
//
//  Developed by: Philipp Paulweber
//                Emmanuel Pescosta
//                <https://github.com/casm-lang/libstdhl>
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
#ifndef _LIBSTDHL_CPP_NETWORK_LSP_PACKET_H_
#define _LIBSTDHL_CPP_NETWORK_LSP_PACKET_H_

#include <libstdhl/net/Packet>
#include <libstdhl/net/lsp/Message>
#include <libstdhl/net/lsp/Protocol>

/**
   @brief    TBD

   TBD
*/

namespace libstdhl
{
    /**
       @extends Stdhl
    */
    namespace Network
    {
        namespace LSP
        {
            /**
               @extends LSP
            */
            class Packet final : public Network::Packet
            {
              public:
                using Ptr = std::shared_ptr< Packet >;

                // create LSP packet from string
                Packet( const std::string& data );

                // create LSP packet to string
                Packet( const Message& payload );

                const Protocol& header( void ) const;

                const Message& payload( void ) const;

                const u8* buffer( void ) const override;

                std::size_t size( void ) const override;

                void resize( std::size_t size ) override;

                std::string dump( const u1 formatted = false ) const;

                void process( ServerInterface& interface ) const;

                static std::vector< Packet > fromString(
                    const std::string& data, std::vector< LSP::Packet >& packages );

              private:
                Protocol m_header;
                Message m_payload;
                std::string m_data;
            };
        }
    }
}

#endif  // _LIBSTDHL_CPP_NETWORK_LSP_PACKET_H_

//
//  Local variables:
//  mode: c++
//  indent-tabs-mode: nil
//  c-basic-offset: 4
//  tab-width: 4
//  End:
//  vim:noexpandtab:sw=4:ts=4:
//