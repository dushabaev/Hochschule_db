inherited placeForm: TplaceForm
  Caption = 'Place'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = Tables.placeSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = Tables.placeSource
    Hints.Strings = ()
  end
end
