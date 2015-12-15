// ---------------------------------------------------------------------------

#pragma hdrstop

#include "DataModule.h"
#include "StructUnitSpec.h"
#include "Hochschule.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma classgroup "Vcl.Controls.TControl"
#pragma resource "*.dfm"
TDM *DM;

// ---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner) : TDataModule(Owner), hochFilterRows(0) {
}
// ---------------------------------------------------------------------------

void __fastcall TDM::DataModuleDestroy(TObject *Sender) {
	/* domain->Active = false;
	 eduLevel->Active = false;
	 hochAndLevel->Active = false;
	 hochType->Active = false;
	 hochschule->Active = false;
	 place->Active = false;
	 region->Active = false;
	 settlement->Active = false;
	 speciality->Active = false;
	 structUnitSpec->Active = false;
	 structUnitSpecStud->Active = false;
	 structUnitType->Active = false;
	 structUnit->Active = false;
	 studyingType->Active = false;
	 */
	ADOConnection->Close();
}
// ---------------------------------------------------------------------------

void __fastcall TDM::DataModuleCreate(TObject *Sender) {
	ADOConnection->Open();
	/* domain->Active = true;
	 eduLevel->Active = true;
	 hochAndLevel->Active = true;
	 hochType->Active = true;
	 hochschule->Active = true;
	 place->Active = true;
	 region->Active = true;
	 settlement->Active = true;
	 speciality->Active = true;
	 structUnitSpec->Active = true;
	 structUnitSpecStud->Active = true;
	 structUnitType->Active = true;
	 structUnit->Active = true;
	 studyingType->Active = true;
	 */
}
// ---------------------------------------------------------------------------

void __fastcall TDM::structUnitSpecAfterScroll(TDataSet *DataSet) {
	TstructUnitSpecForm* form = structUnitSpecForm;
	if (!form) {
		return;
	}

	form->refreshEduLevelLB(DataSet);
	form->refreshDomainLB(DataSet);
	form->updateCourseLB(form);

	form->refreshHochschuleLB(DataSet);
	form->refreshStructUnitTypeLB(DataSet);
	form->updateStructUnitNameLB(form);

}
// ---------------------------------------------------------------------------

void __fastcall TDM::hochschuleFilterRecord(TDataSet *DataSet, bool &Accept) {
	Accept = true;
	if (!hochForm) {
        return;
	}
	// Filter by name
	if (hochForm->filterRB->Checked)
		if (hochForm->FOpts.Contains(foCaseInsensitive))
			if (hochForm->FOpts.Contains(foNoPartialCompare))
				Accept = DataSet->FieldByName("name")->AsString.UpperCase()
					== hochForm->hochSearchBox->Text.UpperCase() ||
					hochForm->hochSearchBox->Text == "";
			else
				Accept = DataSet->FieldByName("name")->AsString.UpperCase().Pos
					(hochForm->hochSearchBox->Text.UpperCase()) == 1 ||
					hochForm->hochSearchBox->Text == "";

		else if (hochForm->FOpts.Contains(foNoPartialCompare))
			Accept = DataSet->FieldByName("name")
				->AsString == hochForm->hochSearchBox->Text ||
				hochForm->hochSearchBox->Text == "";
		else
			Accept = DataSet->FieldByName("name")->AsString.Pos
				(hochForm->hochSearchBox->Text) == 0 ||
				hochForm->hochSearchBox->Text == "";

	// Filter by other categories
	Accept = Accept &&
		// Region
		(!hochForm->regionCheckBox->Checked ||
		DataSet->FieldByName("region")->AsString ==
		hochForm->regionFilter->Text) &&

		// Setllement
		(!hochForm->settlementCheckBox->Checked ||
		DataSet->FieldByName("settlement")->AsString ==
		hochForm->settlementFilter->Text) &&

		// Hochschule type
		(!hochForm->typeCheckBox->Checked ||
		DataSet->FieldByName("hoch_type_lookup")->AsString ==
		hochForm->hochTypeFilter->Text);

	if (Accept && hochForm->accrLevelFilterCheckBox->Checked) {
		if (hochForm->partialRanges->Checked) {
			for (int i = 0; Accept && i < hochForm->comboBoxes.size(); i+=2) {
				Accept = Accept && 
				// Is lower bound in range ?
				(DataSet->FieldByName("accr_level_low")->AsInteger >=
				StrToInt(hochForm->comboBoxes[i]->Text) &&
				DataSet->FieldByName("accr_level_low")->AsInteger <=
				StrToInt(hochForm->comboBoxes[i+1]->Text) ||

				// Is upper bound in range ?
				DataSet->FieldByName("accr_level_high")->AsInteger >=
				StrToInt(hochForm->comboBoxes[i]->Text) &&
				DataSet->FieldByName("accr_level_high")->AsInteger <=
				StrToInt(hochForm->comboBoxes[i+1]->Text));
			}
		}
		else{
			for (int i = 0; Accept && i < hochForm->comboBoxes.size(); i+=2) {
				Accept = Accept && 
				DataSet->FieldByName("accr_level_low")->Text ==
				hochForm->comboBoxes[i]->Text &&
				DataSet->FieldByName("accr_level_high")->Text ==
				hochForm->comboBoxes[i+1]->Text;
			}
        }
	}

	if (Accept) {
		++hochFilterRows;
		UnicodeString str="";
		for (int i = 0; i < DataSet->FieldCount-1; i++)
			str += DataSet->Fields->Fields[i]->Text + ";";
		if (DataSet->FieldCount-1 >= 0) {
			str += DataSet->Fields->Fields[DataSet->FieldCount-1]->Text;
		}
		hochForm->Memo->Lines->Add(str);
	}

}
// ---------------------------------------------------------------------------

void __fastcall TDM::hochschuleAfterScroll(TDataSet * DataSet) {
	ThochForm* form = hochForm;
	if (!form || form->Memo->Lines->Count <= 0)
		return;

	form->region->ItemIndex = form->region->Items->IndexOf
		(DataSet->FieldByName("region")->AsString);
	form->updateSettlement();

	form->lowBound->ItemIndex = DataSet->FieldByName("accr_level_low")->AsInteger-1;
	form->lowBoundChange(form->lowBound);

	form->highBound->ItemIndex = DataSet->FieldByName("accr_level_high")->AsInteger-1;
}
// ---------------------------------------------------------------------------

