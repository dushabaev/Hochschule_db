object Navigation: TNavigation
  Left = 0
  Top = 0
  Caption = 'Navigation'
  ClientHeight = 162
  ClientWidth = 1000
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object domainBtn: TButton
    Left = 775
    Top = 132
    Width = 83
    Height = 25
    Caption = #1043#1072#1083#1091#1079#1100
    TabOrder = 0
    OnClick = domainBtnClick
  end
  object regionBtn: TButton
    Left = 421
    Top = 70
    Width = 75
    Height = 25
    Caption = #1054#1073#1083#1072#1089#1090#1100
    TabOrder = 1
    OnClick = regionBtnClick
  end
  object accrLvlBtn: TButton
    Left = 8
    Top = 39
    Width = 129
    Height = 25
    Caption = #1056#1110#1074#1077#1085#1100' '#1072#1082#1088#1077#1076#1080#1090#1072#1094#1110#1111' '#1042#1053#1047
    TabOrder = 2
    OnClick = accrLvlBtnClick
  end
  object eduLvlBtn: TButton
    Left = 143
    Top = 39
    Width = 177
    Height = 25
    Caption = #1054#1089#1074#1110#1090#1085#1100#1086'-'#1082#1074#1072#1083#1110#1092#1110#1082#1072#1094#1110#1081#1085#1080#1081' '#1088#1110#1074#1077#1085#1100
    TabOrder = 3
    OnClick = eduLvlBtnClick
  end
  object studTypeBtn: TButton
    Left = 897
    Top = 70
    Width = 98
    Height = 25
    Caption = #1060#1086#1088#1084#1072' '#1085#1072#1074#1095#1072#1085#1085#1103
    TabOrder = 4
    OnClick = studTypeBtnClick
  end
  object settlementBtn: TButton
    Left = 507
    Top = 70
    Width = 75
    Height = 25
    Caption = #1052#1110#1089#1090#1086
    TabOrder = 5
    OnClick = settlementBtnClick
  end
  object placeBtn: TButton
    Left = 421
    Top = 39
    Width = 161
    Height = 25
    Caption = #1054#1073#1083#1072#1089#1090#1100' '#1110' '#1084#1110#1089#1090#1086
    TabOrder = 6
    OnClick = placeBtnClick
  end
  object structUnitTypeBtn: TButton
    Left = 599
    Top = 132
    Width = 161
    Height = 25
    Caption = #1058#1080#1087' '#1089#1090#1088#1091#1082#1090#1091#1088#1085#1086#1075#1086' '#1087#1110#1076#1088#1086#1079#1076#1110#1083#1091
    TabOrder = 7
    OnClick = structUnitTypeBtnClick
  end
  object structUnitSpecBtn: TButton
    Left = 599
    Top = 70
    Width = 259
    Height = 25
    Caption = #1057#1087#1077#1094#1110#1072#1083#1100#1085#1110#1089#1090#1100' '#1089#1090#1088#1091#1082#1090#1091#1088#1085#1086#1075#1086' '#1087#1110#1076#1088#1086#1079#1076#1110#1083#1091
    TabOrder = 8
    OnClick = structUnitSpecBtnClick
  end
  object structUnitBtn: TButton
    Left = 599
    Top = 101
    Width = 161
    Height = 25
    Caption = #1057#1090#1088#1091#1082#1090#1091#1088#1085#1080#1081' '#1087#1110#1076#1088#1086#1079#1076#1110#1083
    TabOrder = 9
    OnClick = structUnitBtnClick
  end
  object specBtn: TButton
    Left = 775
    Top = 101
    Width = 83
    Height = 25
    Caption = #1057#1087#1077#1094#1110#1072#1083#1100#1085#1110#1089#1090#1100
    TabOrder = 10
    OnClick = specBtnClick
  end
  object structUnitSpecStudBtn: TButton
    Left = 596
    Top = 39
    Width = 396
    Height = 25
    Caption = #1060#1086#1088#1084#1072' '#1085#1072#1074#1095#1072#1085#1085#1103' '#1085#1072' '#1089#1087#1077#1094#1110#1072#1083#1100#1085#1086#1089#1090#1110' '#1089#1090#1088#1091#1082#1090#1091#1088#1085#1086#1075#1086' '#1087#1110#1076#1088#1086#1079#1076#1110#1083#1091
    TabOrder = 11
    OnClick = structUnitSpecStudBtnClick
  end
  object hochTypeBtn: TButton
    Left = 326
    Top = 39
    Width = 89
    Height = 25
    Caption = #1058#1080#1087' '#1042#1053#1047
    TabOrder = 12
    OnClick = hochTypeBtnClick
  end
  object hochBtn: TButton
    Left = 8
    Top = 8
    Width = 987
    Height = 25
    Caption = #1042#1053#1047
    TabOrder = 13
    OnClick = hochBtnClick
  end
end
