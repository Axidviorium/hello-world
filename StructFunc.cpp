#include "pch.h"
#include "StructFunc.h"


//ќпределение функции, открывающей BMP файл по названию из текстового
int opFile(FILE ** fb)
{
	//локальные вспомогательные переменные
	const int lenst = 81;
	char newFileName[lenst];
	FILE* f1;
	std::ifstream inFile("input.txt");


	if (!inFile) { std::cout << "Mo input file" << std::endl; return 0; }
	inFile >> newFileName;
	inFile.close();
	std::cout << "\nFile name: " << newFileName << "\n\n";
	if ((f1 = fopen(newFileName, "rb")) == NULL) { std::cout << "File not found!\n";  return 0; };
	*fb = f1;
	return 1;
}

//ќписание функции, читающей 2 байта из BMP-файла
WORD read_u16(FILE *fp)
{
	WORD N;
	fread(&N, sizeof(WORD), 1, fp);
	return N;
}

//ќписание функции, читающей 4 байта из BMP-файла (без знака)
DWORD read_u32(FILE *fp)
{
	DWORD N;
	fread(&N, sizeof(DWORD), 1, fp);
	return N;
}


//ќписание функции, читающей 4 байта из BMP-файла (со знаком)
LONG read_s32(FILE * fp)
{
	LONG N;
	fread(&N, sizeof(LONG), 1, fp);
	return N;
}


//ќписание функции, заполн€ющей BITMAPFILEHEADER файла
void loadBMFH(BITMAPFILEHEADER * bmfh, FILE * fb)
{
	fseek(fb, 0, 0);					//устанавливаем указатель на начало файла
	(*bmfh).bfType = read_u16(fb);		//«аполн€ем пол€ BITMAPFILEHEADER
	(*bmfh).bfSize = read_u32(fb);
	(*bmfh).bfReserved1 = read_u16(fb);
	(*bmfh).bfReservsd2 = read_u16(fb);
	(*bmfh).bfOffBits = read_u32(fb);
}


// ќписание функции, заполн€ющей BITMAPINFO файла версии 3
void loadBMIv3(BITMAPINFO * bmi, FILE * fb)
{
	fseek(fb, 14, 0);
	(*bmi).bVSize = read_u32(fb);
	(*bmi).bVWidth = read_s32(fb);
	(*bmi).bVHeight = read_s32(fb);
	(*bmi).bVPlanes = read_u16(fb);
	(*bmi).bVBitCount = read_u16(fb);
	(*bmi).bVCompression = read_u32(fb);
	(*bmi).bVSizeImage = read_u32(fb);
	(*bmi).bVXPelsPerMeter = read_s32(fb);
	(*bmi).bVYPelsPerMeter = read_s32(fb);
	(*bmi).bVClrUsed = read_u32(fb);
	(*bmi).bVClrImportant = read_u32(fb);
}


//ќписание функции, заполн€ющей BITMAPINFO файла версии 4
void loadBMIv4(BITMAPINFO * bmi, FILE * fb)
{
	fseek(fb, 14, 0);
	(*bmi).bVSize = read_u32(fb);
	(*bmi).bVWidth = read_s32(fb);
	(*bmi).bVHeight = read_s32(fb);
	(*bmi).bVPlanes = read_u16(fb);
	(*bmi).bVBitCount = read_u16(fb);
	(*bmi).bVCompression = read_u32(fb);
	(*bmi).bVSizeImage = read_u32(fb);
	(*bmi).bVXPelsPerMeter = read_s32(fb);
	(*bmi).bVYPelsPerMeter = read_s32(fb);
	(*bmi).bVClrUsed = read_u32(fb);
	(*bmi).bVClrImportant = read_u32(fb);
	(*bmi).bVRedMask = read_u32(fb);
	(*bmi).bVGreenMask = read_u32(fb);
	(*bmi).bVBlueMask = read_u32(fb);
	(*bmi).bVAlphaMask = read_u32(fb);
	(*bmi).bVSCType = read_u32(fb);
	(*bmi).RedX = read_s32(fb);
	(*bmi).RedY = read_s32(fb);
	(*bmi).RedZ = read_s32(fb);
	(*bmi).GreenX = read_s32(fb);
	(*bmi).GreenY = read_s32(fb);
	(*bmi).GreenZ = read_s32(fb);
	(*bmi).BlueX = read_s32(fb);
	(*bmi).BlueY = read_s32(fb);
	(*bmi).BlueZ = read_s32(fb);
	(*bmi).GammaRed = read_u32(fb);
	(*bmi).GammaGreen = read_u32(fb);
	(*bmi).GammaBlue = read_u32(fb);
}


