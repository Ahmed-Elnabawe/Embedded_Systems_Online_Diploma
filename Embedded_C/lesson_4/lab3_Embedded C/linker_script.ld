/*
	linker_script 
	Ahmed Elnabawe
*/

MEMORY
{
	flash(RX)	: ORIGIN = 0x00000000, LENGTH = 512M
	sram(RWX)	: ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
	.text : {
		*(.vectors*)
		*(.text*)
		*(.rodata)
		. = ALIGN(4);
		_E_text = . ;
	}>flash
	.data : {
		_S_data = . ;
		*(.data*)
		. = ALIGN(4);
		_E_data = . ;
	}>sram AT> flash
	.bss : {
	. = ALIGN(4);
		_S_bss = . ;
		*(.bss)
		_E_bss = . ;
	}>sram
}