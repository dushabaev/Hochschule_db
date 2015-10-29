// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Hochschule.h"
#include "DataModule.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "template"
#pragma resource "*.dfm"
using namespace std;
ThochForm *hochForm;
/*
template <typename T>
T min(T a, T b){
	return a <= b ? a : b;
}

template <typename T>
T max(T a, T b){
	return !min(a, b);
}
*/
// ---------------------------------------------------------------------------
__fastcall ThochForm::ThochForm(TComponent* Owner) : TtemplateForm(Owner) {
}
// ---------------------------------------------------------------------------

int ThochForm::getPlaceId() {
	TADOQuery* Q = DM->Query;
	Q->SQL->Text =
		"SELECT place.id FROM place JOIN (region, settlement) ON (region.id = region_id AND settlement.id = settlement_id) WHERE (region.name = :region AND settlement.name = :settlement)";
	Q->Parameters->ParamByName("region")->DataType = ftWideString;
	Q->Parameters->ParamByName("region")->Value = region->Text;

	Q->Parameters->ParamByName("settlement")->DataType = ftWideString;
	Q->Parameters->ParamByName("settlement")->Value = settlement->Text;

	Q->Active = true;
	Q->First();
	return Q->FieldByName("id")->AsInteger;
}

void ThochForm::updateSettlementFilter() {
	vector<TComboBox*>v;
	v.push_back(settlementFilter);
	refreshSettlement(v, regionFilter->Text);
	settlementFilter->ItemIndex = 0;
}

void ThochForm::updateSettlement() {
	vector<TComboBox*>v;
	v.push_back(settlement);

	refreshSettlement(v, region->Text);

	int index = settlement->Items->IndexOf
		(DBGrid1->DataSource->DataSet->FieldByName("settlement")->AsString);
	settlement->ItemIndex = index >= 0 ? index : 0;
}

void ThochForm::refreshSettlement(vector<TComboBox*>CB, UnicodeString value) {
	TADOQuery* Q = DM->Query;
	Q->SQL->Text =
		"SELECT settlement.name FROM place JOIN (settlement, region) ON (settlement_id=settlement.id AND region_id = region.id) WHERE region.name=:region ORDER BY settlement.name";
	Q->Parameters->ParamByName("region")->DataType = ftWideString;
	Q->Parameters->ParamByName("region")->Value = value;
	Q->Active = true;
	for (int i = 0; i < CB.size(); ++i)
		CB[i]->Items->Clear();

	for (Q->First(); !Q->Eof; Q->Next()) {
		for (int i = 0; i < CB.size(); ++i)
			CB[i]->Items->Add(Q->FieldByName("name")->AsString);
	}
}