//ќписание функции, заполн€ющей BITMAPINFO файла версии 5
void loadBMIv5(BITMAPINFO * bmi, FILE * fb)
{
	fseek(fb, 14, 0);
	(*bmi).bVSize = read_u32(fb);
	(*bmi).bVWidth = read_s32(fb);
	(*bmi).bVHeight = read_s32(fb);
	(*bmi).bVPlanes = read_u16(fb);
	(*bmi).bVBitCount = read_u16(fb);
	(*bmi).bVCompression = read_u32(fb);
	(*bmi).bVSizeImage = read_u32(fb);
	(*bmi).bVXPelsPerMeter = read_s32(fb);
	(*bmi).bVYPelsPerMeter = read_s32(fb);
	(*bmi).bVClrUsed = read_u32(fb);
	(*bmi).bVClrImportant = read_u32(fb);
	(*bmi).bVRedMask = read_u32(fb);
	(*bmi).bVGreenMask = read_u32(fb);
	(*bmi).bVBlueMask = read_u32(fb);
	(*bmi).bVAlphaMask = read_u32(fb);
	(*bmi).bVSCType = read_u32(fb);
	(*bmi).RedX = read_s32(fb);
	(*bmi).RedY = read_s32(fb);
	(*bmi).RedZ = read_s32(fb);
	(*bmi).GreenX = read_s32(fb);
	(*bmi).GreenY = read_s32(fb);
	(*bmi).GreenZ = read_s32(fb);
	(*bmi).BlueX = read_s32(fb);
	(*bmi).BlueY = read_s32(fb);
	(*bmi).BlueZ = read_s32(fb);
	(*bmi).GammaRed = read_u32(fb);
	(*bmi).GammaGreen = read_u32(fb);
	(*bmi).GammaBlue = read_u32(fb);
	(*bmi).Intent = read_u32(fb);
	(*bmi).ProfileData = read_u32(fb);
	(*bmi).ProfileSize = read_u32(fb);
	(*bmi).Reserved = read_u32(fb);
}


//ќписание функции, заполн€ющей BITMAPINFO файла
int loadBMPI(FILE * fb, BITMAPFILEHEADER * bmfh, BITMAPINFO* bmi)
{
	DWORD BMPVersion;

	if ((*bmfh).bfType != 0x4d42) { std::cout << "Not BMP file!First bytes are not 0x4d42"; return 0; }

	fseek(fb, 14, 0);
	BMPVersion = read_u32(fb);
	switch (BMPVersion)
	{
	case 40: 
		std::cout << "BMP version 3\n";
		loadBMIv3(bmi, fb);
		break;

	case 108: 
		std::cout << "BMP version 4\n";
		loadBMIv4(bmi, fb);
		break;

	case 124:
		std::cout << "BMP version 5\n";
		loadBMIv5(bmi, fb);
		break;

	default:
		std::cout << "BMP version is not 3 nor 4 nor 5 \n";
		return 0;
		break;
	}
	return 1;
}


