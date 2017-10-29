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
