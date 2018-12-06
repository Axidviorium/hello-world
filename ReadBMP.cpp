// ReadBMP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "StructFunc.h"

 
//static unsigned short read_ut16(FILE *fp)
//{
//	unsigned char b0, b1;
//
//	b0 = getc(fp);
//	b1 = getc(fp);
//
//	return ((b1 << 8) | b0);
//}
//
//
//static unsigned int read_ut32(FILE *fp)
//{
//	unsigned char b0, b1, b2, b3;
//
//	b0 = getc(fp);
//	b1 = getc(fp);
//	b2 = getc(fp);
//	b3 = getc(fp);
//
//	return ((((((b3 << 8) | b2) << 8) | b1) << 8) | b0);
//}

int main()
{
	BITMAPFILEHEADER bmfh;
	BITMAPINFO bmi;
	FILE *f = NULL;							//указатель для файла с изображением
	RGBQUAD** pixelSet = NULL;

	std::cout << "Hello World!\n";
	if (!opFile(&f)){ std::cout << "OpFile stopped with code NULL!\n";  return 1; }	//Открываем BMP файл по названию в текстовом файле
	loadBMFH(&bmfh, f);																//Заполняем поля BITMAPFILEHEADER
	if (!loadBMPI(f, &bmfh, &bmi)) { std::cout << "Load is fail!"; return 1; }		//Заполняем поля BITMAPINFO

	showBMFH(&bmfh);
	showBMI(&bmi);

	if (!chkSetMask(&bmi)) { std::cout << "Unsupported format!"; return 1; }		//проверка и выставление масок
	pixelSet = createImageBuf(&bmi);		//Выделяем динамическую память под пиксели 
	std::cout << "\naddr pixel set:" << std::hex << pixelSet << "\n";
	loadImageBuf(f, &bmfh, &bmi, pixelSet);	//Заполняем память
	printHexPixel(&bmi, pixelSet);			//Вывод значений пикселей
	fclose(f);								//Закрываем файл
	delImgBuf(&bmi, pixelSet);				//Освобождаем память
	pixelSet = NULL;
	
	std::cout << "\nFin!\n";
}


//fopen_s(&f, "Abba.bmp", "rb");