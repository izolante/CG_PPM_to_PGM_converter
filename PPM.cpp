#include "PPM.hpp"
#include "PGM.hpp"
#include <iostream>
using namespace std;

PPM::PPM()
{
    pixels = nullptr;
	larg = 0;
	alt = 0;
	tipo = "";
}

PPM::~PPM() {
    if (pixels)
        delete pixels;
    pixels = nullptr;
}


int PPM::getLargura()
{
    return larg;
}

int PPM::getAltura()
{
    return alt;
}

unsigned char* & PPM::getPixels()
{
    return pixels;
}

void PPM::getPixel(int x, int y, unsigned char *corR, unsigned char *corG, unsigned char *corB)
{
    if (!pixels) //Se "pixels==NULL" retorna
        return;

    *corR = pixels[y*larg*3 + x*3]; //cor do canal R para pixels de coordenada (x, y)
    *corG = pixels[y*larg*3 + x*3 + 1];
    *corB = pixels[y*larg*3 + x*3 + 2];

    cout << "\n R: " << corR << " G: " << corG <<  " B: " << corB << endl;
}

void PPM::setPixel(int x, int y, unsigned char corR, unsigned char corG, unsigned char corB)
{
    if (!pixels)//Se "pixels==NULL" retorna
        return;

    pixels[y*larg*3 + x*3] = corR;
    pixels[y*larg*3 + x*3 + 1] = corG;
    pixels[y*larg*3 + x*3 + 2] = corB;
    
        
}

void PPM::circulaArea(int x1, int y1, int x2, int y2, unsigned char corR, unsigned char corG, unsigned char corB)
{
    if (!pixels)//Se "pixels==NULL" retorna
        return;

    for(int i = 0; i < larg*3; i+=3)
        cout << "\n i: " << i;
    //pixels[y*larg*3 + x*3] = corR;
    //pixels[y*larg*3 + x*3 + 1] = corG;
    //pixels[y*larg*3 + x*3 + 2] = corB;
    
        
}

void PPM::convertePPMtoPGM(){
    cout << "convertePPMtoPGM < entrou";

    cout << "\n larg: " << larg << " alt: " << alt;

    PGM *img = new PGM();
    img->Criar(larg, alt);
    int h = 0;
    unsigned char r=0, g=0, b=0;
    int cinza = 0;
    /*
    r = pixels[1*larg*3 + 1*3];
    g = pixels[1*larg*3 + 1*3 + 1];
    b = pixels[1*larg*3 + 1*3 + 2];

    cout << endl;
    cout << r << " " << g << " " <<  b << endl;
    */
    
    for(int i = 0; i < larg; i++){
        for(int j = 0; j < alt; j+=0){
            //cout << "\n\n pixel " << i << " - " << j << pixels[j*larg*3 + i*3 +h];

            switch(h){
                case 0:
                    cout << "\n h: 0";
                    r = pixels[j*larg*3 + i*3 + h];
                    h++;
                    break;
                case 1:
                    cout << "\n h: 1";
                    g = pixels[j*larg*3 + i*3 + h];
                    h++;
                    break;
                case 2:
                    cout << "\n h: 2";
                    b = pixels[j*larg*3 + i*3 + h];
                    h = 0;

                    cout << "\n pixel ( " << i << ", " << j << " ) cor: " << " r: " << (int) r << " g: " << (int) g << " b: " << (int) b << endl; 
                    cinza = 0.299 * (int) r + 0.587 * (int) g + 0.114 * (int) b;

                    img->setPixel(i, j, cinza);
                    j++;
                    break;
            }
            
        }
    }
    img->gravar("miranha.pgm");
    //pixels[j*larg*3 + i*3 + h]

}

/* // gera uma imagem pulando 2 pixels no X e no Y
void PPM::convertePPMtoPGM(){
    cout << "convertePPMtoPGM < entrou";

    cout << "\n larg: " << larg << " alt: " << alt;

    PGM *img = new PGM();
    img->Criar(larg, alt);
    int h = 0;
    unsigned char r=0, g=0, b=0;
    int cinza = 0;
    /*
    r = pixels[1*larg*3 + 1*3];
    g = pixels[1*larg*3 + 1*3 + 1];
    b = pixels[1*larg*3 + 1*3 + 2];

    cout << endl;
    cout << r << " " << g << " " <<  b << endl;
    
    
    for(int i = 0; i < larg; i+=3){
        for(int j = 0; j < alt; j++){
            //cout << "\n\n pixel " << i << " - " << j << pixels[j*larg*3 + i*3 +h];

            switch(h){
                case 0:
                    cout << "\n h: 0";
                    r = pixels[j*larg*3 + i*3 + h];
                    h++;
                    break;
                case 1:
                    cout << "\n h: 1";
                    g = pixels[j*larg*3 + i*3 + h];
                    h++;
                    break;
                case 2:
                    cout << "\n h: 2";
                    b = pixels[j*larg*3 + i*3 + h];
                    h = 0;

                    cout << "\n pixel ( " << i << ", " << j << " ) cor: " << " r: " << (int) r << " g: " << (int) g << " b: " << (int) b << endl; 
                    cinza = 0.299 * (int) r + 0.587 * (int) g + 0.114 * (int) b;

                    img->setPixel(i, j, cinza);

                    break;
            }
            
        }
    }
    img->gravar("miranha.pgm");
    //pixels[j*larg*3 + i*3 + h]

}*/

