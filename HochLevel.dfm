inherited accrLevelForm: TaccrLevelForm
  Caption = 'Accreditaion level'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = Tables.hochAndLevelSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = Tables.hochAndLevelSource
    Hints.Strings = ()
  end
end
