//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Settlement.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "template"
#pragma resource "*.dfm"
TsettlementForm *settlementForm;
//---------------------------------------------------------------------------
__fastcall TsettlementForm::TsettlementForm(TComponent* Owner)
	: TtemplateForm(Owner)
{
}
//---------------------------------------------------------------------------
