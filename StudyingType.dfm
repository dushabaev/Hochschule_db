inherited sutdyingTypeForm: TsutdyingTypeForm
  Caption = 'Sutdying type'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = Tables.studyingTypeSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = Tables.studyingTypeSource
    Hints.Strings = ()
  end
end
