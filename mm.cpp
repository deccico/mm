//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("mm.res");
USEFORM("Unit1.cpp", frmMain);
USE("mm.todo", ToDo);
USEUNIT("mmrutinas.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TfrmMain), &frmMain);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
