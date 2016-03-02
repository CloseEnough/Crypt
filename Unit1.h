//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TMemo *Memo1;
        TMemo *Memo2;
        TButton *Button1;
        TRadioGroup *RadioGroup1;
        TCheckBox *CheckBox1;
        TLabel *Label1;
        TMemo *Memo3;
        TLabel *Label2;
        TButton *Button3;
        TRadioGroup *RadioGroup2;
        TCheckBox *CheckBox2;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N5;
        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *N12;
        TMenuItem *N3;
        TActionList *ActionList1;
        TEditSelectAll *EditSelectAll1;
        TEditCut *EditCut1;
        TEditPaste *EditPaste1;
        TEditUndo *EditUndo1;
        TEditDelete *EditDelete1;
        TMenuItem *Cut1;
        TMenuItem *Paste1;
        TMenuItem *Undo1;
        TMenuItem *Delete1;
        TMenuItem *N2;
        TMenuItem *N4;
        TMenuItem *N8;
        TMenuItem *N9;
        TMenuItem *N13;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Memo1Change(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall N9Click(TObject *Sender);
        void __fastcall N7Click(TObject *Sender);
        void __fastcall N10Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall EditSelectAll1Execute(TObject *Sender);
        void __fastcall EditCut1Execute(TObject *Sender);
        void __fastcall EditPaste1Execute(TObject *Sender);
        void __fastcall EditUndo1Execute(TObject *Sender);
        void __fastcall EditDelete1Execute(TObject *Sender);
        void __fastcall N12Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);
        void __fastcall N13Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