//ќписание функции, определ€ющей маску и провер€ющей пригодность формата
int chkSetMask(BITMAPINFO * bmi)
{
	if ((*bmi).bVBitCount != 16 && (*bmi).bVBitCount != 24 && (*bmi).bVBitCount != 32) 
	{ std::cout << "Unsupported bit count. Need 16 or 24 or 32 bpp!\n"; return 0; }

	if ((*bmi).bVCompression != 0 && (*bmi).bVCompression != 3) 
	{ std::cout << "Unsupported compression!\n"; return 0; }

	if (bmi->bVClrUsed) { std::cout << "File contain color table. This type of file is unsupported!"; return 0; }

	if (bmi->bVCompression == 0 || (*bmi).bVRedMask == 0 || (*bmi).bVGreenMask == 0 || (*bmi).bVBlueMask == 0 ) {
		WORD numberOfColors = (*bmi).bVBitCount >> 3;
		if (numberOfColors < 3) { numberOfColors = 3; }
		WORD bitsOnColor = (*bmi).bVBitCount / numberOfColors; //кака€-то муть, должно быть проще, 5 или 8
		WORD maskvalue = (1 << bitsOnColor) - 1; //маска дл€ синего цвета ff или  0000 00ff или 00000000 00000000 00000000 11111111;

		(*bmi).bVBlueMask = maskvalue;
		(*bmi).bVGreenMask = maskvalue << bitsOnColor;
		(*bmi).bVRedMask = maskvalue << (bitsOnColor * 2);
		bmi->bVAlphaMask = maskvalue << (bitsOnColor * 3);
	}
	std::cout << "\nMask value:\n" << std::hex; 
	std::cout << "B:" << bmi->bVBlueMask << std::endl;
	std::cout << "G:" << bmi->bVGreenMask << std::endl;
	std::cout << "R:" << bmi->bVRedMask << std::endl;
	std::cout << "A:" << bmi->bVAlphaMask << std::endl;
	return 1;
}

//ќписание функции, вычисл€ющей отступ
LONG setLining(BITMAPINFO * bmi)
{
	LONG Pad = (((*bmi).bVWidth * (*bmi).bVBitCount / 8) % 4) & 3;
	std::cout << "\ngap is: " << std::dec << Pad << std::endl;
	return Pad;
}


//ќписание функции, выдел€ющей пам€ть под пиксели изображени€
RGBQUAD** createImageBuf(BITMAPINFO * bmi)
{
	RGBQUAD** pixelRGB = new RGBQUAD*[(*bmi).bVHeight];
	for (LONG i = 0; i < (*bmi).bVHeight; i++)
	{
		pixelRGB[i] = new RGBQUAD[(*bmi).bVWidth];
	}
	std::cout << "\naddr buf:" << std::hex << pixelRGB << "\n";
	return pixelRGB;
}

//ќписание функции, выдел€ющей пам€ть под пиксели изображени€
void delImgBuf(BITMAPINFO * bmi, RGBQUAD ** pixelRGB)
{
	for (LONG i = 0; i < +(bmi->bVHeight); i++) { delete[] pixelRGB[i]; }
	delete[] pixelRGB;
	std::cout << "\nMemory have been free!\n";
}

//ќпределение функции, извлекающей бит по маске
BYTE extractBit(const DWORD pixBuf, const DWORD mask)
{
	if (!mask) { return 0; }
	
	DWORD tempMask = mask;
	DWORD numZeroBitsOfMask = 0;

	while (!(tempMask&1))
	{
		tempMask >>= 1;
		numZeroBitsOfMask++;
	}

	return (pixBuf&mask) >> numZeroBitsOfMask;
}


