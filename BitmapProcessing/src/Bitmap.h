//
// Bitmap library Source Code
// Copyright (c) 2016 panhhuu.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//



#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

class Bitmap
{
private:

#pragma pack(push, 1)
	struct BitMapHeader
	{
		short m_Type;
		long m_fSize;
		short m_Reserved1;
		short m_Reserved2;
		long m_DataOffset;
	};
#pragma pack(pop)

#pragma pack(push, 1)
	struct BitMapInformation
	{
		int m_Size;
		int m_Width;
		int m_Height;
		short m_Planes;
		short m_BitDepth;
		long m_Compression;
		long m_SizeImage;
		long m_xPixelsPreMeter;
		long m_yPixelsPreMeter;
		long m_ColorUsed;
		long m_ColorImportant;
	};
#pragma pack(pop)

	BitMapHeader m_Header;
	BitMapInformation m_Information;

public:
	Bitmap();

	bool readImageBMP(const char *filePath, unsigned char *&data);

	void saveImageBMP(const char *filePath, unsigned char *&data);

	~Bitmap();
};
