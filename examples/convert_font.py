#!/usr/bin/python3
import sys

# python convert_font.py pfnfont.pfn font_data > font.h

if len(sys.argv) < 3:
    print("Usage: python convert_font.py <input_file.pfn> <array_name>")
    sys.exit(1)

input_file = sys.argv[1]
array_name = sys.argv[2]

try:
    with open(input_file, "rb") as f:
        print(f"const unsigned char {array_name}[] = {{")
        byte = f.read(1)
        count = 0
        while byte:
            print(f"0x{byte.hex()}", end=", ")
            byte = f.read(1)
            count += 1
            if count % 16 == 0:
                print("") # 16バイトごとに改行
        print("\n};")
        print(f"const unsigned int {array_name}_len = {count};")

except FileNotFoundError:
    print(f"Error: File '{input_file}' not found.")
