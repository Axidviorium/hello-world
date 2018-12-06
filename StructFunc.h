//‘айл содержит описание структур, используемых при чтении BMP-файла, а также описание функций,
// используемых дл€ работы со структурами
#pragma once
#include <iostream>
#include <fstream>

// ¬ведЄм обозначени€ типов
typedef unsigned __int8 BYTE;
typedef unsigned __int16 WORD;
typedef unsigned __int32 DWORD;
typedef __int32 LONG;


// —труктура дл€ заголовка
typedef struct
{
	WORD	bfType;
	DWORD	bfSize;
	WORD	bfReserved1;
	WORD	bfReservsd2;
	DWORD	bfOffBits;

} BITMAPFILEHEADER;


//—труктура дл€ блока BITMAPINFO
typedef struct
{
	DWORD	bVSize;
	LONG	bVWidth;
	LONG	bVHeight;
	WORD	bVPlanes;
	WORD	bVBitCount;
	DWORD	bVCompression;
	DWORD	bVSizeImage;
	LONG	bVXPelsPerMeter;
	LONG	bVYPelsPerMeter;
	DWORD	bVClrUsed;
	DWORD	bVClrImportant;
	DWORD	bVRedMask;
	DWORD	bVGreenMask;
	DWORD	bVBlueMask;
	DWORD	bVAlphaMask;
	DWORD	bVSCType;
	LONG	RedX;
	LONG	RedY;
	LONG	RedZ;
	LONG	GreenX;
	LONG	GreenY;
	LONG	GreenZ;
	LONG	BlueX;
	LONG	BlueY;
	LONG	BlueZ;
	DWORD	GammaRed;
	DWORD	GammaGreen;
	DWORD	GammaBlue;
	DWORD	Intent;
	DWORD	ProfileData;
	DWORD	ProfileSize;
	DWORD	Reserved;
} BITMAPINFO;


//—труктура дл€ хранени€ цветов пиксел€
typedef struct
{
	BYTE   rgbBlue;
	BYTE   rgbGreen;
	BYTE   rgbRed;
	BYTE   rgbReserved;
} RGBQUAD;



WORD read_u16(FILE *fp);	//ќбъ€вление функции, читающей 2 байта из BMP-файла
DWORD read_u32(FILE *fp);	//ќбъ€вление функции, читающей 4 байта из BMP-файла (беззнаковое целое)
LONG read_s32(FILE *fp);	//ќбъ€вление функции, читающей 4 байта из BMP-файла (с учЄтом знака)

int opFile(FILE** fb);								//ќбъ€вление функции, открывающей BMP файл по названию из текстового
void loadBMFH(BITMAPFILEHEADER* bmfh, FILE* fb);	//ќбъ€вление функции, заполн€ющей BITMAPFILEHEADER файла
void loadBMIv3(BITMAPINFO* bmi, FILE * fb);			//ќбъ€вление функции, заполн€ющей BITMAPINFO файла версии 3
void loadBMIv4(BITMAPINFO* bmi, FILE * fb);			//ќбъ€вление функции, заполн€ющей BITMAPINFO файла версии 4
void loadBMIv5(BITMAPINFO* bmi, FILE * fb);			//ќбъ€вление функции, заполн€ющей BITMAPINFO файла версии 5
int loadBMPI(FILE* fb, BITMAPFILEHEADER* bmfh, BITMAPINFO* bmi);	//ќбъ€вление функции, загружающей BMP - файл


int chkSetMask(BITMAPINFO* bmi);						//ќбъ€вление функции, определ€ющей маску
LONG setLining(BITMAPINFO*bmi);							//ќбъ€вление функции, вычисл€ющей отступ. ¬спомогательна€ функци€
RGBQUAD** createImageBuf(BITMAPINFO* bmi);				//ќбъ€вление функции, выдел€ющей пам€ть под пиксели изображени€
void delImgBuf(BITMAPINFO* bmi, RGBQUAD** pixelRGB);	//объ€вление функции, освобождающей динамически выделенную пам€ть
BYTE extractBit(const DWORD pixBuf, const DWORD mask);	//ќбъ€вление функции, извлекающей бит по маске. ¬спомогательна€ функци€.
void loadImageBuf(FILE* fb, BITMAPFILEHEADER* bmfh, BITMAPINFO* bmi, RGBQUAD** pixelRGB);	//ќбъ€вление функции, записывающей пиксели в буфер

void printHexPixel(BITMAPINFO* bmi, RGBQUAD** pixelRGB);	//ќбъ€вление функции, вывод€щей значени€ пикселей
void showBMFH(BITMAPFILEHEADER* bmfh);						//ќбъ€вление функции, вывод€щей пол€ BITMAPFILEHEADER файла
void showBMI(BITMAPINFO *bmi);								//ќбъ€вление функции, вывод€щей пол€ BITMAPINFO файла


//Ўаблон функции чтени€ байтов в буфер
template <typename Type>
void readBytes(FILE *f, Type &buffer, std::size_t num) {
	fread(&buffer, sizeof(BYTE), num, f);
}