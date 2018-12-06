//���� �������� �������� ��������, ������������ ��� ������ BMP-�����, � ����� �������� �������,
// ������������ ��� ������ �� �����������
#pragma once
#include <iostream>
#include <fstream>

// ����� ����������� �����
typedef unsigned __int8 BYTE;
typedef unsigned __int16 WORD;
typedef unsigned __int32 DWORD;
typedef __int32 LONG;


// ��������� ��� ���������
typedef struct
{
	WORD	bfType;
	DWORD	bfSize;
	WORD	bfReserved1;
	WORD	bfReservsd2;
	DWORD	bfOffBits;

} BITMAPFILEHEADER;


//��������� ��� ����� BITMAPINFO
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


//��������� ��� �������� ������ �������
typedef struct
{
	BYTE   rgbBlue;
	BYTE   rgbGreen;
	BYTE   rgbRed;
	BYTE   rgbReserved;
} RGBQUAD;



WORD read_u16(FILE *fp);	//���������� �������, �������� 2 ����� �� BMP-�����
DWORD read_u32(FILE *fp);	//���������� �������, �������� 4 ����� �� BMP-����� (����������� �����)
LONG read_s32(FILE *fp);	//���������� �������, �������� 4 ����� �� BMP-����� (� ������ �����)

int opFile(FILE** fb);								//���������� �������, ����������� BMP ���� �� �������� �� ����������
void loadBMFH(BITMAPFILEHEADER* bmfh, FILE* fb);	//���������� �������, ����������� BITMAPFILEHEADER �����
void loadBMIv3(BITMAPINFO* bmi, FILE * fb);			//���������� �������, ����������� BITMAPINFO ����� ������ 3
void loadBMIv4(BITMAPINFO* bmi, FILE * fb);			//���������� �������, ����������� BITMAPINFO ����� ������ 4
void loadBMIv5(BITMAPINFO* bmi, FILE * fb);			//���������� �������, ����������� BITMAPINFO ����� ������ 5
int loadBMPI(FILE* fb, BITMAPFILEHEADER* bmfh, BITMAPINFO* bmi);	//���������� �������, ����������� BMP - ����


int chkSetMask(BITMAPINFO* bmi);						//���������� �������, ������������ �����
LONG setLining(BITMAPINFO*bmi);							//���������� �������, ����������� ������. ��������������� �������
RGBQUAD** createImageBuf(BITMAPINFO* bmi);				//���������� �������, ���������� ������ ��� ������� �����������
void delImgBuf(BITMAPINFO* bmi, RGBQUAD** pixelRGB);	//���������� �������, ������������� ����������� ���������� ������
BYTE extractBit(const DWORD pixBuf, const DWORD mask);	//���������� �������, ����������� ��� �� �����. ��������������� �������.
void loadImageBuf(FILE* fb, BITMAPFILEHEADER* bmfh, BITMAPINFO* bmi, RGBQUAD** pixelRGB);	//���������� �������, ������������ ������� � �����

void printHexPixel(BITMAPINFO* bmi, RGBQUAD** pixelRGB);	//���������� �������, ��������� �������� ��������
void showBMFH(BITMAPFILEHEADER* bmfh);						//���������� �������, ��������� ���� BITMAPFILEHEADER �����
void showBMI(BITMAPINFO *bmi);								//���������� �������, ��������� ���� BITMAPINFO �����


//������ ������� ������ ������ � �����
template <typename Type>
void readBytes(FILE *f, Type &buffer, std::size_t num) {
	fread(&buffer, sizeof(BYTE), num, f);
}