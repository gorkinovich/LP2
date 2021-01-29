inherited Delincuentes: TDelincuentes
  Left = 282
  Top = 51
  Caption = 'Delincuentes'
  ClientHeight = 602
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
    Left = 496
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
  end
  inherited RBTipoOjos: TRadioGroup
    Top = 296
  end
  inherited RBTipoBoca: TRadioGroup
    Top = 424
  end
  inherited RBTipoOrejas: TRadioGroup
    Top = 360
  end
  inherited RBTipoMenton: TRadioGroup
    Top = 488
  end
  inherited CmdAnyadir: TButton
    Left = 136
    Top = 560
  end
  inherited CmdEliminar: TButton
    Left = 376
    Top = 560
  end
  inherited CmdModificar: TButton
    Left = 256
    Top = 560
  end
  inherited CmdNuevo: TButton
    Left = 16
    Top = 560
  end
  object TxtSupervisor: TEdit [22]
    Left = 152
    Top = 160
    Width = 313
    Height = 21
    TabOrder = 14
  end
  object CBConfidente: TCheckBox [23]
    Left = 472
    Top = 160
    Width = 97
    Height = 17
    Caption = 'Confidente'
    TabOrder = 15
  end
  object TxtDelitos: TMemo [24]
    Left = 152
    Top = 96
    Width = 417
    Height = 57
    TabOrder = 16
  end
  object CLBDelitos: TCheckListBox [25]
    Left = 56
    Top = 192
    Width = 513
    Height = 33
    ItemHeight = 13
    Items.Strings = (
      'Lectura'
      'Anhelo')
    TabOrder = 17
  end
  inherited MenuPrincipal: TMainMenu
    object mnuConfidentes: TMenuItem
      Caption = 'Confidentes'
      OnClick = mnuConfidentesClick
    end
  end
end
