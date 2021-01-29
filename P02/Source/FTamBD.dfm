object TamBD: TTamBD
  Left = 401
  Top = 440
  BorderStyle = bsDialog
  Caption = 'TamBD'
  ClientHeight = 97
  ClientWidth = 297
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LblPregunta: TLabel
    Left = 8
    Top = 8
    Width = 260
    Height = 13
    Caption = 'Cuantos elementos desea que tenga la base de datos: '
  end
  object TxtRespuesta: TEdit
    Left = 8
    Top = 32
    Width = 281
    Height = 21
    TabOrder = 0
    Text = '1000'
    OnKeyDown = TxtRespuestaKeyDown
  end
  object CmdCancelar: TButton
    Left = 8
    Top = 64
    Width = 75
    Height = 25
    Caption = '&Cancelar'
    TabOrder = 1
    OnClick = CmdCancelarClick
  end
  object CmdAceptar: TButton
    Left = 216
    Top = 64
    Width = 75
    Height = 25
    Caption = '&Aceptar'
    TabOrder = 2
    OnClick = CmdAceptarClick
  end
end
