//---------------------------------------------------------------------------

#ifndef EduLevelH
#define EduLevelH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Mask.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TeduLevelForm : public TForm
{
__published:	// IDE-managed Components
	TDBGrid *DBGrid1;
	TDBNavigator *DBNavigator1;
private:	// User declarations
public:		// User declarations
	__fastcall TeduLevelForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TeduLevelForm *eduLevelForm;
//---------------------------------------------------------------------------
#endif
