inherited settlementForm: TsettlementForm
  Caption = 'Settlement'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = Tables.settlementSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = Tables.settlementSource
    Hints.Strings = ()
  end
end
