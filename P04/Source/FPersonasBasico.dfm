object PersonasBasico: TPersonasBasico
  Left = 318
  Top = 168
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'FPersonasBasico'
  ClientHeight = 474
  ClientWidth = 625
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Menu = MenuPrincipal
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LblFicha: TLabel
    Left = 208
    Top = 8
    Width = 115
    Height = 20
    Caption = 'Ficha número:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object LblNumFicha: TLabel
    Left = 400
    Top = 8
    Width = 11
    Height = 20
    BiDiMode = bdLeftToRight
    Caption = '1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentBiDiMode = False
    ParentFont = False
  end
  object LblNombre: TLabel
    Left = 72
    Top = 80
    Width = 37
    Height = 13
    Caption = 'Nombre'
  end
  object LblDNI: TLabel
    Left = 72
    Top = 56
    Width = 19
    Height = 13
    Caption = 'DNI'
  end
  object Retrato: TImage
    Left = 320
    Top = 104
    Width = 241
    Height = 185
  end
  object Retina: TImage
    Left = 320
    Top = 296
    Width = 241
    Height = 121
    OnClick = RetinaClick
  end
  object CmdBuscar: TButton
    Left = 496
    Top = 432
    Width = 113
    Height = 33
    Caption = 'B&uscar'
    TabOrder = 9
    OnClick = CmdBuscarClick
  end
  object CmdAnt: TButton
    Left = 16
    Top = 48
    Width = 33
    Height = 377
    Caption = '<'
    TabOrder = 7
    OnClick = CmdAntClick
  end
  object CmdSig: TButton
    Left = 576
    Top = 48
    Width = 33
    Height = 377
    Caption = '>'
    TabOrder = 8
    OnClick = CmdSigClick
  end
  object TxtNombre: TEdit
    Left = 152
    Top = 72
    Width = 417
    Height = 21
    TabOrder = 1
  end
  object RBTipoPelo: TRadioGroup
    Left = 56
    Top = 104
    Width = 249
    Height = 57
    Caption = ' Tipo de pelo '
    Columns = 3
    Items.Strings = (
      'Largo'
      'Raya'
      'Raso')
    TabOrder = 2
    OnClick = RBTipoPeloClick
  end
  object RBTipoOjos: TRadioGroup
    Left = 56
    Top = 168
    Width = 249
    Height = 57
    Caption = ' Tipo de ojos '
    Columns = 3
    Items.Strings = (
      'Redondos'
      'Gafas'
      'Rasgados')
    TabOrder = 3
    OnClick = RBTipoOjosClick
  end
  object RBTipoBoca: TRadioGroup
    Left = 56
    Top = 296
    Width = 249
    Height = 57
    Caption = ' Tipo de boca '
    Columns = 3
    Items.Strings = (
      'Larga'
      'Pequeña'
      'Delgada')
    TabOrder = 5
    OnClick = RBTipoBocaClick
  end
  object RBTipoOrejas: TRadioGroup
    Left = 56
    Top = 232
    Width = 249
    Height = 57
    Caption = ' Tipo de orejas y nariz '
    Columns = 3
    Items.Strings = (
      'Gancho'
      'Redonda'
      'Pequeña')
    TabOrder = 4
    OnClick = RBTipoOrejasClick
  end
  object RBTipoMenton: TRadioGroup
    Left = 56
    Top = 360
    Width = 249
    Height = 57
    Caption = ' Tipo de mentón '
    Columns = 3
    Items.Strings = (
      'Afeitado'
      'Barba'
      'Perilla')
    TabOrder = 6
    OnClick = RBTipoMetonClick
  end
  object TxtDNI: TEdit
    Left = 152
    Top = 48
    Width = 417
    Height = 21
    TabOrder = 0
  end
  object MenuPrincipal: TMainMenu
    Left = 16
    Top = 8
    object mnuArchivo: TMenuItem
      Caption = 'Archivo'
      object mnuArchivoSalir: TMenuItem
        Caption = 'Salir'
        OnClick = mnuArchivoSalirClick
      end
    end
  end
  object OpenPicDlg: TOpenPictureDialog
    Left = 56
    Top = 8
  end
end
