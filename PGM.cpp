#include "PGM.hpp"
#include "PPM.hpp"

#include <iostream>
using namespace std;

PGM::PGM(){
    pixels = nullptr;
	larg = 0;
	alt = 0;
	tipo = "";
}

PGM::~PGM() {
    if (pixels)
        //delete pixels;
    pixels = nullptr;
}


void PGM::Criar (int largura, int altura){
    this->larg = largura;
    this->alt = altura;
    this->tipo = "P2";
    pixels = new unsigned char [this->larg * this->alt];

    for (int i = 0; i < (this->larg * this->alt); i++){
        pixels[i] = 0;
    }
}
void PGM :: setLinha(int y, unsigned char cor){
    for(int x=0; x<larg; x++){
        pixels[y*larg+x] = cor;
    }
}
void PGM::setPintaLinha (unsigned char cor){
    for(int y=50; y<alt; y+=50){
        setLinha(y,cor);
    }
}
void PGM::pintaLinha (unsigned char cor){
    for(int y=50; y<alt; y+=50){
        setLinha(y,cor);
    }
}


int PGM::getLargura()
{
    return larg;
}

int PGM::getAltura()
{
    return alt;
}


unsigned char* & PGM::getPixels()
{
    return pixels;
}

unsigned char PGM::getPixel(int x, int y){
    if(pixels == nullptr)
    {
        cout << "Erro: faça a leitura da imagem antes de ler os pixels\n";
        return 0;
    }
    return pixels[y*larg + x];
}

void PGM::setPixel(int x, int y, unsigned char cor){

    if(pixels)
        pixels[y*larg + x] = cor;
}
bool PGM::ler(string caminho) {
    ifstream arq;
    string aux;

    

    arq.open(caminho);
    if (!arq.is_open()) {
        cout << "PGM: endereco do arquivo invalido\n";
        return false;
    }

    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler o tipo da imagem\n";
        return false;
    }
    tipo = aux;


    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler a largura da imagem\n";
        return false;
    }
    larg = atoi(aux.c_str());

    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler a altura da imagem\n";
        return false;
    }
    alt = atoi(aux.c_str());


    if (!lerDado(arq, &aux)) {
        cout << "PGM: erro ao ler o valor máximo de cor\n";
        return false;
    }
    vmax = atoi(aux.c_str());

    if (pixels)
        delete pixels;
    pixels = new unsigned char[larg * alt];

    int i = 0;
    while (!arq.eof()) {
        if (!lerDado(arq, &aux)) {
            break;
        }

        pixels[i] = (unsigned char) atoi(aux.c_str());
        i++;

    }

    //cout << "i: " << i << endl;
    if (i != larg * alt) {
        cout << "PGM: erro ao ler os pixels\n";
        return false;
    }

    //cout << this->tipo << endl;
    //cout << this->larg << endl;
    //cout << this->alt << endl;
    //cout << this->vmax << endl;


    return true;
}



bool PGM::gravar(string caminho) {

    if (!pixels)
        return false;

    ofstream arq;

    arq.open(caminho);
    if (!arq.is_open()) {
        cout << "PGM: endereco do arquivo invalido\n";
        return false;
    }

    arq << tipo << endl;

    arq << larg << " " << alt << endl;

    arq << 255 << endl; // valor máximo de cor fixo em 255

    int tam = larg * alt;
    for (int i = 0; i < tam; i++)
    {
        arq << (int) pixels[i] << endl;
        arq.flush();
    }
        

    arq.close();
    return true;
}

bool PGM::lerDado(ifstream &arq, string *dado) {
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

void PGM::inverteImagem (){
    PGM *img = new PGM();
	
	img->Criar(larg,alt);

    int x1 = 0;
    int y1 = -1;
    unsigned char corP;

    for(int y=alt; y>=0; y--){
        for(int x=0; x<larg; x++){
            cout << "\n x: " << x << endl;
            cout << "\n y: " << y << endl;
            
            corP = pixels[y * larg + x];
            img->setPixel(x, y1, corP);
        }
        y1++;
    }

    img->gravar("output.pgm");

	//delete img;
}

void PGM::copiaRegiao (int x1, int y1, int x2, int y2){
    PGM *img = new PGM();
	
	img->Criar(larg,alt);
    cout << "x1: " << x1 << endl;
    cout << "y1: " << y1 << endl;

    cout << "x2: " << x2 << endl;
    cout << "y2: " << y2 << endl;
    unsigned char corP;

    for(int i = 0; i < larg; i++){
        for(int j = 0; j < alt; j++){
            if(i >= x1 && i <= x2 && j >= y1 && j <= y2){
                corP = pixels[j * larg + i];
                img->setPixel(i, j, corP);
            }
        }
    }

    img->gravar("output.pgm");

	//delete img;
}