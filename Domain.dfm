object domainForm: TdomainForm
  Left = 390
  Top = 0
  Caption = 'Domain'
  ClientHeight = 527
  ClientWidth = 958
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnShow = FormShow
  DesignSize = (
    958
    527)
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 256
    Top = 35
    Width = 31
    Height = 13
    Caption = #1043#1072#1083#1091#1079#1110
  end
  object applyBtn: TButton
    Left = 869
    Top = 8
    Width = 75
    Height = 25
    Anchors = [akTop, akRight]
    Caption = 'Apply'
    TabOrder = 0
    OnClick = applyBtnClick
  end
  object nextBtn: TButton
    Left = 869
    Top = 138
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Next'
    TabOrder = 3
    OnClick = nextBtnClick
  end
  object priorBtn: TButton
    Left = 869
    Top = 97
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Prior'
    TabOrder = 2
    OnClick = priorBtnClick
  end
  object addBtn: TButton
    Left = 869
    Top = 178
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Add'
    TabOrder = 4
    OnClick = addBtnClick
  end
  object deleteBtn: TButton
    Left = 869
    Top = 218
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Delete'
    TabOrder = 5
    OnClick = deleteBtnClick
  end
  object beginBtn: TButton
    Left = 869
    Top = 59
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Begin'
    TabOrder = 1
    OnClick = beginBtnClick
  end
  object endBtn: TButton
    Left = 869
    Top = 258
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'End'
    TabOrder = 6
    OnClick = endBtnClick
  end
  object DBGrid1: TDBGrid
    AlignWithMargins = True
    Left = 8
    Top = 50
    Width = 750
    Height = 467
    Margins.Left = 8
    Margins.Top = 50
    Margins.Right = 200
    Margins.Bottom = 10
    Align = alClient
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 7
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
  end
  object idEdit: TEdit
    Left = 8
    Top = 10
    Width = 121
    Height = 21
    TabOrder = 8
  end
  object nameEdit: TEdit
    Left = 135
    Top = 10
    Width = 623
    Height = 21
    TabOrder = 9
  end
end
