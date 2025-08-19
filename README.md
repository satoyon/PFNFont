# PFNFont

## What is this?

This Arduino library renders Japanese characters on various display devices using the [Pinot Font](https://github.com/yoshinari-nomura/pinot) format.

The Pinot Font format is simple and sorted by Unicode codepoint. This design allows for fast rendering of UTF-8 strings, even on low-power microcontrollers. For more details on the font format itself, please refer to the [original Pinot Font repository](https://github.com/yoshinari-nomura/pinot).

The PFNFont class is designed to be platform-independent, requiring no specific microcontroller architecture or display hardware. This makes it compatible with virtually all Arduino-based boards.

---
(Japanese)
PFNFontは、MicroPythonのために作成された[Pinot Font](https://github.com/yoshinari-nomura/pinot)を使って、任意のディスプレイデバイスに日本語キャラクタを出力するためのArduino向けのライブラリです。[Pinot Font](https://github.com/yoshinari-nomura/pinot)はシンプル、かつUnicodeコードポイントでソートされているため、非力なマイクロコントローラでもUTF-8の文字列を高速に表示できる特徴があります。[Pinot Font](https://github.com/yoshinari-nomura/pinot)の詳細はオリジナルの説明を参照してください。

PFNFontクラスはディスプレイデバイスや、マイクロコントローラのアーキテクチャに依存していないので、（おそらくは）すべてのArduinoファミリーで利用できるはずです。

## How to use?

To use the PFNFont class, you will need sufficient ROM or RAM to store the font data. You must also provide a callback function that draws the font's bitmap data to your specific display.

Please see the SimpleDraw example for a detailed implementation. This example demonstrates the library's functionality by rendering Japanese characters as ASCII art in the Arduino Serial Monitor.

---
(Japanese)
PFNFontを利用するには、フォントデータを格納できるサイズのROMまたはRAMと、ディスプレイにフォントビットマップを描くコールバック関数が必要です。詳細はexamples以下のSimpleDrawを参照してください。SimpleDrawは、Arduino IDEのシリアルターミナルにアスキーアートで日本語文字を出力します。
