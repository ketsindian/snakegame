#include <stdio.h>
#define print_ch(n) printf("%c",n)
#define print(n) printf("%d",n)
#define tabt printf("\t")
#define endln printf("\n")
#define scan(x) scanf("%d",&x);
#define n1 40
#define n2 40
struct Snake
{
	int head_x;
	int head_y;
	int tail_x;
	int tail_y;
	int length;
	struct node
	{
		int node_x;
		int node_y;
	}node[100];
};
 struct Fruit
{
	int f_x;
	int f_y;
};

static struct Snake snake;
static struct Fruit f;
int field[n1][n2];
int ni=-1;
int score =0;

void get_snake(struct Snake *p_s)
{	
	endln;
	printf("\thead position is : (");
	print(p_s->head_x);
	printf(",");
	print(p_s->head_y);
	printf(") \t");

	printf("\ttail position is : (");
	print(p_s->tail_x);
	printf(",");
	print(p_s->tail_y);
	printf(") \t");
}
void get_Fruit(struct Fruit *p_f)
{
	printf("\tFruit position is : (");
	print(p_f->f_x);
	printf(",");
	print(p_f->f_y);
	printf(") \n");
}
void get_nodes(struct Snake *p_s)
{
	int k;
	if (ni==-1)
	{
		printf("\t\tno nodes \n");
	}
	else 
	{
		printf("\tnode array is :-- [ ");
		for(k=0;k<=ni;k++)
		{
			printf("(");
			print(p_s->node[k].node_x);
			printf(",");
			print(p_s->node[k].node_y);
			printf(")");
		}
		printf("]\n");
	}
}


void set_field(struct Snake *p_s ,struct Fruit *p_f)
{
	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(i==p_s->head_x && j==p_s->head_y)
				field[i][j]='*';
			else if(i==p_s->tail_x && j==p_s->tail_y)
				field[i][j]='*';
			else if(i==p_f->f_x && j==p_f->f_y)
				field[i][j]='@';
			else 
				field[i][j]='-';;
		}
	}
}
void clear()
{
	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			field[i][j]='-';
		}
	}
}
void replace()
{
	int i,j;
	for(i=0;i<n1;i++)
	{
		for(j=0;j<n2;j++)
		{
			if(field[i][j]==0)
				field[i][j]='-';
		}
	}
}
void print_arr()
{
	endln;
	int i,j;
	for(i=0;i<n1;i++)
	{
		tabt;
		tabt;
		tabt;
		print(i);
		tabt;
		for(j=0;j<n2;j++)
		{
			print_ch(field[i][j]);
			printf(" ");
		}
		endln;
	}
}


void defaulty(struct Snake *p_s,struct Fruit *p_f)
{
	p_s->head_x=n1/2;//(n1/2);
	p_s->head_y=n2/3;//(n2/2);
	p_s->tail_x=n1/2;//(n1/2)-1;
	p_s->tail_y=n2/3+n1/4;//(n2/2);
	p_f->f_x=(n1/2)+2;
	p_f->f_y=(n2/2);
}


