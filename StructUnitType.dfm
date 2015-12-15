inherited structUnitTypeForm: TstructUnitTypeForm
  Caption = 'Structural unit type'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = DM.structUnitTypeSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = DM.structUnitTypeSource
    Hints.Strings = ()
  end
end
