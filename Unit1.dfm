object Form1: TForm1
  Left = 248
  Top = 246
  BorderStyle = bsSingle
  Caption = 'Crypt Translator v1.0'
  ClientHeight = 474
  ClientWidth = 1016
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 744
    Top = 208
    Width = 106
    Height = 13
    Caption = #1056#1086#1079#1084#1110#1088#1085#1110#1089#1090#1100' '#1082#1083#1102#1095#1072': 0'
    ParentShowHint = False
    ShowHint = False
  end
  object Label2: TLabel
    Left = 744
    Top = 16
    Width = 66
    Height = 13
    Hint = #1044#1080#1074'. '#1076#1086#1074#1110#1076#1082#1091', '#1097#1086#1073' '#1076#1110#1079#1085#1072#1090#1080#1089#1103' '#1087#1088#1072#1074#1080#1083#1072' '#1074#1074#1086#1076#1091'.'
    Caption = #1042#1074#1077#1076#1110#1090#1100' '#1082#1083#1102#1095
    ParentShowHint = False
    ShowHint = True
  end
  object Memo1: TMemo
    Left = 8
    Top = 8
    Width = 729
    Height = 201
    ScrollBars = ssVertical
    TabOrder = 0
    OnChange = Memo1Change
  end
  object Memo2: TMemo
    Left = 8
    Top = 264
    Width = 729
    Height = 201
    ScrollBars = ssVertical
    TabOrder = 1
  end
  object Button1: TButton
    Left = 8
    Top = 216
    Width = 729
    Height = 41
    Caption = #1054#1087#1088#1072#1094#1102#1074#1072#1090#1080' '#1090#1077#1082#1089#1090
    TabOrder = 2
    OnClick = Button1Click
  end
  object RadioGroup1: TRadioGroup
    Left = 745
    Top = 320
    Width = 208
    Height = 65
    Caption = #1058#1080#1087' '#1096#1080#1092#1088#1091#1074#1072#1085#1085#1103
    ItemIndex = 0
    Items.Strings = (
      #1047#1072' '#1089#1090#1086#1074#1087#1094#1103#1084#1080
      #1047#1072' '#1088#1103#1076#1082#1072#1084#1080)
    TabOrder = 3
  end
  object CheckBox1: TCheckBox
    Left = 744
    Top = 392
    Width = 217
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1091#1074#1072#1090#1080' '#1084#1072#1090#1088#1080#1094#1110' '#1096#1080#1092#1088#1091#1074#1072#1085#1085#1103
    TabOrder = 4
  end
  object Memo3: TMemo
    Left = 744
    Top = 40
    Width = 257
    Height = 161
    TabOrder = 5
  end
  object Button3: TButton
    Left = 832
    Top = 8
    Width = 169
    Height = 25
    Hint = #1058#1110#1083#1100#1082#1080' '#1087#1110#1089#1083#1103' '#1074#1074#1077#1076#1077#1085#1085#1103' '#1090#1077#1082#1089#1090#1091'.'
    Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1085#1072' '#1075#1077#1085#1077#1088#1072#1094#1110#1103' '#1082#1083#1102#1095#1072
    ParentShowHint = False
    ShowHint = True
    TabOrder = 6
    OnClick = Button3Click
  end
  object RadioGroup2: TRadioGroup
    Left = 744
    Top = 248
    Width = 209
    Height = 65
    Caption = #1042#1080#1073#1077#1088#1110#1090#1100' '#1086#1087#1077#1088#1072#1094#1110#1102
    ItemIndex = 0
    Items.Strings = (
      #1047#1072#1096#1080#1092#1088#1091#1074#1072#1090#1080' '#1090#1077#1082#1089#1090
      #1056#1086#1079#1096#1080#1092#1088#1091#1074#1072#1090#1080' '#1090#1077#1082#1089#1090)
    TabOrder = 7
  end
  object CheckBox2: TCheckBox
    Left = 744
    Top = 224
    Width = 249
    Height = 17
    Hint = 
      #1042#1080#1082#1086#1088#1080#1089#1090#1086#1074#1091#1108#1090#1100#1089#1103' '#1076#1083#1103' '#1096#1080#1092#1088#1091#1074#1072#1085#1085#1103' '#1076#1077#1082#1110#1083#1100#1082#1086#1093' '#1090#1077#1082#1089#1090#1110#1074' '#1088#1110#1079#1085#1080#1093' '#1088#1086#1079#1084#1110#1088#1110 +
      #1074' '#1086#1076#1085#1080#1084' '#1082#1083#1102#1095#1077#1084'.'
    Caption = #1057#1090#1072#1085#1076#1072#1088#1090#1085#1072' '#1088#1086#1079#1084#1110#1088#1085#1110#1089#1090#1100' '#1082#1083#1102#1095#1072
    ParentShowHint = False
    ShowHint = True
    TabOrder = 8
    OnClick = CheckBox2Click
  end
  object MainMenu1: TMainMenu
    Left = 16
    Top = 16
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N2: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1090#1077#1082#1089#1090
        Visible = False
      end
      object N4: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080' '#1090#1077#1082#1089#1090
        Visible = False
      end
      object N8: TMenuItem
        Caption = #1047#1073#1077#1088#1077#1075#1090#1080' '#1082#1083#1102#1095
        ShortCut = 16467
        OnClick = N8Click
      end
      object N9: TMenuItem
        Caption = #1042#1110#1076#1082#1088#1080#1090#1080' '#1082#1083#1102#1095
        ShortCut = 16463
        OnClick = N9Click
      end
      object N13: TMenuItem
        Caption = #1042#1080#1093#1110#1076
        OnClick = N13Click
      end
    end
    object N5: TMenuItem
      Caption = #1055#1088#1072#1074#1082#1072
      object N7: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1080' '#1074#1089#1110' '#1087#1086#1083#1103
        ShortCut = 24661
        OnClick = N7Click
      end
      object N10: TMenuItem
        Caption = #1054#1095#1080#1089#1090#1080#1090#1080' '#1090#1077#1082#1089#1090#1086#1074#1110' '#1087#1086#1083#1103
        ShortCut = 16469
        OnClick = N10Click
      end
      object N3: TMenuItem
        Action = EditSelectAll1
        Caption = #1042#1080#1076#1110#1083#1080#1090#1080' '#1074#1089#1077
      end
      object Cut1: TMenuItem
        Action = EditCut1
        Caption = #1042#1080#1088#1110#1079#1072#1090#1080
      end
      object Paste1: TMenuItem
        Action = EditPaste1
        Caption = #1042#1089#1090#1072#1074#1080#1090#1080
      end
      object Undo1: TMenuItem
        Action = EditUndo1
        Caption = #1042#1110#1076#1084#1110#1085#1072
      end
      object Delete1: TMenuItem
        Action = EditDelete1
        Caption = #1042#1080#1076#1072#1083#1080#1090#1080
      end
    end
    object N6: TMenuItem
      Caption = #1044#1086#1074#1110#1076#1082#1072
      object N11: TMenuItem
        Caption = #1044#1086#1074#1110#1076#1082#1072
        ShortCut = 112
        OnClick = N11Click
      end
      object N12: TMenuItem
        Caption = #1055#1088#1086' '#1087#1088#1086#1075#1088#1072#1084#1091
        OnClick = N12Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = 'txt'
    Filter = #1058#1077#1082#1089#1090#1086#1074#1080#1081' '#1076#1086#1082#1091#1084#1077#1085#1090'|*.txt'
    Left = 48
    Top = 16
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = 'txt'
    Filter = #1058#1077#1082#1089#1090#1086#1074#1080#1081' '#1076#1086#1082#1091#1084#1077#1085#1090'|*.txt'
    Left = 80
    Top = 16
  end
  object ActionList1: TActionList
    Left = 112
    Top = 16
    object EditSelectAll1: TEditSelectAll
      Category = 'Edit'
      Caption = 'Select &All'
      Hint = 'Select All|Selects the entire document'
      ShortCut = 16449
      OnExecute = EditSelectAll1Execute
    end
    object EditCut1: TEditCut
      Category = 'Edit'
      Caption = 'Cu&t'
      Hint = 'Cut|Cuts the selection and puts it on the Clipboard'
      ImageIndex = 0
      ShortCut = 16472
      OnExecute = EditCut1Execute
    end
    object EditPaste1: TEditPaste
      Category = 'Edit'
      Caption = '&Paste'
      Hint = 'Paste|Inserts Clipboard contents'
      ImageIndex = 2
      ShortCut = 16470
      OnExecute = EditPaste1Execute
    end
    object EditUndo1: TEditUndo
      Category = 'Edit'
      Caption = '&Undo'
      Hint = 'Undo|Reverts the last action'
      ImageIndex = 3
      ShortCut = 16474
      OnExecute = EditUndo1Execute
    end
    object EditDelete1: TEditDelete
      Category = 'Edit'
      Caption = '&Delete'
      Hint = 'Delete|Erases the selection'
      ImageIndex = 5
      ShortCut = 46
      OnExecute = EditDelete1Execute
    end
  end
end