void connect_snake(struct Snake *p_s)
{
	int i,j,k;
	if(ni==-1)
	{
		if(p_s->head_x==p_s->tail_x)
		{
			i=p_s->head_x;
			if(p_s->head_y>p_s->tail_y)
			{
				for(j=p_s->tail_y+1;j<=p_s->head_y;j++)
				{
					field[i][j]='*';
				}
			}
			else 
			{
				for(j=p_s->head_y+1;j<=p_s->tail_y;j++)
				{
					field[i][j]='*';
				}
			}
		}
		else if (p_s->head_y==p_s->tail_y)
		{			
			j=p_s->head_y;
			if(p_s->head_x>p_s->tail_x)
			{
				for(i=p_s->tail_x+1;i<=p_s->head_x;i++)
				{
					field[i][j]='*';
				}
			}
			else 
			{
				for(i=p_s->head_x+1;i<=p_s->tail_x;i++)
				{
					field[i][j]='*';
				}
			}
		}
	}
	else 
	{
		if(p_s->node[0].node_x==p_s->tail_x)
		{
			i=p_s->node[0].node_x;
			if(p_s->node[0].node_y>p_s->tail_y)
			{
				for(j=p_s->tail_y;j<=p_s->node[0].node_y;j++)
				{
					field[i][j]='*';
				}
			}
			else 
			{
				for(j=p_s->node[0].node_y;j<=p_s->tail_y;j++)
				{
					field[i][j]='*';
				}
			}
		}
		else if (p_s->node[0].node_y==p_s->tail_y)
		{			
			j=p_s->node[0].node_y;
			if(p_s->node[0].node_x>p_s->tail_x)
			{
				for(i=p_s->tail_x;i<=p_s->node[0].node_x;i++)
				{
					field[i][j]='*';
				}
			}
			else 
			{
				for(i=p_s->node[0].node_x;i<=p_s->tail_x;i++)
				{
					field[i][j]='*';
				}
			}
		}
		if(p_s->node[ni].node_x==p_s->head_x)
		{
			i=p_s->node[ni].node_x;
			if(p_s->node[ni].node_y>p_s->head_y)
			{
				for(j=p_s->head_y;j<=p_s->node[ni].node_y;j++)
				{
					field[i][j]='*';
				}
			}
			else 
			{
				for(j=p_s->node[ni].node_y;j<=p_s->head_y;j++)
				{
					field[i][j]='*';
				}
			}
		}
		else if (p_s->node[ni].node_y==p_s->head_y)
		{			
			j=p_s->node[ni].node_y;
			if(p_s->node[ni].node_x>p_s->head_x)
			{
				for(i=p_s->head_x;i<=p_s->node[ni].node_x;i++)
				{
					field[i][j]='*';
				}
			}
			else 
			{
				for(i=p_s->node[ni].node_x;i<=p_s->head_x;i++)
				{
					field[i][j]='*';
				}
			}
		}
		for(k=0;k<ni;k++)
		{
			if(p_s->node[k].node_x==p_s->node[k+1].node_x)
			{
				i=p_s->node[k].node_x;
				if(p_s->node[k].node_y>p_s->node[k+1].node_y)
				{
					for(j=p_s->node[k+1].node_y;j<=p_s->node[k].node_y;j++)
					{
						field[i][j]='*';
					}
				}
				else 
				{
					for(j=p_s->node[k].node_y;j<=p_s->node[k+1].node_y;j++)
					{
						field[i][j]='*';
					}
				}
			}
			else if (p_s->node[k].node_y==p_s->node[k+1].node_y)
			{			
				j=p_s->node[k].node_y;
				if(p_s->node[k].node_x>p_s->node[k+1].node_x)
				{
					for(i=p_s->node[k+1].node_x;i<=p_s->node[k].node_x;i++)
					{
						field[i][j]='*';
					}
				}
				else 
				{
					for(i=p_s->node[k].node_x;i<=p_s->node[k+1].node_x;i++)
					{
						field[i][j]='*';
					}
				}
			}
		}
	}
}


int check_direction_head(struct Snake *p_s)
{
	if(field[p_s->head_x][p_s->head_y]==field[p_s->head_x][p_s->head_y-1])
		return 6;
	else if(field[p_s->head_x][p_s->head_y]==field[p_s->head_x-1][p_s->head_y])
		return 2;
	else if(field[p_s->head_x][p_s->head_y]==field[p_s->head_x][p_s->head_y+1])
		return 4 ;
	else if(field[p_s->head_x][p_s->head_y]==field[p_s->head_x+1][p_s->head_y])
		return 8;
	else 
		return 0;
}
int check_direction_tail(struct Snake *p_s)
{
	if(field[p_s->tail_x][p_s->tail_y]==field[p_s->tail_x][p_s->tail_y-1])
		return 4;
	else if(field[p_s->tail_x][p_s->tail_y]==field[p_s->tail_x-1][p_s->tail_y])
		return 8;
	else if(field[p_s->tail_x][p_s->tail_y]==field[p_s->tail_x][p_s->tail_y+1])
		return 6 ;
	else if(field[p_s->tail_x][p_s->tail_y]==field[p_s->tail_x+1][p_s->tail_y])
		return 2;
	else 
		return 0;
}


