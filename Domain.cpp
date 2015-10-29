//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Domain.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TdomainForm *domainForm;

void TdomainForm::fillEdits(){
	idEdit->Text = DM->domain->FieldByName("id")->Text;
	nameEdit->Text = DM->domain->FieldByName("name")->Text;
}

void TdomainForm::fillRecord(){
	DM->domain->FieldByName("id")->Text = idEdit->Text;
	DM->domain->FieldByName("name")->Text = nameEdit->Text;
}


//---------------------------------------------------------------------------
__fastcall TdomainForm::TdomainForm(TComponent* Owner)
	: TForm(Owner), minHeight(Height), minWidth(Width)
{
}
//---------------------------------------------------------------------------


void __fastcall TdomainForm::beginBtnClick(TObject *Sender)
{
	DM->domain->First();
	this->fillEdits();
}
//---------------------------------------------------------------------------



void __fastcall TdomainForm::nextBtnClick(TObject *Sender)
{
	DM->domain->Next();
	this->fillEdits();
}
//---------------------------------------------------------------------------

void __fastcall TdomainForm::priorBtnClick(TObject *Sender)
{
	DM->domain->Prior();
	this->fillEdits();
}
//---------------------------------------------------------------------------

void __fastcall TdomainForm::addBtnClick(TObject *Sender)
{
	DM->domain->Insert();
	this->fillRecord();
	DM->domain->Post();
}
//---------------------------------------------------------------------------

void __fastcall TdomainForm::deleteBtnClick(TObject *Sender)
{
	DM->domain->Delete();
}
//---------------------------------------------------------------------------

void __fastcall TdomainForm::endBtnClick(TObject *Sender)
{
	DM->domain->Last();
	this->fillEdits();
}
//---------------------------------------------------------------------------

void __fastcall TdomainForm::applyBtnClick(TObject *Sender)
{
	DM->domain->Edit();
	this->fillRecord();
	DM->domain->Post();
}
//---------------------------------------------------------------------------


void __fastcall TdomainForm::FormShow(TObject *Sender)
{
	this->beginBtn->Click();
	this->fillEdits();
}
//---------------------------------------------------------------------------