/*
void PPM::convertePPMtoPGM(){
    cout << "convertePPMtoPGM < entrou";

    cout << "\n larg: " << larg << " alt: " << alt;

    PGM *img = new PGM();
    img->Criar(larg, alt);
    int h = 0;
    unsigned char r=0, g=0, b=0;
    int cinza = 0;
    /*
    r = pixels[1*larg*3 + 1*3];
    g = pixels[1*larg*3 + 1*3 + 1];
    b = pixels[1*larg*3 + 1*3 + 2];

    cout << endl;
    cout << r << " " << g << " " <<  b << endl;
    
    
    for(int i = 0; i < larg; i++){
        for(int j = 0; j < alt; j++){
            //cout << "\n\n pixel " << i << " - " << j << pixels[j*larg*3 + i*3 +h];

            switch(h){
                case 0:
                    cout << "\n h: 0";
                    r = pixels[j*larg*3 + i*3 + h];
                    h++;
                    break;
                case 1:
                    cout << "\n h: 1";
                    g = pixels[j*larg*3 + i*3 + h];
                    h++;
                    break;
                case 2:
                    cout << "\n h: 2";
                    b = pixels[j*larg*3 + i*3 + h];
                    h = 0;

                    cout << "\n pixel ( " << i << ", " << j << " ) cor: " << " r: " << (int) r << " g: " << (int) g << " b: " << (int) b << endl; 
                    cinza = 0.299 * (int) r + 0.587 * (int) g + 0.114 * (int) b;
                    //cout << ""
                    img->setPixel(i, j, cinza);

                    break;
            }
            
        }
    }
    img->gravar("miranha.pgm");
    //pixels[j*larg*3 + i*3 + h]

}*/


bool PPM::ler(string caminho) {
    ifstream arq;
    string aux;

    

    arq.open(caminho);
    if (!arq.is_open()) {
        cout << "Erro ao ler PPM: endereco do arquivo invalido!\n";
        return false;
    }

    if (!lerDado(arq, &aux)) {
        cout << "Erro ao ler PPM: não foi possível ler o tipo da imagem!\n";
        return false;
    }
    tipo = aux;


    if (!lerDado(arq, &aux)) {
        cout << "Erro ao ler PPM: ão foi possível ler a largura da imagem\n";
        return false;
    }
    larg = atoi(aux.c_str());

    if (!lerDado(arq, &aux)) {
        cout << "Erro ao ler PPM: ão foi possível ler a altura da imagem\n";
        return false;
    }
    alt = atoi(aux.c_str());


    if (!lerDado(arq, &aux)) {
        cout << "Erro ao ler PPM: não foi possível ler o valor máximo de cor!\n";
        return false;
    }
    vmax = atoi(aux.c_str());

    if (pixels) //verifica se o vetor de pixels já está alocado (pixels != NULL) e desaloca memória.
        delete pixels;

    //aloca o vetor de pixels    
    pixels = new unsigned char[larg * alt * 3];

    //lê os valores de cor dos pixels
    int i = 0;
    while (!arq.eof()) 
    {
        if (!lerDado(arq, &aux)) {
            break;
        }

        pixels[i] = (unsigned char) atoi(aux.c_str());
        i++;
    }

    //cout << "i: " << i << endl;
    if (i != larg * alt * 3) {
        cout << "Erro ao ler PPM: a quantidades de pixels lida é inválida!\n";
        return false;
    }

    //cout << this->tipo << endl;
    //cout << this->larg << endl;
    //cout << this->alt << endl;
    //cout << this->vmax << endl;


    return true;
}


bool PPM::gravar(string caminho) {

    if (!pixels)
        return false;

    ofstream arq;

    arq.open(caminho);
    if (!arq.is_open()) {
        cout << "Erro ao gravar PPM: endereco do arquivo invalido!\n";
        return false;
    }

    arq << tipo << endl;

    arq << larg << " " << alt << endl;

    arq << 255 << endl; // valor máximo de cor fixo em 255

    int tam = larg * alt *3 ;
    for (int i = 0; i < tam; i++)
    {
        arq << (int) pixels[i] << endl;
        arq.flush();
    }
        

    arq.close();
    return true;
}


bool PPM::lerDado(ifstream &arq, string *dado) {
    string aux;
    while (!arq.eof()) {
        arq >> aux;
        if (aux.size() > 0 && aux[0] == '#') {
            std::getline(arq, aux);
        }else if(aux.size() > 0){
            *dado = aux;
            return true;
        }

        aux = "";
    }
    return false;
}
