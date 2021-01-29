object MainForm: TMainForm
  Left = 246
  Top = 110
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'Retrato robot de criminales'
  ClientHeight = 265
  ClientWidth = 521
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Retrato: TMemo
    Left = 160
    Top = 16
    Width = 201
    Height = 209
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Courier New'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
  end
  object CmdGenerarCara: TButton
    Left = 8
    Top = 232
    Width = 505
    Height = 25
    Caption = 'Generar Cara'
    TabOrder = 1
    OnClick = CmdGenerarCara_OnClick
  end
  object RBTipoPelo: TRadioGroup
    Left = 8
    Top = 8
    Width = 145
    Height = 105
    Caption = ' Tipo de pelo '
    Items.Strings = (
      'Largo'
      'Raya'
      'Raso')
    TabOrder = 2
  end
  object RBTipoOjos: TRadioGroup
    Left = 8
    Top = 120
    Width = 145
    Height = 105
    Caption = ' Tipo de ojos '
    Items.Strings = (
      'Redondos'
      'Gafas'
      'Rasgados')
    TabOrder = 3
  end
  object RBTipoBoca: TRadioGroup
    Left = 368
    Top = 8
    Width = 145
    Height = 105
    Caption = ' Tipo de boca '
    Items.Strings = (
      'Larga'
      'Pequeña'
      'Delgada')
    TabOrder = 4
  end
  object RBTipoOrejas: TRadioGroup
    Left = 368
    Top = 120
    Width = 145
    Height = 105
    Caption = ' Tipo de orejas y nariz '
    Items.Strings = (
      'Gancho'
      'Redonda'
      'Pequeña')
    TabOrder = 5
  end
end
