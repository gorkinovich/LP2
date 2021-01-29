inherited Confidentes: TConfidentes
  Left = 309
  Top = 101
  Caption = 'Confidentes'
  ClientHeight = 602
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited Retrato: TImage
    Top = 232
  end
  inherited Retina: TImage
    Top = 424
  end
  object LblSupervisor: TLabel [6]
    Left = 72
    Top = 168
    Width = 50
    Height = 13
    Caption = 'Supervisor'
  end
  object LblDelitos: TLabel [7]
    Left = 72
    Top = 104
    Width = 32
    Height = 13
    Caption = 'Delitos'
  end
  inherited CmdBuscar: TButton
    Top = 560
  end
  inherited CmdAnt: TButton
    Height = 505
  end
  inherited CmdSig: TButton
    Height = 505
  end
  inherited RBTipoPelo: TRadioGroup
    Top = 232
    Enabled = False
  end
  inherited RBTipoOjos: TRadioGroup
    Top = 296
    Enabled = False
  end
  inherited RBTipoBoca: TRadioGroup
    Top = 424
    Enabled = False
  end
  inherited RBTipoOrejas: TRadioGroup
    Top = 360
    Enabled = False
  end
  inherited RBTipoMenton: TRadioGroup
    Top = 488
    Enabled = False
  end
  object TxtSupervisor: TEdit [18]
    Left = 152
    Top = 160
    Width = 313
    Height = 21
    TabOrder = 10
  end
  object CBConfidente: TCheckBox [19]
    Left = 472
    Top = 160
    Width = 97
    Height = 17
    Caption = 'Confidente'
    TabOrder = 11
  end
  object TxtDelitos: TMemo [20]
    Left = 152
    Top = 96
    Width = 417
    Height = 57
    TabOrder = 12
  end
  object CLBDelitos: TCheckListBox [21]
    Left = 56
    Top = 192
    Width = 513
    Height = 33
    ItemHeight = 13
    Items.Strings = (
      'Lectura'
      'Anhelo')
    TabOrder = 13
  end
end
