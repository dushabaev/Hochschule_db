inherited structUnitSpecStudForm: TstructUnitSpecStudForm
  Caption = 'Structural unit speciality and studying type'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = DM.structUnitSpecStudSource
  end
  inherited DBNavigator1: TDBNavigator
    Hints.Strings = ()
  end
end
