//---------------------------------------------------------------------------

#ifndef DomainH
#define DomainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TdomainForm : public TForm
{
__published:	// IDE-managed Components
	TButton *applyBtn;
	TButton *nextBtn;
	TButton *priorBtn;
	TButton *addBtn;
	TButton *deleteBtn;
	TButton *beginBtn;
	TButton *endBtn;
	TDBGrid *DBGrid1;
	TLabel *Label1;
	TEdit *idEdit;
	TEdit *nameEdit;
	void __fastcall beginBtnClick(TObject *Sender);
	void __fastcall nextBtnClick(TObject *Sender);
	void __fastcall priorBtnClick(TObject *Sender);
	void __fastcall addBtnClick(TObject *Sender);
	void __fastcall deleteBtnClick(TObject *Sender);
	void __fastcall endBtnClick(TObject *Sender);
	void __fastcall applyBtnClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);


private:	// User declarations
	int minHeight, minWidth;
	int deltaHeight, deltaWidth;
public:		// User declarations
	__fastcall TdomainForm(TComponent* Owner);
	void fillEdits();
	void fillRecord();
};
//---------------------------------------------------------------------------
extern PACKAGE TdomainForm *domainForm;
//---------------------------------------------------------------------------
#endif
