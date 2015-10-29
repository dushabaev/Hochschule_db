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

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TNavigation *Navigation;
//---------------------------------------------------------------------------
__fastcall TNavigation::TNavigation(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TNavigation::domainBtnClick(TObject *Sender)
{
	domainForm->Show();
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
	hochForm->Show();
}
//---------------------------------------------------------------------------


