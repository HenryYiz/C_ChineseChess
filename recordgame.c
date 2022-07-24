#include "function.h"
#define  feof(_stream)  ((_stream)->_flag & _IOEOF)
extern FILE *p;
extern FILE *q;
extern int isrecord;
extern int isrecordplay;
extern int recordtime;
void recordgame()
{
	//FILE *p;
	int x,y;
	if (isrecord==1)
	{
	p = fopen ("record.txt","a");//以输出的形式（写）打开文件
	if (p!=NULL)
 {
 	for (y=0;y<10;y++)
	{
		for (x=0;x<9;x++)
    	{
   		fprintf(p,"%d ",board[x][y].name);
   		fprintf(p,"%d ",board[x][y].overRiver);
   		fprintf(p,"%d ",board[x][y].type);
		//fputc(board[x][y].overRiver,p);
		//fputc(board[x][y].type,p);
        }
    }
    
    fclose (p);
 }
}
}

void recordplay()
{
	//FILE *q;
	int x,y;
	int size;
	//if (isrecordplay==1)
	//{
		q = fopen ("record.txt","r");
		rewind (q);
		fseek ( q , 666*recordtime, SEEK_SET);
		if(q!=NULL)
		{
			for (y=0;y<10;y++)
			{
				for (x=0;x<9;x++)
				{
					//board[x][y].name=fgetc(q);
   		            //board[x][y].overRiver=fgetc(q);
   		            //board[x][y].type=fgetc(q);
				 	fscanf(q,"%d",&board[x][y].name);
				 	if (board[0][0].name==EOF)
				 	{
				 		break;
					}
   		            fscanf(q,"%d",&board[x][y].overRiver);
   		            fscanf(q,"%d",&board[x][y].type);
				}
			}
		}
		//fclose (q);
		//InitConsole();
	   // printf("%d",size);
	//}
}


