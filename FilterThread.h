//---------------------------------------------------------------------------

#ifndef FilterThreadH
#define FilterThreadH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class ThochForm;
class Filter : public TThread
{
private:
	ThochForm* Form;
protected:
	void __fastcall Execute();
	void __fastcall show();
	void __fastcall filter();
public:
	__fastcall Filter(bool CreateSuspended, ThochForm* Form);
	void __fastcall OnFilterTerminate();
};
//---------------------------------------------------------------------------
#endif
