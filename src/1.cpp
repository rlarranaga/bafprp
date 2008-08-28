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

#include "1.h"
#include "output.h"

namespace bafprp
{

	const r1Maker r1Maker::registerThis;

	IBafRecord* r1Maker::make( const BYTE* data, int length, const std::string& filename, long filePos ) const
	{
		LOG_TRACE( "r1Maker::make" );
		LOG_TRACE( "/r1Maker::make" );
		return new r1( data, length, filename, filePos );
	}

	r1::r1( const BYTE* data, int length, const std::string& filename, long filePos ) : IBafRecord( data, length, filename, filePos )
	{
		// make the real structure
		addField( "structurecode" ); 
		addField( "calltype" ); 
		addField( "sensortype" ); 
		addField( "sensorid" ); 
		addField( "recordofficetype" );
		addField( "recordofficeid" );
		addField( "date" );
		addField( "timingindicator" );
		addField( "studyindicator" );
		addField( "calledpartyanswerindicator" );
		addField( "servicetrafficind" );
		addField( "operatoraction" );
		addField( "servicefeaturecode" );
		addField( "originatingnpa" );
		addField( "originatingnumber" );
		addField( "overseasindicator" );
		addField( "terminatingnpa" );
		addField( "terminatingnumber" );
		addField( "time" );
		addField( "elapsedtime" );
		decodeModules();
	}

	std::string r1::getType() const
	{
		// Need to look at the call type field
		std::string ret;
		const IField* field = getField( "calltype" );
		if( !field ) 
		{
			LOG_ERROR( "No 'calltype' field in record 1" );
			return "";
		}

		switch( field->getInt() )
		{
		case 5:
			ret = "Record 1: Local message rate call";
			break;
		case 6:
			ret = "Record 1: Toll call or non-US";
			break;
		default:
			ret = "Record 1: Unknown";
		}
		return ret;
	}

	r1::~r1()
	{
	}

}