inherited Personas: TPersonas
  Left = 316
  Top = 173
  Caption = 'FPersonas'
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited CmdBuscar: TButton
    Left = 488
    Width = 121
  end
  object CmdAnyadir: TButton [16]
    Left = 128
    Top = 432
    Width = 113
    Height = 33
    Caption = '&Añadir'
    TabOrder = 10
    OnClick = CmdAnyadirClick
  end
  object CmdEliminar: TButton [17]
    Left = 368
    Top = 432
    Width = 113
    Height = 33
    Caption = '&Eliminar'
    TabOrder = 11
    OnClick = CmdEliminarClick
  end
  object CmdModificar: TButton [18]
    Left = 248
    Top = 432
    Width = 113
    Height = 33
    Caption = '&Modificar'
    TabOrder = 12
    OnClick = CmdModificarClick
  end
  object CmdNuevo: TButton [19]
    Left = 8
    Top = 432
    Width = 113
    Height = 33
    Caption = '&Nuevo'
    TabOrder = 13
    OnClick = CmdNuevoClick
  end
  inherited MenuPrincipal: TMainMenu
    inherited mnuArchivo: TMenuItem
      Caption = '&Archivo'
      object mnuArchivoNuevo: TMenuItem [0]
        Caption = '&Nuevo'
        OnClick = mnuArchivoNuevoClick
      end
      object mnuArchivoN1: TMenuItem [1]
        Caption = '-'
      end
      object mnuArchivoAbrir: TMenuItem [2]
        Caption = '&Abrir'
        OnClick = mnuArchivoAbrirClick
      end
      object mnuArchivoGuardar: TMenuItem [3]
        Caption = '&Guardar'
        OnClick = mnuArchivoGuardarClick
      end
      object mnuArchivoGuardarComo: TMenuItem [4]
        Caption = 'Guardar &como'
        OnClick = mnuArchivoGuardarComoClick
      end
      object mnuArchivoN2: TMenuItem [5]
        Caption = '-'
      end
      inherited mnuArchivoSalir: TMenuItem
        Caption = '&Salir'
      end
    end
    object mnuBBDD: TMenuItem
      Caption = '&Base de Datos'
      object mnuBBDDNueva: TMenuItem
        Caption = 'Nue&va'
        OnClick = mnuBBDDNuevaClick
      end
      object mnuBBDDN1: TMenuItem
        Caption = '-'
      end
      object mnuBBDDNuevo: TMenuItem
        Caption = '&Nuevo'
        OnClick = mnuBBDDNuevoClick
      end
      object mnuBBDDAnyadir: TMenuItem
        Caption = '&Añadir'
        OnClick = mnuBBDDAnyadirClick
      end
      object mnuBBDDModificar: TMenuItem
        Caption = '&Modificar'
        OnClick = mnuBBDDModificarClick
      end
      object mnuBBDDEliminar: TMenuItem
        Caption = '&Eliminar'
        OnClick = mnuBBDDEliminarClick
      end
      object mnuBBDDBuscar: TMenuItem
        Caption = '&Buscar'
        OnClick = mnuBBDDBuscarClick
      end
    end
  end
  inherited OpenPicDlg: TOpenPictureDialog
    Left = 48
  end
  object OpenDlg: TOpenDialog
    Left = 80
    Top = 8
  end
  object SaveDlg: TSaveDialog
    Left = 112
    Top = 8
  end
end
