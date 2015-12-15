//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "FilterThread.h"
#include "DataModule.h"
#include "Hochschule.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Filter::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall Filter::Filter(bool CreateSuspended, ThochForm* Form)
	: TThread(CreateSuspended), Form(Form)
{
}
//---------------------------------------------------------------------------
void __fastcall Filter::Execute()
{
	FreeOnTerminate = true;
	OnTerminate = (TNotifyEvent)&OnFilterTerminate;
	//Synchronize(&filter);
	filter();
}
//---------------------------------------------------------------------------

void __fastcall Filter::show(){
	bool empty = Form->Memo->Lines->Count == 0;
	Form->setComboBoxesState(!empty);
	Form->notFound->Visible = empty;
	Form->ActivityIndicator1->Animate = false;
}

void __fastcall Filter::OnFilterTerminate(){
	Synchronize(&show);
}

void __fastcall Filter::filter(){
	Form->DBGrid1->DataSource->DataSet->Filtered = false;
	Form->DBGrid1->DataSource->DataSet->Filtered = true;
}