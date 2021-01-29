//----------------------------------------------------------------------
// Gorka Suárez García - Ing. Tec. Inf. de Gestión 2º B.
// Práctica 03 - Grupo 03.
//----------------------------------------------------------------------
#pragma hdrstop
#include "CaraConfidente.h"
#pragma package(smart_init)


Graphics::TBitmap * CaraConfidente::cargarBMP(AnsiString bmp)
{
    Graphics::TBitmap * BMP = &Graphics::TBitmap();
    BMP->LoadFromFile(bmp);
    return BMP;
}


Graphics::TBitmap * CaraConfidente::bitmaps[11] =
{
    CaraConfidente::cargarBMP("Images/A pescar.bmp"),
    CaraConfidente::cargarBMP("Images/Abanicos.bmp"),
    CaraConfidente::cargarBMP("Images/Azteca.bmp"),
    CaraConfidente::cargarBMP("Images/Grano de cafe.bmp"),
    CaraConfidente::cargarBMP("Images/Lazo azul 16.bmp"),
    CaraConfidente::cargarBMP("Images/Plumas.bmp"),
    CaraConfidente::cargarBMP("Images/Pompas.bmp"),
    CaraConfidente::cargarBMP("Images/Rhododendron.bmp"),
    CaraConfidente::cargarBMP("Images/Roca verde.bmp"),
    CaraConfidente::cargarBMP("Images/Santa Fe.bmp"),
    CaraConfidente::cargarBMP("Images/Viento.bmp")
};



CaraConfidente::CaraConfidente () : Cara ()
{
}


CaraConfidente::CaraConfidente (Pelo unPelo, Ojos unosOjos, NarizYOrejas unaNarizYOrejas,
                      Boca unaBoca, Menton unMenton) :
    Cara (unPelo, unosOjos, unaNarizYOrejas, unaBoca, unMenton)
{
}


CaraConfidente::~CaraConfidente ()
{
}


string CaraConfidente::getClassName (void) const
{
    return "CaraConfidente";
}


void CaraConfidente::dibuja (TCanvas * canvas) const
{
    canvas->Draw(0, 0, CaraConfidente::bitmaps[random(11)]);
}  


void CaraConfidente::dibujaSupervisor (TCanvas * canvas) const
{
    this->dibujaCara(canvas);
}


bool CaraConfidente::salvaTXT (ofstream & salida) const
{
	salida << this->getClassName().c_str() << endl;
	return this->salvarDatosTXT(salida);
}


bool CaraConfidente::cargaTXT (ifstream & entrada)
{
	char aux[256];
    
    entrada.getline(aux, 256);
    if(entrada.eof() || (aux != this->getClassName())) return false;

	return this->cargarDatosTXT(entrada);
}