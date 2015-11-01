inherited structUnitSpecForm: TstructUnitSpecForm
  Caption = 'Structural unit speciality'
  ClientHeight = 614
  ClientWidth = 1190
  Position = poDesigned
  OnCreate = FormShow
  ExplicitWidth = 1206
  ExplicitHeight = 653
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel [0]
    Left = 8
    Top = 245
    Width = 72
    Height = 13
    Caption = 'Education level'
  end
  object Label2: TLabel [1]
    Left = 432
    Top = 245
    Width = 35
    Height = 13
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Domain'
  end
  object Label3: TLabel [2]
    Left = 792
    Top = 245
    Width = 34
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'Course'
  end
  object Label4: TLabel [3]
    Left = 8
    Top = 5
    Width = 54
    Height = 13
    Caption = 'Hochschule'
  end
  object Label5: TLabel [4]
    Left = 432
    Top = 8
    Width = 93
    Height = 13
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Structural unit type'
  end
  object Label6: TLabel [5]
    Left = 792
    Top = 8
    Width = 97
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'Structural unit name'
  end
  inherited DBGrid1: TDBGrid
    Top = 400
    Width = 1180
    Height = 183
    Margins.Top = 400
    DataSource = DM.structUnitSpecSource
  end
  inherited DBNavigator1: TDBNavigator
    Top = 586
    Width = 1180
    DataSource = DM.structUnitSpecSource
    VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast, nbInsert, nbDelete, nbPost, nbCancel, nbRefresh]
    Hints.Strings = ()
    ExplicitTop = 586
    ExplicitWidth = 1100
  end
  object eduLevelLB: TListBox
    Left = 8
    Top = 264
    Width = 404
    Height = 129
    ItemHeight = 13
    TabOrder = 2
    OnClick = updateCourseLB
  end
  object domainLB: TListBox
    Left = 432
    Top = 264
    Width = 337
    Height = 129
    Anchors = [akLeft, akTop, akRight]
    ItemHeight = 13
    ScrollWidth = 800
    TabOrder = 3
    OnClick = updateCourseLB
  end
  object courseLB: TListBox
    Left = 792
    Top = 264
    Width = 361
    Height = 129
    Anchors = [akTop, akRight]
    ItemHeight = 13
    ScrollWidth = 800
    TabOrder = 4
  end
  object hochschuleLB: TListBox
    Left = 8
    Top = 24
    Width = 401
    Height = 201
    ItemHeight = 13
    ScrollWidth = 1125
    TabOrder = 5
    OnClick = updateStructUnitNameLB
  end
  object structUnitTypeLB: TListBox
    Left = 432
    Top = 27
    Width = 337
    Height = 198
    Anchors = [akLeft, akTop, akRight]
    ItemHeight = 13
    ScrollWidth = 500
    TabOrder = 6
    OnClick = updateStructUnitNameLB
  end
  object structUnitNameLB: TListBox
    Left = 792
    Top = 24
    Width = 361
    Height = 201
    Anchors = [akTop, akRight]
    ItemHeight = 13
    ScrollWidth = 500
    TabOrder = 7
  end
end
