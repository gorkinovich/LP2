object Delincuentes: TDelincuentes
  Left = 184
  Top = 110
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Base de Delincuentes'
  ClientHeight = 475
  ClientWidth = 779
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnDestroy = FormDestroy
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LblFicha: TLabel
    Left = 208
    Top = 8
    Width = 115
    Height = 20
    Caption = 'Ficha n�mero:'
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
    Top = 56
    Width = 37
    Height = 13
    Caption = 'Nombre'
  end
  object LblDelitos: TLabel
    Left = 72
    Top = 80
    Width = 32
    Height = 13
    Caption = 'Delitos'
  end
  object Retrato: TMemo
    Left = 208
    Top = 216
    Width = 209
    Height = 209
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 16
  end
  object CmdAgregar: TButton
    Left = 16
    Top = 432
    Width = 137
    Height = 33
    Caption = '&Agregar'
    TabOrder = 9
    OnClick = CmdAgregarClick
  end
  object CmdBorrar: TButton
    Left = 168
    Top = 432
    Width = 137
    Height = 33
    Caption = '&Borrar'
    TabOrder = 10
    OnClick = CmdBorrarClick
  end
  object CmdModificar: TButton
    Left = 320
    Top = 432
    Width = 137
    Height = 33
    Caption = '&Modificar'
    TabOrder = 11
    OnClick = CmdModificarClick
  end
  object CmdBuscar: TButton
    Left = 472
    Top = 432
    Width = 137
    Height = 33
    Caption = 'B&uscar'
    TabOrder = 12
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
    Left = 728
    Top = 48
    Width = 33
    Height = 377
    Caption = '>'
    TabOrder = 8
    OnClick = CmdSigClick
  end
  object TxtNombre: TEdit
    Left = 152
    Top = 48
    Width = 569
    Height = 21
    TabOrder = 0
  end
  object TxtDelitos: TMemo
    Left = 152
    Top = 80
    Width = 569
    Height = 121
    TabOrder = 1
  end
  object RBTipoPelo: TRadioGroup
    Left = 56
    Top = 208
    Width = 145
    Height = 105
    Caption = ' Tipo de pelo '
    ItemIndex = 0
    Items.Strings = (
      'Largo'
      'Raya'
      'Raso')
    TabOrder = 2
    OnClick = RBTipoPeloClick
  end
  object RBTipoOjos: TRadioGroup
    Left = 56
    Top = 320
    Width = 145
    Height = 105
    Caption = ' Tipo de ojos '
    ItemIndex = 0
    Items.Strings = (
      'Redondos'
      'Gafas'
      'Rasgados')
    TabOrder = 3
    OnClick = RBTipoOjosClick
  end
  object RBTipoBoca: TRadioGroup
    Left = 424
    Top = 320
    Width = 145
    Height = 105
    Caption = ' Tipo de boca '
    ItemIndex = 0
    Items.Strings = (
      'Larga'
      'Peque�a'
      'Delgada')
    TabOrder = 5
    OnClick = RBTipoBocaClick
  end
  object RBTipoOrejas: TRadioGroup
    Left = 424
    Top = 208
    Width = 145
    Height = 105
    Caption = ' Tipo de orejas y nariz '
    ItemIndex = 0
    Items.Strings = (
      'Gancho'
      'Redonda'
      'Peque�a')
    TabOrder = 4
    OnClick = RBTipoOrejasClick
  end
  object RBTipoMenton: TRadioGroup
    Left = 576
    Top = 208
    Width = 145
    Height = 105
    Caption = ' Tipo de ment�n '
    ItemIndex = 0
    Items.Strings = (
      'Afeitado'
      'Barba'
      'Perilla')
    TabOrder = 6
    OnClick = RBTipoMetonClick
  end
  object CmdReiniciar: TButton
    Left = 624
    Top = 432
    Width = 137
    Height = 33
    Caption = '&Reiniciar'
    TabOrder = 13
    OnClick = CmdReiniciarClick
  end
  object CmdCargar: TButton
    Left = 576
    Top = 328
    Width = 145
    Height = 33
    Caption = '&Cargar'
    TabOrder = 14
    OnClick = CmdCargarClick
  end
  object CmdSalvar: TButton
    Left = 576
    Top = 376
    Width = 145
    Height = 33
    Caption = '&Salvar'
    TabOrder = 15
    OnClick = CmdSalvarClick
  end
end
