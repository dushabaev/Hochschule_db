object searchSettingsForm: TsearchSettingsForm
  Left = 0
  Top = 0
  Caption = 'Search settings'
  ClientHeight = 139
  ClientWidth = 232
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object RadioGroup1: TRadioGroup
    Left = 16
    Top = 8
    Width = 177
    Height = 81
    Caption = 'Search type'
    ItemIndex = 0
    Items.Strings = (
      'Locate'
      'Filter')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 72
    Top = 106
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
  end
end
