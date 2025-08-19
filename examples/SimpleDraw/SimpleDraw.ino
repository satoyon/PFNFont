#include <PFNFont.h>
#include "font.h"

extern const unsigned char shnmk14u_pfn[];  // フォントデータ
extern const unsigned int shnmk14u_pfn_len; // フォントデータの長さ

// 描画コールバック関数の実装例
// PFNFontライブラリが文字を描画する必要があるときにこの関数を呼び出す
// ここで手持ちのディスプレイにピクセルを描画する処理を実装する
// このサンプルではシリアルモニタに日本語フォントのアスキーアートを描きます
void draw_gryph_callback(font_gryph_t *gryph, int x, int y) {
  Serial.println("--- Character Start ---");
  Serial.printf("Draw at (x:%d, y:%d), size (%d x %d)\n", x, y, gryph->width, gryph->height);

  // ビットマップデータをシリアルモニタに表示
  for (int r = 0; r < gryph->height; r++) {
    for (int c = 0; c < gryph->width; c++) {
      int bit_index = r * gryph->width + c;
      int byte_index = bit_index / 8;
      int bit_offset = 7 - (bit_index % 8);
      if ((gryph->bitmap[byte_index] >> bit_offset) & 1) {
        Serial.print("*");
      } else {
        Serial.print(" ");
      }
    }
    Serial.println();
  }
  Serial.println("--- Character End ---");
}

// PFNFontオブジェクト
PFNFont font((uint8_t*)shnmk14u_pfn, (size_t)shnmk14u_pfn_len, draw_gryph_callback);

void setup() {
  Serial.begin(115200);
  delay(2000); // シリアルモニタが開くのを待つ

  if (font.isValid()) {
    Serial.println("Font data is valid.");
    // UTF-8文字列を描画
    font.draw_string(u8"こんにちは, 世界!", 10, 20);
  } else {
    Serial.println("Error: Font data is invalid.");
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
