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
