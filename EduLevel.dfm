object eduLevelForm: TeduLevelForm
  Left = 0
  Top = 0
  Caption = 'Education level'
  ClientHeight = 374
  ClientWidth = 750
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    AlignWithMargins = True
    Left = 5
    Top = 5
    Width = 740
    Height = 338
    Margins.Left = 5
    Margins.Top = 5
    Margins.Right = 5
    Margins.Bottom = 0
    Align = alClient
    DataSource = Tables.eduLevelSource
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object DBNavigator1: TDBNavigator
    AlignWithMargins = True
    Left = 5
    Top = 346
    Width = 740
    Height = 25
    Margins.Left = 5
    Margins.Right = 5
    DataSource = Tables.eduLevelSource
    Align = alBottom
    Flat = True
    TabOrder = 1
  end
end
