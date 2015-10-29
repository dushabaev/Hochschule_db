//---------------------------------------------------------------------------

#ifndef HochLevelH
#define HochLevelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "template.h"
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
//---------------------------------------------------------------------------
class TaccrLevelForm : public TtemplateForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TaccrLevelForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TaccrLevelForm *accrLevelForm;
//---------------------------------------------------------------------------
#endif
