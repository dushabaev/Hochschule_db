inherited structUnitForm: TstructUnitForm
  Caption = 'Structural Unit'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = Tables.structUnitSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = Tables.structUnitSource
    Hints.Strings = ()
  end
end
