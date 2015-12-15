inherited sutdyingTypeForm: TsutdyingTypeForm
  Caption = 'Sutdying type'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = DM.studyingTypeSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = DM.studyingTypeSource
    Hints.Strings = ()
  end
end
