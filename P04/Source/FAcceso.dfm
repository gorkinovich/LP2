object Acceso: TAcceso
  Left = 413
  Top = 343
  Width = 389
  Height = 145
  BorderIcons = [biSystemMenu]
  Caption = 'Sistema de Reconocimiento de Delincuentes'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = Menu
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 42
    Height = 13
    Caption = 'Usuario: '
  end
  object Label2: TLabel
    Left = 8
    Top = 40
    Width = 60
    Height = 13
    Caption = 'Contraseña: '
  end
  object Nombre: TEdit
    Left = 72
    Top = 8
    Width = 305
    Height = 21
    TabOrder = 0
  end
  object Contrasenya: TEdit
    Left = 72
    Top = 32
    Width = 305
    Height = 21
    TabOrder = 1
  end
  object Login: TButton
    Left = 8
    Top = 64
    Width = 105
    Height = 25
    Caption = '&Login'
    TabOrder = 2
    OnClick = LoginClick
  end
  object Salir: TButton
    Left = 120
    Top = 64
    Width = 257
    Height = 25
    Caption = '&Salir'
    TabOrder = 3
    OnClick = SalirClick
  end
  object Menu: TMainMenu
    Left = 216
    object mnuPrincipal: TMenuItem
      Caption = '&Principal'
      object mnuLogin: TMenuItem
        Caption = '&Log-in'
        OnClick = mnuLoginClick
      end
      object mnuSep: TMenuItem
        Caption = '-'
      end
      object mnuSalir: TMenuItem
        Caption = '&Salir'
        OnClick = mnuSalirClick
      end
    end
  end
end
