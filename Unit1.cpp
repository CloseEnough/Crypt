//---------------------------------------------------------------------------

#include <vcl.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <iostream.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
char* keychar=new char[Memo3->Text.Length()];
strcpy(keychar, Memo3->Text.c_str());//оголошуєм символьний масив ключа і копіюєм в нього дані із поля Memo3
int keylen=Memo3->Text.Length()/2;
int* key=new int[keylen];//оголошуєм масив який буде містити ключ у числовому форматі
int l=0;
for(int i=0; i<Memo3->Text.Length()-1; i++)
        {
                if(l<keylen)
                {
                        key[l]=(((int)keychar[i]-48)*10)+((int)keychar[i+1]-48); l++; i++;
                }
                else
                break;
        }//переводим ключ в числовий формат із символьного

  if(CheckBox2->Checked==false)
  {
  int n=floor(sqrt(Memo1->Text.Length()));//Розмірність матриці
                if(n*n<Memo1->Text.Length())
                        n++;
  char* temp1=new char[Memo1->Text.Length()];//одновимірний масив із незакодованим текстом
  char **decode=new char *[n];
  for(int i=0; i<n; i++)
        decode[i]=new char[n];
  char **encode=new char *[n];
        if(RadioGroup2->ItemIndex==0)
        {

                if(RadioGroup1->ItemIndex==0)
                {
                                Form2->StringGrid1->RowCount=n+1;
                                Form2->StringGrid1->ColCount=n+1;
                                for(int i=1; i<n+1; i++)
                                {
                                Form2->StringGrid1->Cells[0][i]=i;
                                Form2->StringGrid1->Cells[i][0]=i;
                                }
                                strcpy(temp1, Memo1->Text.c_str());//копіюєм в одновимірний масив значення поля із текстом
                                int k=0;//лічильник, який буде відповідати за довжину одновимірного масиву
                                for(int i=0; i<n; i++)
                                        for(int j=0; j<n; j++)
                                        {
                                                if(k<Memo1->Text.Length())
                                                decode[i][j]=temp1[k];
                                                else
                                                decode[i][j]=' ';
                                                k++;
                                        }//записуєм одновимірний масив у двовимірний
                                for(int i=0; i<n; i++)
                                        for(int j=0; j<n; j++)
                                        {
                                                Form2->StringGrid1->Cells[j+1][i+1]=decode[i][j];
                                        }//записуєм у к-т StringGrid1 незашифровані дані
                                for(int i=0; i<n; i++)
                                        encode[i]=new char[n];
                                for(int i=0; i<n; i++)
                                        for(int j=0, l=0; j<n; j++, l++)
                                        {
                                                if(l==Memo3->Text.Length())
                                                l=0;
                                                encode[i][j]=decode[i][key[l]-1];
                                        }
                                Form2->StringGrid2->RowCount=n+1;
                                Form2->StringGrid2->ColCount=n+1;
                                for(int i=1, l=0; i<n+1; i++, l++)
                                {
                                Form2->StringGrid2->Cells[0][i]=i;
                                Form2->StringGrid2->Cells[i][0]=key[l];
                                }
                                for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                                        Form2->StringGrid2->Cells[j+1][i+1]=encode[i][j];
                                Memo2->Clear();
                                for(int i=1; i<n+1; i++)
                                        for(int j=1; j<n+1; j++)
                                        {
                                                if(Form2->StringGrid2->Cells[j][i]==' ')
                                                        Memo2->Text=Memo2->Text+'_';
                                                else
                                                        Memo2->Text=Memo2->Text+Form2->StringGrid2->Cells[j][i];
                                        }


                }
                if(RadioGroup1->ItemIndex==1)
                {
                        Form2->StringGrid1->RowCount=n+1;
                        Form2->StringGrid1->ColCount=n+1;
                        for(int i=1; i<n+1; i++)
                                {
                                Form2->StringGrid1->Cells[0][i]=i;
                                Form2->StringGrid1->Cells[i][0]=i;
                                }
                        strcpy(temp1, Memo1->Text.c_str());//копіюєм в одновимірний масив значення поля із текстом
                        int k=0;//лічильник, який буде відповідати за довжину одновимірного масиву
                        for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                                {
                                        if(k<Memo1->Text.Length())
                                                decode[i][j]=temp1[k];
                                        else
                                                decode[i][j]=' ';
                                        k++;
                                }//записуєм одновимірний масив у двовимірний
                        for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                                {
                                        Form2->StringGrid1->Cells[j+1][i+1]=decode[i][j];
                                }//записуєм у к-т StringGrid1 незашифровані дані
                        for(int i=0; i<n; i++)
                                encode[i]=new char[n];
                        for(int i=0; i<n; i++)
                                for(int j=0, l=0; j<n; j++, l++)
                                {
                                        if(l==Memo3->Text.Length())
                                        l=0;
                                        encode[j][i]=decode[key[l]-1][i];
                                }
                        Form2->StringGrid2->RowCount=n+1;
                        Form2->StringGrid2->ColCount=n+1;
                        for(int i=1, l=0; i<n+1; i++, l++)
                                {
                                Form2->StringGrid2->Cells[0][i]=key[l];
                                Form2->StringGrid2->Cells[i][0]=i;
                                }
                        for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                                        Form2->StringGrid2->Cells[j+1][i+1]=encode[i][j];
                        Memo2->Clear();
                        for(int i=1; i<n+1; i++)
                                for(int j=1; j<n+1; j++)
                                {
                                        if(Form2->StringGrid2->Cells[j][i]==' ')
                                                Memo2->Text=Memo2->Text+'_';
                                        else
                                                Memo2->Text=Memo2->Text+Form2->StringGrid2->Cells[j][i];
                                }

                }
        }
        if(RadioGroup2->ItemIndex==1)
        {
                if(RadioGroup1->ItemIndex==0)
                {
                        Form2->StringGrid1->RowCount=n+1;
                        Form2->StringGrid1->ColCount=n+1;
                        for(int i=1, l=0; i<n+1; i++, l++)
                                {
                                Form2->StringGrid1->Cells[0][i]=i;
                                Form2->StringGrid1->Cells[i][0]=key[l];
                                }
                        strcpy(temp1, Memo1->Text.c_str());//копіюєм в одновимірний масив значення поля із текстом
                        int k=0;//лічильник, який буде відповідати за довжину одновимірного масиву
                        for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                                {
                                        if(k<Memo1->Text.Length())
                                                decode[i][j]=temp1[k];
                                        else
                                                decode[i][j]=' ';
                                        k++;
                                }//записуєм одновимірний масив у двовимірний
                        for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                                {
                                        Form2->StringGrid1->Cells[j+1][i+1]=decode[i][j];
                                }//записуєм у к-т StringGrid1 незашифровані дані
                        for(int i=0; i<n; i++)
                                encode[i]=new char[n];
                        for(int i=0; i<n; i++)
                                for(int j=0, l=0; j<n; j++, l++)
                                {
                                        if(l==Memo3->Text.Length())
                                        l=0;
                                        encode[i][key[l]-1]=decode[i][j];
                                }
                        Form2->StringGrid2->RowCount=n+1;
                        Form2->StringGrid2->ColCount=n+1;
                        for(int i=1; i<n+1; i++)
                                {
                                Form2->StringGrid2->Cells[0][i]=i;
                                Form2->StringGrid2->Cells[i][0]=i;
                                }
                        for(int i=0; i<n; i++)
                                for(int j=0; j<n; j++)
                        Form2->StringGrid2->Cells[j+1][i+1]=encode[i][j];
                        Memo2->Clear();
                        for(int i=1; i<n+1; i++)
                                for(int j=1; j<n+1; j++)
                                {
                                        if(Form2->StringGrid2->Cells[j][i]=='_')
                                                Memo2->Text=Memo2->Text+' ';
                                        else
                                                Memo2->Text=Memo2->Text+Form2->StringGrid2->Cells[j][i];
                                }

                }
                if(RadioGroup1->ItemIndex==1)
                {
                Form2->StringGrid1->RowCount=n+1;
                Form2->StringGrid1->ColCount=n+1;
                for(int i=1, l=0; i<n+1; i++, l++)
                                {
                                Form2->StringGrid1->Cells[0][i]=key[l];
                                Form2->StringGrid1->Cells[i][0]=i;
                                }
                strcpy(temp1, Memo1->Text.c_str());//копіюєм в одновимірний масив значення поля із текстом
                int k=0;//лічильник, який буде відповідати за довжину одновимірного масиву
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                        {
                                if(k<Memo1->Text.Length())
                                        decode[i][j]=temp1[k];
                                else
                                        decode[i][j]=' ';
                                k++;
                        }//записуєм одновимірний масив у двовимірний
                for(int i=0; i<n; i++)
                        for(int j=0; j<n; j++)
                        {
                                Form2->StringGrid1->Cells[j+1][i+1]=decode[i][j];
                        }//записуєм у к-т StringGrid1 незашифровані дані
                for(int i=0; i<n; i++)
                        encode[i]=new char[n];
                for(int i=0; i<n; i++)
                        for(int j=0, l=0; j<n; j++, l++)
                                {
                                        if(l==Memo3->Text.Length())
                                        l=0;
                                        encode[key[l]-1][i]=decode[j][i];
                                }
             Form2->StringGrid2->RowCount=n+1;
             Form2->StringGrid2->ColCount=n+1;
             for(int i=1; i<n+1; i++)
                                {
                                Form2->StringGrid2->Cells[0][i]=i;
                                Form2->StringGrid2->Cells[i][0]=i;
                                }
             for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                        Form2->StringGrid2->Cells[j+1][i+1]=encode[i][j];
             Memo2->Clear();
             for(int i=1; i<n+1; i++)
                        for(int j=1; j<n+1; j++)
                        {
                             if(Form2->StringGrid2->Cells[j][i]=='_')
                                        Memo2->Text=Memo2->Text+' ';
                                else
                                        Memo2->Text=Memo2->Text+Form2->StringGrid2->Cells[j][i];
                        }


             }
        }
        delete[]encode;
        delete[]decode;
        delete[]temp1;
  }
  if(CheckBox2->Checked==true)
  {
  int m=9;
  int n=Memo1->Text.Length()/9;
  if(Memo1->Text.Length()*9>n)
  n++;
  char* temp1=new char[Memo1->Text.Length()];//одновимірний масив із незакодованим текстом
  char **decode=new char *[n];
  for(int i=0; i<n; i++)
        decode[i]=new char[m];
  char **encode=new char *[n];
        if(RadioGroup2->ItemIndex==0)
        {
                                Form2->StringGrid1->RowCount=n+1;
                                Form2->StringGrid1->ColCount=m+1;
                                for(int i=1, j=1; i<n+1||j<m+1; i++, j++)
                                {
                                Form2->StringGrid1->Cells[j][0]=j;
                                Form2->StringGrid1->Cells[0][i]=i;
                                }
                                strcpy(temp1, Memo1->Text.c_str());//копіюєм в одновимірний масив значення поля із текстом
                                int k=0;//лічильник, який буде відповідати за довжину одновимірного масиву
                                for(int i=0; i<n; i++)
                                        for(int j=0; j<m; j++)
                                        {
                                                if(k<Memo1->Text.Length())
                                                decode[i][j]=temp1[k];
                                                else
                                                decode[i][j]=' ';
                                                k++;
                                        }//записуєм одновимірний масив у двовимірний
                                for(int i=0; i<n; i++)
                                        for(int j=0; j<m; j++)
                                        {
                                                Form2->StringGrid1->Cells[j+1][i+1]=decode[i][j];
                                        }//записуєм у к-т StringGrid1 незашифровані дані
                                for(int i=0; i<n; i++)
                                        encode[i]=new char[m];
                                for(int i=0; i<n; i++)
                                        for(int j=0, l=0; j<m; j++, l++)
                                        {
                                                if(l==Memo3->Text.Length())
                                                l=0;
                                                encode[i][j]=decode[i][key[l]-1];
                                        }
                                Form2->StringGrid2->RowCount=n+1;
                                Form2->StringGrid2->ColCount=m+1;
                                for(int i=1, j=1, l=0; i<n+1||j<m+1||l<9; i++, j++, l++)
                                {
                                Form2->StringGrid2->Cells[j][0]=key[l];
                                Form2->StringGrid2->Cells[0][i]=i;
                                }
                                for(int i=0; i<n; i++)
                                for(int j=0; j<m; j++)
                                        Form2->StringGrid2->Cells[j+1][i+1]=encode[i][j];
                                Memo2->Clear();
                                for(int i=1; i<n+1; i++)
                                        for(int j=1; j<m+1; j++)
                                        {
                                                if(Form2->StringGrid2->Cells[j][i]==' ')
                                                        Memo2->Text=Memo2->Text+'_';
                                                else
                                                        Memo2->Text=Memo2->Text+Form2->StringGrid2->Cells[j][i];
                                        }

        }
        if(RadioGroup2->ItemIndex==1)
        {
                        Form2->StringGrid1->RowCount=n+1;
                        Form2->StringGrid1->ColCount=m+1;
                        for(int i=1, j=1, l=0; i<n+1||j<m+1||l<9; i++, j++, l++)
                                {
                                Form2->StringGrid1->Cells[j][0]=key[l];
                                Form2->StringGrid1->Cells[0][i]=i;
                                }
                        strcpy(temp1, Memo1->Text.c_str());//копіюєм в одновимірний масив значення поля із текстом
                        int k=0;//лічильник, який буде відповідати за довжину одновимірного масиву
                        for(int i=0; i<n; i++)
                                for(int j=0; j<m; j++)
                                {
                                        if(k<Memo1->Text.Length())
                                                decode[i][j]=temp1[k];
                                        else
                                                decode[i][j]=' ';
                                        k++;
                                }//записуєм одновимірний масив у двовимірний
                        for(int i=0; i<n; i++)
                                for(int j=0; j<m; j++)
                                {
                                        Form2->StringGrid1->Cells[j+1][i+1]=decode[i][j];
                                }//записуєм у к-т StringGrid1 незашифровані дані
                        for(int i=0; i<n; i++)
                                encode[i]=new char[m];
                        for(int i=0; i<n; i++)
                                for(int j=0, l=0; j<m; j++, l++)
                                {
                                        if(l==Memo3->Text.Length())
                                        l=0;
                                        encode[i][key[l]-1]=decode[i][j];
                                }
                        Form2->StringGrid2->RowCount=n+1;
                        Form2->StringGrid2->ColCount=m+1;
                        for(int i=1, j=1; i<n+1||j<m+1; i++, j++)
                                {
                                Form2->StringGrid2->Cells[j][0]=j;
                                Form2->StringGrid2->Cells[0][i]=i;
                                }
                        for(int i=0; i<n; i++)
                                for(int j=0; j<m; j++)
                        Form2->StringGrid2->Cells[j+1][i+1]=encode[i][j];
                        Memo2->Clear();
                        for(int i=1; i<n+1; i++)
                                for(int j=1; j<m+1; j++)
                                {
                                      if(Form2->StringGrid2->Cells[j][i]=='_')
                                                Memo2->Text=Memo2->Text+' ';
                                        else
                                                Memo2->Text=Memo2->Text+Form2->StringGrid2->Cells[j][i];
                                }

        }
        delete[]encode;
        delete[]decode;
        delete[]temp1;
  }
  if(CheckBox1->Checked==true)
  Form2->Show();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Memo1Change(TObject *Sender)
{
if(CheckBox2->Checked==false)
        {
                int n=floor(sqrt(Memo1->Text.Length()));//Розмірність матриці
                if(n*n<Memo1->Text.Length())
                        n++;
                Label1->Caption="Розмірність ключа: "+IntToStr(n);
        }
else
        {
                Label1->Caption="Розмірність ключа: 9";
        }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button3Click(TObject *Sender)
{
srand(time(NULL));
if (CheckBox2->Checked==false)
        {
                int n=floor(sqrt(Memo1->Text.Length()));//Розмірність матриці
                if(n*n<Memo1->Text.Length())
                        n++;
                int *key=new int[n];
                for(int i=0; i<n; i++)
                        {
                                key[i]=i+1;
                        }
                for(int i=0; i<n; i++)
                        {
                                int j = rand() % n;
                                int tmp = key[i];
                                key[i] = key[j];
                                key[j] = tmp;
                        }
                AnsiString str;
                for(int i=0; i<n; i++)
                        {
                                if(key[i]<=9)
                                {
                                        str+='0';
                                        str+=IntToStr(key[i]);
                                }
                                if(key[i]>=10)
                                {
                                str+=IntToStr(key[i]/10);
                                str+=IntToStr(key[i]%10);
                                }
                        }
                Memo3->Text=str;

        }
if(CheckBox2->Checked==true)
        {
        int n=9;
        int *key=new int[n];
                for(int i=0; i<n; i++)
                        {
                                key[i]=i+1;
                        }
                for(int i=0; i<n; i++)
                        {
                                int j = rand() % n;
                                int tmp = key[i];
                                key[i] = key[j];
                                key[j] = tmp;
                        }
                AnsiString str;
                for(int i=0; i<n; i++)
                        {
                                if(key[i]<=9)
                                {
                                        str+='0';
                                        str+=IntToStr(key[i]);
                                }
                                if(key[i]>=10)
                                {
                                str+=IntToStr(key[i]/10);
                                str+=IntToStr(key[i]%10);
                                }
                        }
                Memo3->Text=str;

        }
}
//---------------------------------------------------------------------------





void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
if(CheckBox2->Checked==true)
RadioGroup1->Enabled=false;
else
RadioGroup1->Enabled=true;
if(CheckBox2->Checked==true)
Label1->Caption="Розмірність ключа: 9";
else
{
int n=floor(sqrt(Memo1->Text.Length()));//Розмірність матриці
                if(n*n<Memo1->Text.Length())
                        n++;
                Label1->Caption="Розмірність ключа: "+IntToStr(n);
}
}
//---------------------------------------------------------------------------





