//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "StructUnitSpec.h"
#include "DataModule.h"
#include <vector>
#include <string>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "template"
#pragma resource "*.dfm"
TstructUnitSpecForm *structUnitSpecForm;

int addToListBox(TADOQuery* Q, TListBox* LB, UnicodeString storedValue){
	int valueIndex = -1;
	Q->ExecSQL();
	Q->First();
	while(!Q->Eof) {
		LB->Items->Add(Q->Fields->Fields[0]->Text);
		if (Q->Fields->Fields[0]->Text == storedValue) {
			valueIndex = LB->Items->Count-1;
		}
		Q->Next();
	}
	return valueIndex;
};

void execQueryWithParams(TADOQuery* Q, std::vector<TListBox*> LB, std::vector<UnicodeString> params){
	Q->Active = false;
	for (unsigned int i = 0; i < params.size(); ++i){
		Q->Parameters->ParamByName(params[i])->Value = LB[i]->Items->Strings[LB[i]->ItemIndex];
	}
	Q->Active = true;
	Q->ExecSQL();
}

int getId(TADOQuery* Q, std::vector<TListBox*> LB, std::vector<UnicodeString> params){
	execQueryWithParams(Q, LB, params);
	Q->First();
	return	Q->FieldByName("id")->AsInteger;
}

void updateLB(TADOQuery* Q, TADOTable* table, std::vector<TListBox*> LB, std::vector<UnicodeString> params, UnicodeString field){
	TListBox* last = LB[LB.size()-1];
	last->Clear();
	execQueryWithParams(Q, LB, params);

	last->ItemIndex = addToListBox(Q, last, table->FieldByName(field)->Text);

	if (last->ItemIndex == -1 && last->Count > 0) {
		last->ItemIndex = 0;
	}
}

//---------------------------------------------------------------------------
__fastcall TstructUnitSpecForm::TstructUnitSpecForm(TComponent* Owner)
	: TtemplateForm(Owner)
{
}
//---------------------------------------------------------------------------




void TstructUnitSpecForm::fillInEduLevelLB(){
	eduLevelLB->ItemIndex = addToListBox(DM->Query, eduLevelLB, DM->structUnitSpec->FieldByName("edu_level_lookup")->Text);
}

void TstructUnitSpecForm::fillInDomainLB(){
	domainLB->ItemIndex = addToListBox(DM->Query, domainLB, DM->structUnitSpec->FieldByName("domain_lookup")->Text);
}


void TstructUnitSpecForm::fillInHochschuleLB(){
	hochschuleLB->ItemIndex = addToListBox(DM->Query, hochschuleLB, DM->structUnitSpec->FieldByName("hochschule_lookup")->Text);
}

void TstructUnitSpecForm::fillInStructUnitTypeLB(){
	structUnitTypeLB->ItemIndex = addToListBox(DM->Query, structUnitTypeLB, DM->structUnitSpec->FieldByName("struct_unit_type_lookup")->Text);
}


void TstructUnitSpecForm::refreshEduLevelLB(TDataSet* DataSet){
	eduLevelLB->ItemIndex = eduLevelLB->Items->IndexOf(DataSet->FieldByName("edu_level_lookup")->Text);
}

void TstructUnitSpecForm::refreshDomainLB(TDataSet* DataSet){
	domainLB->ItemIndex = domainLB->Items->IndexOf(DataSet->FieldByName("domain_lookup")->Text);
}


void TstructUnitSpecForm::refreshHochschuleLB(TDataSet* DataSet){
	hochschuleLB->ItemIndex = hochschuleLB->Items->IndexOf(DataSet->FieldByName("hochschule_lookup")->Text);
}

void TstructUnitSpecForm::refreshStructUnitTypeLB(TDataSet* DataSet){
	structUnitTypeLB->ItemIndex = structUnitTypeLB->Items->IndexOf(DataSet->FieldByName("struct_unit_type_lookup")->Text);
}


void __fastcall TstructUnitSpecForm::FormShow(TObject *Sender)
{
	TADOQuery* Q = DM->Query;
	Q->Prepared = true;

	// Speciality
	Q->SQL->Text = "SELECT name FROM edu_level ORDER BY name";
	Q->Active = true;
	fillInEduLevelLB();

	Q->SQL->Text = "SELECT name FROM domain ORDER BY name";
	Q->Active = true;
	fillInDomainLB();

	updateCourseLB(this);

	// structural unit
	Q->SQL->Clear();
	Q->SQL->Text = "SELECT name FROM hochschule ORDER BY name";
	Q->Active = true;
	fillInHochschuleLB();

	Q->SQL->Text = "SELECT type FROM struct_unit_type ORDER BY type";
	Q->Active = true;
	fillInStructUnitTypeLB();

	updateStructUnitNameLB(this);
}
//---------------------------------------------------------------------------

void __fastcall TstructUnitSpecForm::updateCourseLB(TObject *Sender)
{
	std::vector<TListBox*> LB;
	LB.push_back(eduLevelLB);
	LB.push_back(domainLB);
	LB.push_back(courseLB);

	std::vector<UnicodeString> params;
	params.push_back("edu_level");
	params.push_back("domain");

	updateLB(
		DM->courseNameQ,
		DM->structUnitSpec,
		LB, params, "course_name"
	);
	params.push_back("speciality");
	int id = getId(DM->specialityQ, LB, params);

	if (DM->structUnitSpec->FieldByName("speciality_id")->AsInteger != id){
		DM->structUnitSpec->Edit();
		DM->structUnitSpec->FieldByName("speciality_id")->AsInteger = id;
		//DM->structUnitSpec->Post();
	}
}
//---------------------------------------------------------------------------

void __fastcall TstructUnitSpecForm::updateStructUnitNameLB(TObject *Sender)
{
	std::vector<TListBox*> LB;
	LB.push_back(hochschuleLB);
	LB.push_back(structUnitTypeLB);
	LB.push_back(structUnitNameLB);

	std::vector<UnicodeString> params;
	params.push_back("hoch");
	params.push_back("type");

	updateLB(
		DM->structUnitNameQ,
		DM->structUnitSpec,
		LB, params, "struct_unit_name"
	);
	params.push_back("structUnitName");

	int id = getId(DM->structUnitQ, LB, params);
	if (DM->structUnitSpec->FieldByName("structural_unit_id")->AsInteger != id) {
		DM->structUnitSpec->Edit();
		DM->structUnitSpec->FieldByName("structural_unit_id")->AsInteger = id;
		//DM->structUnitSpec->Post();
	}
}
//---------------------------------------------------------------------------

void __fastcall TstructUnitSpecForm::Button1Click(TObject *Sender)
{
	std::vector<TListBox*> LB;
	LB.push_back(eduLevelLB);
	LB.push_back(domainLB);
	LB.push_back(courseLB);

	std::vector<UnicodeString> params;
	params.push_back("edu_level");
	params.push_back("domain");
	params.push_back("speciality");

	int id = getId(DM->specialityQ, LB, params);
	DM->structUnitSpec->Edit();
	DM->structUnitSpec->FieldByName("speciality_id")->AsInteger = id;
	DM->structUnitSpec->Post();
}
//---------------------------------------------------------------------------

