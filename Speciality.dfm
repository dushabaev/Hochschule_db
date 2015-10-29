inherited specialityForm: TspecialityForm
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = Tables.specialitySource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = Tables.specialitySource
    Hints.Strings = ()
  end
end
