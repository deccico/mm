//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <MPlayer.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Dialogs.hpp>

#include "mmrutinas.h"
#include "Sysutils.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TPanel *panelVideo;
    TPanel *Panel2;
    TPanel *Panel3;
    TButton *btnOpen;
    TButton *btnClose;
    TButton *btnAllWindow;
    TLabel *Label1;
    TButton *btnDefSize;
    TButton *btnClearAll;
    TButton *btnClearItem;
    TListBox *lstVideos;
    TButton *Button4;
    TTimer *tmrHideMouse;
    TTimer *tmrNextVideo;
    TOpenDialog *OpenDialog1;
    TListBox *lst;
    TLabel *Label2;
    TButton *btnProp;
    TTimer *tmrFrame;
    TLabel *lblFrame;
    TButton *Button1;
    TEdit *txtFile;
    TRichEdit *re;
    TMediaPlayer *media;
    TLabel *lblSub;
    TStaticText *lblStatus;
    TLabel *lblTot;
    void __fastcall btnCloseClick(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnAllWindowClick(TObject *Sender);
    void __fastcall Button4Click(TObject *Sender);
    void __fastcall btnOpenClick(TObject *Sender);
    void __fastcall panelVideoClick(TObject *Sender);
    void __fastcall lstVideosClick(TObject *Sender);
    void __fastcall mediaNotify(TObject *Sender);
    void __fastcall btnClearAllClick(TObject *Sender);
    void __fastcall btnClearItemClick(TObject *Sender);
    void __fastcall tmrHideMouseTimer(TObject *Sender);
    void __fastcall FormKeyPress(TObject *Sender, char &Key);
    void __fastcall btnDefSizeClick(TObject *Sender);
    void __fastcall FormResize(TObject *Sender);
    void __fastcall mediaPostClick(TObject *Sender, TMPBtnType Button);
    void __fastcall tmrNextVideoTimer(TObject *Sender);
    void __fastcall btnPropClick(TObject *Sender);
    void __fastcall tmrFrameTimer(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
