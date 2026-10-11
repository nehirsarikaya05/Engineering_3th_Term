DOSYA = top_module.v
MODUL = top_module

devre.png: $(DOSYA)
	yosys -q -p "read_verilog $(DOSYA); proc; opt; show -format png -prefix devre $(MODUL)"

goster: devre.png
	xdg-open devre.png

temizle:
	rm -f devre.png devre.dot
