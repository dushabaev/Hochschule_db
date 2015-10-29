//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Region.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "template"
#pragma resource "*.dfm"
TregionForm *regionForm;
//---------------------------------------------------------------------------
__fastcall TregionForm::TregionForm(TComponent* Owner)
	: TtemplateForm(Owner)
{
}
//---------------------------------------------------------------------------
