ENTRY(reset)
MEMORY{
	mem (rwx) : ORIGIN = 0x00000000 , LENGTH = 64M
}
SECTIONS
{
	. = 0x10000;
	.startup . :
	{
		startup.o(.text)
	}>mem
	.text :
	{
		*(.text) 
	}>mem
	.bss :
	{
		*(.bss)
	}>mem
	.data :
	{
		*(.data)
	}>mem
	. = . +0x1000;
	stack_top = . ;
}