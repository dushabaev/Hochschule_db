//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "NavigationUnit.h"
#include "DataModule.h"
#include "Domain.h"
#include "eduLevel.h"
#include "EduLevel.h"
#include "HochLevel.h"
#include "Hochschule.h"
#include "HochType.h"
#include "Place.h"
#include "Region.h"
#include "Settlement.h"
#include "Speciality.h"
#include "StructUnit.h"
#include "StructUnitSpec.h"
#include "StructUnitSpecStud.h"
#include "StructUnitType.h"
#include "StudyingType.h"
#include "SignIn.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNavigation *Navigation;

enum class User {
	Anonymous, EduSecretary, Admin, None
};

User SignIn(TSignInForm* Form){
	if (Form->ShowModal() != mrOk)
		return User::None;

	if (Form->UserName == "anonymous")
		return User::Anonymous;

	if (Form->UserName == "edu" && Form->Password == "edu")
		return User::EduSecretary;

	if (Form->UserName == "admin" && Form->Password == "admin")
		return User::Admin;

	return None;
}

//---------------------------------------------------------------------------
__fastcall TNavigation::TNavigation(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TNavigation::domainBtnClick(TObject *Sender)
{
	switch (SignIn(SignInForm)) {
	case User::Anonymous:
		domainForm->Show();
		break;
	case User::EduSecretary:
		domainForm->Show();
		break;
	case User::Admin:
		domainForm->Show();
		break;
	}
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::accrLvlBtnClick(TObject *Sender)
{
	accrLevelForm->Show();
}
//---------------------------------------------------------------------------



void __fastcall TNavigation::studTypeBtnClick(TObject *Sender)
{
	sutdyingTypeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::specBtnClick(TObject *Sender)
{
	specialityForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::structUnitTypeBtnClick(TObject *Sender)
{
	structUnitTypeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::structUnitBtnClick(TObject *Sender)
{
	structUnitForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::structUnitSpecBtnClick(TObject *Sender)
{
	structUnitSpecForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::structUnitSpecStudBtnClick(TObject *Sender)
{
	structUnitSpecStudForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::settlementBtnClick(TObject *Sender)
{
	settlementForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::regionBtnClick(TObject *Sender)
{
	regionForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::placeBtnClick(TObject *Sender)
{
	placeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::hochTypeBtnClick(TObject *Sender)
{
	hochTypeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::eduLvlBtnClick(TObject *Sender)
{
	eduLevelForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TNavigation::hochBtnClick(TObject *Sender)
{
	switch (SignIn(SignInForm)) {
	case User::Anonymous:
		hochForm->Show();
		hochForm->DBGrid1->ReadOnly = true;
		hochForm->setComboBoxesState(false);
		break;
	case User::EduSecretary:
	case User::Admin:
		hochForm->Show();
		break;
	}
}
//---------------------------------------------------------------------------


