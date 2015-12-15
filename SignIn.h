//---------------------------------------------------------------------------

#ifndef SignInH
#define SignInH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Buttons.hpp>
//---------------------------------------------------------------------------
class TSignInForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *UserName;
	TEdit *Password;
	TLabel *Label1;
	TLabel *Label2;
	TBitBtn *SignIn;
	TBitBtn *Cancel;
private:	// User declarations
public:		// User declarations
	__fastcall TSignInForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TSignInForm *SignInForm;
//---------------------------------------------------------------------------
#endif
