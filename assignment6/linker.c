#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#define HEADERS 1
#define NO_HEADERS 0
char cstr_12[13];
typedef struct nament {
  char name[26];
  int addr;
  struct nament *next;
} SYMTABENTRY;

int get_sym_val(char*);

void append_table(void);

void generate_code(int);
 
void print_first_pass(int);
FILE *p1, *p2;
unsigned short pc = 0;

SYMTABENTRY *symtab = NULL;

int main( int argc, char* argv[]){
  int x, i, zz, linum=0, a=0, object_file=0;
  char instruction[18], symbol[26]; 
  if(argc>1&&(strcmp(argv[1], "-o")==0)){object_file = 1;i=2;} else i=1;
  p1 = fopen("/tmp/passone", "w+");
  unlink("/tmp/passone");
  while(i<argc){
    if((p2=fopen(argv[i], "r"))==NULL){exit(3);}
    while(fscanf(p2, "%d %s", &pc, instruction) != EOF){
      if(pc == 4096) break;
      symbol[0]='\0';
      if(instruction[0] == 'U'){fscanf(p2, "%s", symbol);}
      zz = pc+a;
      fprintf(p1, " %d %s %s \n", zz, instruction, symbol);
    }
    while(fscanf(p2, "%s %d", symbol, &x) != EOF){
    SYMTABENTRY *ss=malloc(sizeof(SYMTABENTRY));
  if(symtab==NULL){
    symtab=ss;
    ss->next=NULL;
  } else {
    ss->next=symtab;
    symtab=ss;
  }
  strcpy(ss->name, symbol);
  ss->addr=x+a;
    }
    a=zz+1;
    fclose(p2);
    i++;
  }
  if(object_file){
    print_first_pass(NO_HEADERS);
    printf("4096 x\n");
    append_table();
    return 0;
  }
  generate_code(linum);
  return 0;
}

void generate_code(int linum){
	char linbuf[10];
	char instruction[18];
	int  line_number;
	int  pc, mask, sym_val,i, j, old_pc, diff;
	char symbol[26];

	line_number = old_pc = 0;
	rewind(p1);

	sprintf(linbuf,"%5d:  ", line_number);

	while(fscanf(p1,"%d %s", &pc, instruction) != EOF){
	if((diff = pc - old_pc ) > 1){
	  for(j=1; j<diff; j++){
		sprintf(linbuf,"%5d:  ", line_number++);
		printf("%s1111111111111111\n",(linum ? linbuf: "\0"));
	  }
	}
	sprintf(linbuf,"%5d:  ", line_number++);
	old_pc = pc;

	 if(instruction[0] == 'U'){
	   fscanf(p1, "%s", symbol);
	   if((sym_val = get_sym_val(symbol)) == -1){
		fprintf(stderr, "no symbol in symbol table: %s\n", symbol);
		exit(27);
	   }
	   	
           for(i=0; i<12; i++){
	     cstr_12[i] = '0';
	   }
	   cstr_12[12] = '\0';
         
	   mask = 2048;
           for(i=0; i<12; i++){
	      if(sym_val & mask)
		  cstr_12[i] = '1';
	      mask >>= 1;
	   }
	   for(i=0; i<12; i++){
		instruction[i+5] = cstr_12[i];
	   }
	   printf("%s%s\n",(linum ? linbuf: "\0"),&instruction[1]);
	 }else
	   printf("%s%s\n",(linum ? linbuf: "\0"),instruction);
	}
	fclose(p1);
}
int get_sym_val(char *symbol){
  int i,j;
	struct nament *element, *list;

	for(list = symtab; list != (struct nament *)0; list = list->next){
		if(strcmp(list->name, symbol) == 0){
		   return(list->addr);
		}
	}
	return(-1);
}
void append_table(){

  struct nament *list;
  
  printf("   %d %s\n", 4096, "x");
  for(list=symtab;list != NULL;list=list->next) {
  printf("       %-25s %4d\n", list->name, list->addr);
  }
}
void print_first_pass(int headers){
  char inbuf[81];
  if(headers == HEADERS){
    printf("\n FIRST PASS \n");
    rewind(p1);
    while(fgets(inbuf, 80, p1) != NULL){
      printf("      %s", inbuf);
    }
    printf("\n  SECOND PASS  \n");
  } else{
    rewind(p1);
    while(fgets(inbuf, 80, p1) != NULL){
      printf("    %s", inbuf);
    }
  }
}