inherited hochTypeForm: ThochTypeForm
  Caption = 'Hochschule type'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = Tables.hochTypeSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = Tables.hochTypeSource
    Hints.Strings = ()
  end
end
