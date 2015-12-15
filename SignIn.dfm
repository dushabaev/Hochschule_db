object SignInForm: TSignInForm
  Left = 0
  Top = 0
  Caption = 'Sign in'
  ClientHeight = 99
  ClientWidth = 191
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 11
    Width = 48
    Height = 13
    Caption = 'Username'
  end
  object Label2: TLabel
    Left = 8
    Top = 38
    Width = 46
    Height = 13
    Caption = 'Password'
  end
  object UserName: TEdit
    Left = 62
    Top = 8
    Width = 121
    Height = 21
    TabOrder = 0
  end
  object Password: TEdit
    Left = 62
    Top = 35
    Width = 121
    Height = 21
    PasswordChar = '*'
    TabOrder = 1
  end
  object SignIn: TBitBtn
    Left = 8
    Top = 62
    Width = 75
    Height = 25
    Caption = 'Sign in'
    ModalResult = 1
    TabOrder = 2
  end
  object Cancel: TBitBtn
    Left = 108
    Top = 66
    Width = 75
    Height = 25
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
  end
end