int check_tail_node(struct Snake *p_s)  
{
	int c=-1;
	if(ni==-1)
		return -1;
	else
	{
			if((p_s->node[0].node_x==p_s->tail_x)&&(p_s->node[0].node_y==p_s->tail_y))
			{
				c=0;
				printf("\n\n match occured \n\n");
			}
		
		return c;
	}
}
void delete_node(struct Snake *p_s,int c)
{
	int k;
	for(k=0;k<ni;k++)
	{
		p_s->node[k]=p_s->node[k+1];
	}
	ni--;
}
void create_node(struct Snake *p_s)
{
	ni++;
	p_s->node[ni].node_x=p_s->head_x;
	p_s->node[ni].node_y=p_s->head_y;
	endln;
}

void update_Fruit(struct Snake *p_s,struct Fruit *p_f)
{
	int sum_x,sum_y;
	score++;
	sum_x=p_s->head_x + p_s->tail_x;
	sum_y=p_s->head_y + p_s->tail_y;
	if((0<sum_x && sum_x<n1) && (0<sum_y && sum_y<n2) )	
	{
		p_f->f_x= sum_x/(n1/3) + score %(n1/3) - 0.3*(sum_y%(n1/5));
		p_f->f_y= sum_y/(n1/3) + score %(n2/3) - score %3 - 0.3* (sum_x%(n2/5));
	}
	else if((0<sum_x && sum_x<n1) && (n2<sum_y && sum_y<(2*n2)))
	{
		p_f->f_x= sum_x/(n1/5) + score %(n1/3) - 0.3*(sum_y%(n1/5));
		p_f->f_y= sum_y/(n1/5)+ score %(n2/3)- score %3 - 0.3*(sum_x%(n2/5));
	}
	else if((n1<sum_x && sum_x<(2*n1)) && (0<sum_y && sum_y<n2))
	{
		p_f->f_x= sum_x/(n1/7) + score %(n1/3) - 0.3*(sum_y%(n1/5));
		p_f->f_y= sum_y/(n2/7) + score %(n2/3) - score %3 - 0.3*(sum_x%(n2/5));
	}
	else
	{
		p_f->f_x= sum_x/(n1/10) + score %(n1/3) - 0.3*(sum_y%(n1/5));
		p_f->f_y= sum_y/(n1/10) + score %(n2/3)- score %3 - 0.3*(sum_x%(n2/5));
	}
	while((field[p_f->f_x][p_f->f_y] == '*') || (p_f->f_x>n1 || p_f->f_y>n2 || p_f->f_x <0 || p_f->f_y <0))
	{
		p_f->f_x=p_f->f_x+2*(sum_x%10);
		p_f->f_y=p_f->f_y+2*(sum_x%9);
	}

}
	
