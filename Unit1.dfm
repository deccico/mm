object frmMain: TfrmMain
  Left = 91
  Top = 82
  Width = 729
  Height = 508
  Caption = 'MM Videos'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000000020000000000000000000000000000000000000000
    000000008000008000000080800080000000800080008080000080808000C0C0
    C0000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000000000000000000000000000000000000000
    0000000AA00A00000000000000000000000000AA000AA0000000000000000000
    00000A200000A00000000000000000000000A2000000A0000000000000000000
    000A20000000A0000000000000000000000A2000000A20000000000000000000
    004A2000000A20000000000000000006040A2000002200000000000000000004
    604AA200002200000000000000000006460AAA40022200000000000000000440
    6464222042200000000000000000040646464604000000000000000000000444
    60006460400000000000000000004666111006440000F0000000000000006469
    1911006040000FF000000000000046999991104601000FFF0000000000006499
    B9991464910000FF000000000000669BBB911640910000FFF000000000000469
    B9996404900000FFF0000000000000669996000900000FFFFF00000000000000
    6660400000FFFFFFFFFFFFFFFF0000000054400000FFF00FFF0F0FF0FF000000
    004045000FFF0FF0F0F0F0FFFFF00000005450000FFF0FF0F0F0F0F0FFF00000
    005545000FFF0FF0F0FFF0F0FFF00500045004000FFF0FF0F0FFF0F0FFF00500
    550045000FFF0FF0FFFFFFF0FFF044445000500000FFF00FFFFFFFF0FF000050
    0005400000FFFFFFFFFFFFFFFF0000054545000000000000000000000000FFFF
    FFFFFFFFFFFFFFE6FFFFFFCE7FFFFF9F7FFFFF3F7FFFFE7F7FFFFC3E7FFFF81E
    7FFFE00CFFFFE00CFFFFC000FFFF8001FFFF8007FFFF80047FFF00061FFF0007
    0FFF000307FF000387FF000383FF800783FFC00C0003F0380001FC380001FC30
    0000FC300000FC300000B9B00000B330000007780001DE780001E0FC0003}
  KeyPreview = True
  OldCreateOrder = False
  Visible = True
  OnCreate = FormCreate
  OnKeyPress = FormKeyPress
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Label2: TLabel
    Left = 176
    Top = 272
    Width = 32
    Height = 13
    Caption = 'Label2'
  end
  object panelVideo: TPanel
    Left = 0
    Top = 0
    Width = 497
    Height = 440
    Align = alClient
    Caption = 'Video no disponible'
    Color = clBlack
    TabOrder = 0
    OnClick = panelVideoClick
  end
  object Panel2: TPanel
    Left = 0
    Top = 440
    Width = 721
    Height = 41
    Align = alBottom
    Color = clBlack
    TabOrder = 1
    object lblSub: TLabel
      Left = 1
      Top = 24
      Width = 719
      Height = 16
      Align = alBottom
      Caption = 'lblText'
      Color = clBlack
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentColor = False
      ParentFont = False
      Visible = False
    end
    object re: TRichEdit
      Left = 400
      Top = 0
      Width = 321
      Height = 41
      PlainText = True
      ScrollBars = ssVertical
      TabOrder = 0
      Visible = False
      WordWrap = False
    end
  end
  object Panel3: TPanel
    Left = 497
    Top = 0
    Width = 224
    Height = 440
    Align = alRight
    Color = clBlack
    TabOrder = 2
    object Label1: TLabel
      Left = 7
      Top = 316
      Width = 29
      Height = 16
      Caption = 'tecla'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      Visible = False
    end
    object lblFrame: TLabel
      Left = 8
      Top = 336
      Width = 39
      Height = 13
      Caption = 'lblFrame'
      Color = clGreen
      ParentColor = False
      Visible = False
    end
    object lblTot: TLabel
      Left = 48
      Top = 320
      Width = 39
      Height = 13
      Caption = 'lblFrame'
      Color = clGreen
      ParentColor = False
      Visible = False
    end
    object btnOpen: TButton
      Left = 8
      Top = 8
      Width = 49
      Height = 17
      Caption = 'Abrir'
      TabOrder = 0
      OnClick = btnOpenClick
    end
    object btnClose: TButton
      Left = 160
      Top = 8
      Width = 33
      Height = 17
      Caption = 'X'
      TabOrder = 1
      Visible = False
      OnClick = btnCloseClick
    end
    object btnAllWindow: TButton
      Left = 56
      Top = 8
      Width = 105
      Height = 17
      Caption = 'Pantalla completa'
      TabOrder = 2
      OnClick = btnAllWindowClick
    end
    object btnDefSize: TButton
      Left = 7
      Top = 280
      Width = 97
      Height = 25
      Caption = 'Tamaño x Defecto'
      TabOrder = 3
      OnClick = btnDefSizeClick
    end
    object btnClearAll: TButton
      Left = 7
      Top = 256
      Width = 81
      Height = 17
      Caption = 'Borrar Todos'
      TabOrder = 4
      OnClick = btnClearAllClick
    end
    object btnClearItem: TButton
      Left = 119
      Top = 256
      Width = 90
      Height = 17
      Caption = 'Borrar'
      TabOrder = 5
      OnClick = btnClearItemClick
    end
    object lstVideos: TListBox
      Left = 7
      Top = 32
      Width = 209
      Height = 217
      ItemHeight = 13
      TabOrder = 6
      OnClick = lstVideosClick
    end
    object Button4: TButton
      Left = 141
      Top = 192
      Width = 75
      Height = 25
      Caption = 'Button4'
      TabOrder = 7
      Visible = False
      OnClick = Button4Click
    end
    object lst: TListBox
      Left = 32
      Top = 72
      Width = 105
      Height = 153
      ItemHeight = 13
      TabOrder = 8
      Visible = False
    end
    object btnProp: TButton
      Left = 112
      Top = 280
      Width = 89
      Height = 25
      Caption = 'Proporcional'
      TabOrder = 9
      OnClick = btnPropClick
    end
    object Button1: TButton
      Left = 32
      Top = 360
      Width = 105
      Height = 17
      Caption = 'texto'
      TabOrder = 10
      Visible = False
      OnClick = Button1Click
    end
    object txtFile: TEdit
      Left = 104
      Top = 336
      Width = 105
      Height = 21
      TabOrder = 11
      Text = 'Matrix CD1.txt'
      Visible = False
    end
    object media: TMediaPlayer
      Left = 8
      Top = 408
      Width = 197
      Height = 20
      ColoredButtons = [btPlay, btPause, btStop, btNext, btPrev, btStep, btBack]
      EnabledButtons = [btPlay, btPause, btStop, btNext, btPrev, btStep, btBack]
      VisibleButtons = [btPlay, btPause, btStop, btNext, btPrev, btStep, btBack]
      Anchors = [akLeft, akTop, akBottom]
      AutoRewind = False
      TabOrder = 12
      OnPostClick = mediaPostClick
      OnNotify = mediaNotify
    end
    object lblStatus: TStaticText
      Left = 9
      Top = 385
      Width = 27
      Height = 20
      BorderStyle = sbsSunken
      Caption = 'ghg'
      Color = clGreen
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      TabOrder = 13
    end
  end
  object tmrHideMouse: TTimer
    Interval = 1300
    OnTimer = tmrHideMouseTimer
    Left = 160
    Top = 264
  end
  object tmrNextVideo: TTimer
    Interval = 1200
    OnTimer = tmrNextVideoTimer
    Left = 190
    Top = 264
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '*.mpg'
    Filter = 'Videos|*.mpg; *.mpeg;*.avi;*.asf|All|*.*'
    InitialDir = 'd:\videos'
    Options = [ofAllowMultiSelect, ofPathMustExist, ofFileMustExist, ofEnableSizing]
    Left = 220
    Top = 264
  end
  object tmrFrame: TTimer
    Enabled = False
    Interval = 350
    OnTimer = tmrFrameTimer
    Left = 256
    Top = 264
  end
end
