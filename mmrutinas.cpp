//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "mmrutinas.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)


//devuelve coordenadas y area de la pantalla
void VerAreaVideo(int &x, int &y, int &h, int &w)
{
    TRect area;
    area=frmMain->media->DisplayRect;
    x=area.Left;
    y=area.Top;
    h=area.Right;
    w=area.Bottom;
}