void main()
{
	int i,j,c,check_head,check_tail,x;
	int flag_valid,flag_got_Fruit;
	struct Snake *p_s =&snake;
	struct Fruit *p_f=&f;
	//replace();
	defaulty(&snake,&f);
	set_field(&snake,&f);
	connect_snake(&snake);
	//print_arr();
	get_Fruit(&f);
	get_snake(&snake);
	print_arr();
	check_head=check_direction_head(&snake);
	check_tail=check_direction_tail(&snake);
	printf("\thead direction is :- ");
	print(check_head);
	tabt;
	printf("tail direction is :- ");
	print(check_tail);
	endln;
	while(1)	
	{
		flag_valid=1;
		flag_got_Fruit=0;
		check_head=check_direction_head(&snake);
		check_tail=check_direction_tail(&snake);
		printf("play your move --- ");
		scan(x);
		switch (x)
		{
			case 2:
			{
				if(check_head==4 || check_head==6)
				{
					create_node(&snake);
					(p_s->head_x)++;
					break;
				}
				else if(check_head==2)
				{
					(p_s->head_x)++;
					break;
				}
				else 
				{
					flag_valid=0;
					break;	
				}
			}
			case 8:
			{
				if(check_head==4 || check_head==6)
				{
					create_node(&snake);
					(p_s->head_x)--;
					break;
				}
				else if(check_head==8)
				{
					(p_s->head_x)--;
					break;
				}
				else 
				{
					flag_valid=0;
					break;	
				}
			}
			case 4:
			{
				if(check_head==4)
				{
					(p_s->head_y)--;
					break;
				}
				else if(check_head==2 || check_head==8)
				{
					create_node(&snake);
					(p_s->head_y)--;
					break;
				}
				else 
				{
					flag_valid=0;
					break;	
				}
			}
			case 6:
			{
				if(check_head==8 || check_head==2)
				{
					create_node(&snake);
					(p_s->head_y)++;
					break;
				}
				else if(check_head==6)
				{
					(p_s->head_y)++;
					break;
				}
				else 
				{
					flag_valid=0;
					break;	
				}
			}
			default :
			{
				flag_valid=0;
				printf("\tinvalid move\n");
			}
		}
		
		if(p_s->head_x==p_f->f_x && p_s->head_y==p_f->f_y)
		{
			update_Fruit(&snake,&f);
			flag_got_Fruit=1;
		}


		if(flag_valid==1 && flag_got_Fruit==0)
		{
			printf("\t\t   valid\n");
			if(check_tail==8)
			{
				(p_s->tail_x)--;
				c=check_tail_node(&snake);
				if(c!=-1)
					delete_node(&snake,c);

			}
			else if(check_tail==2)
			{
				(p_s->tail_x)++;
				c=check_tail_node(&snake);
				if(c!=-1)
					delete_node(&snake,c);

			}
			else if(check_tail==4)
			{
				(p_s->tail_y)--;
				c=check_tail_node(&snake);
				if(c!=-1)
					delete_node(&snake,c);
			}
			else if(check_tail==6)
			{
				(p_s->tail_y)++;
				c=check_tail_node(&snake);
				if(c!=-1)
					delete_node(&snake,c);
			}

		}
		set_field(&snake,&f);
		connect_snake(&snake);
		print_arr();
		get_snake(&snake);
		get_Fruit(&f);
		check_head=check_direction_head(&snake);
		check_tail=check_direction_tail(&snake);
		if(p_s->head_x > n1-1 || p_s->head_y > n2-1 || p_s->head_x < 0 || p_s->head_y < 0)
		{
			break;
		}

		if(check_head==8)
		{
			if((field[p_s->head_x - 1][p_s->head_y]=='*') || (field[p_s->head_x][p_s->head_y + 1]=='*') || (field[p_s->head_x][p_s->head_y - 1]=='*'))
				break;
		}
		else if(check_head==2)
		{
			if((field[p_s->head_x + 1][p_s->head_y]=='*') || (field[p_s->head_x][p_s->head_y + 1]=='*') || (field[p_s->head_x][p_s->head_y - 1]=='*'))
				break;
		}
		else if(check_head==4)
		{
			if((field[p_s->head_x][p_s->head_y - 1]=='*') || (field[p_s->head_x + 1][p_s->head_y]=='*') || (field[p_s->head_x - 1][p_s->head_y]=='*'))
				break;
		}
		else if(check_head==6)
		{
			if((field[p_s->head_x][p_s->head_y + 1]=='*') || (field[p_s->head_x + 1][p_s->head_y]=='*') || (field[p_s->head_x - 1][p_s->head_y]=='*'))
				break;
		}
		printf("\thead direction is :- ");
		print(check_head);
		tabt;
		printf("tail direction is :- ");
		print(check_tail);
		endln;
		printf("\tno of nodes are :-  ");
		print(ni+1);
		get_nodes(&snake);
		printf("\tscore is :--   ");
		print(score);
		endln;
	}	
	printf("\n\t**************** GAME OVER ***************");
	printf("\n \t ******************YOUR SCORE IS  -- ");
	print(score);
	endln;
}