//ќписание функции, записывающей пиксели в буфер
void loadImageBuf(FILE * fb, BITMAPFILEHEADER* bmfh, BITMAPINFO * bmi, RGBQUAD ** pixelRGB)
{
	DWORD bufForPixel, RedMask, GreenMask, BlueMask, AlphaMask;//буфер дл€ 1 пиксел€
	LONG gap = setLining(bmi);//зазор в строке
	BYTE NumOfBytes = (bmi->bVBitCount) / 8;//количество байт на пиксель
	DWORD count = 0;

	RedMask = bmi->bVRedMask;
	GreenMask = bmi->bVGreenMask;
	BlueMask = bmi->bVBlueMask;
	AlphaMask = bmi->bVAlphaMask;

	/*std::cout << "\nMask load value:\n";
	std::cout << std::hex  << "B:" << bmi->bVBlueMask << std::endl;
	std::cout << "G:" << bmi->bVGreenMask << std::endl;
	std::cout << "R:" << bmi->bVRedMask << std::endl;
	std::cout << "A:" << bmi->bVAlphaMask << std::endl;*/

	fseek(fb, (*bmfh).bfOffBits, 0);
	std::cout << "\nOffset is: " << std::dec << bmfh->bfOffBits << std::endl;
	
	for (LONG i = 0; i < (*bmi).bVHeight; i++)
	{
		for (LONG j = 0; j < (*bmi).bVHeight; j++)
		{
			readBytes(fb, bufForPixel, NumOfBytes);
			/*std::cout << "\n Buffer value is: " << std::hex << bufForPixel << std::endl;*/

			pixelRGB[i][j].rgbRed = extractBit(bufForPixel, RedMask);
			pixelRGB[i][j].rgbGreen = extractBit(bufForPixel, GreenMask);
			pixelRGB[i][j].rgbBlue = extractBit(bufForPixel, BlueMask);
			pixelRGB[i][j].rgbReserved = extractBit(bufForPixel, AlphaMask);
			count++;
			/*std::cout << std::hex
				<< "R::" << +pixelRGB[i][j].rgbRed << ", "
				<< "G::" << +pixelRGB[i][j].rgbGreen << ", "
				<< "B::" << +pixelRGB[i][j].rgbBlue << ", "
				<< "A::" << +pixelRGB[i][j].rgbReserved << ";\n";*/
		}
		fseek(fb, gap, 1);
	}
	std::cout << "\nNumber of pixels: " << std::dec << count << std::endl;
}


//ќписание функции, вывод€щей значени€ пикселей
void printHexPixel(BITMAPINFO* bmi, RGBQUAD ** pixelRGB)
{
	std::cout << "\n\n\t Image pixels value in HEX:\n\n";
	for (LONG i = 0; i < bmi->bVHeight; i++)//(bmi->bVHeight)
	{
		for (LONG j = 0; j < bmi->bVWidth; j++)//(bmi->bVWidth)
		{
			std::cout << std::hex
				<< "R::" << +pixelRGB[i][j].rgbRed << ", "
				<< "G::" << +pixelRGB[i][j].rgbGreen << ", "
				<< "B::" << +pixelRGB[i][j].rgbBlue << ", "
				<< "A::" << +pixelRGB[i][j].rgbReserved << "; \t";
		}
		std::cout << std::endl;
	}
	std::cout << std::dec << "\n\nThat's all\n";
}

//ќписание функции, вывод€щей пол€ BITMAPFILEHEADER файла
void showBMFH(BITMAPFILEHEADER * bmfh)
{
	std::cout << "\n\tBITMAPFILEHEADER structure\n";
	std::cout <<"first byte in HEX: "<< std::hex << (*bmfh).bfType << '\n';
	std::cout << "File size (in bytes): " << std::dec << (*bmfh).bfSize << std::endl;
	std::cout << "Picture data begins from byte: " << (*bmfh).bfOffBits << "\n";
}


//ќпределение функции, вывод€щей пол€ BITMAPINFO файла
void showBMI(BITMAPINFO * bmi)
{
	std::cout << "\n\n\tBITMAPINFO structure\n";
	std::cout << "BMP file size (format version): " << (*bmi).bVSize << std::endl;
	std::cout << "Width: " << (*bmi).bVWidth << std::endl;
	std::cout << "Height: " << (*bmi).bVHeight << std::endl;
	std::cout << "Should be 1: " << (*bmi).bVPlanes << std::endl;
	std::cout << "Bits per pixel: " << (*bmi).bVBitCount << std::endl;
	std::cout << "Image size (in bytes): " << (*bmi).bVSizeImage << std::endl;
	std::cout << "Compression method: " << (*bmi).bVCompression << std::endl;
	std::cout << "Colors in color palette: " << (*bmi).bVClrUsed << std::endl;
	std::cout << "Important color used: " << (*bmi).bVClrImportant << std::endl;
	std::cout << "Red mask: " << std::hex << (*bmi).bVRedMask << std::endl;
	std::cout << "Green mask: " << (*bmi).bVGreenMask << std::endl;
	std::cout << "Blue mask: " << (*bmi).bVBlueMask << std::endl;
	std::cout << "Alpha mask: " << (*bmi).bVAlphaMask << std::endl;
}

