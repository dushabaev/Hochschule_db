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

void fetchQuery(TADOQuery* Q, TComboBox** items, unsigned int count) {
	Q->Active = true;
	for (Q->First(); !Q->Eof; Q->Next())
		for (unsigned int i = 0; i < count; ++i) {
			UnicodeString record = Q->Fields->Fields[0]->AsString;
			if (items[i]->Items->IndexOf(record) == -1)
				items[i]->Items->Add(record);
		}
}

bool itemExist(TComboBox* box, UnicodeString item) {
	return box->Items->IndexOf(item) != -1;
}

UnicodeString selectedItem(TComboBox* box) {
	return box->Items->Strings[box->ItemIndex];
}

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
	// Comment to find
	Q->Parameters->ParseSQL(Q->SQL->Text, true);
	Q->Parameters->ParamByName("region")->DataType = ftWideString;
	Q->Parameters->ParamByName("region")->Value = value;
	Q->Active = true;
	for (unsigned int i = 0; i < CB.size(); ++i)
		CB[i]->Items->Clear();

	for (Q->First(); !Q->Eof; Q->Next()) {
		for (unsigned int i = 0; i < CB.size(); ++i)
			CB[i]->Items->Add(Q->FieldByName("name")->AsString);
	}
}

void __fastcall ThochForm::FormCreate(TObject *Sender) {
	partialKeyCheckBox->Checked = true;
	caseIsnensetiveCheckBox->Checked = true;
	LOpts << loPartialKey << loCaseInsensitive;
	FOpts << foCaseInsensitive;

	TLabel* label = new TLabel(ScrollBox1);
	TComboBox* box = new TComboBox(ScrollBox1);
	TButton* btn = new TButton(ScrollBox1);

	label->Caption = "From";
	label->Parent = ScrollBox1;
	label->Left = 11;
	label->Top = 22;
	label->Name += GetTickCount();
	labels.push_back(label);

	label = new TLabel(ScrollBox1);
	label->Parent = ScrollBox1;
	label->Caption = "To";
	label->Left = 99;
	label->Top = 22;
	label->Name += GetTickCount();
	label->Tag = 1;
	labels.push_back(label);

	box->Parent = ScrollBox1;
	box->Left = 41;
	box->Top = 20;
	box->Name += GetTickCount();
	box->Width = 40;
	comboBoxes.push_back(box);

	box = new TComboBox(ScrollBox1);
	box->Parent = ScrollBox1;
	box->Left = 117;
	box->Top = 20;
	box->Name += GetTickCount();
	box->Width = 40;
	box->Tag = 1;
	comboBoxes.push_back(box);

	btn->Parent = ScrollBox1;
	btn->Left = 167;
	btn->Top = 22;
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
	
	if (autoFilterCheckBox->Checked && regionCheckBox->Checked) {
		TDataSet* ds = DBGrid1->DataSource->DataSet;
		
		ds->Filtered = false;

		if (ds->Filter.Length() != 0)
			ds->Filter += " AND ";
			
		ds->Filter += "region = '" +regionFilter->Text + "'";

		ds->Filtered = true;
		
	}
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::delButtonClick(TObject *Sender) {
	TButton* btn = (TButton*)Sender;
	addButton->Top -= 30;

	for (int i = buttons.size() - 1; i > btn->Tag; --i) {
		labels[i * 2]->Top = labels[(i - 1) * 2]->Top;
		labels[i * 2]->Tag -= 2;

		labels[i * 2 + 1]->Top = labels[(i - 1) * 2 + 1]->Top;
		labels[i * 2 + 1]->Tag -= 2;

		comboBoxes[i * 2]->Top = comboBoxes[(i - 1) * 2]->Top;
		comboBoxes[i * 2]->Tag -= 2;

		comboBoxes[i * 2 + 1]->Top = comboBoxes[(i - 1) * 2 + 1]->Top;
		comboBoxes[i * 2 + 1]->Tag -= 2;

		buttons[i]->Top = buttons[i - 1]->Top;
		buttons[i]->Tag -= 1;
	}

	delete labels[btn->Tag * 2];
	labels.erase(labels.begin() + btn->Tag*2);

	delete labels[btn->Tag * 2];
	labels.erase(labels.begin() + btn->Tag*2);

	delete comboBoxes[btn->Tag * 2];
	comboBoxes.erase(comboBoxes.begin() + btn->Tag*2);

	delete comboBoxes[btn->Tag * 2];
	comboBoxes.erase(comboBoxes.begin() + btn->Tag*2);

	delete buttons[btn->Tag];
	buttons.erase(buttons.begin() + btn->Tag);

	if (buttons.size() == 1) {
		buttons[0]->Enabled = false;
	}
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
	label->Tag = labels[labels.size() - 2]->Tag + 2;
	labels.push_back(label);

	label = new TLabel(ScrollBox1);
	label->Parent = ScrollBox1;
	label->Caption = labels[labels.size() - 2]->Caption;
	label->Left = labels[labels.size() - 2]->Left;
	label->Top = labels[labels.size() - 2]->Top + 30;
	label->Name += IntToStr((int)GetTickCount());
	label->Tag = labels[labels.size() - 2]->Tag + 2;
	labels.push_back(label);

	box->Parent = ScrollBox1;
	box->Left = comboBoxes[comboBoxes.size() - 2]->Left;
	box->Top = comboBoxes[comboBoxes.size() - 2]->Top + 30;
	box->Tag = comboBoxes[comboBoxes.size() - 2]->Tag + 2;
	box->Name += IntToStr((int)GetTickCount());
	box->Tag = comboBoxes[comboBoxes.size() - 2]->Tag + 2;
	box->Width = 40;
	comboBoxes.push_back(box);

	box = new TComboBox(ScrollBox1);
	box->Parent = ScrollBox1;
	box->Left = comboBoxes[comboBoxes.size() - 2]->Left;
	box->Top = comboBoxes[comboBoxes.size() - 2]->Top + 30;
	box->Tag = comboBoxes[comboBoxes.size() - 2]->Tag + 2;
	box->Name += IntToStr((int)GetTickCount());
	box->Tag = comboBoxes[comboBoxes.size() - 2]->Tag + 2;
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
	btn->Tag = buttons.size();
	buttons.back()->Enabled = true;
	buttons.push_back(btn);

	addButton->Top += 30;
	f(comboBoxes[comboBoxes.size() - 2], comboBoxes[comboBoxes.size() - 1]);
}

void ThochForm::f(TComboBox* lowBound, TComboBox* highBound) {
	TADOQuery* Q = DM->Query;
	Q->SQL->Text =
		"SELECT MIN(accr_level_low) minL, MAX(accr_level_low) maxL, MIN(accr_level_high) minH, MAX(accr_level_high) maxH FROM hochschule";
	Q->Active = true;
	Q->First();
	int minAccrLevel = 1, maxAccrLevel = 1, minL =
		Q->Fields->Fields[0]->AsInteger, maxL = Q->Fields->Fields[1]->AsInteger,
		minH = Q->Fields->Fields[2]->AsInteger, maxH =
		Q->Fields->Fields[3]->AsInteger;

	minAccrLevel = min(min(minL, minH), minAccrLevel);
	maxAccrLevel = max(max(maxL, maxH), maxAccrLevel);

	for (int i = minAccrLevel; i <= maxAccrLevel; i++) {
		if (!itemExist(lowBound, IntToStr(i)))
			lowBound->Items->Add(IntToStr(i));

		if (!itemExist(highBound, IntToStr(i)))
			highBound->Items->Add(IntToStr(i));
	}
	lowBound->ItemIndex = minAccrLevel - 1;
	highBound->ItemIndex = maxAccrLevel - 1;
	lowBound->OnChange = lowBoundChange;
}

// ---------------------------------------------------------------------------
void __fastcall ThochForm::FormShow(TObject *Sender) {
	TADOQuery* Q = DM->Query;

	TComboBox* comboBox[] = {region, regionFilter, settlement, settlementFilter
	};

	Q->SQL->Text = "SELECT name FROM region ORDER BY name";
	fetchQuery(Q, comboBox, 2);
	regionFilter->ItemIndex = 0;
	region->ItemIndex = region->Items->IndexOf
		(DBGrid1->DataSource->DataSet->FieldByName("region")->AsString);

	// ------------------------------------------------------------------------------
	Q->SQL->Text =
		"SELECT settlement.name FROM place JOIN (settlement, region) ON (settlement_id=settlement.id AND region_id = region.id) WHERE region.name=:region ORDER BY settlement.name";
	for (unsigned int i = 0; i < 2; i++) {
		Q->Parameters->ParamByName("region")->DataType = ftWideString;
		Q->Parameters->ParamByName("region")->Value = selectedItem(comboBox[i]);
		fetchQuery(Q, &comboBox[i + 2], 1);
	}
	settlementFilter->ItemIndex = 0;
	settlement->ItemIndex = settlement->Items->IndexOf
		(DBGrid1->DataSource->DataSet->FieldByName("settlement")->AsString);

	// ------------------------------------------------------------------------------
	Q->SQL->Text = "SELECT type FROM hoch_type ORDER BY type";
	fetchQuery(Q, &hochTypeFilter, 1);
	hochTypeFilter->ItemIndex = 0;

	// ------------------------------------------------------------------------------
	f(lowBound, highBound);
	f(comboBoxes[comboBoxes.size() - 2], comboBoxes[comboBoxes.size() - 1]);

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
void __fastcall ThochForm::lowBoundChange(TObject *Sender) {
	TComboBox *sender = (TComboBox*)Sender, *cmb = sender->Tag == -1 ?
		highBound : comboBoxes[sender->Tag + 1];
	UnicodeString item = selectedItem(cmb);

	cmb->Clear();
	for (int i = StrToInt(selectedItem(sender)); i <= sender->Items->Count; i++)
	{
		cmb->Items->Add(IntToStr(i));
	}
	cmb->ItemIndex = StrToInt(selectedItem(sender)) >= StrToInt(item) ? 0 :
		cmb->Items->IndexOf(item);

	if (sender->Tag == -1) {
		TDataSet* ds = DBGrid1->DataSource->DataSet;

		if (ds->FieldByName("accr_level_low")->AsString != selectedItem(sender))
		{
			ds->Edit();
			ds->FieldByName("accr_level_low")->AsString = selectedItem(sender);
			ds->Post();
		}
		
		cmb->OnChange(cmb);
	}
}
// ---------------------------------------------------------------------------

void __fastcall ThochForm::highBoundChange(TObject *Sender)
{
	TComboBox *sender = (TComboBox*)Sender;
	TDataSet* ds = DBGrid1->DataSource->DataSet;
	
	if (sender->Tag == -1) {
		if (ds->FieldByName("accr_level_high")->AsString != selectedItem(sender))
		{
			ds->Edit();
			ds->FieldByName("accr_level_high")->AsString = selectedItem(sender);
			ds->Post();
		}
	}

}
//---------------------------------------------------------------------------

