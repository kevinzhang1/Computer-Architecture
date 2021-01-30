all:
	gcc -o linker linker.c
	./masm_mrd -o<a6.asm>a6.obj
	./masm_mrd -o<readint.asm>readint.obj
	./masm_mrd -o<writeint.asm>writeint.obj
	./masm_mrd -o<writestr.asm>writestr.obj
	./masm_mrd -o<addints.asm>addints.obj
	./masm_mrd -o<xbsywt.asm>xbsywt.obj
	./masm_mrd -o<rbsywt.asm>rbsywt.obj
	./masm_mrd -o<data.asm>data.obj
	./linker a6.obj readint.obj writeint.obj writestr.obj addints.obj xbsywt.obj rbsywt.obj data.obj>a6.exe
	./mic1 prom_mrd.dat a6.exe 0 2048
dump :
	./masm_mrd -o<a6.asm>a6.obj
	./masm_mrd -o<xbswt.asm>xbswt.obj
	./masm_mrd -o<rbswt.asm>rbswt.obj
	./linker -o a6.obj xbswt.obj rbswt.obj 
clean :
	rm *.obj
	rm *.exe
	rm linker
