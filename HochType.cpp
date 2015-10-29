//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HochType.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "template"
#pragma resource "*.dfm"
ThochTypeForm *hochTypeForm;
//---------------------------------------------------------------------------
__fastcall ThochTypeForm::ThochTypeForm(TComponent* Owner)
	: TtemplateForm(Owner)
{
}
//---------------------------------------------------------------------------
