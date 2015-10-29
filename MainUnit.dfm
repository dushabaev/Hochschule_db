object MainForm: TMainForm
  Left = 0
  Top = 0
  Caption = 'MainForm'
  ClientHeight = 119
  ClientWidth = 231
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object SecondBtn: TButton
    Left = 78
    Top = 29
    Width = 75
    Height = 25
    Caption = 'Second'
    TabOrder = 0
    OnClick = SecondBtnClick
  end
  object ThirdBtn: TButton
    Left = 78
    Top = 69
    Width = 75
    Height = 25
    Caption = 'Third'
    TabOrder = 1
  end
end
