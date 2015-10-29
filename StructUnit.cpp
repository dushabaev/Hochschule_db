//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StructUnit.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "template"
#pragma resource "*.dfm"
TstructUnitForm *structUnitForm;
//---------------------------------------------------------------------------
__fastcall TstructUnitForm::TstructUnitForm(TComponent* Owner)
	: TtemplateForm(Owner)
{
}
//---------------------------------------------------------------------------
