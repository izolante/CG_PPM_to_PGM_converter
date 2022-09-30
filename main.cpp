#include <iostream>
#include "PPM.hpp"
#include "PGM.hpp"

using namespace std;

int main(void)
{
	setlocale(LC_ALL, "Portuguese");
	
	PPM *img = new PPM();

	//|Ler
	img->ler("spider.ppm");

	//unsigned char r=0, g=0, b=0;
	//int x = 0, y=0;
	//img->getPixel(x, y, &r, &g, &b);
	//cout << "A cor do pixel(" << x << ", " << y << ") é " << "[" << (int) r << ", " << (int) g << ", " << (int) b << "]\n";
	
	img->convertePPMtoPGM();

	//SET
	//img->setPixel(1, 0, 0, 128, 128); // pixel(1, 0), RGB(0, 128, 128)

	//img->circulaArea(0, 0, 0, 0, 0, 0, 0);

	//GET
	//unsigned char r=0, g=0, b=0;
	//int x = 0, y=0;
	//img->getPixel(x, y, &r, &g, &b);
	//cout << "A cor do pixel(" << x << ", " << y << ") é " << "[" << (int) r << ", " << (int) g << ", " << (int) b << "]\n";

	//Gravar
	//img->gravar("saida.ppm");


	//Desalocar memória
	cout << "\n\n\n\n\n\n Imagem salva como miranha.pgm";
	delete img;
	
	return EXIT_SUCCESS; 
}
