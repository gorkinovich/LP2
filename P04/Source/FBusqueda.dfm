object Busqueda: TBusqueda
  Left = 432
  Top = 216
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Busqueda'
  ClientHeight = 473
  ClientWidth = 536
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LblTitulo: TLabel
    Left = 8
    Top = 8
    Width = 311
    Height = 37
    Caption = 'Describa al criminal:'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object GBCaja: TGroupBox
    Left = 8
    Top = 48
    Width = 521
    Height = 385
    TabOrder = 3
    object LblRetina: TLabel
      Left = 8
      Top = 360
      Width = 37
      Height = 13
      Caption = 'Retina: '
    end
    object TxtRetina: TEdit
      Left = 48
      Top = 352
      Width = 465
      Height = 21
      TabOrder = 0
    end
  end
  object Retrato: TMemo
    Left = 168
    Top = 72
    Width = 201
    Height = 209
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
  end
  object CmdOK: TButton
    Left = 104
    Top = 440
    Width = 121
    Height = 25
    Caption = '&OK'
    TabOrder = 1
    OnClick = CmdOKClick
  end
  object CmdCancel: TButton
    Left = 312
    Top = 440
    Width = 121
    Height = 25
    Caption = '&Cancel'
    TabOrder = 2
    OnClick = CmdCancelClick
  end
  object RBTipoOjos: TRadioGroup
    Left = 16
    Top = 232
    Width = 145
    Height = 161
    Caption = ' Tipo de ojos '
    ItemIndex = 0
    Items.Strings = (
      'Redondos'
      'Gafas'
      'Rasgados')
    TabOrder = 4
    OnClick = RBTipoOjosClick
  end
  object RBTipoPelo: TRadioGroup
    Left = 16
    Top = 64
    Width = 145
    Height = 161
    Caption = ' Tipo de pelo '
    ItemIndex = 0
    Items.Strings = (
      'Largo'
      'Raya'
      'Raso')
    TabOrder = 5
    OnClick = RBTipoPeloClick
  end
  object RBTipoOrejas: TRadioGroup
    Left = 168
    Top = 288
    Width = 201
    Height = 105
    Caption = ' Tipo de orejas y nariz '
    ItemIndex = 0
    Items.Strings = (
      'Gancho'
      'Redonda'
      'Pequeña')
    TabOrder = 6
    OnClick = RBTipoOrejasClick
  end
  object RBTipoBoca: TRadioGroup
    Left = 376
    Top = 64
    Width = 145
    Height = 161
    Caption = ' Tipo de boca '
    ItemIndex = 0
    Items.Strings = (
      'Larga'
      'Pequeña'
      'Delgada')
    TabOrder = 7
    OnClick = RBTipoBocaClick
  end
  object RBTipoMenton: TRadioGroup
    Left = 376
    Top = 232
    Width = 145
    Height = 161
    Caption = ' Tipo de mentón '
    ItemIndex = 0
    Items.Strings = (
      'Afeitado'
      'Barba'
      'Perilla')
    TabOrder = 8
    OnClick = RBTipoMentonClick
  end
end
