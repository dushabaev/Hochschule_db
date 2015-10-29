//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Domain.h"
#include "MainUnit.h"
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SecondBtnClick(TObject *Sender)
{
	domainForm->Show();
}
//---------------------------------------------------------------------------

