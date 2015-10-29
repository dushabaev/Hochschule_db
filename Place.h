//---------------------------------------------------------------------------

#ifndef PlaceH
#define PlaceH
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
class TplaceForm : public TtemplateForm
{
__published:	// IDE-managed Components
private:	// User declarations
public:		// User declarations
	__fastcall TplaceForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TplaceForm *placeForm;
//---------------------------------------------------------------------------
#endif
