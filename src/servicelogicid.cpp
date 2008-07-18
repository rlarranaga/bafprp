/*
Copyright (C) 2008 by Charles Solar
charlessolar@gmail.com

This file is part of bafprp.

bafprp is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

bafprp is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with bafprp.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "servicelogicid.h"
#include "output.h"

namespace bafprp
{
	const ServiceLogicIDFieldMaker ServiceLogicIDFieldMaker::registerThis;

	IField* ServiceLogicIDFieldMaker::make() const
	{
		LOG_TRACE( "ServiceLogicIDFieldMaker::make" );
		LOG_TRACE( "/ServiceLogicIDFieldMaker::make" );
		return new ServiceLogicID;
		
	}

	ServiceLogicID::ServiceLogicID() : IField()
	{
		LOG_TRACE( "ServiceLogicID::ServiceLogicIDFieldConverter" );
		LOG_TRACE( "/ServiceLogicID::ServiceLogicIDFieldConverter" );
	}


	ServiceLogicID::~ServiceLogicID()
	{
		LOG_TRACE( "ServiceLogicID::~ServiceLogicIDFieldConverter" );
		LOG_TRACE( "/ServiceLogicID::~ServiceLogicIDFieldConverter" );
	}

	bool ServiceLogicID::convert ( const BYTE* data )
	{
		LOG_TRACE( "ServiceLogicID::convert" );
		_return = getChars( data, getSize() );
		_converted = true;

		if( _return.length() != getSize() ) 
		{
			_lastError = "Data read is not the correct size";
			_converted = false;
		}

		LOG_TRACE( "/ServiceLogicID::convert" );
		return _converted;
	}

	int ServiceLogicID::getInt() const
	{
		LOG_TRACE( "ServiceLogicID::getInt" );

		int ret;
		if( !_converted )
		{
			LOG_WARN( "Tried to get int before field was converted" );
			ret = 0;
		}
		else
			ret = atoi( _return.c_str() );

		LOG_TRACE( "/ServiceLogicID::getInt" );
		return ret;
	}

	long ServiceLogicID::getLong() const
	{
		LOG_TRACE( "ServiceLogicID::getLong" );

		long ret;
		if( !_converted )
		{
			LOG_WARN( "Tried to get long before field was converted" );
			ret = 0;
		}
		else
			ret = atol( _return.c_str() );

		LOG_TRACE( "/ServiceLogicID::getLong" );
		return ret;
	}

	std::string ServiceLogicID::getString() const
	{
		LOG_TRACE( "ServiceLogicID::getString" );

		std::string ret;
		if( !_converted )
		{
			LOG_WARN( "Tried to get string before field was converted" );
			ret = "";
		}
		else
			ret = _return;

		LOG_TRACE( "/ServiceLogicID::getString" );
		return ret;
	}
}
