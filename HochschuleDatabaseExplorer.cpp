//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("Settlement.cpp", settlementForm);
USEFORM("Speciality.cpp", specialityForm);
USEFORM("searchSettings.cpp", searchSettingsForm);
USEFORM("Place.cpp", placeForm);
USEFORM("Region.cpp", regionForm);
USEFORM("StructUnit.cpp", structUnitForm);
USEFORM("StudyingType.cpp", sutdyingTypeForm);
USEFORM("template.cpp", templateForm);
USEFORM("StructUnitType.cpp", structUnitTypeForm);
USEFORM("StructUnitSpec.cpp", structUnitSpecForm);
USEFORM("StructUnitSpecStud.cpp", structUnitSpecStudForm);
USEFORM("HochLevel.cpp", accrLevelForm);
USEFORM("EduLevel.cpp", eduLevelForm);
USEFORM("DataModule.cpp", DM); /* TDataModule: File Type */
USEFORM("Domain.cpp", domainForm);
USEFORM("Hochschule.cpp", hochForm);
USEFORM("MainUnit.cpp", MainForm);
USEFORM("NavigationUnit.cpp", Navigation);
USEFORM("HochType.cpp", hochTypeForm);
USEFORM("SignIn.cpp", SignInForm);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TDM), &DM);
		Application->CreateForm(__classid(TNavigation), &Navigation);
		Application->CreateForm(__classid(ThochForm), &hochForm);
		Application->CreateForm(__classid(TdomainForm), &domainForm);
		Application->CreateForm(__classid(TMainForm), &MainForm);
		Application->CreateForm(__classid(TeduLevelForm), &eduLevelForm);
		Application->CreateForm(__classid(TtemplateForm), &templateForm);
		Application->CreateForm(__classid(TsutdyingTypeForm), &sutdyingTypeForm);
		Application->CreateForm(__classid(TspecialityForm), &specialityForm);
		Application->CreateForm(__classid(TstructUnitForm), &structUnitForm);
		Application->CreateForm(__classid(TstructUnitTypeForm), &structUnitTypeForm);
		Application->CreateForm(__classid(TstructUnitSpecForm), &structUnitSpecForm);
		Application->CreateForm(__classid(TstructUnitSpecStudForm), &structUnitSpecStudForm);
		Application->CreateForm(__classid(TsettlementForm), &settlementForm);
		Application->CreateForm(__classid(TregionForm), &regionForm);
		Application->CreateForm(__classid(TplaceForm), &placeForm);
		Application->CreateForm(__classid(ThochTypeForm), &hochTypeForm);
		Application->CreateForm(__classid(TaccrLevelForm), &accrLevelForm);
		Application->CreateForm(__classid(TsearchSettingsForm), &searchSettingsForm);
		Application->CreateForm(__classid(TSignInForm), &SignInForm);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
