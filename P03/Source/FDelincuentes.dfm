inherited Delincuentes: TDelincuentes
  Left = 514
  Top = 209
  OldCreateOrder = True
  PixelsPerInch = 96
  TextHeight = 13
  inherited MenuPrincipal: TMainMenu
    inherited mnuArchivo: TMenuItem
      object mnuArchivoNuevo: TMenuItem [0]
        Caption = 'Nuevo'
        OnClick = mnuArchivoNuevoClick
      end
      object mnuArchivoN1: TMenuItem [1]
        Caption = '-'
      end
      object mnuArchivoAbrir: TMenuItem [2]
        Caption = 'Abrir Txt'
        OnClick = mnuArchivoAbrirClick
      end
      object mnuArchivoGuardar: TMenuItem [3]
        Caption = 'Guardar Txt'
        OnClick = mnuArchivoGuardarClick
      end
      object mnuArchivoGuardarComo: TMenuItem [4]
        Caption = 'Guardar como Txt'
        OnClick = mnuArchivoGuardarComoClick
      end
      object mnuArchivoN2: TMenuItem [5]
        Caption = '-'
      end
    end
    object mnuBBDD: TMenuItem
      Caption = 'Base de Datos'
      object mnuBBDDNuevo: TMenuItem
        Caption = 'Nuevo'
        OnClick = mnuBBDDNuevoClick
      end
      object mnuBBDDN1: TMenuItem
        Caption = '-'
      end
      object mnuBBDDAgregar: TMenuItem
        Caption = 'Agregar'
        OnClick = mnuBBDDAgregarClick
      end
      object mnuBBDDBorrar: TMenuItem
        Caption = 'Borrar'
        OnClick = mnuBBDDBorrarClick
      end
      object mnuBBDDModificar: TMenuItem
        Caption = 'Modificar'
        OnClick = mnuBBDDModificarClick
      end
      object mnuBBDDBuscar: TMenuItem
        Caption = 'Buscar'
        OnClick = mnuBBDDBuscarClick
      end
    end
    object mnuConfidentes: TMenuItem
      Caption = 'Confidentes'
      OnClick = mnuConfidentesClick
    end
  end
  object OpenDlg: TOpenDialog
    Filter = 'Ficheros de Texto (*.txt)|*.txt'
    InitialDir = '.'
    Title = 'Abrir fichero de Delincuentes'
    Left = 56
    Top = 8
  end
  object SaveDlg: TSaveDialog
    Filter = 'Ficheros de Texto (*.txt)|*.txt'
    InitialDir = '.'
    Title = 'Salvar fichero de Delincuentes'
    Left = 96
    Top = 8
  end
end
