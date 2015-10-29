inherited regionForm: TregionForm
  Caption = 'Region'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = Tables.regionSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = Tables.regionSource
    Hints.Strings = ()
  end
end
