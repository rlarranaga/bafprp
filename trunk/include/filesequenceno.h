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

#ifndef FileSequenceNo_H
#define FileSequenceNo_H

#include "ifield.h"

namespace bafprp
{
	class FileSequenceNo : public IField
	{
		friend class FileSequenceNoFieldMaker;
	public:
		int getInt();
		long getLong();
		std::string getString();

		bool convert ( const BYTE* data );

		std::string getError() const { return _lastError; }
		int getSize() const { return 3; }
		std::string getType() const { return "int"; }
		std::string getName() const { return "File Sequence Number"; }

		~FileSequenceNo();
	private:
		FileSequenceNo();

	};

	class FileSequenceNoFieldMaker : public FieldMaker
	{
	public:
		FileSequenceNoFieldMaker() : FieldMaker ( "filesequenceno" ) {}
	protected:
		IField* make() const;
	private:
		static const FileSequenceNoFieldMaker registerThis;
	};

}

#endif