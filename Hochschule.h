//---------------------------------------------------------------------------

#ifndef HochschuleH
#define HochschuleH
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
#include <Vcl.CheckLst.hpp>
#include <Vcl.WinXCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
class ThochForm : public TtemplateForm
{
__published:	// IDE-managed Components
	TSearchBox *hochSearchBox;
	TComboBox *region;
	TComboBox *settlement;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *notFound;
	TGroupBox *searchSettings;
	TCheckBox *partialKeyCheckBox;
	TCheckBox *caseIsnensetiveCheckBox;
	TRadioButton *locateRB;
	TRadioButton *filterRB;
	TGroupBox *filters;
	TComboBox *regionFilter;
	TCheckBox *regionCheckBox;
	TCheckBox *settlementCheckBox;
	TComboBox *settlementFilter;
	TCheckBox *accrLevelFilterCheckBox;
	TComboBox *hochTypeFilter;
	TCheckBox *typeCheckBox;
	TButton *applyFiltersBtn;
	TScrollBox *ScrollBox1;
	TButton *addButton;
	TCheckBox *autoFilterCheckBox;
	TLabel *Label3;
	TComboBox *lowBound;
	TComboBox *highBound;
	TLabel *Label4;
	TLabel *Label5;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall regionChange(TObject *Sender);
	void __fastcall settlementChange(TObject *Sender);
	void __fastcall hochSearchBoxChange(TObject *Sender);
	void __fastcall partialKeyCheckBoxClick(TObject *Sender);
	void __fastcall caseInsensitiveCheckBoxClick(TObject *Sender);
	void __fastcall hochSearchBoxInvokeSearch(TObject *Sender);
	void __fastcall filterRBClick(TObject *Sender);
	void __fastcall locateRBClick(TObject *Sender);
	void __fastcall applyFiltersBtnClick(TObject *Sender);
	void __fastcall filterChange(TObject *Sender);
	void __fastcall addButtonClick(TObject *Sender);
	void __fastcall delButtonClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall autoFilterCheckBoxClick(TObject *Sender);
	void __fastcall settlementCheckBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall ThochForm(TComponent* Owner);
	void updateSettlement();
	void updateSettlementFilter();
	void refreshSettlement(std::vector<TComboBox*>, UnicodeString);
	int getPlaceId();
	TLocateOptions LOpts;
	TFilterOptions FOpts;
	bool autoFilter;
	std::vector<TLabel*> labels;
	std::vector<TComboBox*> comboBoxes;
	std::vector<TButton*> buttons;
};
//---------------------------------------------------------------------------
extern PACKAGE ThochForm *hochForm;
//---------------------------------------------------------------------------
#endif