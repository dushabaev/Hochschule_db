//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "HochLevel.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "template"
#pragma resource "*.dfm"
TaccrLevelForm *accrLevelForm;
//---------------------------------------------------------------------------
__fastcall TaccrLevelForm::TaccrLevelForm(TComponent* Owner)
	: TtemplateForm(Owner)
{
}
//---------------------------------------------------------------------------
