#ifndef PGM_H_INCLUDED
#define PGM_H_INCLUDED

#include <string>
#include <fstream>

class PGM
{
public:
    PGM();
    ~PGM();

    bool ler(std::string caminho);

	void Criar( int altura, int largura);

    void setPintaLinha (unsigned char cor);

    void pintaLinha (unsigned char cor);

    bool gravar(std::string caminho);

     //retorna o vetor de pixels por referência! As alteraçõe realizadas fora da classe serão gravadas no vetor!
    unsigned char* & getPixels();
    
    unsigned char getPixel(int x, int y);

    void setPixel(int x, int y, unsigned char cor);
   
    void setLinha(int y, unsigned char cor);

    void inverteImagem ();

    void copiaRegiao (int x1, int y1, int x2, int y2);

    int getLargura();
	
    int getAltura();


private:
    bool lerDado(std::ifstream &arq, std::string *dado);

    std::string tipo;
	int larg;
	int alt;
	int vmax;
	unsigned char* pixels; // unsigned char -> 0 a 255

};

#endif