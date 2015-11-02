inherited placeForm: TplaceForm
  Caption = 'Place'
  ExplicitWidth = 766
  ExplicitHeight = 413
  PixelsPerInch = 96
  TextHeight = 13
  inherited DBGrid1: TDBGrid
    DataSource = DM.placeSource
  end
  inherited DBNavigator1: TDBNavigator
    DataSource = DM.placeSource
    Hints.Strings = ()
  end
end