void __fastcall ThochForm::FormCreate(TObject *Sender) {
	partialKeyCheckBox->Checked = true;
	caseIsnensetiveCheckBox->Checked = true;
	LOpts << loPartialKey;
	LOpts << loCaseInsensitive;
	FOpts << foCaseInsensitive;

	TLabel* label = new TLabel(ScrollBox1);
	TComboBox* box = new TComboBox(ScrollBox1);
	TButton* btn = new TButton(ScrollBox1);

	label->Caption = "From";
	label->Parent = ScrollBox1;
	label->Left = 11;
	label->Top = 5;
	label->Name += GetTickCount();
	labels.push_back(label);

	label = new TLabel(ScrollBox1);
	label->Parent = ScrollBox1;
	label->Caption = "To";
	label->Left = 99;
	label->Top = 5;
	label->Name += GetTickCount();
	labels.push_back(label);

	box->Parent = ScrollBox1;
	box->Left = 41;
	box->Top = 3;
	box->Name += GetTickCount();
	box->Width = 40;
	comboBoxes.push_back(box);

	box = new TComboBox(ScrollBox1);
	box->Parent = ScrollBox1;
	box->Left = 117;
	box->Top = 3;
	box->Name += GetTickCount();
	box->Width = 40;
	comboBoxes.push_back(box);

	btn->Parent = ScrollBox1;
	btn->Left = 167;
	btn->Top = 5;
	btn->Name += GetTickCount();
	btn->Width = 50;
	btn->Height = 17;
	btn->Caption = "Delete";
	btn->OnClick = delButtonClick;
	btn->Enabled = false;
	buttons.push_back(btn);
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::regionChange(TObject *Sender) {
	updateSettlement();
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::settlementChange(TObject *Sender) {
	int id = getPlaceId();

	if (DBGrid1->DataSource->DataSet->FieldByName("place_id")->AsInteger != id)
	{
		DBGrid1->DataSource->DataSet->Edit();
		DBGrid1->DataSource->DataSet->FieldByName("place_id")->AsInteger = id;
		DBGrid1->DataSource->DataSet->Post();
	}
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::hochSearchBoxChange(TObject *Sender) {
	if (!hochSearchBox->Modified)
		return;
	hochSearchBoxInvokeSearch(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::partialKeyCheckBoxClick(TObject *Sender) {
	if (partialKeyCheckBox->Checked)
		if (locateRB->Checked)
			LOpts << loPartialKey;
		else
			FOpts >> foNoPartialCompare;
	else if (locateRB->Checked)
		LOpts >> loPartialKey;
	else
		FOpts << foNoPartialCompare;

}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::caseInsensitiveCheckBoxClick(TObject *Sender) {
	if (caseIsnensetiveCheckBox->Checked)
		if (locateRB->Checked)
			LOpts << loCaseInsensitive;
		else
			FOpts << foCaseInsensitive;
	else if (locateRB->Checked)
		LOpts >> loCaseInsensitive;
	else
		FOpts >> foCaseInsensitive;
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::hochSearchBoxInvokeSearch(TObject *Sender) {
	// DBGrid1->DataSource->DataSet->Lookup()
	if (locateRB->Checked) {
		if (!DBGrid1->DataSource->DataSet->Locate("name", hochSearchBox->Text,
			this->LOpts)) {
			if (hochSearchBox->Text == "") {
				notFound->Visible = false;
				DBGrid1->DataSource->DataSet->First();
			}
			else
				notFound->Visible = true;
		}
		else
			notFound->Visible = false;
	}
	else {
		DM->hochFilterRows = 0;
		DBGrid1->DataSource->DataSet->Filtered = false;
		DBGrid1->DataSource->DataSet->Filtered = true;
		if (DM->hochFilterRows == 0 && hochSearchBox->Text != "") {
			notFound->Visible = true;
		}
		else
			notFound->Visible = false;
	}
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::filterRBClick(TObject *Sender) {
	if (filterRB->Checked) {
		caseIsnensetiveCheckBox->Checked =
			this->FOpts.Contains(foCaseInsensitive);
		partialKeyCheckBox->Checked = !this->FOpts.Contains(foNoPartialCompare);
	}
	hochSearchBoxInvokeSearch(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::locateRBClick(TObject *Sender) {
	if (locateRB->Checked) {
		caseIsnensetiveCheckBox->Checked =
			this->LOpts.Contains(loCaseInsensitive);
		partialKeyCheckBox->Checked = this->LOpts.Contains(loPartialKey);
	}
	DBGrid1->DataSource->DataSet->Filtered = false;
	hochSearchBoxInvokeSearch(Sender);
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::applyFiltersBtnClick(TObject *Sender) {
	TDataSet* mainTable = DBGrid1->DataSource->DataSet;
	DM->hochFilterRows = 0;
	mainTable->Filtered = false;
	mainTable->Filtered = true;
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::filterChange(TObject *Sender) {
	std::vector<TComboBox*>v;
	v.push_back(settlementFilter);
	refreshSettlement(v, regionFilter->Text);
	settlementFilter->ItemIndex = 0;
	if (autoFilterCheckBox->Checked) {
		DBGrid1->DataSource->DataSet->Filtered = false;
		DBGrid1->DataSource->DataSet->Filtered = true;
	}
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::delButtonClick(TObject *Sender) {
	for (int i = 0; i < 2; i++) {
		delete labels.back();
		labels.pop_back();

		delete comboBoxes.back();
		comboBoxes.pop_back();
	}
	delete buttons.back();
	buttons.pop_back();

	if (buttons.size() == 1) {
		buttons[0]->Enabled = false;
	}

	addButton->Top -= 30;
}

void __fastcall ThochForm::addButtonClick(TObject *Sender) {
	TLabel* label = new TLabel(ScrollBox1);
	TComboBox* box = new TComboBox(ScrollBox1);
	TButton* btn = new TButton(ScrollBox1);

	label->Caption = labels[labels.size() - 2]->Caption;
	label->Parent = ScrollBox1;
	label->Left = labels[labels.size() - 2]->Left;
	label->Top = labels[labels.size() - 2]->Top + 30;
	label->Name += IntToStr((int)GetTickCount());
	labels.push_back(label);

	label = new TLabel(ScrollBox1);
	label->Parent = ScrollBox1;
	label->Caption = labels[labels.size() - 2]->Caption;
	label->Left = labels[labels.size() - 2]->Left;
	label->Top = labels[labels.size() - 2]->Top + 30;
	label->Name += IntToStr((int)GetTickCount());
	labels.push_back(label);

	box->Parent = ScrollBox1;
	box->Left = comboBoxes[comboBoxes.size() - 2]->Left;
	box->Top = comboBoxes[comboBoxes.size() - 2]->Top + 30;
	box->Name += IntToStr((int)GetTickCount());
	box->Width = 40;
	comboBoxes.push_back(box);

	box = new TComboBox(ScrollBox1);
	box->Parent = ScrollBox1;
	box->Left = comboBoxes[comboBoxes.size() - 2]->Left;
	box->Top = comboBoxes[comboBoxes.size() - 2]->Top + 30;
	box->Name += IntToStr((int)GetTickCount());
	box->Width = 40;
	comboBoxes.push_back(box);

	btn->Parent = ScrollBox1;
	btn->Left = buttons.back()->Left;
	btn->Top = buttons.back()->Top + 30;
	btn->Name += IntToStr((int)GetTickCount());
	btn->Width = 50;
	btn->Height = 17;
	btn->Caption = buttons.back()->Caption;
	btn->OnClick = buttons.back()->OnClick;
	buttons.back()->Enabled = true;
	buttons.push_back(btn);

	addButton->Top += 30;

}

// ---------------------------------------------------------------------------
void __fastcall ThochForm::FormShow(TObject *Sender) {
	TADOQuery* Q = DM->Query;
	Q->SQL->Text = "SELECT name FROM region ORDER BY name";
	Q->Active = true;

	for (Q->First(); !Q->Eof; Q->Next()) {
		UnicodeString res = Q->FieldByName("name")->AsString;

		if (regionFilter->Items->IndexOf(res) == -1)
			regionFilter->Items->Add(res);

		if (region->Items->IndexOf(res) == -1)
			region->Items->Add(res);

	}
	regionFilter->ItemIndex = 0;
	region->ItemIndex = region->Items->IndexOf
		(DBGrid1->DataSource->DataSet->FieldByName("region")->AsString);
	updateSettlement();
	updateSettlementFilter();

	Q->SQL->Text = "SELECT type FROM hoch_type ORDER BY type";
	Q->Active = true;
	for (Q->First(); !Q->Eof; Q->Next()) {
		UnicodeString res = Q->FieldByName("type")->AsString;
		if (hochTypeFilter->Items->IndexOf(res) == -1)
			hochTypeFilter->Items->Add(res);
	}

    Q->SQL->Text = "select min(accr_level_low) minL, max(accr_level_low) maxL, min(accr_level_high) minH, max(accr_level_high) maxH from hochschule";
	Q->Active = true;
	int minI=0, maxI=0;
	for (Q->First(); !Q->Eof; Q->Next()) {
		int 
			minL = Q->FieldByName("minL")->AsInteger, 
			maxL = Q->FieldByName("maxL")->AsInteger, 
			minH = Q->FieldByName("maxL")->AsInteger, 
			maxH = Q->FieldByName("maxH")->AsInteger;
		minI = min(min(minL, minH), minI);
		maxI = max(max(maxL, maxH), maxI);		
	}

	for (int i = minI; i <= maxI; i++) {
		if (lowBound->Items->IndexOf(IntToStr(i)) == -1) {
			lowBound->Items->Add(IntToStr(i));
		}
		
		if (highBound->Items->IndexOf(IntToStr(i)) == -1) {
			highBound->Items->Add(IntToStr(i));
		}
	}
		
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::autoFilterCheckBoxClick(TObject *Sender) {
	applyFiltersBtn->Enabled = !autoFilterCheckBox->Enabled;

	DBGrid1->DataSource->DataSet->Filtered = false;
	DBGrid1->DataSource->DataSet->Filtered = true;
}
// ---------------------------------------------------------------------------



void __fastcall ThochForm::settlementCheckBoxClick(TObject *Sender) {
	regionCheckBox->Checked = true;
}
// ---------------------------------------------------------------------------


