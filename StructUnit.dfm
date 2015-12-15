inherited structUnitForm: TstructUnitForm
  Caption = 'Structural Unit'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = DM.structUnitSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = DM.structUnitSource
    Hints.Strings = ()
  end
end
