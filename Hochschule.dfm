inherited hochForm: ThochForm
  Caption = 'Hochschule'
  ClientHeight = 609
  ClientWidth = 1066
  OnCreate = FormCreate
  OnShow = FormShow
  ExplicitWidth = 1082
  ExplicitHeight = 648
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel [0]
    Left = 288
    Top = 65
    Width = 33
    Height = 13
    Caption = 'Region'
  end
  object Label2: TLabel [1]
    Left = 496
    Top = 65
    Width = 52
    Height = 13
    Caption = 'Settlement'
  end
  object notFound: TLabel [2]
    Left = 288
    Top = 27
    Width = 182
    Height = 32
    Caption = 'Nothing was found.'#13#10'Check your query and try again.'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = 8421631
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label3: TLabel [3]
    Left = 814
    Top = 46
    Width = 96
    Height = 13
    Caption = 'Accreditational level'
  end
  object Label4: TLabel [4]
    Left = 880
    Top = 65
    Width = 54
    Height = 13
    Caption = 'High bound'
  end
  object Label5: TLabel [5]
    Left = 740
    Top = 65
    Width = 52
    Height = 13
    Caption = 'Low bound'
  end
  inherited DBGrid1: TDBGrid
    Left = 250
    Top = 87
    Width = 811
    Height = 491
    Margins.Left = 250
    Margins.Top = 60
    DataSource = DM.hochschuleSource
    TabOrder = 3
  end
  inherited DBNavigator1: TDBNavigator
    Top = 581
    Width = 1056
    DataSource = DM.hochschuleSource
    Hints.Strings = ()
    TabOrder = 4
    ExplicitTop = 581
    ExplicitWidth = 1056
  end
  object hochSearchBox: TSearchBox
    AlignWithMargins = True
    Left = 3
    Top = 3
    Width = 1060
    Height = 21
    Align = alTop
    TabOrder = 0
    OnChange = hochSearchBoxChange
    OnInvokeSearch = hochSearchBoxInvokeSearch
  end
  object region: TComboBox
    Left = 338
    Top = 65
    Width = 145
    Height = 21
    TabOrder = 1
    OnChange = regionChange
  end
  object settlement: TComboBox
    Left = 565
    Top = 62
    Width = 145
    Height = 21
    TabOrder = 2
    OnChange = settlementChange
  end
  object searchSettings: TGroupBox
    Left = 8
    Top = 30
    Width = 185
    Height = 73
    Caption = 'Search settings'
    TabOrder = 5
    object partialKeyCheckBox: TCheckBox
      Left = 69
      Top = 51
      Width = 97
      Height = 17
      Caption = 'Partial key'
      Checked = True
      State = cbChecked
      TabOrder = 0
      OnClick = partialKeyCheckBoxClick
    end
    object caseIsnensetiveCheckBox: TCheckBox
      Left = 69
      Top = 28
      Width = 97
      Height = 17
      Caption = 'Case insensetive'
      Checked = True
      State = cbChecked
      TabOrder = 1
      OnClick = caseInsensitiveCheckBoxClick
    end
    object locateRB: TRadioButton
      Left = 16
      Top = 28
      Width = 47
      Height = 17
      Caption = 'Locate'
      Checked = True
      TabOrder = 2
      TabStop = True
      OnClick = locateRBClick
    end
    object filterRB: TRadioButton
      Left = 16
      Top = 51
      Width = 47
      Height = 17
      Caption = 'Filter'
      TabOrder = 3
      OnClick = filterRBClick
    end
  end
  object filters: TGroupBox
    Left = 8
    Top = 109
    Width = 233
    Height = 466
    Anchors = [akLeft, akTop, akBottom]
    Caption = 'Hochschule'#39's filters'
    TabOrder = 6
    DesignSize = (
      233
      466)
    object regionFilter: TComboBox
      Left = 88
      Top = 50
      Width = 142
      Height = 21
      TabOrder = 0
      OnChange = filterChange
    end
    object regionCheckBox: TCheckBox
      Left = 10
      Top = 54
      Width = 53
      Height = 17
      Caption = 'Region'
      TabOrder = 1
    end
    object settlementCheckBox: TCheckBox
      Left = 10
      Top = 81
      Width = 72
      Height = 17
      Caption = 'Settlement'
      TabOrder = 2
      OnClick = settlementCheckBoxClick
    end
    object settlementFilter: TComboBox
      Left = 88
      Top = 77
      Width = 142
      Height = 21
      TabOrder = 3
    end
    object accrLevelFilterCheckBox: TCheckBox
      Left = 48
      Top = 143
      Width = 118
      Height = 15
      Caption = 'Accrediatational level'
      TabOrder = 4
    end
    object applyFiltersBtn: TButton
      Left = 2
      Top = 437
      Width = 229
      Height = 27
      Margins.Left = 50
      Margins.Top = 300
      Margins.Right = 650
      Margins.Bottom = 30
      Align = alBottom
      Caption = 'Apply filters'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Comic Sans MS'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = applyFiltersBtnClick
    end
    object ScrollBox1: TScrollBox
      Left = 3
      Top = 161
      Width = 227
      Height = 268
      Anchors = [akLeft, akTop, akBottom]
      TabOrder = 6
      object addButton: TButton
        Left = 83
        Top = 47
        Width = 28
        Height = 17
        Caption = 'Add'
        TabOrder = 0
        OnClick = addButtonClick
      end
      object equalRanges: TCheckBox
        Left = 11
        Top = 1
        Width = 108
        Height = 17
        Caption = 'Fully equal ranges'
        TabOrder = 1
      end
    end
    object typeCheckBox: TCheckBox
      Left = 10
      Top = 106
      Width = 53
      Height = 17
      Caption = 'Type'
      TabOrder = 7
    end
    object hochTypeFilter: TComboBox
      Left = 88
      Top = 104
      Width = 142
      Height = 21
      TabOrder = 8
    end
    object autoFilterCheckBox: TCheckBox
      Left = 69
      Top = 24
      Width = 65
      Height = 17
      Caption = 'Auto filter'
      TabOrder = 9
      OnClick = autoFilterCheckBoxClick
    end
  end
  object lowBound: TComboBox
    Tag = -1
    Left = 798
    Top = 65
    Width = 46
    Height = 21
    TabOrder = 7
    OnChange = lowBoundChange
  end
  object highBound: TComboBox
    Tag = -1
    Left = 940
    Top = 62
    Width = 46
    Height = 21
    TabOrder = 8
    OnChange = highBoundChange
  end
end
