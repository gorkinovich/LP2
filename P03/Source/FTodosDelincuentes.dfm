object TodosDelincuentes: TTodosDelincuentes
  Left = 623
  Top = 237
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Base de Delincuentes'
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
  object LblDelitos: TLabel
    Left = 72
    Top = 104
    Width = 32
    Height = 13
    Caption = 'Delitos'
  end
  object LblDNI: TLabel
    Left = 72
    Top = 56
    Width = 19
    Height = 13
    Caption = 'DNI'
  end
  object LblSupervisor: TLabel
    Left = 72
    Top = 184
    Width = 50
    Height = 13
    Caption = 'Supervisor'
  end
  object Retrato: TImage
    Left = 208
    Top = 216
    Width = 209
    Height = 161
  end
  object CmdAgregar: TButton
    Left = 136
    Top = 432
    Width = 113
    Height = 33
    Caption = '&Agregar'
    TabOrder = 13
    OnClick = CmdAgregarClick
  end
  object CmdBorrar: TButton
    Left = 256
    Top = 432
    Width = 113
    Height = 33
    Caption = '&Borrar'
    TabOrder = 14
    OnClick = CmdBorrarClick
  end
  object CmdModificar: TButton
    Left = 376
    Top = 432
    Width = 113
    Height = 33
    Caption = '&Modificar'
    TabOrder = 15
    OnClick = CmdModificarClick
  end
  object CmdBuscar: TButton
    Left = 496
    Top = 432
    Width = 113
    Height = 33
    Caption = 'B&uscar'
    TabOrder = 16
    OnClick = CmdBuscarClick
  end
  object CmdAnt: TButton
    Left = 16
    Top = 48
    Width = 33
    Height = 377
    Caption = '<'
    TabOrder = 10
    OnClick = CmdAntClick
  end
  object CmdSig: TButton
    Left = 576
    Top = 48
    Width = 33
    Height = 377
    Caption = '>'
    TabOrder = 11
    OnClick = CmdSigClick
  end
  object TxtNombre: TEdit
    Left = 152
    Top = 72
    Width = 417
    Height = 21
    TabOrder = 1
  end
  object TxtDelitos: TMemo
    Left = 152
    Top = 96
    Width = 417
    Height = 81
    TabOrder = 2
  end
  object RBTipoPelo: TRadioGroup
    Left = 56
    Top = 208
    Width = 145
    Height = 105
    Caption = ' Tipo de pelo '
    Items.Strings = (
      'Largo'
      'Raya'
      'Raso')
    TabOrder = 5
    OnClick = RBTipoPeloClick
  end
  object RBTipoOjos: TRadioGroup
    Left = 56
    Top = 320
    Width = 145
    Height = 105
    Caption = ' Tipo de ojos '
    Items.Strings = (
      'Redondos'
      'Gafas'
      'Rasgados')
    TabOrder = 6
    OnClick = RBTipoOjosClick
  end
  object RBTipoBoca: TRadioGroup
    Left = 424
    Top = 320
    Width = 145
    Height = 105
    Caption = ' Tipo de boca '
    Items.Strings = (
      'Larga'
      'Pequeña'
      'Delgada')
    TabOrder = 8
    OnClick = RBTipoBocaClick
  end
  object RBTipoOrejas: TRadioGroup
    Left = 424
    Top = 208
    Width = 145
    Height = 105
    Caption = ' Tipo de orejas y nariz '
    Items.Strings = (
      'Gancho'
      'Redonda'
      'Pequeña')
    TabOrder = 7
    OnClick = RBTipoOrejasClick
  end
  object RBTipoMenton: TRadioGroup
    Left = 208
    Top = 384
    Width = 209
    Height = 41
    Caption = ' Tipo de mentón '
    Columns = 3
    Items.Strings = (
      'Afeitado'
      'Barba'
      'Perilla')
    TabOrder = 9
    OnClick = RBTipoMetonClick
  end
  object CmdNuevo: TButton
    Left = 16
    Top = 432
    Width = 113
    Height = 33
    Caption = '&Nuevo'
    TabOrder = 12
    OnClick = CmdNuevoClick
  end
  object TxtDNI: TEdit
    Left = 152
    Top = 48
    Width = 417
    Height = 21
    TabOrder = 0
  end
  object TxtSupervisor: TEdit
    Left = 152
    Top = 184
    Width = 321
    Height = 21
    TabOrder = 3
  end
  object CBConfidente: TCheckBox
    Left = 488
    Top = 184
    Width = 81
    Height = 17
    Caption = 'Confidente'
    TabOrder = 4
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
end