void __fastcall TForm1::N9Click(TObject *Sender)
{
if(OpenDialog1->Execute())
Memo3->Lines->LoadFromFile(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
Memo1->Clear();
Memo2->Clear();
Memo3->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
Memo1->Clear();
Memo2->Clear();
}
//---------------------------------------------------------------------------




void __fastcall TForm1::N11Click(TObject *Sender)
{
ShellExecute(Handle, "open", "crypt.hlp", NULL, NULL, SW_SHOWNORMAL);        
}
//---------------------------------------------------------------------------



void __fastcall TForm1::EditSelectAll1Execute(TObject *Sender)
{
if (Form1->ActiveControl==Form1->Memo1)
        {
        Memo1->SelectAll();
        }
if (Form1->ActiveControl==Form1->Memo2)
        {
        Memo2->SelectAll();
        }
if (Form1->ActiveControl==Form1->Memo3)
        {
        Memo3->SelectAll();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditCut1Execute(TObject *Sender)
{
if (Form1->ActiveControl==Form1->Memo1)
        {
        Memo1->CutToClipboard();
        }
if (Form1->ActiveControl==Form1->Memo2)
        {
        Memo2->CutToClipboard();
        }
if (Form1->ActiveControl==Form1->Memo3)
        {
        Memo3->CutToClipboard();
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditPaste1Execute(TObject *Sender)
{
if (Form1->ActiveControl==Form1->Memo1)
        {
        Memo1->PasteFromClipboard();
        }
if (Form1->ActiveControl==Form1->Memo2)
        {
        Memo2->PasteFromClipboard();
        }
if (Form1->ActiveControl==Form1->Memo3)
        {
        Memo3->PasteFromClipboard();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditUndo1Execute(TObject *Sender)
{
if (Form1->ActiveControl==Form1->Memo1)
        {
        Memo1->Undo();
        }
if (Form1->ActiveControl==Form1->Memo2)
        {
        Memo2->Undo();
        }
if (Form1->ActiveControl==Form1->Memo3)
        {
        Memo3->Undo();
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EditDelete1Execute(TObject *Sender)
{
if (Form1->ActiveControl==Form1->Memo1)
        {
        Memo1->ClearSelection();
        }
if (Form1->ActiveControl==Form1->Memo2)
        {
        Memo2->ClearSelection();
        }
if (Form1->ActiveControl==Form1->Memo3)
        {
        Memo3->ClearSelection();
        }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::N12Click(TObject *Sender)
{
Form3->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N8Click(TObject *Sender)
{
if(SaveDialog1->Execute())
        {
        Memo3->Lines->SaveToFile(SaveDialog1->FileName);
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N13Click(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------

