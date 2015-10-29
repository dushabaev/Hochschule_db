//---------------------------------------------------------------------------

#ifndef NavigationUnitH
#define NavigationUnitH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TNavigation : public TForm
{
__published:	// IDE-managed Components
	TButton *domainBtn;
	TButton *regionBtn;
	TButton *accrLvlBtn;
	TButton *eduLvlBtn;
	TButton *studTypeBtn;
	TButton *settlementBtn;
	TButton *placeBtn;
	TButton *structUnitTypeBtn;
	TButton *structUnitSpecBtn;
	TButton *structUnitBtn;
	TButton *specBtn;
	TButton *structUnitSpecStudBtn;
	TButton *hochTypeBtn;
	TButton *hochBtn;
	void __fastcall domainBtnClick(TObject *Sender);
	void __fastcall accrLvlBtnClick(TObject *Sender);
	void __fastcall studTypeBtnClick(TObject *Sender);
	void __fastcall specBtnClick(TObject *Sender);
	void __fastcall structUnitTypeBtnClick(TObject *Sender);
	void __fastcall structUnitBtnClick(TObject *Sender);
	void __fastcall structUnitSpecBtnClick(TObject *Sender);
	void __fastcall structUnitSpecStudBtnClick(TObject *Sender);
	void __fastcall settlementBtnClick(TObject *Sender);
	void __fastcall regionBtnClick(TObject *Sender);
	void __fastcall placeBtnClick(TObject *Sender);
	void __fastcall hochTypeBtnClick(TObject *Sender);
	void __fastcall eduLvlBtnClick(TObject *Sender);
	void __fastcall hochBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TNavigation(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNavigation *Navigation;
//---------------------------------------------------------------------------
#endif
