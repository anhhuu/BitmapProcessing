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



#include "Bitmap.h"

Bitmap::Bitmap()
{
}

bool Bitmap::readImageBMP(const char * filePath, unsigned char *& data)
{
	FILE *fileBMP;
	fileBMP = fopen(filePath, "rb");
	if (fileBMP == nullptr)
	{
		return false;
	}

	fread(&m_Header, sizeof(BitMapHeader), 1, fileBMP);
	fread(&m_Information, sizeof(BitMapInformation), 1, fileBMP);

	int rowSize = (m_Information.m_BitDepth * m_Information.m_Width + 31) / 32 * 4;
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}

	data = new unsigned char[rowSize * m_Information.m_Width];

	fseek(fileBMP, m_Header.m_DataOffset, SEEK_SET);
	fread(data, rowSize * m_Information.m_Width, 1, fileBMP);

	fclose(fileBMP);

	return true;
}

void Bitmap::saveImageBMP(const char * filePath, unsigned char *& data)
{
	FILE * imageFile;
	imageFile = fopen(filePath, "wb");

	fwrite(&m_Header, sizeof(BitMapHeader), 1, imageFile);
	fwrite(&m_Information, sizeof(BitMapInformation), 1, imageFile);

	int size = (m_Information.m_BitDepth * m_Information.m_Width + 31) / 32 * 4;

	fseek(imageFile, m_Header.m_DataOffset, SEEK_SET);
	fwrite(data, size * m_Information.m_Width, 1, imageFile);
	fclose(imageFile);
}

Bitmap::~Bitmap()
{
}
