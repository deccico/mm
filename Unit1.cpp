/*
    Reproductor Multimedia
    Diciembre del 2003
    hecho por Adrián Deccico

*/

//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
int nLine,nAncho,nAlto;  //alto y ancho por defecto de la pantalla de video
TDateTime tTime;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
        media->Notify = true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnCloseClick(TObject *Sender)
{
    media->Stop();
    media->Close();
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
    int n=ParamCount();
    AnsiString s;
    media->Display=panelVideo;
    media->TimeFormat = tfHMS;


    if (n>0){
        for (int i=1;i<=n;i++){
            s=ParamStr(i);
            //s=GetCurrentDir() + "\\" + s;
            lstVideos->Items->Add(s);
        }
        lstVideos->ItemIndex=0;
        lstVideosClick(NULL);
        btnPropClick(NULL);
    }
}
//---------------------------------------------------------------------------

//maximized
void __fastcall TfrmMain::btnAllWindowClick(TObject *Sender)
{
    int nVAncho,nVAlto;
    TRect area;

    //this->BorderStyle=bsNone;
    this->WindowState=wsMaximized;
    panelVideo->Align=alClient;


    btnDefSizeClick(NULL);
    nVAncho=panelVideo->Width;
    nVAlto=(nVAncho*nAlto) / nAncho;

    if (nVAlto > panelVideo->Height){
        nVAlto=panelVideo->Height;
        nVAncho=(nVAlto*nAncho) / nAlto;
    }

    area.Left=panelVideo->Left;
    area.Top=panelVideo->Top;
    area.Right=nVAncho - panelVideo->Left;
    area.Bottom=nVAlto - panelVideo->Top;

    if (nVAncho==panelVideo->Width && (nVAlto<panelVideo->Height))
            area.Top=area.Top + ((panelVideo->Height-nVAlto) / 2);
    else
    if (nVAlto==panelVideo->Height && (nVAncho < panelVideo->Width))
            area.Left=area.Left + ((panelVideo->Width-nVAncho) / 2);


    media->Stop();
    media->Close();
    media->Open();
    media->DisplayRect=area;
    nLine=0;
    media->Play();
    //tmrFrame->Enabled=true;
    //tmrHideMouse->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Button4Click(TObject *Sender)
{
    this->ClientHeight = this->ClientHeight/2;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::btnOpenClick(TObject *Sender)
{
    int nVAncho,nVAlto;
    TRect area;

    btnDefSizeClick(NULL);
    nVAncho=panelVideo->Width;
    nVAlto=(nVAncho*nAlto) / nAncho;

    if (nVAlto > panelVideo->Height){
        nVAlto=panelVideo->Height;
        nVAncho=(nVAlto*nAncho) / nAlto;
    }

    area.Left=panelVideo->Left;
    area.Top=panelVideo->Top;
    area.Right=nVAncho - panelVideo->Left;
    area.Bottom=nVAlto - panelVideo->Top;

    if (nVAncho==panelVideo->Width && (nVAlto<panelVideo->Height))
            area.Top=area.Top + ((panelVideo->Height-nVAlto) / 2);
    else
    if (nVAlto==panelVideo->Height && (nVAncho < panelVideo->Width))
            area.Left=area.Left + ((panelVideo->Width-nVAncho) / 2);
	if (OpenDialog1->Execute())
	{
        if (media->FileName != "")
            media->Stop();
        media->Close();
        media->FileName=OpenDialog1->FileName;
        media->Open();
        media->DisplayRect=area;

        nLine=0;
        media->Play();
        //tmrFrame->Enabled=true;
	}
    for (int i=0; i < OpenDialog1->Files->Count; i++){
        lstVideos->Items->Add(OpenDialog1->Files->Strings[i]);
    }
    //lstVideos->Items = lstVideos->Items->Text + ;
}
//---------------------------------------------------------------------------

//restaurar
void __fastcall TfrmMain::panelVideoClick(TObject *Sender)
{
    int nVAncho,nVAlto;
    TRect area;

    this->WindowState=wsNormal;
    panelVideo->Cursor=crDefault;
    //this->BorderStyle=bsSizeable;
    panelVideo->Align=alNone;
    panelVideo->Width=513;
    panelVideo->Height=345;
    panelVideo->Align=alNone;

    btnDefSizeClick(NULL);
    nVAncho=panelVideo->Width;
    nVAlto=(nVAncho*nAlto) / nAncho;

    if (nVAlto > panelVideo->Height){
        nVAlto=panelVideo->Height;
        nVAncho=(nVAlto*nAncho) / nAlto;
    }

    area.Left=panelVideo->Left;
    area.Top=panelVideo->Top;
    area.Right=nVAncho - panelVideo->Left;
    area.Bottom=nVAlto - panelVideo->Top;

    if (nVAncho==panelVideo->Width && (nVAlto<panelVideo->Height))
            area.Top=area.Top + ((panelVideo->Height-nVAlto) / 2);
    else
    if (nVAlto==panelVideo->Height && (nVAncho < panelVideo->Width))
            area.Left=area.Left + ((panelVideo->Width-nVAncho) / 2);


    media->Stop();
    media->Close();
    media->Open();
    media->DisplayRect=area;
    nLine=0;
    media->Play();
    //tmrFrame->Enabled=true;

}
//---------------------------------------------------------------------------

/*void __fastcall TfrmMain::lstVideosClick(TObject *Sender)
{
    TRect area;
    area.Left=panelVideo->Left;
    area.Top=panelVideo->Top;
    area.Right=panelVideo->Width-panelVideo->Left;
    area.Bottom=panelVideo->Height-panelVideo->Top;

    if (media->Mode==mpPlaying) media->Stop();
    media->Close();
    if (lstVideos->ItemIndex > -1)
        media->FileName=lstVideos->Items->Strings[lstVideos->ItemIndex];
    media->Open();
    media->DisplayRect=area;
    nLine=0;
    //media->TimeFormat = tfMSF;
    tTime = Time();
    lblTot->Caption=media->Length;
    media->Play();
    tmrFrame->Enabled=true;
    //btnPropClick(NULL);

}
//---------------------------------------------------------------------------
*/


void __fastcall TfrmMain::lstVideosClick(TObject *Sender)
{
    int nVAncho,nVAlto;
    TRect area;

    btnDefSizeClick(NULL);
    nVAncho=panelVideo->Width;
    nVAlto=(nVAncho*nAlto) / nAncho;

    if (nVAlto > panelVideo->Height){
        nVAlto=panelVideo->Height;
        nVAncho=(nVAlto*nAncho) / nAlto;
    }

    area.Left=panelVideo->Left;
    area.Top=panelVideo->Top;
    area.Right=nVAncho - panelVideo->Left;
    area.Bottom=nVAlto - panelVideo->Top;

    if (nVAncho==panelVideo->Width && (nVAlto<panelVideo->Height))
            area.Top=area.Top + ((panelVideo->Height-nVAlto) / 2);
    else
    if (nVAlto==panelVideo->Height && (nVAncho < panelVideo->Width))
            area.Left=area.Left + ((panelVideo->Width-nVAncho) / 2);


    if (media->Mode==mpPlaying) media->Stop();
    media->Close();
    if (lstVideos->ItemIndex > -1)
        media->FileName=lstVideos->Items->Strings[lstVideos->ItemIndex];
    media->Open();
    media->DisplayRect=area;
    nLine=0;
    media->Play();
    //tmrFrame->Enabled=true;

    tTime = Time();
    lblTot->Caption=media->Length;

}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::mediaNotify(TObject *Sender)
{
    int i,j;
    AnsiString sMsg;
    AnsiString ModeStr[] = {"Not ready", "Stopped", "Playing", "Recording", "Seeking", "Paused", "Open"};
    sMsg = ModeStr[(int) media->Mode];
    lblStatus->Caption=sMsg;
    /*media->Notify = false;
      if (sMsg=="Stopped"){
        i=lstVideos->ItemIndex;
        j=lstVideos->Items->Count;
        if (i+1==j)
            lstVideos->ItemIndex=0;
        else{
            //lstVideos->ItemIndex=lstVideos->ItemIndex+1;
            //lstVideosClick(NULL);
            media->Next();
        }
    }
    */
    media->Notify = true;
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::btnClearAllClick(TObject *Sender)
{
    lstVideos->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnClearItemClick(TObject *Sender)
{
    lstVideos->Items->Delete(lstVideos->ItemIndex);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::tmrHideMouseTimer(TObject *Sender)
{
    static TPoint OldCur;
    int x,y,w,h; //medidas del panelVideo
    int vx,vy,vw,vh; //medidas del display Video
    TPoint MouseCur;

    //panelVideo->Cursor=crNone;
    //tmrHideMouse->Enabled=false;

    MouseCur =Mouse->CursorPos;
    if (OldCur.x != MouseCur.x || OldCur.y != MouseCur.y){
        if (media->Display->Cursor != 0) media->Display->Cursor=0;
        OldCur =Mouse->CursorPos;
        return;
    }

    VerAreaVideo(vx,vy,vh,vw);

    x = this->Left + panelVideo->Left+4;
    y=this->Top+panelVideo->Top+15;
    h=y+vh-58;
    w=x+vw+80;

    OldCur =Mouse->CursorPos;
    lst->Clear();
    //¿está dentro del panel de video?
    if (MouseCur.x > x && MouseCur.x < w && MouseCur.y > y && MouseCur.y < h){
        lst->Items->Add("mouse off");
        media->Display->Cursor=-1;
    }
    else{
        lst->Items->Add("mouse on");
        media->Display->Cursor=0;
    }


    lst->Items->Add("mouse x" +AnsiString(MouseCur.x));
    lst->Items->Add("panel x" +AnsiString(x));
    lst->Items->Add("mouse y" +AnsiString(MouseCur.y));
    lst->Items->Add("panel y" +AnsiString(y));
    lst->Items->Add("panel h" +AnsiString(h));
    lst->Items->Add("panel w "+AnsiString(w));
    lst->Items->Add("video x" +AnsiString(vx));
    lst->Items->Add("video y" +AnsiString(vy));
    lst->Items->Add("video h" +AnsiString(vh));
    lst->Items->Add("video w" +AnsiString(vw));
    
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormKeyPress(TObject *Sender, char &Key)
{
  if (118==Key)
    lst->Visible=true;
  else
  if (98==Key)
    lst->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnDefSizeClick(TObject *Sender)
{
    TRect area;

    area.Left=panelVideo->Left;
    area.Top=panelVideo->Top;
    area.Right=panelVideo->Left;
    area.Bottom=panelVideo->Top;
    media->DisplayRect=area;
    area=media->DisplayRect;
    nAncho=area.Right-area.Left;
    nAlto=area.Bottom-area.Top;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormResize(TObject *Sender)
{
    //if (this->Height > 150)
    //    Panel1->Height=this->Height-74;

    //if (this->Width > 400)
     //   Panel1->Width=this->Width-325;

}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mediaPostClick(TObject *Sender, TMPBtnType Button)
{
  Label1->Caption="algo";
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::tmrNextVideoTimer(TObject *Sender)
{
    int i,j;
    j=lstVideos->Items->Count;

    if (j==0)
        return;
    if (media->Mode==mpStopped){
        i=lstVideos->ItemIndex;
        if (i+1==j)
            lstVideos->ItemIndex=0;
        else
            lstVideos->ItemIndex=lstVideos->ItemIndex+1;
        lstVideosClick(NULL);}
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::btnPropClick(TObject *Sender)
{
    //todo averiguar tamaño por defecto

    int nVAncho,nVAlto;
    TRect area;

    btnDefSizeClick(NULL);
    nVAncho=panelVideo->Width;
    nVAlto=(nVAncho*nAlto) / nAncho;

    if (nVAlto > panelVideo->Height){
        nVAlto=panelVideo->Height;
        nVAncho=(nVAlto*nAncho) / nAlto;
    }

    area.Left=panelVideo->Left;
    area.Top=panelVideo->Top;
    area.Right=nVAncho - panelVideo->Left;
    area.Bottom=nVAlto - panelVideo->Top;

    if (nVAncho==panelVideo->Width && (nVAlto<panelVideo->Height))
            area.Top=area.Top + ((panelVideo->Height-nVAlto) / 2);
    else
    if (nVAlto==panelVideo->Height && (nVAncho < panelVideo->Width))
            area.Left=area.Left + ((panelVideo->Width-nVAncho) / 2);


    if (media->Mode==mpPlaying) media->Stop();
    media->Close();
    if (lstVideos->ItemIndex > -1)
        media->FileName=lstVideos->Items->Strings[lstVideos->ItemIndex];
    media->Open();
    media->DisplayRect=area;
    nLine=0;
    media->Play();
    //tmrFrame->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::tmrFrameTimer(TObject *Sender)
{
    AnsiString sText,sAux,sT;
    int j,k,sep[4],found=0;
    TDateTime t,t1=Time();
    int i;//=media->Position


    if (re->Lines->Text=="") return;
    j=0;
    k=0;
    for (int r=0;r<5;sep[r]=0,r++);

    sText=re->Lines->Strings[nLine];
    if (sText=="") return;
    t=t1-tTime;
    sT = FormatDateTime("nnsszzz",t);

    sT=sT.SubString(1,sT.Length()-2);
    i = sT.ToInt()+100;

    for(int s=1; s<=sText.Length() && found < 4 ;s++){
        sAux=sText.SubString(s,1);
        if ( sAux == '{' || sAux == '}' ) {
            sep[found]=s;
            found++;
        }
    }

    if (found<4) return;
    try{
    j=sText.SubString(sep[0]+1,sep[1]-sep[0]-1).ToInt();
    k=sText.SubString(sep[2]+1,sep[3]-sep[2]-1).ToInt();
    lblFrame->Caption = AnsiString(i)+" "+AnsiString(j)+" "+AnsiString(k);
    if (i>=j && i<=k){
        lblSub->Caption=sText.SubString(sep[3]+1,sText.Length()-sep[3]-1);
        nLine++;
    }
    else
    lblSub->Caption="";
    //if (i>=j && i>=k)
     //   nLine++;
        //lblSub->Caption="";
    }
    catch(Exception&){
        //;nLine=0
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::Button1Click(TObject *Sender)
{
    re->Lines->LoadFromFile(txtFile->Text);
}
//---------------------------------------------------------------------------

