#include<stdio.h>

typedef struct Tree
    {
      struct Tree *Lchild;
      char data[10];
      struct Tree *Rchild;
      int flag;
      int level;
    
    }TREE;

void push(TREE*);
TREE* pop();
void create(TREE*);
void Inorder_Display_Recursive(TREE*); 
void Inorder_Display_Iterative(TREE*);
void Preorder_Display_Recursive(TREE*);
void Preorder_Display_Iterative(TREE*);
void Postorder_Display_Recursive(TREE*);
void Postorder_Display_Iterative(TREE*);

int tot,top=-1;
TREE *stack[20];

main()
   {
     int op=1,i;
     char ele[5];
     TREE *st=NULL;
     printf("\n\n   *******************  BINARY TREE   *********************");
     printf("\n\n    ENTER THE ROOT  NODE VALE : ");
     st=(TREE*) malloc(sizeof(TREE));
     printf("\n\n  Enter the  DATA  : ");
     scanf("%s",st->data);
     (st)->Lchild=(st)->Rchild=NULL;
      st->flag=0;
      st->level=1;
     create(st);
     printf("\n \t IN ORDER  USING RECURSION: \n\n\t");
     Inorder_Display_Recursive(st);
     printf("\n \t IN ORDER   ITERATIVE METHOD:  \n\n\t");
     Inorder_Display_Iterative(st);
     printf("\n\n\n \t PRE ORDER  USING RECURSION:\n\n\t");
     Preorder_Display_Recursive(st);
     printf("\n \t PRE ORDER  ITERATIVE METHOD:\n\n\t");
     Preorder_Display_Iterative(st);
     printf("\n\n\n \t POST ORDER  USING RECURSION :\n\n\t");
     Postorder_Display_Recursive(st);
     printf("\n \t POST ORDER  ITERATIVE METHOD:\n\n\t");
     Postorder_Display_Iterative(st);
     printf("\n\n\n\n\n");
   }

void Inorder_Display_Recursive(TREE *s)
   {
      if(s==NULL)
          printf("\n\n     TREE EMPTY   ");
       else
         {
          if(s->Lchild !=NULL) 
             Inorder_Display_Recursive((s->Lchild));
          printf(" %s",s->data);
          if(s->Rchild !=NULL)
             Inorder_Display_Recursive((s->Rchild));
         }
   }   
void Inorder_Display_Iterative(TREE *s)
   {
      TREE*p;
       if(s==NULL)
          printf("\n\n  TREE EMPTY   ");
       else
         {
          p=s;
          top=-1;
          while(top>-1||p!=NULL)
           { 
             if(p!=NULL)
               {
                push(p);
                p=p->Lchild;
               }
             else
              {
               p=pop();
               printf(" %s",p->data);
               p=p->Rchild;
              }
            }
           
         }
   }
  
void Preorder_Display_Recursive(TREE *s)
   {
     if(s!=NULL)
        {
          printf(" %s",s->data);
         if(s->Lchild !=NULL)
            Preorder_Display_Recursive((s->Lchild));
         if(s->Rchild !=NULL)
             Preorder_Display_Recursive((s->Rchild));
         }
      else 
         printf("\n  \n  \t  TREE   EMPTY  ");                                                                                                    
   }
void Postorder_Display_Recursive(TREE *s)
   {
      if(s==NULL)
          printf("\n\n     TREE EMPTY   ");
       else
         {
          if(s->Lchild !=NULL)
             Postorder_Display_Recursive((s->Lchild));
          if(s->Rchild !=NULL)
             Postorder_Display_Recursive((s->Rchild));
          printf(" %s",s->data);
         }
                                                                                                 
   }

void create(TREE*t)  
   {
     int op;
     static int lev; 
     TREE *temp;
       lev++;
       system("clear");
       printf("\n\n\t      %s    in LEVEL  %d \n\n",t->data,lev);
       printf("\n Do you want to create  >>LEFT  CHILD<< FOR  THIS PARENT      YES (1) : ");
       scanf("%d",&op);  
	if(op==1)
         {
          
          temp=(TREE*) malloc(sizeof(TREE));
          printf("\n\n  Enter the  DATA  : ");
          scanf("%s",temp->data);
          (temp)->Lchild=(temp)->Rchild=NULL;
           temp->flag=0;
           temp->level=lev+1;
           t->Lchild=temp;
           create(temp);     
         }
       system("clear");
       printf("\n\n\t      %s    in LEVEL  %d \n\n",t->data,lev);
       printf("\n Do you want to create >>RIGHT  CHILD<< FOR  THIS PARENT      YES (1) : ");
       scanf("%d",&op);
        if(op==1)
         {
                                                                                                
          temp=(TREE*) malloc(sizeof(TREE));
          printf("\n\n  Enter the  DATA  : ");
          scanf("%s",temp->data);
          (temp)->Lchild=(temp)->Rchild=NULL;
           temp->flag=0;
           temp->level=lev+1;
           t->Rchild=temp;
           create(temp);
         }
    
     lev--;
    }
 
void Preorder_Display_Iterative(TREE *s)
   {
    TREE *p;
     p=s;
      if(s==NULL)
          printf("\n\n     TREE EMPTY   ");
      else
        {
          top=-1;
          push(s);
        }
       while(top>-1)
        {
          p=pop(); 
           while(p!=NULL)
            {
             printf(" %s",p->data);
             if(p->Rchild!=NULL)
               push(p->Rchild);
             p=p->Lchild;
            }
         }                                                                                      
   }

void Postorder_Display_Iterative(TREE *s)
   {
    TREE *p,*t;
     if(s==NULL)
          printf("\n\n     TREE EMPTY   ");
      else
        {
           p=s;
           top=-1;
            while(1)
            {
                 while(p!=NULL)
                   {
                     push(p);
                      p=p->Lchild;
                   }
           
                 while((stack[top])->flag==1)      //process the node after 
                   {
                       p=pop();
                       printf(" %s",p->data);
                       if(top<0)
                          break;
                   }
                 if(top>-1)
       		   {   
         		 p=(stack[top])->Rchild;
         		 (stack[top])->flag=1;  
       		   }
        	else
        	         break;
             }// end of while
       }//end of else block 
   }

void push(TREE *p)
  {
     stack[++top]=p;
  }
TREE * pop()
  {
      return(stack[top--]);
  }
